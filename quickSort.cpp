#include "quickSort.h"

void quickSort(int *arr, int first, int last, long long &comparision)
{
    int pivot = arr[(first + last) / 2];
    int i = first, j = last;
    do
    {
        while (++comparision && arr[i] < pivot)
            i++;
        while (++comparision && arr[j] > pivot)
            j--;
        if (++comparision && i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (++comparision && i <= j);
    if (++comparision && first < j)
        quickSort(arr, first, j, comparision);
    if (++comparision && i < last)
        quickSort(arr, i, last, comparision);
}
void calQuickSort(int *arr, int n, long long &numCmp){
    numCmp = 0;
    quickSort(arr, 0, n - 1, numCmp);
}
void quickSortRunningTime(int *arr, int first, int last)
{
    int pivot = arr[(first + last) / 2];
    int i = first, j = last;
    do
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (first < j)
        quickSortRunningTime(arr, first, j);
    if (i < last)
        quickSortRunningTime(arr, i, last);
}

double calQuickSortRunningTime(int *arr, int n){
    auto start = high_resolution_clock::now();
    quickSortRunningTime(arr, 0, n - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return (double)duration.count();
}