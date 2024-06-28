#include "ShellSort.h"

double ShellSortRuntime(int* arr, int n)
{
    auto start = high_resolution_clock::now();
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int tmp = arr[i];

            int j;

            for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = tmp;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return (double)duration.count();
}
void Com_ShellSort(int* arr, int n, long long& cnt_com)
{
    cnt_com = 0;
    for (int gap = n / 2; ++cnt_com && gap > 0; gap /= 2)
    {
        for (int i = gap; ++cnt_com && i < n; i++)
        {
            int tmp = arr[i];

            int j;

            for (j = i; (cnt_com += 2) && j >= gap && arr[j - gap] > tmp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = tmp;
        }
    }
}