# include <iostream>
# include <vector>
using namespace std;

template <typename Comparable>
class BinaryHeap{
    public:
        explicit BinaryHeap(int capacity = 100): array(capacity) {
            currentSize = 0;
        }
        explicit BinaryHeap(const vector<Comparable> & items)
            : array(items.size() + 10), currentSize{items.size()}
        {
            for (int i = 0; i < items.size(); i++)
            {
                array[i + 1] = items[i];
            }

            buildHeap();
        }

        bool isEmpty() const;
        const Comparable & findMin() const;

        void insert(const Comparable &);
        void insert(Comparable &&);
        void deleteMin();
        void deleteMin(const Comparable &);
        void makeEmpty();

    private:
        int currentSize;
        vector<Comparable> array;

        void buildHeap();
        void percolateDown(int);
        void percolateUp(int);

};

template <typename Comparable>
bool BinaryHeap<Comparable> :: isEmpty() const{
    return currentSize == 0;
}

template <typename Comparable>
void BinaryHeap<Comparable> :: insert(const Comparable & x){
    if (currentSize == array.size() - 1)
        array.resize(array.size() * 2);

    int hole = ++currentSize;

    Comparable copy = x;
    array[0] = move(copy); // this steps ensures that the following loop terminates at hole = 1

    for(; x < array[hole / 2]; hole /= 2)
        array[hole] = move(array[hole / 2]);

    array[hole] = move(array[0]);

}

template <typename Comparable>
void BinaryHeap<Comparable> :: insert(Comparable && x){
    if (currentSize == array.size() - 1)
        array.resize(array.size() * 2);

    int hole = ++currentSize;

    Comparable copy = x;
    array[0] = move(copy); // this steps ensures that the following loop terminates at hole = 1

    for(; x < array[hole / 2]; hole /= 2)
        array[hole] = move(array[hole / 2]);

    array[hole] = move(array[0]);

}


int main()
{
    cout << "Hellom World!" <<endl;
    return 0;
}
