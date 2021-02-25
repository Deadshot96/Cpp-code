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
size_t HashTable<HashedObj> :: myhash(const HashedObj & x) const{
    static hash<HashedObj> hf;
    return hf(x) % theLists.size();
}


template <typename HashedObj>
void HashTable<HashedObj> :: makeEmpty(){
    for (auto & thisList: theLists)
        thisList.clear();
}

template <typename HashedObj>
bool HashTable<HashedObj> :: contains (const HashedObj & x) const{
    auto & whichList = theLists[myhash(x)];
    return find(begin(whichList), end(whichList), x) != end(whichList);
}

template <typename HashedObj>
bool HashTable<HashedObj> :: remove (const HashedObj & x){
    auto & whichList = theLists[myhash(x)];
    auto itr = find(begin(whichList), end(whichList), x);

    if (itr == end(whichList))
        return false;

    whichList.erase(itr);
    currentSize--;
    return true;
}

template <typename HashedObj>
bool HashTable<HashedObj> :: insert (const HashedObj & x){
    auto & whichList = theLists[myhash(x)];

    if (find(begin(whichList), end(whichList), x) != end(whichList))
        return false;

    whichList.push_back(x);
    currentSize++;

    if (currentSize > theLists.size())
        rehash();

    return true;
}

template <typename HashedObj>
bool HashTable<HashedObj> :: insert(HashedObj && x){
    auto & whichList = theLists[myhash(x)];

    if (find(begin(whichList), end(whichList), x) != end(whichList))
        return false;

    whichList.push_back(move(x));
    currentSize++;

    if (currentSize > theLists.size())
        rehash();
    
    return true;
}

template <typename HashedObj>
void HashTable<HashedObj> :: rehash(){
    vector<list<HashedObj>> oldLists = theLists;

    theLists.resize(2 * oldLists.size());
    for(auto & theList: theLists)
        theList.clear();

    currentSize = 0;
    for (auto & theList: oldLists)
        for (auto & x: theList)
            insert(move(x));
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
