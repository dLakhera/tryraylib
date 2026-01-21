#!/usr/bin/env bash
set -e

echo "Initializing submodules..."
git submodule update --init --recursive

echo "Configuring build..."
cmake -S . -B build

echo "Building..."
# cmake --build build
mkdir build
bash run.sh
