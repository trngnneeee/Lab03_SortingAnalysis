#include "countingSort.h"
#include "flashSort.h"
void countingSort(int *arr, int n, int &numCmp){
    numCmp = 0;

    int maxVal = maxElement1(arr, n, numCmp);
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

double countingSortRuntime(int *arr, int n){
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
    return (double)duration.count();
}

int maxElement1(int *arr, int n, int &count_comparison){
    int max = arr[0];
    for(int i = 1; ++count_comparison && i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
