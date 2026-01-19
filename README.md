\# seq-mergesort



\## Build

On Centaurus:

make clean

make



\## Run one test

./mergesort 1000000



\## Benchmark via Slurm (Centaurus)

sbatch scripts/benchmark\_slurm.sh



After it finishes:

python3 scripts/plot\_results.py results/times.csv results/plot.png



