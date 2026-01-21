\# seq-mergesort



\## Build

On Centaurus:

make clean

make



\## Run one test

./mergesort 1000000

This took awhile but I got it. 
1) SSH into Centaurus
2) Clone the repo git clone https://github.com/mneff468/seq-mergesort.git
cd seq-mergesort

3) make
4)submit the benchmark job, instuctions say not to run large jobs on the head
node but I really don't know what a large project is yet
sbatch slurm_bench.sbatch

5)check the queue: squeue -u $USER

6)After it completes it writes the results to results_centaurus file

7) Generate the graph plot based on results. I used: 
python3 plot.py results_centaurus.txt plot_centaurus.png



\## Benchmark via Slurm (Centaurus)

sbatch scripts/benchmark\_slurm.sh



After it finishes:

python3 scripts/plot\_results.py results/times.csv results/plot.png



