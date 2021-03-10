# include <iostream>
# include <vector>
using namespace std;

template <typename Comparable>
void PrintArray(vector <Comparable>);

template <typename Comparable>
void selectionSort(vector<Comparable> &);

template <typename Iterator>
void selectionSort(const Iterator &, const Iterator &);

template <typename Iterator, typename Comparator>
void selectionSort(const Iterator &, const Iterator &, Comparator);

template <typename Comparable>
void Swap(vector<Comparable> &, size_t, size_t);

int main()
{
    vector<int> arr{20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11};
    int size = arr.size();

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    // selectionSort(arr);
    // selectionSort(arr.begin(), arr.end());
    selectionSort(arr.begin(), arr.end(), greater<int>{});

    PrintArray(arr);
    return 0;
}

template <typename Iterator>
void selectionSort(const Iterator & begin, const Iterator & end){
    selectionSort(begin, end, less<decltype (*begin)>{});
}

template <typename Iterator, typename Comparator>
void selectionSort(const Iterator & begin, const Iterator & end, Comparator lessThan){
    
    if (begin == end)
        return;

    for (Iterator i = begin; i < (end - 1); ++i){
        Iterator j = i + 1, minAddr = i;
        Iterator tmp = i;

        while (j < end) {
            if (lessThan(*j, *minAddr))
                minAddr = j;
            j++;
        }
        
        std::swap(*minAddr, *tmp);
    }

}

template <typename Comparable>
void Swap(vector <Comparable> & a, size_t i, size_t j){
    Comparable tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}


template <typename Comparable>
void selectionSort(vector <Comparable> & a){

    for (size_t i = 0; i < a.size() - 1; ++i){
        size_t minIndex = i, j = i + 1;

        while (j < a.size()){
            if (a[j] < a[minIndex])
                minIndex = j;
            j++;
        }
        Swap(a, i, minIndex);
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
