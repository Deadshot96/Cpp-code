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

template <typename Iterator, typename Comparator>
void __quickSort(const Iterator &, const Iterator &, Comparator);

template <typename Comparable>
void insertionSort(vector<Comparable> &, size_t, size_t);

template <typename Iterator, typename Comparator>
void insertionSort(const Iterator &, const Iterator &, Comparator);

template <typename Iterator, typename Comparator>
const Iterator partition(const Iterator &, const Iterator &, Comparator);

template <typename Iterator>
void PrintArray(const Iterator &, const Iterator&);

int main()
{
    vector<int> arr{20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11, 23, 15,
     43, 17, 32, 12, 61, 86, 43, 76, 73, 35, 65, 45, 55, 42, 78, 58, 82, 0, 94, 81};
    int size = arr.size();

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    quickSort(arr.begin(), arr.end());
    // quickSort(arr.begin(), arr.end(), less<int> {});
    
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

template <typename Iterator>
void PrintArray(const Iterator & begin, const Iterator & end){
    cout << "Array: ";
    for (Iterator i = begin; i <= end; i++)
    {
        cout << *i << "\t";
    }
    cout << endl;
}

template <typename Comparable>
void Swap(vector <Comparable> & a, size_t i, size_t j){
    Comparable tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

template <typename Comparable>
void insertionSort(vector<Comparable> & a, size_t left, size_t right){
    for (size_t i = left + 1; i <= right; i++)
    {
        Comparable tmp = std::move(a[i]);
        size_t j = i;

        while (j > left && a[j - 1] >= tmp){
            a[j] = std::move(a[j - 1]);
            j--;
        }
        a[j] = std::move(tmp);
    }
}

template <typename Comparable>
void quickSort(vector<Comparable> & a){
    quickSort(a, 0, a.size() - 1);
}

template <typename Comparable>
const Comparable & median3(vector<Comparable> & a, size_t left, size_t right){

    /**
     * Return median of left, center, and right.
     * Order these and hide the pivot.
     * We hide pivot at right - 1 because the element at right is 
     * already greater than the pivot so it doesn't violate the partitioning
    */
    
    size_t center = left + (right - left) / 2;

    if (a[center] < a[left])
        Swap(a, left, center);

    if (a[right] < a[left])
        Swap(a, right, left);

    if (a[right] < a[center])
        Swap(a, right, center);

    // Place pivot at right - 1 index
    Swap(a, center, right - 1);

    return a[right - 1];
}

template <typename Comparable>
void quickSort(vector<Comparable> & a, size_t left, size_t right){

    /**
     * Internal quicksort method that makes recursive calls.
     * Uses median-of-three partitioning and a cutoff of 10.
     * a is an array of Comparable items.
     * left is the left-most index of the subarray.
     * right is the right-most index of the subarray.
    */

    if (left + 10 <= right){

        const Comparable & pivot = median3(a, left, right);

        size_t i = left, j = right - 1;

        while (true){
            while (a[++i] < pivot);
            while (pivot < a[--j]);

            if (i < j)
                Swap(a, i, j);
            else 
                break;
        }

        Swap(a, i, right - 1);

        quickSort(a, left, i - 1);
        quickSort(a, i + 1, right);
    }
    else{
        insertionSort(a, left ,right);
    }
}

template <typename Iterator, typename Comparator>
void insertionSort(const Iterator & begin, const Iterator & end, Comparator lessThan){
    // if (begin == end)
    //     return;

    for (Iterator ptr = begin + 1; ptr != end; ptr++)
    {
        auto tmp = std::move(*ptr);
        Iterator j = ptr;

        while (j > begin && lessThan(tmp, *(j - 1))){
            *j = std::move(*(j - 1));
            j--;
        }

        *j = std::move(tmp);
    }
}

template <typename Iterator>
void quickSort(const Iterator & begin, const Iterator & end){
    __quickSort(begin, end - 1, less<decltype (*begin)>{});
}

template <typename Iterator, typename Comparator>
void quickSort(const Iterator & begin, const Iterator & end, Comparator lessThan){
    __quickSort(begin, end - 1, lessThan);
}

template <typename Iterator, typename Comparator>
const Iterator partition(const Iterator & begin, const Iterator & end, Comparator lessThan){
    
    Iterator i = begin, j = begin;
    auto pivot = std::move(*end);

    for (j = begin; j <= end; j++){

        if (lessThan(*j, pivot)){
            std::swap(*i, *j);
            i++;
        }
        
        if (!lessThan(*j, pivot) && !lessThan(pivot, *j)){
            std::swap(*i, *j);
            i++;
        }
    }

    return i - 1;
}

template <typename Iterator, typename Comparator>
void __quickSort(const Iterator & begin, const Iterator & end, Comparator lessThan){
    
    if (begin >= end)
        return;

    const Iterator partitionIdx = partition(begin, end, lessThan);
    
    __quickSort(begin, partitionIdx - 1, lessThan);
    __quickSort(partitionIdx + 1, end, lessThan);

    
}