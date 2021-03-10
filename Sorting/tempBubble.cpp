# include <iostream>
# include <vector>
using namespace std;

template <typename Comparable>
void PrintArray(vector <Comparable>);

template <typename Comparable>
void bubbleSort(vector<Comparable> &a);

template <typename Comparable>
void Swap(vector<Comparable> &, size_t, size_t);

template <typename Iterator>
void bubbleSort(const Iterator &, const Iterator &);

template <typename Iterator, typename Comparator>
void bubbleSort(const Iterator &, const Iterator &, Comparator); 


int main()
{
    vector<int> arr{20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11};
    int size = arr.size();

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    // bubbleSort(arr);
    // bubbleSort(arr.begin(), arr.end());
    bubbleSort(arr.begin(), arr.end(), greater<int>{});

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
void bubbleSort(vector <Comparable> & a){
    for (size_t i = 0; i < a.size() - 1; i++)
    {
        for (size_t j = 0; j < a.size() - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
                Swap(a, j, j + 1);
        }
    }
    
}

template <typename Iterator>
void bubbleSort(const Iterator & begin, const Iterator & end){
    bubbleSort(begin, end, less<decltype (*begin)>{});
}

template <typename Iterator, typename Comparator>
void bubbleSort(const Iterator & begin, const Iterator & end, Comparator lessThan){
    
    if (begin == end)
        return;

    size_t sortedLength = 0;
    for (Iterator i = begin; i < (end - 1); i++)
    {
        for (Iterator j = begin; j < (end - sortedLength - 1); j++)
        {
            if (lessThan(*(j + 1), *j))
                std::swap(*j, *(j + 1));
        }
        sortedLength += 1;
    }
}
