import sys
import csv
import math

import matplotlib.pyplot as plt

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 plot_results.py <input_csv> <output_png>")
        sys.exit(1)

    inp = sys.argv[1]
    out = sys.argv[2]

    xs = []
    ys = []

    with open(inp, newline="") as f:
        r = csv.DictReader(f)
        for row in r:
            n = int(row["n"])
            t = float(row["seconds"])
            if n > 0 and t > 0:
                xs.append(n)
                ys.append(t)

    if not xs:
        print("No data found in CSV.")
        sys.exit(1)

    plt.figure()
    plt.plot(xs, ys, marker="o")
    plt.xscale("log")   # assignment wants log scale
    plt.yscale("log")   # optional, but makes growth clearer across many magnitudes
    plt.xlabel("Array size (n)")
    plt.ylabel("Time (seconds)")
    plt.title("Sequential Merge Sort Runtime")
    plt.grid(True, which="both")
    plt.tight_layout()
    plt.savefig(out, dpi=200)

    print(f"Saved plot to {out}")

if __name__ == "__main__":
    main()
