#include "insertionSort.h"

void insertionSort(int* a, int n, int &numCmp) {
    numCmp = 0;
    for (int i = 1; ++numCmp && i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while ((++numCmp && j >= 0) && (++numCmp && a[j] > key)) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void insertionSortRuntime(int* a, int n) {
    auto start = high_resolution_clock::now();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Running time: " << duration.count() << endl;
}
