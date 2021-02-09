# include <iostream>
using namespace std;

void QuickSort(int [], int);
void QuickSortUtil(int [], int, int);
int partition(int[], int, int);
void PrintArray(int [], int);
void Swap(int [], int, int);

int main()
{
    int arr[] = {20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11};
    int size = sizeof(arr) / sizeof(int);

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    QuickSort(arr, size);

    PrintArray(arr, size);
    return 0;
}

void QuickSort(int arr[], int size){
    QuickSortUtil(arr, 0, size - 1);
}

void QuickSortUtil(int arr[], int lo, int hi){

    if (lo >= hi)
        return;

    int partitionIndex = partition(arr, lo, hi);

    QuickSortUtil(arr, lo, partitionIndex - 1);
    QuickSortUtil(arr, partitionIndex + 1, hi);
}

int partition(int arr[], int lo, int hi){
    int pivot = arr[hi];
    int i = lo, j = lo;

    for (j = lo; j <= hi; j++)
    {
        if (arr[j] <= pivot){
            Swap(arr, i, j);
            i++;
        }
    }
    return i - 1;
}


void PrintArray(int arr[], int size){
    cout << "Printing Array: \n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << "\n";
}

void Swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

