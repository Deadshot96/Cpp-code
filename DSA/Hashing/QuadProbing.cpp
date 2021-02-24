# include <iostream>
# include <vector>
using namespace std;

int nextPrime(int);
bool isPrime(int);

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

template <typename HashedObj>
int HashTable<HashedObj> :: findPos(const HashedObj & x) const{
    int offset = 1;
    int currentPos = myhash(x);

    while (array[currentPos].info != EMPTY &&
        array[currentPos].element != x){
        currentPos += offset;
        offset += 2;

        if (currentPos >= array.size())
            currentPos -= array.size();
    }

    return currentPos;

}

template <typename HashedObj>
bool HashTable<HashedObj> :: insert(const HashedObj & x){
    int currentPos = findPos(x);
    
    if (isActive(currentPos))
        return false;

    array[currentPos].element = x;
    array[currentPos].info = ACTIVE;

    if (++currentSize > array.size() / 2)
        rehash();

    return true;
}

template <typename HashedObj>
bool HashTable<HashedObj> :: insert(HashedObj && x){
    int currentPos = findPos(move(x));

    if (isActive(currentPos))
        return false;

    array[currentPos].element = move(x);
    array[currentPos].info = ACTIVE;

    if (++currentSize > array.size() / 2)
        rehash();

    return true;
}

template <typename HashedObj>
bool HashTable<HashedObj> :: remove(const HashedObj & x){
    int currentPos = findPos(x);
    if (!isActive(currentPos))
        return false;

    array[currentPos].info = DELETED;
    return true;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}

bool isPrime(int n){
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n%2 == 0 || n%3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n%i == 0 || n%(i + 2) == 0)
            return false;

    return true; 
}

int nextPrime(int n){
    if (n <= 1)
        return 2;
    
    int prime = n;
    bool found = false;

    while (!found){
        prime++;

        if (isPrime(prime))
            found = true;
    }

    return prime;
}