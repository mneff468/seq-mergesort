#!/usr/bin/env bash
set -euo pipefail

make

OUT="results.txt"
: > "$OUT"

for p in 1 2 3 4 5 6 7 8
do
  N=$((10**p))
  echo "Running N=$N"
  ./mergesort "$N" >> "$OUT"
done

echo "Wrote $OUT"
