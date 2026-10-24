{ pkgs ? import <nixpkgs> {}
  # the commit, as `asgl --version` names it; the flake passes self.shortRev
, commit ? null
}:

let
  ecl = pkgs.callPackage ./ecl-cpp.nix { };
  gecode = pkgs.callPackage ./gecode.nix { };
in

pkgs.stdenv.mkDerivation rec {
  pname = "asgl";
  # ./VERSION is the version; asgl.lisp reads the same file
  version = pkgs.lib.fileContents ./VERSION;

  src = pkgs.lib.cleanSource ./.;

  # read by asgl.lisp at compile time; a sandbox has no .git to ask
  ASGL_COMMIT = if commit == null then "" else commit;

  nativeBuildInputs = [
    pkgs.autoconf
    pkgs.automake
    pkgs.makeWrapper
    pkgs.gcc
    pkgs.ragel
  ];

  buildInputs = [
    ecl
    gecode
    pkgs.gmp
    pkgs.mpfr
    pkgs.libffi
    pkgs.ruby
    pkgs.bundler
  ];

  # Configure with --without-gist as per upstream build
  configurePhase = ''
    echo "Running autoreconf..."
    autoreconf -vfi

    echo "Configuring ASGL..."
    ./configure --without-gist
  '';

  buildPhase = ''
    echo "Building ASGL..."
    bash scripts/generate-make-mk.sh
    make all
  '';

  installPhase = ''
    echo "Installing ASGL into $out..."
    mkdir -p $out/bin
    cp bin/asgl $out/bin/
  '';
}
