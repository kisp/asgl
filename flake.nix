{
  description = "ASGL — an abstract argumentation solver in ECL + GECODE (with a Lingeling SAT backend)";

  # Pinned to the exact nixpkgs the classic build already targets (24.05); see
  # ./.envrc and .github/workflows/ci.yml. The 2015-era ECL 16.1.2 + GECODE
  # 4.3.3 stack does NOT configure against newer nixpkgs, so this pin is
  # load-bearing — it is what makes `nix profile install` reproducible.
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/63dacb46bf939521bdc93981b4cbb7ecb58427a0";

  outputs =
    { self, nixpkgs }:
    let
      systems = [
        "x86_64-linux"
        "aarch64-linux"
      ];
      forEachSystem =
        f: nixpkgs.lib.genAttrs systems (system: f (import nixpkgs { inherit system; }));
      # the commit built, for `asgl --version`: 1a7da06, or 1a7da06-dirty
      # for a working tree with changes
      commit = self.shortRev or self.dirtyShortRev or null;
      asglFor = pkgs: import ./default.nix { inherit pkgs commit; };
    in
    {
      # The package IS the classic ./default.nix, fed the pinned pkgs and the
      # commit. A plain `nix-build` builds the same, only its `asgl --version`
      # names no commit; the flake adds a layer, it does not fork the build.
      packages = forEachSystem (pkgs: rec {
        asgl = asglFor pkgs;
        default = asgl;
      });

      # `nix run github:kisp/asgl` / `nix profile install github:kisp/asgl`
      # -> the `asgl` binary on PATH.
      apps = forEachSystem (pkgs: rec {
        asgl = {
          type = "app";
          program = "${asglFor pkgs}/bin/asgl";
        };
        default = asgl;
        # nix run .#self-check [-- tests/tests-quick.lisp ...], from the
        # repository: the Lisp unit tests, all or the files named, against
        # this working tree
        self-check = {
          type = "app";
          program = "${pkgs.writeShellScript "asgl-self-check" ''
            export ASGL_HOME="$PWD"
            exec ${asglFor pkgs}/bin/asgl --check "$@"
          ''}";
        };
      });

      # `nix develop` == the classic ./shell.nix (autoconf/ecl/gecode/ragel plus
      # the cucumber/aruba test tooling).
      devShells = forEachSystem (pkgs: {
        default = import ./shell.nix { inherit pkgs; };
      });

      # `nix flake check` runs the whole test suite, each part as a check of
      # its own, so that one part can be run alone:
      #   nix build .#checks.x86_64-linux.self-check   the Lisp unit tests
      #   nix build .#checks.x86_64-linux.features     every cucumber feature
      checks = forEachSystem (
        pkgs:
        let
          asgl = asglFor pkgs;
          src = pkgs.lib.cleanSource ./.;
          cucumber = pkgs.bundlerEnv {
            name = "cucumber-aruba-for-asgl";
            gemdir = ./.;
          };
          # a writable copy of the sources, the tests write into it
          workCopy = ''
            export HOME=$TMPDIR
            cp -r ${src} work
            chmod -R u+w work
            cd work
          '';
        in
        {
          # asgl --check: the suite of tests/*.lisp, which compiles
          # tests/support/*.lisp first: so a C compiler and the headers ECL
          # includes, the inputs of the development shell
          self-check =
            pkgs.runCommandCC "asgl-self-check"
              {
                nativeBuildInputs = [ asgl ];
                buildInputs = [
                  (pkgs.callPackage ./ecl-cpp.nix { })
                  (pkgs.callPackage ./gecode.nix { })
                  pkgs.boehmgc
                  pkgs.gmp
                  pkgs.libffi
                ];
              }
              ''
                set -o pipefail
                ${workCopy}
                ASGL_HOME=$PWD asgl --check | tee $out
                grep -q 'SELF-CHECK PASSED SUCCESSFULLY' $out
              '';

          # every cucumber feature, with the data unpacked as `rake test` does
          features =
            pkgs.runCommand "asgl-features"
              {
                nativeBuildInputs = [
                  cucumber
                  pkgs.ruby
                  pkgs.perl
                  pkgs.which
                  pkgs.gnutar
                  pkgs.xz
                ];
              }
              ''
                set -o pipefail
                ${workCopy}
                mkdir -p bin
                ln -sf ${asgl}/bin/asgl bin/asgl
                rm -rf data/iccma15_testcases && tar xf data/iccma15_testcases.tar.xz
                rm -rf data/real-ee-gr-solutions && tar -C data -xf data/real-ee-gr-solutions.tar.xz
                rm -rf data/iccma15_solutions && tar xf data/iccma15_solutions.tar.xz && bash support/fixes.sh
                cucumber --format progress | tee $out
              '';
        }
      );

      formatter = forEachSystem (pkgs: pkgs.nixfmt-rfc-style);
    };
}
