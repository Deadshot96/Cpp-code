# include <iostream>
# include <vector>
using namespace std;

template <typename Comparable>
void PrintArray(vector <Comparable>);

template <typename Comparable>
void quickSort(vector<Comparable> &);

template <typename Comparable>
void quickSort(vector<Comparable> &, size_t, size_t);

template <typename Comparable>
const Comparable & median3(vector <Comparable> &, size_t, size_t);

template <typename Comparable>
void Swap(vector<Comparable> &, size_t, size_t);

template <typename Iterator>
void quickSort(const Iterator &, const Iterator &);

template <typename Iterator, typename Comparator>
void quickSort(const Iterator &, const Iterator &, Comparator); 

template <typename Comparable>
void insertionSort(vector<Comparable> &);

int main()
{
    vector<int> arr{20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11, 23, 15,
     43, 17, 32, 12, 61, 86, 43, 76, 73, 35, 65, 45, 55, 42, 78, 58, 82, 0, 94, 81};
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

template <typename Comparable>
void Swap(vector <Comparable> & a, size_t i, size_t j){
    Comparable tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

template <typename Comparable>
void insertionSort(vector<Comparable> & a){
    for (size_t i = 1; i < a.size(); i++)
    {
        Comparable tmp = std::move(a[i]);
        size_t j = i;

        while (j > 0 && a[j - 1] >= tmp){
            a[j] = std::move(a[j - 1]);
            j--;
        }

        a[j] = std::move(tmp);
    }
}