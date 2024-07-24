#!/bin/bash

set -euxo pipefail

# git add .
# git commit -m wip || true

git clean -fxd

nix-shell \
  --pure --run 'bash steps.sh'
