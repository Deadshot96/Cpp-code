# include <iostream>
using namespace std;

void SelectionSort(int [], int);
void PrintArray(int [], int);
void Swap(int [], int, int);

int main()
{
    int arr[] = {20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11};
    int size = sizeof(arr) / sizeof(int);

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    SelectionSort(arr, size);

    PrintArray(arr, size);
    return 0;
}


void SelectionSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i, j = i + 1;

        while (j < size){
            if (arr[j] < arr[minIndex])
                minIndex = j;

            j++;
        }
        Swap(arr, minIndex, i);
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

