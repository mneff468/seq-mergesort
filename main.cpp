#include <chrono>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

static void mergeRange(vector<int>& a, vector<int>& tmp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else              tmp[k++] = a[j++];
    }
    while (i <= mid)   tmp[k++] = a[i++];
    while (j <= right) tmp[k++] = a[j++];

    for (int p = left; p <= right; ++p) a[p] = tmp[p];
}

static void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(a, tmp, left, mid);
    mergeSort(a, tmp, mid + 1, right);
    mergeRange(a, tmp, left, mid, right);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <N>\n";
        return 1;
    }

    long long Nll = atoll(argv[1]);
    if (Nll <= 0 || Nll > 2000000000LL) {
        cerr << "N must be a positive integer.\n";
        return 1;
    }
    int N = (int)Nll;

    vector<int> a(N), tmp(N);

    mt19937 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, 1000000);
    for (int i = 0; i < N; ++i) a[i] = dist(rng);

    auto start = chrono::high_resolution_clock::now();
    mergeSort(a, tmp, 0, N - 1);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> ms = end - start;
    cout << N << " " << ms.count() << "\n";
    return 0;
}
