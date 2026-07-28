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
    in
    {
      # The package IS the unchanged classic ./default.nix, fed the pinned pkgs.
      # So `nix build .#asgl` and a plain `nix-build` produce the same store path;
      # the flake adds a layer, it does not fork the build.
      packages = forEachSystem (pkgs: rec {
        asgl = import ./default.nix { inherit pkgs; };
        default = asgl;
      });

      # `nix run github:kisp/asgl` / `nix profile install github:kisp/asgl`
      # -> the `asgl` binary on PATH.
      apps = forEachSystem (pkgs: rec {
        asgl = {
          type = "app";
          program = "${import ./default.nix { inherit pkgs; }}/bin/asgl";
        };
        default = asgl;
      });

      # `nix develop` == the classic ./shell.nix (autoconf/ecl/gecode/ragel plus
      # the cucumber/aruba test tooling).
      devShells = forEachSystem (pkgs: {
        default = import ./shell.nix { inherit pkgs; };
      });

      formatter = forEachSystem (pkgs: pkgs.nixfmt-rfc-style);
    };
}
