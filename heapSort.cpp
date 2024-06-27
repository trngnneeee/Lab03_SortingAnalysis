#include "heapSort.h"

void heapRebuildComparison(int start, int *arr, int n, int &count_comparison){
    int left = 2 * start + 1;
    ++count_comparison;
    if(left >= n){
        return;
    }
    int right = 2 * start + 2;
    ++count_comparison;
    if(right < n){
        count_comparison++;
        if(arr[right] > arr[left]){
            left = right;
        }
    }

    count_comparison++;
    if(arr[start] < arr[left]){
        swap(arr[start], arr[left]);
        heapRebuildComparison(left, arr, n, count_comparison);
    }
}

void heapSortComparison(int *arr, int n, int &count_comparison){
    count_comparison = 0;
    int index = n / 2 - 1;
    for (; ++count_comparison && index >= 0; index--)
    {
        heapRebuildComparison(index, arr, n, count_comparison);
    }

    swap(arr[0], arr[n - 1]);
    int heapSize = n - 1;
    while(++count_comparison && heapSize > 1){
        heapRebuildComparison(0, arr, heapSize, count_comparison);
        heapSize--;
        swap(arr[0], arr[heapSize]);
    }
}

void heapSortRuntime(int *arr, int n){
    auto start = high_resolution_clock::now();
    heapSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Running time: " << (double)duration.count() << endl;
}

void heapRebuild(int start, int *arr, int n){
    int left = 2 * start + 1;
    if(left >= n){
        return;
    }
    int right = 2 * start + 2;
    if(right < n){
        if(arr[right] > arr[left]){
            left = right;
        }
    }

    if(arr[start] < arr[left]){
        swap(arr[start], arr[left]);
        heapRebuild(left, arr, n);
    }
}

void heapSort(int *arr, int n){
    int index = n / 2 - 1;
    for (; index >= 0; index--)
    {
        heapRebuild(index, arr, n);
    }

    swap(arr[0], arr[n - 1]);
    int heapSize = n - 1;
    while(heapSize > 1){
        heapRebuild(0, arr, heapSize);
        heapSize--;
        swap(arr[0], arr[heapSize]);
    }
}
