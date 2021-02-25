# include <iostream>
# include <vector>
# include <random>
using namespace std;

bool isPrime(int);
int nextPrime(int);
template <typename AnyType, typename HashFamily>
class CuckooHashTable{

    public:

        explicit CuckooHashTable(int size = 101) : array(nextPrime(size)){
            numHashFunctions = hashFunctions.getNumberOfFunctions();
            rehashes = 0;
            makeEmpty();
        }

        void makeEmpty();
        bool contains(const AnyType &) const;

        bool remove(const AnyType &);
        bool insert(const AnyType &);
        bool insert(AnyType &&);

    private:

        struct HashEntry
        {
            AnyType element;
            bool isActive;

            HashEntry(const AnyType & e = AnyType(), bool a = false)
                : element{e}, isActive{a} {}

            HashEntry(AnyType && e, bool a = false)
                : element{move(e)}, isActive{a} {}

        };

        bool insertHelper(const AnyType &);
        bool insertHelper(AnyType &&);
        bool isActive(int) const;

        size_t myhash(const AnyType &, int) const;
        int findPos(const AnyType &) const;
        void expand();
        void rehash();
        void rehash(int);

        static constexpr double MAX_LOAD = 0.40;
        static const int ALLOWED_REHASH = 5;

        vector<HashEntry> array;
        int currentSize;
        int numHashFunctions;
        int rehashes;
        // UniformRandom r;
        HashFamily hashFunctions;

};

template <typename AnyType, typename HashFamily>
void CuckooHashTable<AnyType, HashFamily> :: makeEmpty(){
    currentSize = 0;
    for (auto & entry: array)
        entry.isActive = false;
}


template <typename AnyType, typename HashFamily>
size_t CuckooHashTable<AnyType, HashFamily> :: myhash(const AnyType & x, int which) const {
    return hashFunctions.hash(x, which) % array.size();
}

template <typename AnyType, typename HashFamily>
int CuckooHashTable<AnyType, HashFamily> :: findPos(const AnyType & x) const{
    for (int i = 0; i < numHashFunctions; ++i){
        int pos = myhash(x, i);

        if (isActive(pos) && array[pos].element == x)
            return pos;
    }
    return -1;
}

template <typename AnyType, typename HashFamily>
bool CuckooHashTable<AnyType, HashFamily> :: contains(const AnyType & x) const{
    return findPos(x) != -1;
}

template <typename AnyType, typename HashFamily>
bool CuckooHashTable<AnyType, HashFamily> :: remove(const AnyType & x){
    int currentPos = findPos(x);

    if (!isActive(currentPos))
        return false;

    array[currentPos].isActive = false;
    --currentSize;
    return true;
}

template <typename AnyType, typename HashFamily>
bool CuckooHashTable<AnyType, HashFamily> :: insert(const AnyType & x){
    if (contains(x))
        return false;

    if (currentSize >= array.size() * MAX_LOAD)
        expand();

    return insertHelper(x);
}

template <typename AnyType, typename HashFamily>
bool CuckooHashTable<AnyType, HashFamily> :: insert(AnyType && x){
    if (contains(x))
        return false;

    if (currentSize >= array.size() * MAX_LOAD)
        expand();

    return insertHelper(move(x));
}

template <typename AnyType, typename HashFamily>
bool CuckooHashTable<AnyType, HashFamily> :: insertHelper(const AnyType & x){
    const int COUNT_LIMIT = 100;

    while (true){
        int lastPos = -1;
        int pos;

        for (int i = 0; i < COUNT_LIMIT; i++)
        {
            
            for (int i = 0; i < numHashFunctions; i++)
            {
                pos = myhash(x, i);

                if (!isActive(pos)){
                    array[pos] = move(HashEntry(move(x), true));
                    ++currentSize;
                    return true;
                }
            }

            int i = 0;

            do
            {
                pos = myhash(x, r.nextInt(numHashFunctions));
            } while (pos == lastPos && i++ < 5);
            
            lastPos = pos;
            swap(x, array[pos].element);

        }

        if(++rehashes > ALLOWED_REHASH){
            expand();
            rehashes = 0;
        }
        else{
            rehash();
        }
        
    }
}


template <typename AnyType, typename HashFamily>
bool CuckooHashTable<AnyType, HashFamily> :: insertHelper(AnyType && x){
    const int COUNT_LIMIT = 100;
    
    while (true){
        int lastPos = -1;
        int pos;

        for (int i = 0; i < COUNT_LIMIT; i++)
        {
            
            for (int i = 0; i < numHashFunctions; i++)
            {
                pos = myhash(x, i);

                if (!isActive(pos)){
                    array[pos] = move(HashEntry(move(x), true));
                    ++currentSize;
                    return true;
                }
            }

            int i = 0;

            do
            {
                pos = myhash(x, r.nextInt(numHashFunctions));
            } while (pos == lastPos && i++ < 5);
            
            lastPos = pos;
            swap(x, array[pos].element);

        }

        if(++rehashes > ALLOWED_REHASH){
            expand();
            rehashes = 0;
        }
        else{
            rehash();
        }
        
    }
}

template <typename AnyType, typename HashFamily>
void CuckooHashTable<AnyType, HashFamily> :: expand(){
    rehash(static_cast<int>(array.size() / MAX_LOAD));
}

template <typename AnyType, typename HashFamily>
void CuckooHashTable<AnyType, HashFamily> :: rehash(){
    rehash(nextPrime(array.size() * 2));
}

template <typename AnyType, typename HashFamily>
void CuckooHashTable<AnyType, HashFamily> :: rehash(int newSize){
    vector<HashEntry> oldArray = array;

    array.resize(nextPrime(newSize));

    for (auto & entry : array)
    {
        entry.isActive = false;
    }

    currentSize = 0;
    for (auto & entry: oldArray)
        if (entry.isActive)
            inset(move(entry.element));
    
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


int main(int argc, char const *argv[])
{
    cout << "Hellow, World!" << endl;
    return 0;
}
