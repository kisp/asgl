{
  pkgs ? import <nixpkgs> { },
}:

let

ecl_cpp = pkgs.callPackage ./ecl-cpp.nix {};

in

pkgs.mkShell {
  buildInputs = [
    pkgs.which
    pkgs.autoconf
    pkgs.gmp
    ecl_cpp
    pkgs.gecode
    pkgs.ragel
  ];
  shellHook = ''
    echo "Welcome to the development environment!"
  '';
}
