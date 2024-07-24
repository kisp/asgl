{
  pkgs ? import <nixpkgs> { },
}:

pkgs.mkShell {
  buildInputs = [
    pkgs.which
    pkgs.autoconf
    pkgs.gmp
    pkgs.ecl
  ];
  shellHook = ''
    echo "Welcome to the development environment!"
  '';
}
