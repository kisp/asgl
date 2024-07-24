{
  pkgs ? import <nixpkgs> { },
}:

let
  ecl_cpp = pkgs.callPackage ./ecl-cpp.nix { };
  gecode = pkgs.callPackage ./gecode.nix { };
in

pkgs.mkShell {
  buildInputs = [
    pkgs.which
    pkgs.autoconf
    ecl_cpp
    gecode
    pkgs.ragel
  ];
  shellHook = ''
    echo "Welcome to the development environment!"
  '';
}
