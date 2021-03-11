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

template <typename Iterator, typename Comparator>
void merge(const Iterator &, const Iterator &, const Iterator &, Comparator); 

int main()
{
    vector<int> arr{20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11};
    int size = arr.size();

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    mergeSort(arr);
    mergeSort(arr.begin(), arr.end());
    mergeSort(arr.begin(), arr.end(), greater<int>{});

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

template <typename Iterator>
void mergeSort(const Iterator & begin, const Iterator & end){
    mergeSort(begin, end - 1, less<decltype (*begin)> {});
}

template <typename Iterator, typename Comparator>
void mergeSort(const Iterator & begin, const Iterator & end, Comparator lessThan){
    
    if (begin == end)
        return;

    Iterator mid = begin + (end - begin) / 2;
    mergeSort(begin, mid, lessThan);
    mergeSort(mid + 1, end, lessThan);
    merge(begin, mid, end, lessThan);
}

template <typename Iterator, typename Comparator>
void merge(const Iterator & begin, const Iterator & mid, const Iterator & end, Comparator lessThan){
    
    size_t sizeLeft = mid - begin + 1;
    size_t sizeRight = end - mid;
    
    vector<std::decay_t<decltype(*begin)>> tempLeft(sizeLeft);
    vector<std::decay_t<decltype(*begin)>> tempRight(sizeRight);

    for (size_t i = 0; i < sizeLeft; i++)
        tempLeft[i] = std::move(*(begin + i));
    
    for (size_t i = 0; i < sizeRight; i++)
        tempRight[i] = std::move(*(mid + i + 1));

    size_t i = 0, j = 0;
    Iterator ptr = begin;

    while (i < sizeLeft && j < sizeRight){
        if (lessThan(tempLeft[i], tempRight[j]))
            *ptr = std::move(tempLeft[i++]);
        else
            *ptr = std::move(tempRight[j++]);

        ptr++;
    }

    while (i < sizeLeft){
        *ptr = std::move(tempLeft[i++]);
        ptr++;
    }

    while (j < sizeRight){
        *ptr = std::move(tempRight[j++]);
        ptr++;
    }
}