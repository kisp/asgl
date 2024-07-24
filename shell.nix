{
  pkgs ? import <nixpkgs> { },
}:

let

ecl_cpp = pkgs.callPackage ./ecl_cpp.nix {};

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
