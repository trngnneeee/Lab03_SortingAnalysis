#include"Selection_Sort.h"

void selecionSortComparision(int *arr, int n, int &comparision){
    comparision = 0;
    for(int i = 0; ++comparision && i < n - 1 ; i++){
        int minIndex = i;
        for(int j = i + 1; ++comparision && j < n; j++){
            if(++comparision && arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void selecionSortTime(int *arr, int n){
    for(int i = 0; i < n - 1 ; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void calTimeSelectionSort(int *arr, int n){
    auto start = high_resolution_clock::now(); //start 
    selecionSortTime(arr, n);

    auto stop = high_resolution_clock::now(); //stop
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Running time: " << duration.count() << endl;
}