#include "RadixSort.h"

void RadixSortRuntime(int* arr, int n)
{
    clock_t begin_radix = clock(); // start
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int digit = 0, div;
    do
    {
        digit++;
        div = max / pow(10, digit);
    } while (div > 0);


    int* tmpArr[10];
    for (int i = 0; i < 10; i++)
    {
        tmpArr[i] = new int[n];
    }

    int tmpCount[10];

    int divisor = 1;

    for (int d = 0; d < digit; d++)
    {
        for (int i = 0; i < 10; i++)
        {
            tmpCount[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            int digit_val = (arr[i] / divisor) % 10;
            tmpArr[digit_val][tmpCount[digit_val]++] = arr[i];
        }
        int index = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < tmpCount[i]; j++)
            {
                arr[index++] = tmpArr[i][j];
            }
        }

        divisor *= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        delete[] tmpArr[i];
    }

    clock_t end_radix = clock(); // end
    cout << "Time run: " << (float)(end_radix - begin_radix) / CLOCKS_PER_SEC << " s" << endl;
}
void Com_RadixSort(int* arr, int n, int& cnt_com)
{
    
    cnt_com = 0;

    int max_val = arr[0];

    for (int i = 1; ++cnt_com && i < n; i++)
    {
        if (++cnt_com && arr[i] > max_val)
            max_val = arr[i];
    }

    int digit = 0, div;
    do
    {
        digit++;
        div = max_val / pow(10, digit);
    } while (++cnt_com && div > 0);

    int* tmpArr[10];

    for (int i = 0; ++cnt_com && i < 10; i++)
    {
        tmpArr[i] = new int[n];
    }

    int tmpCount[10];

    int divisor = 1;
    for (int d = 0; ++cnt_com && d < digit; d++)
    {

        for (int i = 0; ++cnt_com && i < 10; i++)
        {
            tmpCount[i] = 0;
        }

        for (int i = 0; ++cnt_com && i < n; i++)
        {
            int digit_val = (arr[i] / divisor) % 10;
            tmpArr[digit_val][tmpCount[digit_val]++] = arr[i];
        }

        int index = 0;
        for (int i = 0; ++cnt_com && i < 10; i++)
        {
            for (int j = 0; ++cnt_com && j < tmpCount[i]; j++)
            {
                arr[index++] = tmpArr[i][j];
            }
        }

        divisor *= 10;
    }

    for (int i = 0; ++cnt_com && i < 10; i++)
    {
        delete[] tmpArr[i];
    }

    cout << "Number of comparisons: " << cnt_com << endl;
}
