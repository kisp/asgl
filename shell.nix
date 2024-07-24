{
  pkgs ? import <nixpkgs> { },
}:

pkgs.mkShell {
  buildInputs = [
    pkgs.which
    pkgs.autoconf
    pkgs.gmp
    pkgs.ecl
    pkgs.gecode
  ];
  shellHook = ''
    echo "Welcome to the development environment!"
  '';
}
