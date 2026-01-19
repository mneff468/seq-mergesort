#!/bin/bash
#SBATCH --job-name=mergebench
#SBATCH --partition=Centaurus
#SBATCH --time=02:00:00
#SBATCH --mem=16G
#SBATCH --output=results/slurm-%j.out

set -euo pipefail

mkdir -p results
OUT="results/times.csv"
echo "n,seconds" > "$OUT"

# Build on the compute node (ensures correct environment)
make clean || true
make

# powers of 10: 10^1 ... 10^9
for exp in $(seq 1 9); do
  n=$((10**exp))
  echo "Running n=$n" 1>&2
  t=$(./mergesort "$n")
  echo "$n,$t" >> "$OUT"
done

echo "Wrote: $OUT" 1>&2
