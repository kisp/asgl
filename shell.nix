{
  pkgs ? import <nixpkgs> { },
}:

let
  ecl_cpp = pkgs.callPackage ./ecl-cpp.nix { };
  gecode = pkgs.callPackage ./gecode.nix { };
  cucumber-aruba-from-gemfile = pkgs.bundlerEnv {
    name = "cucumber-aruba-for-asgl";
    inherit (pkgs.ruby);
    gemdir = ./.;
  };
in

pkgs.mkShell {
  buildInputs = [
    pkgs.which
    pkgs.autoconf
    ecl_cpp
    gecode
    pkgs.ragel
    cucumber-aruba-from-gemfile
    pkgs.ruby
  ];
  shellHook = ''
    echo "Welcome to the development environment!"
  '';
}
