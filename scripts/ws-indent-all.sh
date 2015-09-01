#!/bin/bash

set -e

cat tools/source-files.txt | xargs ./tools/whitespace-cleanup.el
