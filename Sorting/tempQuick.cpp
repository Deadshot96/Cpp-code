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
void insertionSort(vector<Comparable> &, size_t, size_t);

int main()
{
    vector<int> arr{20, 15, 49, 3, 44, 10, 20, 1, 12, 40, 78, 84, 39, 11, 23, 15,
     43, 17, 32, 12, 61, 86, 43, 76, 73, 35, 65, 45, 55, 42, 78, 58, 82, 0, 94, 81};
    int size = arr.size();

    cout << "Hello, World!\n";
    cout << "Size of array: " << size << endl;

    // Calling the Function
    quickSort(arr, 0, arr.size() - 1);

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