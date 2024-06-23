#include "ShellSort.h"

void ShellSortRuntime(int* arr, int n)
{
    clock_t begin_radix = clock(); // start
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

    clock_t end_radix = clock(); // end
    cout << "Time run: " << (float)(end_radix - begin_radix) / CLOCKS_PER_SEC << " s" << endl;
}
void Com_ShellSort(int* arr, int n, int& cnt_com)
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

    cout << "Number of comparisons: " << cnt_com << endl;
}