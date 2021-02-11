# include <iostream>
# include <vector>
using namespace std;


template <typename Comparable>
class BinarySearchTree{

    public:
        BinarySearchTree(); // Zero Constructor
        BinarySearchTree(const BinarySearchTree & rhs); // copy Constructor
        BinarySearchTree(const BinarySearchTree && rhs) // move Constructor
        ~BinarySearchTree(); // Destructor

        const Comparable & findMax() const;
        const Comparable & findMin() const;
        bool contains (const Comparable & key) const;
        bool isEmpty() const;
        void printTree(ostream & out = cout) const;

        void makeEmpty();
        void insert(const Comparator & x); // lvalue insert
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

        }

        BinaryNode *root;




}