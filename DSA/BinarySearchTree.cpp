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
void BinarySearchTree<Comparable> :: insert(Comparable && x){
    insert(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable> :: remove(const Comparable & x){
    remove(x, root);
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



int main()
{
    cout << "Hello, World!\n";
    return 0;
}
