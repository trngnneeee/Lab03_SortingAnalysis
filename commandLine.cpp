#include "bubbleSort.h"
#include "countingSort.h"
#include "flashSort.h"
#include "heapSort.h"
#include "insertionSort.h"
#include "Merge_Sort.h"
#include "quickSort.h"
#include "RadixSort.h"
#include "Selection_Sort.h"
#include "Shaker_Sort.h"
#include "ShellSort.h"
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

int *readFile(int &n, char *filename);
void runSort(int *arr, int n, char *algorithm, char *mode);
void writeFile(int *arr, int n, string filename);

int main(int argc, char *argv[])
{
    if (argc == 5)
    {
        if (strcmp(argv[1], "-a") == 0)
        {
            cout << "ALGORITHM MODE" << endl;
            cout << "Algorithm: " << argv[2] << endl;
            bool isNumeric = true;
            for (int i = 0; argv[3][i] != '\0'; i++)
            {
                if (!isdigit(argv[3][i]))
                {
                    isNumeric = false;
                    break;
                }
            }
            int n;
            int *num;
            // command 1
            if(!isNumeric){
                cout << "Input file: " << argv[3] << endl;
                num = readFile(n, argv[3]);
                cout << "Input size: " << n << endl;
                runSort(num, n, argv[2], argv[4]);
                writeFile(num, n, "output.txt");
            } 
            //Command 3
            else if(isNumeric){
                n = atoi(argv[3]);
                num = new int[n];

                cout << "Input order: Randomize\n";
                cout << "--------------------------";
                GenerateRandomData(num, n);
                writeFile(num, n, "input1.txt");
                runSort(num, n, argv[2], argv[4]);

                cout << "Input order: Nearly Sorted\n";
                cout << "----------------------------";
                GenerateNearlySortedData(num, n);
                writeFile(num, n, "input2.txt");
                runSort(num, n, argv[2], argv[4]);

                cout << "Input order: Sorted\n";
                cout << "----------------------------";
                GenerateSortedData(num, n);
                writeFile(num, n, "input3.txt");
                runSort(num, n, argv[2], argv[4]);

                cout << "Input order: Reverse\n";
                cout << "----------------------------";
                GenerateReverseData(num, n);
                writeFile(num, n, "input4.txt");
                runSort(num, n, argv[2], argv[4]);

            }
        }
    } else if(argc == 6){
        //Prototype: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
        if(argv[1] == "-a"){
            cout << "ALGORITHM MODE" << endl;
            cout << "Algorithm: " << argv[2] << endl;
            int n = atoi(argv[3]);
            int *num = new int[n];
            if(strcmp(argv[4], "-rand") == 0){
                cout << "Input order: randomize data\n";
                cout << "--------------------------";
                GenerateRandomData(num, n);
                writeFile(num, n, "input.txt");
                runSort(num, n, argv[2], argv[5]);
                writeFile(num, n, "output.txt");
            } else if(strcmp(argv[4], "-nsorted") == 0){
                cout << "Input order: nearly sorted data\n";
                cout << "----------------------------";
                GenerateNearlySortedData(num, n);
                writeFile(num, n, "input.txt");
                runSort(num, n, argv[2], argv[5]);
                writeFile(num, n, "output.txt")
            } else if(strcmp(argv[4], "-sorted") == 0){
                cout << "Input order: sorted data\n";
                cout << "----------------------------";
                GenerateSortedData(num, n);
                writeFile(num, n, "input.txt");
                runSort(num, n, argv[2], argv[5]);
                writeFile(num, n, "output.txt");
            } else if(strcmp(argv[4], "-rev") == 0){
                cout << "Input order: reverse sorted data\n";
                cout << "----------------------------";
                GenerateReverseData(num, n);
                writeFile(num, n, "input.txt");
                runSort(num, n, argv[2], argv[5]);
                writeFile(num, n, "output.txt");
            }
        }
    }
    return 0;
}

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
    if(strcmp(algorithm, "bubble-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            bubbleSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison;
            bubbleSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            bubbleSortRuntime(arr, n);
            int count_comparison;
            bubbleSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "counting-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            countingSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison;
            countingSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            countingSortRuntime(arr, n);
            int count_comparison;
            countingSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "flash-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            flashSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison;
            flashSortComparison(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            flashSortRuntime(arr, n);
            int count_comparison;
            flashSortComparison(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "heap-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            heapSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison;
            heapSortComparison(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            heapSortRuntime(arr, n);
            int count_comparison;
            heapSortComparison(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "insertion-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            insertionSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison;
            insertionSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            insertionSortRuntime(arr, n);
            int count_comparison;
            insertionSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "merge-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            mergeSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison;
            calComparisionMergeSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            mergeSortRuntime(arr, n);
            int count_comparison;
            calComparisionMergeSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "quick-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            quickSortRunTime(arr, 0, n - 1);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison;
            calQuickSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            quickSortRunTime(arr, 0, n - 1);
            int count_comparison;
            calQuickSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "radix-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            RadixSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison;
            Com_RadixSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            RadixSortRuntime(arr, n);
            int count_comparison;
            Com_RadixSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "selection-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            calTimeSelectionSort(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison;
            selecionSortComparision(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            calTimeSelectionSort(arr, n);
            int count_comparison;
            selecionSortComparision(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "shaker-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            calTimeShakerSort(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison;
            shakerSortComparision(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            calTimeShakerSort(arr, n);
            int count_comparison;
            shakerSortComparision(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "shell-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            ShellSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison;
            Com_ShellSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            ShellSortRuntime(arr, n);
            int count_comparison;
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
