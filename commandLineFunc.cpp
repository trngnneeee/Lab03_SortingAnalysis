#include "commandLine.h"

int *readFile(int &n, char *filename){
    ifstream fin(filename);
    if(!fin.is_open()){
        cout << "Cannot open file " << filename << endl;
        return NULL;
    }

    fin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++){
        fin >> a[i];
    }

    fin.close();
    return a;
}

void runSort(int *arr, int n, char *algorithm, char *mode){
    long long count_comparison = 0;
    if(strcmp(algorithm, "bubble-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << bubbleSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            bubbleSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << bubbleSortRuntime(arr, n) << endl;
            bubbleSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "counting-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << countingSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            countingSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << countingSortRuntime(arr, n) << endl;
            countingSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "flash-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << flashSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            flashSortComparison(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << flashSortRuntime(arr, n) << endl;
            flashSortComparison(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "heap-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << heapSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            heapSortComparison(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << heapSortRuntime(arr, n) << endl;
            heapSortComparison(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "insertion-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << insertionSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            insertionSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << insertionSortRuntime(arr, n) << endl;
            insertionSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "merge-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << mergeSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            calComparisionMergeSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << mergeSortRuntime(arr, n) << endl;
            calComparisionMergeSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "quick-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << calQuickSortRunningTime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            calQuickSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << calQuickSortRunningTime(arr, n) << endl;
            calQuickSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "radix-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << RadixSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            Com_RadixSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << RadixSortRuntime(arr, n) << endl;
            Com_RadixSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "selection-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << calTimeSelectionSort(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            selecionSortComparision(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << calTimeSelectionSort(arr, n) << endl;
            selecionSortComparision(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "shaker-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << calTimeShakerSort(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            shakerSortComparision(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << calTimeShakerSort(arr, n) << endl;
            shakerSortComparision(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "shell-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << ShellSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            Com_ShellSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << ShellSortRuntime(arr, n) << endl;
            Com_ShellSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else{
        cout << "Algorithm not found!" << endl;
    }
}

void writeFile(int *arr, int n, string filename){
    ofstream fout(filename);
    fout << n << endl;
    for(int i = 0; i < n; i++){
        fout << arr[i] << " ";
    }
    fout << endl;

    fout.close();
}
double runSort2(int *arr, int n, char *algorithm, char *mode){
    long long count_comparison = 0;
    if(strcmp(algorithm, "bubble-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return bubbleSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            bubbleSort(arr, n, count_comparison);
            return  (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "counting-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return countingSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            countingSort(arr, n, count_comparison);
            return (double)count_comparison ;
        }
    }
    else if(strcmp(algorithm, "flash-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return flashSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            flashSortComparison(arr, n, count_comparison);
            return  (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "heap-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return heapSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            heapSortComparison(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "insertion-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return insertionSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            insertionSort(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "merge-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return mergeSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            calComparisionMergeSort(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "quick-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return calQuickSortRunningTime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            calQuickSort(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "radix-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return RadixSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            Com_RadixSort(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "selection-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return calTimeSelectionSort(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            selecionSortComparision(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "shaker-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return calTimeShakerSort(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            shakerSortComparision(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "shell-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return ShellSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            Com_ShellSort(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    return -1;
}