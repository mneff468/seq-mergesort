#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

// TODO: implement merge + mergesort
static void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    // your implementation here
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <N>\n";
        return 1;
    }

    long long N = atoll(argv[1]);
    if (N <= 0) {
        cerr << "N must be positive\n";
        return 1;
    }

    vector<int> a((size_t)N);
    vector<int> tmp((size_t)N);

    mt19937 rng(12345);
    uniform_int_distribution<int> dist(numeric_limits<int>::min(),
                                       numeric_limits<int>::max());

    for (long long i = 0; i < N; i++) {
        a[(size_t)i] = dist(rng);
    }

    auto t0 = chrono::steady_clock::now();
    mergeSort(a, tmp, 0, (int)N - 1);
    auto t1 = chrono::steady_clock::now();

    chrono::duration<double> elapsed = t1 - t0;

    // Print only seconds (so Slurm script can capture it)
    cout << elapsed.count() << "\n";
    return 0;
}
