# include <iostream>
using namespace std;

/*
    We assume that Comparable object can be compared;
    They have operator<, operator>, operator<=, operator!=, 
    operator>= and operator!= overloaded
*/

template <typename Comparable>
class AVLTree{
    public:
        AVLTree(); // Zero Constructor
        AVLTree(const AVLTree &); // Copy Constructor
        AVLTree(const AVLTree &&); // Move Constructor
        ~AVLTree(); // Destructor

        const Comparable & findMax() const;
        const Comparable & findMin() const;
        bool contains(const Comparable &) const;
        bool isEmpty() const;
        void printTree(ostream & out = cout) const;

        void makeEmpty();
        void insert(const Comparable &);
        void insert(Comparable &&);
        void remove(const Comparable &);
        void getHeight() const;

        void preorder(ostream & out = cout) const;
        void inorder(ostream & out = cout) const;
        void postorder(ostream & out = cout) const;

        AVLTree & operator= (const AVLTree &);
        AVLTree & operator= (AVLTree &&);

    private:

        struct AVLNode{
            Comparable element;
            AVLNode *left;
            AVLNode *right;

            AVLNode(const Comparable & theElement, AVLNode *lt = nullptr, AVLNode *rt = nullptr)
                : element{theElement}, left{lt}, right{rt}{}
            
            AVLNode(const Comparable && theElement, AVLNode *lt = nullptr, AVLNode *rt = nullptr)
                : element{theElement}, left{lt}, right{rt}{}
        };

        // Data
        AVLNode *root;

        int getHeight(AVLNode *) const;
        void insert(const Comparable &, AVLNode * &);
        void insert(Comparable &&, AVLNode * &);
        void remove(const Comparable &, AVLNode * &);
        AVLNode * findMax(AVLNode *) const;
        AVLNode * findMin(AVLNode *) const;
        bool contains(const Comparable &, AVLNode *) const;
        void makeEmpty(AVLNode * &);
        void printTree(AVLNode *, ostream & out = cout) const;
        AVLNode * clone(AVLNode *) const;
        
        void preorder(AVLNode *, ostream & out = cout) const;
        void inorder(AVLNode *, ostream & out = cout) const;
        void postorder(AVLNode *, ostream & out = cout) const;

};



int main()
{
    cout << "Hello, World!\n";
    return 0;
}
