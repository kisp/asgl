#!/bin/bash

set -e

./bin/asgl --cover-report
make clean | tail
