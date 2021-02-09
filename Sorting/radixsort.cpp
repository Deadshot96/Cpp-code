# include <iostream>
using namespace std;

void RadixSort(int[], int);
void CountSort(int[], int, int);
void PrintArray(int [], int);
void Swap(int [], int, int);
int getMax(int [], int);
int getMin(int[], int);

int main()
{
    int arr[] = {103, 32, 212, 4432, 2311, 312, 34, 112, 18, 132, 3, 53, 3347, 502, 
    345, 525, 13, 11, 1444, 1135, 3512, 4000, 623, 3445, 1352, 9421};
    int size = sizeof(arr) / sizeof(int);

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;
    
    // Calling the Function
    RadixSort(arr, size);

    PrintArray(arr, size);
    return 0;
}

void RadixSort(int arr[], int size){
    int maxElement = getMax(arr, size);
    int div = 1;
    while (maxElement > 0){
        CountSort(arr, size, div);
        maxElement /= div;
        div *= 10;
    }
}


void CountSort(int arr[], int size, int div){
    int range = 10;
    int freqArray[range] = {0};

    
    for (int i = 0; i < size; i++)
        freqArray[arr[i] / div % 10]++;

    for (int i = 1; i < range; i++)
        freqArray[i] += freqArray[i - 1];

    int ans[size];

    for (int i = size - 1; i >= 0; i--)
    {
        int idx = arr[i] / div % 10;
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
