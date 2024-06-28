#include "quickSort.h"

int partitionRunTime(int* arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSortRunTime(int* arr, int low, int high)
{
    if (low < high)
    {
        int pi = partitionRunTime(arr, low, high);
        quickSortRunTime(arr, low, pi - 1);
        quickSortRunTime(arr, pi + 1, high);
    }
}

double calQuickSortRunTime(int* arr, int n)
{
    auto start = high_resolution_clock::now();

    quickSortRunTime(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return (double)duration.count();
}

int partition(int* arr, int low, int high, long long& numCmp)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; ++numCmp && j <= high - 1; j++)
    {
        if (++numCmp && arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int* arr, int low, int high, long long& numCmp)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, numCmp);
        quickSort(arr, low, pi - 1, numCmp);
        quickSort(arr, pi + 1, high, numCmp);
    }
}

void calQuickSort(int* arr, int n, long long& numCmp)
{
    numCmp = 0;
    quickSort(arr, 0, n - 1, numCmp);
}