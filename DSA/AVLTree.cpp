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
            int height;

            AVLNode(const Comparable & theElement, AVLNode *lt = nullptr, AVLNode *rt = nullptr, int ht = 0)
                : element{theElement}, left{lt}, right{rt}, height{ht} {}
            
            AVLNode(const Comparable && theElement, AVLNode *lt = nullptr, AVLNode *rt = nullptr, int ht = 0)
                : element{theElement}, left{lt}, right{rt}, height{ht} {}
        };

        // Data
        AVLNode *root;
        static const int ALLOWED_IMBALANCE = 1;

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

        void balance(AVLNode * &);
        void rotateWithLeftChild(AVLNode * &);
        void rotateWithRightChild(AVLNode * &);
        void doubleWithLeftChild(AVLNode * &);
        void doubleWithRightChild(AVLNode * &);
};

template <typename Comparable>
const Comparable & AVLTree<Comparable> :: findMax() const{
    return findMax(root)->element;
}

template <typename Comparable>
typename AVLTree<Comparable> :: AVLNode * AVLTree<Comparable> :: findMax(AVLNode * t) const{
    if (t == nullptr)
        return nullptr;
    else if (t->right != nullptr)
        return findMax(t->right);
    else
        return t;
}

template <typename Comparable>
const Comparable & AVLTree<Comparable> :: findMin() const{
    return findMin(root)->element;
}

template <typename Comparable>
typename AVLTree<Comparable> :: AVLNode * AVLTree<Comparable> :: findMin(AVLNode *t) const{
    if (t == nullptr)
        while (t->left != nullptr)
            t = t->left;
    return t;
}

template <typename Comparable>
void AVLTree<Comparable> :: insert(const Comparable & x){
    insert(x, root);
}

template <typename Comparable>
void AVLTree<Comparable> :: insert(const Comparable & x, AVLNode * & t){
    if (t == nullptr)
        t = new AVLNode{x};
    else if (x < t->element)
        insert(x, t->left);
    else if (x > t->element)
        insert(x, t->right);
    else
    /* Do nothing if duplicate element occurs*/ 
    ;

    balance(t);

}

template <typename Comparable>
void AVLTree<Comparable> :: balance(AVLNode * & t){
    if (t == nullptr)
        return;

    if ((getHeight(t->left) - getHeight(t->right)) > ALLOWED_IMBALANCE){
        if (getHeight(t->left->left) >= getHeight(t->left->right))
            rotateWithLeftChild(t);
        else
            doubleWithLeftChild(t);
    }
    else if ((getHeight(t->right) - getHeight(t->left)) > ALLOWED_IMBALANCE){
        if (getHeight(t->right->right) >= getHeight(t->right->left))
            rotateWithRightChild(t);
        else
            doubleWithRightChild(t);
    }

    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
}

template <typename Comparable>
void AVLTree<Comparable> :: rotateWithLeftChild(AVLNode * & k2){
    AVLNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
    k1->height = max(getHeight(k1->left), k2->height) + 1;
    k2 = k1;
}

template <typename Comparable>
void AVLTree<Comparable> :: rotateWithRightChild(AVLNode * & k2){
    AVLNode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
    k1->height = max(getHeight(k1->right), k2->height) + 1;
    k2 = k1;
}

template <typename Comparable>
void AVLTree<Comparable> :: doubleWithLeftChild(AVLNode * & k3){
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

template <typename Comparable>
void AVLTree<Comparable> :: doubleWithRightChild(AVLNode * & k3){
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}

template <typename Comparable>
void AVLTree<Comparable> :: insert(Comparable && x){
    insert(move(x), root);
}

template <typename Comparable>
void AVLTree<Comparable> :: insert(Comparable && x, AVLNode * & t){
    if (t == nullptr)
        t = new AVLNode {move(x)};
    else if (x < t->element)
        insert(move(x), t->left);
    else if (x > t->element)
        insert(move(x), t->right);
    else 
    /* Do nothing if duplicate element occurs*/ 
    ;

    balance(t);      
}

template <typename Comparable>
bool AVLTree<Comparable> :: contains(const Comparable & key) const {
    return contains(key, root);
}

template <typename Comparable>
bool AVLTree<Comparable> :: contains(const Comparable & key, AVLNode *t) const {
    if (t == nullptr)
        return false;
    else if (t->element > key)
        return contains(key, t->left);
    else if (t->element < key)
        return contains(key, t->right);
    else
        return true;
}

template <typename Comparable>
bool AVLTree<Comparable> :: isEmpty() const{
    return root == nullptr;
}

template <typename Comparable>
int AVLTree<Comparable> :: getHeight(AVLNode *t) const{
    return t == nullptr ? -1 : t->height;
}

template <typename Comparable>
void AVLTree<Comparable> :: remove(const Comparable & key){
    remove(key, root);
}

template <typename Comparable>
void AVLTree<Comparable> :: remove(const Comparable & key, AVLNode * & t){
    if (t == nullptr)
        return;

    if (key < t->element)
        remove(key, t->left);
    else if (key > t->element)
        remove(key, t->right);
    else if (t->left != nullptr && t->right != nullptr){
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);   
    }
    else{
        AVLNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }

    balance(t);
}

template <typename Comparable>
void AVLTree<Comparable> :: preorder(ostream & out) const{
    out << "Preorder Traversal: " <<endl;
    preorder(root, out);
}

template <typename Comparable>
void AVLTree<Comparable> :: preorder(AVLNode * t, ostream & out) const{
    if (t != nullptr){
        out << t->element << "\t";
        preorder(t->left);
        preorder(t->right);
    }
}

template <typename Comparable>
void AVLTree<Comparable> :: inorder(ostream & out) const{
    out << "Inorder Traversal: " <<endl;
    inorder(root, out);
}

template <typename Comparable>
void AVLTree<Comparable> :: inorder(AVLNode * t, ostream & out) const{
    if (t != nullptr){
        inorder(t->left);
        out << t->element << "\t";
        inorder(t->right);
    }
}

template <typename Comparable>
void AVLTree<Comparable> :: postorder(ostream & out) const{
    out << "Postorder Traversal: " <<endl;
    postorder(root, out);
}

template <typename Comparable>
void AVLTree<Comparable> :: postorder(AVLNode * t, ostream & out) const{
    if (t != nullptr){
        postorder(t->left);
        postorder(t->right);
        out << t->element << "\t";
    }
}

template <typename Comparable>
AVLTree<Comparable> :: ~AVLTree(){
    makeEmpty();
}

template <typename Comparable>
void AVLTree<Comparable> :: makeEmpty(){
    makeEmpty(root);
}

template <typename Comparable>
void AVLTree<Comparable> :: makeEmpty(AVLNode * & t){
    if (t != nullptr){
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

template <typename Comparable>
typename AVLTree<Comparable> :: AVLNode * AVLTree<Comparable> :: clone(AVLNode *t) const{
    if (t == nullptr)
        return nullptr;
    else
        return new AVLNode{t->element, clone(t->left), clone(t->right)};
}

template <typename Comparable>
AVLTree<Comparable> :: AVLTree(){
    root = nullptr;
}

template <typename Comparable>
AVLTree<Comparable> :: AVLTree(const AVLTree & rhs){
    root = clone(rhs.root);
}

template <typename Comparable>
AVLTree<Comparable> :: AVLTree(const AVLTree && rhs): root{rhs.root}{
    rhs = nullptr;
}

template <typename Comparable>
AVLTree<Comparable> & AVLTree<Comparable> :: operator= (const AVLTree & rhs){
    if (this != &rhs)
        root = clone(rhs.root);
    return *root;   
}

template <typename Comparable>
AVLTree<Comparable> & AVLTree<Comparable> :: operator= (AVLTree && rhs){
    swap(root, rhs.root);
    rhs.root = nullptr;
    return *this;
}

template <typename Comparable>
void AVLTree<Comparable> :: printTree(ostream & out) const{
    if (isEmpty())
        out << "Empty Tree" <<endl;
    else
        printTree(root, out);

}

template <typename Comparable>
void AVLTree<Comparable> :: printTree(AVLNode *t, ostream & out) const{
    if (t != nullptr){
        printTree(t->left, out);
        out << t->element << endl;
        printTree(t->right, out);
    }
}

int main()
{
    cout << "Hello, World!\n";

    AVLTree<int> t;

    t.insert(3);
    t.insert(2);
    t.insert(1);

    for (int i = 4; i < 8; i++)
        t.insert(i);

    for (int i = 16; i > 9; i--)
        t.insert(i);

    t.insert(8);
    t.insert(9);

    t.inorder();


    return 0;
}
