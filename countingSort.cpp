#include "countingSort.h"

void countingSort(int *arr, int n, int &numCmp){
    numCmp = 0;

    int maxVal = *max_element(arr, arr + n);
    numCmp += n;

    int* count = new int[maxVal + 1]();

    for (int i = 0; ++numCmp && i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; ++numCmp && i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    int* output = new int[n];

    for (int i = n - 1; ++numCmp && i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; ++numCmp && i < n; i++) {
        arr[i] = output[i];
    }
    delete[] count;
}

void countingSortRuntime(int *arr, int n){
    auto start = high_resolution_clock::now();  
    int maxVal = *max_element(arr, arr + n);
    int* count = new int[maxVal + 1]();

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    int* output = new int[n];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    delete[] count;

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " ms" << endl;
}
