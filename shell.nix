{
  pkgs ? import <nixpkgs> { },
}:

pkgs.mkShell {
  buildInputs = [
    pkgs.cowsay
    pkgs.which
    pkgs.autoconf
  ];
  shellHook = ''
    echo "Welcome to the development environment!"
  '';
}
