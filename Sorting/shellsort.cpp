# include <iostream>
using namespace std;

void ShellSort(int [], int);
void PrintArray(int [], int);
void Swap(int [], int, int);

int main()
{
    int arr[] = {20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11};
    int size = sizeof(arr) / sizeof(int);

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    ShellSort(arr, size);

    PrintArray(arr, size);
    return 0;
}

void ShellSort(int arr[], int size){
    for (int gap = size / 2; gap >= 1; gap /= 2)
    {
        for (int j = gap; j < size; j++)
        {
            for (int i = j - gap; i >= 0; i -= gap)
            {
                if (arr[i] > arr[i + gap])
                {
                    Swap(arr, i, i + gap);
                }
                else{
                    break;
                }
            }
            
        }
        
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

