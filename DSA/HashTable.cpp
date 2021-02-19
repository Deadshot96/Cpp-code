# include <iostream>
# include <vector>
# include <list>
using namespace std;

/*
    HashedObj = Objects that provide a hash function and equality operators
    (operator== or operator!=, or possibly both).
*/

template <typename HashedObj>
class HashTable{
    public:
        explicit HashTable(int size = 101);
        bool contains(const HashedObj &) const;
        void makeEmpty();
        bool insert(const HashedObj &);
        bool insert(HashedObj &&);
        bool remove (const HashedObj &);

    private:
        vector<list<HashedObj>> theLists;
        int currentSize;

        void rehash();
        size_t myhash(const HashedObj &) const;
};

template <typename HashedObj>
void HashTable<HashedObj> :: makeEmpty(){
    for (auto & thisList: theLists)
        thisList.clear();
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
