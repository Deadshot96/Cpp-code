# include <iostream>
using namespace std;


template <typename Comparable>
class LeftistHeap{

    public:
        LeftistHeap();
        LeftistHeap(const LeftistHeap &);
        LeftistHeap(LeftistHeap &&);
        ~LeftistHeap();

        LeftistHeap & operator= (const LeftistHeap &);
        LeftistHeap & operator= (LeftistHeap &&);

        bool isEmtpy() const;
        const Comparable & findMin() const;

        void insert(const Comparable &);
        void insert(Comparable &&);
        void deleteMin();
        void deleteMin(Comparable &);
        void makeEmpty();
        void merge(LeftistHeap &);

    private:
        
        struct LeftistNode
        {
            Comparable element;
            LeftistNode * left;
            LeftistNode * right;
            int npl;

            LeftistNode(const Comparable &e, LeftistNode *l = nullptr, LeftistNode *r = nullptr, int np = 0)
                : element{e}, left{l}, right{r}, npl{np} {}

            LeftistNode(Comparable && e, LeftistNode *l = nullptr, LeftistNode *r = nullptr, int np = 0)
                : element{std::move(e)}, left{l}, right{r}, npl{np} {}
        };

        LeftistNode *root;

        LeftistNode * merge(LeftistNode *, LeftistNode *);
        LeftistHeap * merge1(LeftistNode *, LeftistNode *);

        void swapChildren(LeftistNode *);
        void reclainMemort(LeftistNode *);
        LeftistNode * clone(LeftistNode *) const;
};

template <typename Comparable>
void LeftistHeap<Comparable> :: merge(LeftistHeap & rhs){
    if (rhs == this)
        return; // Avoid aliasing problem

    root = merge(root, rhs.root);
    rhs.root = nullptr;
}

template <typename Comparable>
typename LeftistHeap<Comparable> :: LeftistNode * LeftistHeap<Comparable> :: merge(LeftistNode *h1, LeftistNode *h2){
    if (h1 == nullptr)
        return h2;
    
    if (h2 == nullptr)
        return h1;

    if (h1->element < h2->element)
        return merge1(h1, h2);
    else
        return merge1(h2, h1);
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
