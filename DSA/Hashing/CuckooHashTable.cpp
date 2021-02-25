# include <iostream>
# include <vector>
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
