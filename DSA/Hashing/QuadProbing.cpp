# include <iostream>
# include <vector>
using namespace std;

template <typename HashedObj>
class HashTable{

    public:
        explicit HashTable(int size = 101);

        bool contains(const HashedObj &) const;
        void makeEmpty();
        bool insert(const HashedObj &);
        bool insert(HashedObj &&);
        bool remove(const HashedObj &);

        enum EntryType {ACTIVE, EMPTY, DELETED};

    private:

        struct HashedEntry
        {
            HashedObj element;
            EntryType info;

            HashedEntry(const HashedObj & x = HashedObj{}, EntryType i = EMPTY)
                :element{x}, info{i} {};

            HashedEntry(HashedObj && x, EntryType i = EMPTY)
                :element{move(x)}, info{i} {};

        };

        vector<HashedEntry> array;
        int currentSize;

        bool isActive(int) const;
        int findPos(const HashedObj &) const;
        void rehash();
        size_t myhash(const HashedObj &) const;
        
};

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
