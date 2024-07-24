set -euxo pipefail

echo hello

autoconf configure.ac > configure
chmod +x configure

./configure

make
