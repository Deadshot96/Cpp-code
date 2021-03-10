# include <iostream>
# include <vector>
using namespace std;

template <typename Comparable>
void PrintArray(vector <Comparable>);

template <typename Comparable>
void insertionSort(vector<Comparable> &a){
    for (size_t p = 1; p < a.size(); ++p){
        Comparable tmp = move(a[p]);
        size_t j;
        for (j = p; j > 0 && tmp < a[j - 1]; --j)
            a[j] = move(a[j - 1]);

        a[j] = move(tmp); 
    }
}

int main()
{
    vector<int> arr{20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11};
    int size = arr.size();

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    insertionSort(arr);

    PrintArray(arr);
    return 0;
}

template<typename Comparable>
void PrintArray(vector<Comparable> arr){
    cout << "Printing Array: \n";
    for (Comparable a: arr)
    {
        cout << a << "\t";
    }
    cout << "\n";
}
