set -euxo pipefail

echo hello

autoconf configure.ac > configure
chmod +x configure

./configure --without-gist

./scripts/generate-make-mk.sh

make

./bin/asgl
