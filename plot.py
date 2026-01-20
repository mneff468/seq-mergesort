import sys
import matplotlib.pyplot as plt

def read_results(path):
    xs = []
    ys = []
    with open(path, "r") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) != 2:
                continue
            n = int(parts[0])
            t = float(parts[1])
            xs.append(n)
            ys.append(t)
    return xs, ys

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 plot.py <results.txt> <plot.png>")
        sys.exit(1)

    results_path = sys.argv[1]
    out_path = sys.argv[2]

    xs, ys = read_results(results_path)

    plt.figure()
    plt.plot(xs, ys, marker="o")
    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Array size N (log scale)")
    plt.ylabel("Time (ms, log scale)")
    plt.title("Merge Sort Benchmark")
    plt.grid(True, which="both", linestyle="--", linewidth=0.5)
    plt.tight_layout()
    plt.savefig(out_path, dpi=200)
    print(f"Wrote {out_path}")

if __name__ == "__main__":
    main()
