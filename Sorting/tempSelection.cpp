# include <iostream>
# include <vector>
using namespace std;

template <typename Comparable>
void PrintArray(vector <Comparable>);

template <typename Comparable>
void selectionSort(vector<Comparable> &);

int main()
{
    vector<int> arr{20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11};
    int size = arr.size();

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    selectionSort(arr);

    PrintArray(arr);
    return 0;
}


template <typename Comparable>
void selectionSort(vector <Comparable> & a){

    for (size_t i = 0; i < a.size() - 1; ++a){
        size_t minIndex = i, j = i + 1;

        while (j < a.size()){
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        swap(a.begin() + i, a.begin() + minIndex)
    }

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
