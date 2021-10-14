#!/bin/bash

dirs=$(find "$1" -name "*" -type d | wc -l)
files=$(find "$1" -name "*" -type f | wc -l)

echo "There were $dirs directories."
echo "There were $files regular files."
