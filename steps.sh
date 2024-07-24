set -euxo pipefail

echo hello

autoconf configure.ac > configure
chmod +x configure

./configure

./scripts/generate-make-mk.sh

make
