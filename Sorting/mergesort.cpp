# include <iostream>
using namespace std;

void MergeSort(int [], int);
void MergeSortedArrays(int [], int, int, int);
void MergeSortUtil(int [], int, int);
void PrintArray(int [], int);
void Swap(int [], int, int);

int main()
{
    int arr[] = {20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11};
    int size = sizeof(arr) / sizeof(int);

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    MergeSort(arr, size);

    PrintArray(arr, size);
    return 0;
}

void MergeSort(int arr[], int size){
    MergeSortUtil(arr, 0, size - 1);
}


void MergeSortUtil(int arr[], int lo, int hi){
    if (lo >= hi)
        return;

    int mid = lo + (hi - lo) / 2;

    MergeSortUtil(arr, lo, mid);
    MergeSortUtil(arr, mid + 1, hi);
    MergeSortedArrays(arr, lo, mid, hi);

}


void MergeSortedArrays(int arr[], int lo, int mid, int hi){
    int sizeA = mid - lo + 1;
    int sizeB = hi - mid;


    int arrA[sizeA], arrB[sizeB];

    for (int i = 0; i < sizeA; i++)
        arrA[i] = arr[lo + i];

    for (int i = 0; i < sizeB; i++)
        arrB[i] = arr[mid + 1 + i];

    
    int i = 0, j = 0, k = lo;

    while (i < sizeA && j < sizeB){
        if (arrA[i] <= arrB[j])
            arr[k] = arrA[i++];
        else
            arr[k] = arrB[j++];

        k++;
    }

    while (i < sizeA)
        arr[k++] = arrA[i++];

    while (j < sizeB)
        arr[k++] = arrB[j++];

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

