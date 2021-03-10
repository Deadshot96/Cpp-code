# include <iostream>
# include <vector>
using namespace std;

template <typename Comparable>
void PrintArray(vector <Comparable>);

template <typename Comparable>
void shellSort(vector<Comparable> &a);

template <typename Comparable>
void Swap(vector<Comparable> &, size_t, size_t);

template <typename Iterator>
void shellSort(const Iterator &, const Iterator &);

template <typename Iterator, typename Comparator>
void shellSort(const Iterator &, const Iterator &, Comparator); 


int main()
{
    vector<int> arr{20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11};
    int size = arr.size();

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    shellSort(arr);
    shellSort(arr.begin(), arr.end());
    shellSort(arr.begin(), arr.end(), greater<int>{});

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
void shellSort(vector <Comparable> & a){
    for (size_t gap = a.size() / 2; gap > 0; gap /= 2)
    {
        for (size_t i = gap; i < a.size(); i++)
        {
            Comparable tmp = std::move(a[i]);
            size_t j = i;

            while (j >= gap && tmp < a[j - gap]){
                a[j] = std::move(a[j - gap]);
                j -= gap;
            }
            a[j] = std::move(tmp);
        }
    }
}

template<typename Iterator>
void shellSort(const Iterator & begin, const Iterator & end){
    shellSort(begin, end, less<decltype (*begin)>{});
}

template<typename Iterator, typename Comparator>
void shellSort(const Iterator & begin, const Iterator & end, Comparator lessThan){
    size_t size = end - begin;

    for (size_t gap = size / 2; gap > 0; gap /= 2)
    {
        for (Iterator i = begin + gap; i < end; i++)
        {
            auto tmp = std::move(*i);
            Iterator j = i;

            while (j >= (begin + gap) && lessThan(tmp, *(j - gap))){
                *j = std::move(*(j - gap));
                j -= gap;
            }
            *j = std::move(tmp);
        }
    }
}