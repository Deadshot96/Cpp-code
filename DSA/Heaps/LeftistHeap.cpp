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

        bool isEmpty() const;
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
        LeftistNode * merge1(LeftistNode *, LeftistNode *);

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

template <typename Comparable>
typename LeftistHeap<Comparable> :: LeftistNode * LeftistHeap<Comparable> :: merge1(LeftistNode *h1, LeftistNode *h2){
    
    if (h1->left == nullptr) // Single Node
        h1->left = h2;       // Other fields in h2 are already accurate
    else{
        h1->right = merge(h1->right, h2);
        if (h1->left->npl < h1->right->npl)
            swapChildren(h1);
        h1->npl = h1->right->npl + 1;
    }

    return h1;
}

template <typename Comparable>
void LeftistHeap<Comparable> :: insert(const Comparable & x){
    root = merge(new LeftistNode{x}, root);
}

template <typename Comparable>
void LeftistHeap<Comparable> :: insert(Comparable && x){
    root = merge(new LeftistNode{move(x)}, root);
}

template <typename Comparable>
void LeftistHeap<Comparable> :: deleteMin(){
    if(isEmpty()){
        cout << "Underflow!\n";
        return;
    }

    LeftistNode *oldRoot = root;
    root = merge(root->left, root->right);
    delete oldRoot;
}

template <typename Comparable>
void LeftistHeap<Comparable> :: deleteMin(Comparable & minItem){
    minItem = findMin();
    deleteMin();
}

template <typename Comparable>
bool LeftistHeap<Comparable> :: isEmpty() const{
    return root == nullptr;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
