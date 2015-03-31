#!/bin/bash
# ASGL an abstract argumentation solver in ECL and GECODE.
# Copyright (C) 2015  Kilian Sprotte

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

set -e

if [ -z "$ASGL_HOME" ]; then
    export ASGL_HOME=`pwd`
fi

bash scripts/generate-make-mk.sh

# make clean
# bash scripts/generate-make-mk.sh
# make install-ref
# make test-ref

make clean
bash scripts/generate-make-mk.sh
autoconf
./configure
make install-v1
make test-v1
./bin/asgl --check

make clean
echo DONE
