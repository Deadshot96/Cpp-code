# include <iostream>
# include <vector>
using namespace std;

template <typename Comparable>
void PrintArray(vector <Comparable>);

template <typename Comparable>
void mergeSort(vector<Comparable> &);

template <typename Comparable>
void mergeSort(vector<Comparable> &, vector<Comparable> &, size_t, size_t);

template <typename Comparable>
void merge(vector<Comparable> &, vector<Comparable> &, size_t, size_t, size_t);

template <typename Comparable>
void Swap(vector<Comparable> &, size_t, size_t);

template <typename Iterator>
void mergeSort(const Iterator &, const Iterator &);

template <typename Iterator, typename Comparator>
void mergeSort(const Iterator &, const Iterator &, Comparator); 


int main()
{
    vector<int> arr{20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11};
    int size = arr.size();

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    mergeSort(arr);

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
void mergeSort(vector <Comparable> & a){
    vector <Comparable> tempVec(a.size());
    mergeSort(a, tempVec, 0, a.size() - 1);
}

template <typename Comparable>
void mergeSort(vector <Comparable> & a, vector<Comparable> & tempVec, size_t lo, size_t hi){
    if (lo >= hi)
        return;

    size_t mid = lo + (hi - lo) / 2;
    mergeSort(a, tempVec, lo, mid);
    mergeSort(a, tempVec, mid + 1, hi);
    merge(a, tempVec, lo, mid, hi);
}

template <typename Comparable>
void merge(vector <Comparable> & a, vector <Comparable> & tempVec, size_t lo, size_t mid, size_t hi){

    size_t leftPos = lo, rightPos = mid + 1, tempPos = lo;

    while (leftPos <= mid && rightPos <= hi)
        if (a[leftPos] <= a[rightPos])
            tempVec[tempPos++] = std::move(a[leftPos++]);
        else
            tempVec[tempPos++] = std::move(a[rightPos++]);

    while (leftPos <= mid)
        tempVec[tempPos++] = std::move(a[leftPos++]);

    while (rightPos <= hi)
        tempVec[tempPos++] = std::move(a[rightPos++]);

    for (size_t i = lo; i <= hi; i++)
        a[i] = std::move(tempVec[i]);
}