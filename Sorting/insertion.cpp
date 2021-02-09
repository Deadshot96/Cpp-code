# include <iostream>
using namespace std;

void InsertionSort(int [], int);
void PrintArray(int [], int);
void Swap(int [], int, int);

int main()
{
    int arr[] = {20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11};
    int size = sizeof(arr) / sizeof(int);

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    InsertionSort(arr, size);

    PrintArray(arr, size);
    return 0;
}

void InsertionSort(int arr[], int size){
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i], j = i;
        while (j > 0 && arr[j - 1] > temp){
            arr[j] = arr[j - 1];
            j--;
        }
        
        arr[j] = temp;
    }
    
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

