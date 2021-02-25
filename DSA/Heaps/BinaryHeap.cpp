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
        void deleteMin(Comparable &);
        void makeEmpty();
        int getSize() const;

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

template <typename Comparable>
void BinaryHeap<Comparable> :: deleteMin(){
    if (isEmpty())
        cout << "Underflow" << endl;

    array[1] = move(array[currentSize--]);
    percolateDown(1);

}

template <typename Comparable>
void BinaryHeap<Comparable> :: deleteMin(Comparable & x){
    if (isEmpty())
        cout << "Underflow" << endl;

    x = move(array[1]);
    array[1] = move(array[currentSize--]);
    percolateDown(1);

}

template <typename Comparable>
void BinaryHeap<Comparable> :: makeEmpty(){
    array.clear();
    currentSize = 0;
}

template <typename Comparable>
void BinaryHeap<Comparable> :: percolateDown(int hole){
    int child;
    Comparable tmp = move(array[hole]);

    for(; hole * 2 <= currentSize; hole = child){
        child = hole * 2;

        if (child != currentSize && array[child + 1] < array[child])
            child++;
        
        if (array[child] < tmp)
            array[hole] = move(array[child]);
        else
            break;
    }
    array[hole] = tmp;
}

template <typename Comparable>
void BinaryHeap<Comparable> :: percolateUp(int hole){
    array[0] = move(array[hole]); // this steps ensures that the following loop terminates at hole = 1

    for(; array[hole] < array[hole / 2]; hole /= 2)
        array[hole] = move(array[hole / 2]);

    array[hole] = move(array[0]);

}

template <typename Comparable>
const Comparable & BinaryHeap<Comparable> :: findMin() const{
    return array[1];
}

template <typename Comparable>
int BinaryHeap<Comparable> :: getSize() const{
    return currentSize;
}

template <typename Comparable>
void BinaryHeap<Comparable> :: buildHeap(){
    for (int i = currentSize / 2; i > 0; i--)
    {
        percolateDown(i);
    }
}

int main()
{
    cout << "Hello, World!" <<endl;
    BinaryHeap<int> pq;
    pq.insert(4);
    pq.insert(3);
    pq.insert(20);
    pq.insert(1);
    int i = 12;
    pq.insert(i);

    pq.deleteMin();

    cout << "Min is: " << pq.findMin() << endl;
    cout << "Size is: " << pq.getSize() << endl;
    return 0;
}
