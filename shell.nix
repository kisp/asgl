{
  pkgs ? import <nixpkgs> { },
}:

let

  ecl_cpp = pkgs.callPackage ./ecl-cpp.nix { };
  pkgsForGecode = import (builtins.fetchTarball {
    url = "https://github.com/NixOS/nixpkgs/archive/515b06ef2ae59b9813b3606888e1791ede8f9090.tar.gz";
  }) { };

in

pkgs.mkShell {
  buildInputs = [
    pkgs.which
    pkgs.autoconf
    pkgs.gmp
    ecl_cpp
    pkgsForGecode.gecode
    pkgs.ragel
  ];
  shellHook = ''
    echo "Welcome to the development environment!"
  '';
}
