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
#include "DataGenerator.h"
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

int *readFile(int &n, char *filename);
void runSort(int *arr, int n, char *algorithm, char *mode);
void writeFile(int *arr, int n, string filename);
double runSort2(int *arr, int n, char *algorithm, char *mode);

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
                cout << "Input size: " << n <<"\n";
                cout << "\n";
                cout << "Input order: Randomize\n";
                cout << "--------------------------\n";
                GenerateRandomData(num, n);
                writeFile(num, n, "input1.txt");
                runSort(num, n, argv[2], argv[4]);
                
                cout << "\n";
                cout << "Input order: Nearly Sorted\n";
                cout << "----------------------------\n";
                GenerateNearlySortedData(num, n);
                writeFile(num, n, "input2.txt");
                runSort(num, n, argv[2], argv[4]);

                cout <<"\n";
                cout << "Input order: Sorted\n";
                cout << "----------------------------\n";
                GenerateSortedData(num, n);
                writeFile(num, n, "input3.txt");
                runSort(num, n, argv[2], argv[4]);

                cout << "\n";
                cout << "Input order: Reverse\n";
                cout << "----------------------------\n";
                GenerateReverseData(num, n);
                writeFile(num, n, "input4.txt");
                runSort(num, n, argv[2], argv[4]);
                delete []num;
            }
        }else if(strcmp(argv[1], "-c") == 0){
            //[Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
            cout << "COMPARE NODE\n";
            cout << "Algorithm: " << argv[2] << " | " << argv[3] <<"\n";
            cout << "Input file: " << argv[4] <<"\n";
            int n = 0;
            int *num = readFile(n, argv[4]);
            cout << "Input size: " << n <<"\n";
            cout << "-------------------------------\n";
            cout << "Running time: " << runSort2(num, n, argv[2], (char*)"-time")<< "|"<< runSort2(num, n, argv[3], (char *)"-time") << endl;
            cout << "Comparisions: " << (int)runSort2(num, n, argv[2], (char*)"-comp")<< "|"<< (int)runSort2(num, n, argv[3], (char*)"-comp") << endl;
        }else cout <<"Not Found!\n";
    } else if(argc == 6){
        //Prototype: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
        if(argv[1] == "-a"){
            cout << "ALGORITHM MODE" << endl;
            cout << "Algorithm: " << argv[2] << endl;
            int n = atoi(argv[3]);
            int *num = new int[n];
            cout << "Input size: " << n << "\n";
            if(strcmp(argv[4], "-rand") == 0){
                cout << "Input order: randomize data\n";
                cout << "--------------------------\n";
                GenerateRandomData(num, n);
                writeFile(num, n, "input.txt");
                runSort(num, n, argv[2], argv[5]);
                writeFile(num, n, "output.txt");
            } else if(strcmp(argv[4], "-nsorted") == 0){
                cout << "Input order: nearly sorted data\n";
                cout << "----------------------------\n";
                GenerateNearlySortedData(num, n);
                writeFile(num, n, "input.txt");
                runSort(num, n, argv[2], argv[5]);
                writeFile(num, n, "output.txt");
            } else if(strcmp(argv[4], "-sorted") == 0){
                cout << "Input order: sorted data\n";
                cout << "----------------------------\n";
                GenerateSortedData(num, n);
                writeFile(num, n, "input.txt");
                runSort(num, n, argv[2], argv[5]);
                writeFile(num, n, "output.txt");
            } else if(strcmp(argv[4], "-rev") == 0){
                cout << "Input order: reverse sorted data\n";
                cout << "----------------------------\n";
                GenerateReverseData(num, n);
                writeFile(num, n, "input.txt");
                runSort(num, n, argv[2], argv[5]);
                writeFile(num, n, "output.txt");
            }
            delete []num;
        }else if(argv[1] == "-c"){
            //a.exe -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
            cout << "COMPARE MODE \n";
            cout << "Algorithm: " << argv[2] << " | " << argv[3] << "\n";
            cout << "Input size: " << argv[4] << "\n";
            int n = stoi(argv[4]);
            int *num = new int[n];
            if(strcmp(argv[5], "-rand") == 0){
                cout << "Input order: randomize data\n";
                cout << "--------------------------\n";
                GenerateRandomData(num, n);
                writeFile(num, n, "input.txt");
                cout << "Running time: " << runSort2(num, n, argv[2], (char*)"-time") <<" | " << runSort2(num, n, argv[3], (char*)"-time") << endl;
                cout << "Comparisions: " << (int)runSort2(num, n, argv[2], (char*)"-comp") << " | " << (int)runSort2(num, n, argv[3],(char*) "-comp") << endl;
                //writeFile(num, n, "output.txt");
            } else if(strcmp(argv[5], "-nsorted") == 0){
                cout << "Input order: nearly sorted data\n";
                cout << "----------------------------\n";
                GenerateNearlySortedData(num, n);
                writeFile(num, n, "input.txt");
                cout << "Running time: " << runSort2(num, n, argv[2], (char*)"-time") <<" | " << runSort2(num, n, argv[3], (char*)"-time") << endl;
                cout << "Comparisions: " << (int)runSort2(num, n, argv[2], (char*)"-comp") << " | " << (int)runSort2(num, n, argv[3], (char*)"-comp") << endl;
                //writeFile(num, n, "output.txt");
            } else if(strcmp(argv[4], "-sorted") == 0){
                cout << "Input order: sorted data\n";
                cout << "----------------------------\n";
                GenerateSortedData(num, n);
                writeFile(num, n, "input.txt");
                cout << "Running time: " << runSort2(num, n, argv[2], (char*)"-time") <<" | " << runSort2(num, n, argv[3], (char*)"-time") << endl;
                cout << "Comparisions: " << (int)runSort2(num, n, argv[2], (char*)"-comp") << " | " << (int)runSort2(num, n, argv[3], (char*)"-comp") << endl;
                //writeFile(num, n, "output.txt");
            } else if(strcmp(argv[4], "-rev") == 0){
                cout << "Input order: reverse sorted data\n";
                cout << "----------------------------\n";
                GenerateReverseData(num, n);
                writeFile(num, n, "input.txt");
                cout << "Running time: " << runSort2(num, n, argv[2], (char*)"-time") <<" | " << runSort2(num, n, argv[3], (char*)"-time") << endl;
                cout << "Comparisions: " << (int)runSort2(num, n, argv[2], (char*)"-comp") << " | " << (int)runSort2(num, n, argv[3], (char*)"-comp") << endl;
                //writeFile(num, n, "output.txt");
            }
            delete []num;
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
            cout << "Running time: " << bubbleSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            bubbleSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << bubbleSortRuntime(arr, n) << endl;
            int count_comparison = 0;
            bubbleSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "counting-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << countingSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            countingSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << countingSortRuntime(arr, n) << endl;
            int count_comparison = 0;
            countingSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "flash-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << flashSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            flashSortComparison(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << flashSortRuntime(arr, n) << endl;
            int count_comparison = 0;
            flashSortComparison(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "heap-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << heapSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            heapSortComparison(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << heapSortRuntime(arr, n) << endl;
            int count_comparison = 0;
            heapSortComparison(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "insertion-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << insertionSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            insertionSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << insertionSortRuntime(arr, n) << endl;
            int count_comparison = 0;
            insertionSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "merge-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << mergeSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            calComparisionMergeSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << mergeSortRuntime(arr, n) << endl;
            int count_comparison = 0;
            calComparisionMergeSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "quick-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << quickSortRunTime(arr, 0, n - 1) << endl;
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            calQuickSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << quickSortRunTime(arr, 0, n - 1) << endl;
            int count_comparison = 0;
            calQuickSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "radix-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << RadixSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            Com_RadixSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << RadixSortRuntime(arr, n) << endl;
            int count_comparison = 0;
            Com_RadixSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "selection-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << calTimeSelectionSort(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            selecionSortComparision(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << calTimeSelectionSort(arr, n) << endl;
            int count_comparison = 0;
            selecionSortComparision(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "shaker-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << calTimeShakerSort(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            shakerSortComparision(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << calTimeShakerSort(arr, n) << endl;
            int count_comparison = 0;
            shakerSortComparision(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
    }
    else if(strcmp(algorithm, "shell-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            cout << "Running time: " << ShellSortRuntime(arr, n) << endl;
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            Com_ShellSort(arr, n, count_comparison);
            cout << "Comparisions: " << count_comparison << endl;
        }
        else if(strcmp(mode, "-both") == 0){
            cout << "Running time: " << ShellSortRuntime(arr, n) << endl;
            int count_comparison = 0;
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
    if(strcmp(algorithm, "bubble-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return bubbleSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            bubbleSort(arr, n, count_comparison);
            return  (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "counting-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return countingSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            countingSort(arr, n, count_comparison);
            return (double)count_comparison ;
        }
    }
    else if(strcmp(algorithm, "flash-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return flashSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            flashSortComparison(arr, n, count_comparison);
            return  (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "heap-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return heapSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            heapSortComparison(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "insertion-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return insertionSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            insertionSort(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "merge-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return mergeSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            calComparisionMergeSort(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "quick-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return quickSortRunTime(arr, 0, n - 1);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            calQuickSort(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "radix-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return RadixSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            Com_RadixSort(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "selection-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return calTimeSelectionSort(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            selecionSortComparision(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "shaker-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return calTimeShakerSort(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            shakerSortComparision(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    else if(strcmp(algorithm, "shell-sort") == 0){
        if(strcmp(mode, "-time") == 0)
            return ShellSortRuntime(arr, n);
        else if(strcmp(mode, "-comp") == 0){
            int count_comparison = 0;
            Com_ShellSort(arr, n, count_comparison);
            return (double)count_comparison;
        }
    }
    return -1;
}