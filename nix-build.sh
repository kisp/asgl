#!/bin/bash

set -euxo pipefail

git add .

git commit -m wip || true

git clean -nxd

nix-shell \
  --pure --run 'bash steps.sh'
