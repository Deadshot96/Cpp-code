# include <iostream>
using namespace std;

void CountSort(int[], int);
void PrintArray(int [], int);
void Swap(int [], int, int);
int getMax(int [], int);
int getMin(int[], int);

int main()
{
    int arr[] = {10, 3, 2, 4, 1, 2, 3, 12, 18, 12, 3, 5, 7, 0, 3, 5, 1, 11, 14, 15, 12, 4, 6, 3, 2, 9};
    int size = sizeof(arr) / sizeof(int);

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;
    
    // Calling the Function
    CountSort(arr, size);

    PrintArray(arr, size);
    return 0;
}

void CountSort(int arr[], int size){
    int minElement = getMin(arr, size), maxElement = getMax(arr, size);
    int range = maxElement - minElement + 1;
    int freqArray[range] = {0};

    
    for (int i = 0; i < size; i++)
        freqArray[arr[i] - minElement]++;

    for (int i = 1; i < range; i++)
        freqArray[i] += freqArray[i - 1];

    int ans[size];

    for (int i = size - 1; i >= 0; i--)
    {
        int idx = arr[i] - minElement;
        int pos = freqArray[idx] - 1;
        ans[pos] = arr[i];
        freqArray[idx]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = ans[i];
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

int getMin(int arr[], int size){
    int minElement = arr[0];

    for (int i = 1; i < size; i++)
    {
        if(arr[i] < minElement)
            minElement = arr[i];
    }
    
    return minElement;
}


int getMax(int arr[], int size){
    int maxElement = arr[0];

    for (int i = 1; i < size; i++)
    {
        if(arr[i] > maxElement)
            maxElement = arr[i];
    }
    
    return maxElement;
}
