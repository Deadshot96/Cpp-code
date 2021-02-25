# include <iostream>
# include <vector>
using namespace std;

template <typename Comparable>
class BinaryHeap{
    public:
        explicit BinaryHeap(int capacity = 100);
        explicit BinaryHeap(const vector<Comparable> & items);

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

int main()
{
    cout << "Hellom World!" <<endl;
    return 0;
}
