{
  pkgs ? import <nixpkgs> { },
}:

pkgs.mkShell {
  buildInputs = [
    pkgs.cowsay
    pkgs.which
    pkgs.autoconf
    pkgs.gmp
  ];
  shellHook = ''
    echo "Welcome to the development environment!"
  '';
}
