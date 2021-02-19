# include <iostream>
# include <vector>
using namespace std;

/*
    HashedObj = Objects that provide a hash function and equality operators
    (operator== or operator!=, or possibly both).
*/

template <HashedObj>
class HashTable{
    public:
        explicit HashTable(int size = 101);
        bool contains(const HashedObj &) const;
        void makeEmpty();
        bool insert(const HashedObj &);
        bool insert(Hashed &&);
        bool remove (const HashedObj &);

    private:
        vector<list<HashedObj>> theLists;
        int currentSize;

        void rehash();
        size_t myhash(const HashedObj &) const;
};