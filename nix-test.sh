#!/bin/bash

set -euxo pipefail

nix-shell \
    --pure --run 'cucumber features/syntax.feature'
