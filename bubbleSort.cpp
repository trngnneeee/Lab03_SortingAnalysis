#include "bubbleSort.h"

void bubbleSort(int *arr, int n, int &count_comparison){
    count_comparison = 0;
    for(int i = 0; ++count_comparison && i < n - 1; i++){
        for(int j = 0; ++count_comparison && j < n - i - 1; j++){
            count_comparison++;
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSortRuntime(int *arr, int n){
    auto start = high_resolution_clock::now(); //start 
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    auto stop = high_resolution_clock::now(); //stop
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " ms" << endl;
}