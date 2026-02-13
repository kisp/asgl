{
  lib,
  stdenv,
  fetchurl,
  fetchpatch,
  perl,
}:

stdenv.mkDerivation rec {
  pname = "gecode";
  version = "4.3.3";

  src = fetchurl {
    url = "https://github.com/Gecode/gecode/archive/refs/tags/release-${version}.tar.gz";
    sha256 = "sha256-EOmQqEtfBH/J4w7wtcFhrVuU7F0NWJO9Qfn4b0QHZaw=";
  };

  patches = [
    # (import ./fix-const-weights-clang-patch.nix fetchpatch)
  ];

  postPatch = ''
    substituteInPlace gecode/flatzinc/lexer.yy.cpp \
      --replace "register " ""
  '';

  nativeBuildInputs = [ perl ];

  preConfigure = "patchShebangs configure";

  configureFlags = [
    "--disable-gist"
    "--disable-qt"
    "--disable-examples"
    "--disable-flatzinc"
    "--disable-float-vars"
  ];

  env.CXXFLAGS = lib.optionalString stdenv.cc.isClang "-std=c++14";

  meta = with lib; {
    license = licenses.mit;
    homepage = "https://www.gecode.org";
    description = "Toolkit for developing constraint-based systems";
    platforms = platforms.all;
    maintainers = [ maintainers.manveru ];
  };
}
