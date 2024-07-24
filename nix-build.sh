#!/bin/bash

set -euxo pipefail

git add .

git commit -m wip

git clean -nxd

nix-shell \
  --pure --run 'bash steps.sh'
