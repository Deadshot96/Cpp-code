# include <iostream>
# include <vector>
using namespace std;

template <typename Comparable>
void PrintArray(vector <Comparable>);

template <typename Comparable>
void heapSort(vector<Comparable> &);

template <typename Comparable>
void Swap(vector<Comparable> &, size_t, size_t);

template <typename Iterator>
void heapSort(const Iterator &, const Iterator &);

template <typename Iterator, typename Comparator>
void heapSort(const Iterator &, const Iterator &, Comparator);

template <typename Comparable>
void percDown(vector <Comparable> &, int, int);

inline int leftChild(int);

int main()
{
    vector<int> arr{20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11};
    int size = arr.size();

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    heapSort(arr);

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
void heapSort(vector<Comparable> & a){
    for (int i = a.size() / 2 - 1; i >= 0; i--) // Built Heap
        percDown(a, i, a.size());

    for (int j = a.size() - 1; j > 0; j--) // Delete max
    {
        std::swap(a[0], a[j]);
        percDown(a, 0, j);
    }
}


/**
 * Internal method for heapsort.
 * i is the index of an item in the heap.
 * Returns the index of the left child.
*/

inline int leftChild(int i){
    return 2 * i + 1;
}

/**
 * Internal method for heapsort that is used in deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
*/

template <typename Comparable>
void percDown(vector<Comparable> & a, int i, int n){
    int child;
    Comparable tmp = std::move(a[i]);

    for (; leftChild(i) < n; i = child)
    {
        child = leftChild(i);

        if (child != n - 1 && a[child] < a[child + 1])
            ++child;

        if (tmp < a[child])
            a[i] = std::move(a[child]);
        else
            break;
    }
    a[i] = std::move(tmp);
}