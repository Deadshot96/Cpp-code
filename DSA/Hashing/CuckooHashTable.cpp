# include <iostream>
# include <vector>
using namespace std;

bool isPrime(int);
int nextPrime(int);
template <typename AnyType, typename HashFamily>
class CuckooHashTable{

    public:

        explicit CuckooHashTable(int size = 101);

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

        vector<HashEntry> arrray;
        int currentSize;
        int numHashFunctions;
        int rehashes;
        // UniformRandom r;
        HashFamily hashFunctions;

};

int main(int argc, char const *argv[])
{
    cout << "Hellow, World!" << endl;
    return 0;
}
