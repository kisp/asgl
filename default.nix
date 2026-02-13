{ pkgs ? import <nixpkgs> {} }:

let
  ecl = pkgs.callPackage ./ecl-cpp.nix { };
  gecode = pkgs.callPackage ./gecode.nix { };
in

pkgs.stdenv.mkDerivation rec {
  pname = "asgl";
  version = "0.1.4";

  src = ./.;

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

  # Generate configure and Makefile from configure.ac / Makefile.in
  preConfigure = ''
    echo "Running autoreconf..."
    autoreconf -vfi
  '';

  # Configure with --without-gist as per upstream build
  configurePhase = ''
    echo "Configuring ASGL..."
    ./configure --without-gist
  '';

  buildPhase = ''
    echo "Building ASGL..."
    make all
  '';

  installPhase = ''
    echo "Installing ASGL into $out..."
    mkdir -p $out/bin
    cp bin/asgl $out/bin/
  '';
}
