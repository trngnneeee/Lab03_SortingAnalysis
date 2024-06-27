#include "flashSort.h"

void flashSortComparison(int *arr, int n, int &count_comparison){
    count_comparison = 0;
    ++count_comparison;
    int m = 0.45 * n;
    int min = minElement(arr, n, count_comparison);
    int max = maxElement(arr, n, count_comparison);

    if(min == max)
        return;

    int *l = new int[m + 1]{0};

    for(int i = 0; ++count_comparison && i < n; i++){
        int k = (int)((m - 1) * ((double)(arr[i] - min) / (max - min)));
        l[k]++;
    }

    for(int i = 1; ++count_comparison && i < m; i++){
        l[i] += l[i - 1];
    }

    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int flash;
    
    while(++count_comparison && nmove < n - 1){
        while(++count_comparison && j > l[k] - 1){
            j++;
            k = (int)((m - 1) * ((double)(arr[j] - min) / (max - min)));
        }
        flash = arr[j];
        while(++count_comparison && j != l[k]){
            k = (int)((m - 1) * ((double)(flash - min) / (max - min)));
            swap(arr[l[k] - 1], flash);
            l[k]--;
            nmove++;
        }
    }

    for (int i = 1; ++count_comparison && i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(++count_comparison && j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    delete[] l;
}

void flashSort(int *arr, int n){
    int m = 0.45 * n;
    int min = *min_element(arr, arr + n);
    int max = *max_element(arr, arr + n);

    if(min == max)
        return;

    int *l = new int[m + 1]{0};

    for(int i = 0; i < n; i++){
        int k = (int)((m - 1) * ((double)(arr[i] - min) / (max - min)));
        l[k]++;
    }

    for(int i = 1; i < m; i++){
        l[i] += l[i - 1];
    }

    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int flash;
    while(nmove < n - 1){
        while (j > l[k] - 1){
            j++;
            k = (int)((m - 1) * ((double)(arr[j] - min) / (max - min)));
        }
        flash = arr[j];
        while(j != l[k]){
            k = (int)((m - 1) * ((double)(flash - min) / (max - min)));
            swap(arr[l[k] - 1], flash);
            l[k]--;
            nmove++;
        }
    }

    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    delete[] l;
}

void flashSortRuntime(int *arr, int n){
    auto start = high_resolution_clock::now();
    flashSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Running time: " << duration.count() << endl;
}

int minElement(int *arr, int n, int &count_comparison){
    int min = arr[0];
    for(int i = 1; ++count_comparison && i < n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int maxElement(int *arr, int n, int &count_comparison){
    int max = arr[0];
    for(int i = 1; ++count_comparison && i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}