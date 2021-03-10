# include <iostream>
# include <vector>
using namespace std;

template <typename Comparable>
void PrintArray(vector <Comparable>);

template <typename Comparable>
void insertionSort(vector<Comparable> &a);

template <typename Comparable>
void Swap(vector<Comparable> &, size_t, size_t);

template <typename Iterator>
void insertionSort(const Iterator &, const Iterator &);

template <typename Iterator, typename Comparator>
void insertionSort(const Iterator &, const Iterator &, Comparator);

int main()
{
    vector<int> arr{20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11};
    int size = arr.size();

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    // insertionSort(arr);
    // insertionSort(arr.begin(), arr.end());
    insertionSort(arr.begin(), arr.end(), greater<int> {});

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
    a[j] = a[i];
}

template <typename Comparable>
void insertionSort(vector <Comparable> & a){
    for (size_t i = 1; i < a.size(); i++)
    {   
        Comparable tmp = std::move(a[i]);
        size_t j;
        for (j = i; j > 0 and tmp < a[j - 1]; j--)
            a[j] = std::move(a[j - 1]);
        a[j] = std::move(tmp);
    }
}

template <typename Iterator>
void insertionSort(const Iterator & begin, const Iterator & end){
    insertionSort(begin, end, less<decltype (*begin)>{});
}

template <typename Iterator, typename Comparator>
void insertionSort(const Iterator & begin, const Iterator & end, Comparator lessThan){
    if (begin == end)
        return;

    for (Iterator i = begin + 1; i < end; i++)
    {
        auto tmp = std::move(*i);
        Iterator j;

        for (j = i; j != begin && lessThan(tmp, *(j - 1)); j--)
            *j = std::move(*(j - 1));

        *j = std::move(tmp); 
    }
    
}