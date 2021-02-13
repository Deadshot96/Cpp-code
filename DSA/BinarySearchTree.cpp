# include <iostream>
# include <vector>
using namespace std;


template <typename Comparable>
class BinarySearchTree{

    public:
        BinarySearchTree(); // Zero Constructor
        BinarySearchTree(const BinarySearchTree &); // copy Constructor
        BinarySearchTree(const BinarySearchTree &&); // move Constructor
        ~BinarySearchTree(); // Destructor

        const Comparable & findMax() const;
        const Comparable & findMin() const;
        bool contains (const Comparable &) const;
        bool isEmpty() const;
        void printTree(ostream & out = cout) const;

        void makeEmpty();
        void insert(const Comparable &); // lvalue insert
        void insert(Comparable &&); // rvalue insert
        void remove(const Comparable &);

        BinarySearchTree & operator= (const BinarySearchTree &); // copy assignment
        BinarySearchTree & operator= (BinarySearchTree &&); // move assignment

    private:
        struct BinaryNode{
            Comparable element;
            BinaryNode *left;
            BinaryNode *right;

            BinaryNode(const Comparable & theElement, BinaryNode *lt = nullptr, BinaryNode *rt = nullptr)
                : element{theElement}, left{lt}, right{rt} {}

            BinaryNode(const Comparable && theElement, BinaryNode *lt = nullptr, BinaryNode *rt = nullptr)
                : element{move(theElement)}, left{lt}, right{rt} {}

        };

        BinaryNode *root;

        void insert(const Comparable &, BinaryNode * &);
        void insert(Comparable &&, BinaryNode * &);
        void remove(const Comparable &, BinaryNode * &);
        BinaryNode * findMax(BinaryNode *) const;
        BinaryNode * findMin(BinaryNode *) const;
        bool contains (const Comparable &, BinaryNode *) const;
        void makeEmpty(BinaryNode * &);
        void printTree(BinaryNode *, ostream & out = cout) const;
        BinaryNode * clone (BinaryNode *) const;

};

template <typename Comparable>
bool BinarySearchTree<Comparable> :: contains(const Comparable & key) const{
    return contains(key, root);
}

template <typename Comparable>
bool BinarySearchTree<Comparable> :: contains(const Comparable & key, BinaryNode *t) const{

    if (t == nullptr){
        return false;
    }
    else if (key < t->element){
        return contains(key, t->left);
    }
    else if (key > t->element){
        return contains(key, t->right);
    }
    else{
        return true;
    }

}

template <typename Comparable>
void BinarySearchTree<Comparable> :: insert(const Comparable & x){
    insert(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable> :: insert(const Comparable & rhs, BinaryNode * & t){
    if (t == nullptr)
        t = new BinaryNode{rhs};

    else if (rhs < t->element)
        insert(rhs, t->left);
    
    else if (rhs > t->element)
        insert(rhs, t->right);

    else/* Do nothing if duplicate element occurs*/;
}


template <typename Comparable>
void BinarySearchTree<Comparable> :: insert(Comparable && x){
    insert(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable> :: insert(Comparable && rhs, BinaryNode* & t){
    if (t == nullptr)
        t = new BinaryNode{move(rhs)};
    else if (rhs < t->element)
        insert(move(rhs), t->left);
    else if (rhs > t->element)
        insert(move(rhs), t->right);
    else/* Do nothing if duplicate element occurs*/;
}


template <typename Comparable>
void BinarySearchTree<Comparable> :: remove(const Comparable & x){
    remove(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable> :: remove(const Comparable & x, BinaryNode * &t){
    if (t == nullptr){
        return;
    }
    else if(x < t->element){
        remove(x, t->left);
    }
    else if(x > t->element){
        remove(x, t->right);
    }
    else if(t->left != nullptr && t->right != nullptr){
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }
    else{
        BinaryNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
}

template <typename Comparable> 
const Comparable & BinarySearchTree<Comparable> :: findMax () const{
    return findMax(root)->element;
}


template <typename Comparable> 
typename BinarySearchTree<Comparable> :: BinaryNode* BinarySearchTree<Comparable> :: findMax (BinaryNode *t) const{
    if (t == nullptr)
        return nullptr;
    else if (t->right != nullptr)
        return findMax(t->right);
    else
        return t;
}

template <typename Comparable>
const Comparable & BinarySearchTree<Comparable> :: findMin() const{
    return findMin(root)->element;
}

template <typename Comparable>
typename BinarySearchTree<Comparable> :: BinaryNode* BinarySearchTree<Comparable> :: findMin(BinaryNode *t) const{
    if (t != nullptr)
        while (t->left != nullptr)
            t = t-> left;
    return t;
}

template <typename Comparable>
BinarySearchTree<Comparable> :: ~BinarySearchTree(){
    makeEmpty();
}

template <typename Comparable>
void BinarySearchTree<Comparable> :: makeEmpty(){
    makeEmpty(root);
}

template <typename Comparable>
void BinarySearchTree<Comparable> :: makeEmpty(BinaryNode * & t){
    if (t != nullptr){
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

template <typename Comparable>
bool BinarySearchTree<Comparable> :: isEmpty() const{
    return root == nullptr;
}

template <typename Comparable>
BinarySearchTree<Comparable> :: BinarySearchTree(){
    root = nullptr;
}

template <typename Comparable>
BinarySearchTree<Comparable> :: BinarySearchTree(const BinarySearchTree & rhs){
    root = clone(rhs.root);
}

template <typename Comparable>
typename BinarySearchTree<Comparable> :: BinaryNode * BinarySearchTree<Comparable> :: clone(BinaryNode *t) const {
    if (t == nullptr)
        return nullptr;
    else
        return new BinaryNode{t->element, clone(t->left), clone(t->right)};
}

template <typename Comparable>
BinarySearchTree<Comparable> :: BinarySearchTree(const BinarySearchTree && rhs) : root{rhs.root} {
    rhs = nullptr;
}

template <typename Comparable>
BinarySearchTree<Comparable> & BinarySearchTree<Comparable> :: operator= (const BinarySearchTree & rhs){
    if (this != &rhs)
        root = clone(rhs.root);
    return *this;
}

template <typename Comparable>
BinarySearchTree<Comparable> & BinarySearchTree<Comparable> :: operator= (BinarySearchTree && rhs){
    swap(root, rhs.root);
    return *this;
}



int main()
{
    cout << "Hello, World!\n";
    return 0;
}
