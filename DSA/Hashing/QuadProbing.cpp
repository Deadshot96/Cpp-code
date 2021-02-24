# include <iostream>
# include <vector>
using namespace std;

int nextPrime(int);

template <typename HashedObj>
class HashTable{

    public:
        explicit HashTable(int size = 101)
            :array(nextPrime(size)) {makeEmpty();}

        bool contains(const HashedObj &) const;
        void makeEmpty();
        bool insert(const HashedObj &);
        bool insert(HashedObj &&);
        bool remove(const HashedObj &);

        enum EntryType {ACTIVE, EMPTY, DELETED};

    private:

        struct HashEntry
        {
            HashedObj element;
            EntryType info;

            HashEntry(const HashedObj & x = HashedObj{}, EntryType i = EMPTY)
                :element{x}, info{i} {};

            HashEntry(HashedObj && x, EntryType i = EMPTY)
                :element{move(x)}, info{i} {};

        };

        vector<HashEntry> array;
        int currentSize;

        bool isActive(int) const;
        int findPos(const HashedObj &) const;
        void rehash();
        size_t myhash(const HashedObj &) const;
        
};

template <typename HashedObj>
void HashTable<HashedObj> :: makeEmpty(){
    currentSize = 0;
    for(auto & entry: array)
        entry.info = EMPTY;
}

template <typename HashedObj>
bool HashTable<HashedObj> :: contains (const HashedObj & x) const{
    return isActive(findPos(x));
}

template <typename HashedObj>
bool HashTable<HashedObj> :: isActive(int currentPos) const{
    return array[currentPos].info == ACTIVE;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
