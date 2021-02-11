# include <iostream>
# include <vector>
using namespace std;


template <typename Comparable>
class BinarySearchTree{

    public:
        BinarySearchTree(); // Zero Constructor
        BinarySearchTree(const BinarySearchTree & rhs); // copy Constructor
        BinarySearchTree(const BinarySearchTree && rhs); // move Constructor
        ~BinarySearchTree(); // Destructor

        const Comparable & findMax() const;
        const Comparable & findMin() const;
        bool contains (const Comparable & key) const;
        bool isEmpty() const;
        void printTree(ostream & out = cout) const;

        void makeEmpty();
        void insert(const Comparable & x); // lvalue insert
        void insert(Comparable && x); // rvalue insert
        void remove(const Comparable & x);

        BinarySearchTree & operator= (const BinarySearchTree & rhs); // copy assignment
        BinarySearchTree & operator= (BinarySearchTree && rhs); // move assignment

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

        void insert(const Comparable & x, BinaryNode * & t);
        void insert(Comparable && x, BinaryNode * & t);
        void remove(const Comparable & x, BinaryNode * & t);
        BinaryNode * findMax(BinaryNode * t) const;
        BinaryNode * findMin(BinaryNode * t) const;
        bool contains (const Comparable & x, BinaryNode *t) const;
        void makeEmpty(BinaryNode * & t);
        void printTree(BinaryNode * t, ostream & out = cout) const;
        BinaryNode * clone (BinaryNode * t) const;

};


int main()
{
    cout << "Hello, World!\n";
    return 0;
}
