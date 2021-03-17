# include <iostream>
# include <vector>
using namespace std;

class DisjSets{
    public:
        explicit DisjSets(int);
        int find(int) const;
        int find(int);
        void unionSets(int, int);
        void unionSetsByHeight(int, int);

    private:
        vector<int> s;
};

DisjSets :: DisjSets(int numElements) 
    : s{numElements, -1} {}


/**
 * Union two disjoint sets.
 * For simplicity, we assume root1 and root2 are distinct
 * and represent set names.
 * root1 is the root of set 1.
 * root2 is the root of set 2.
*/
void DisjSets :: unionSets(int root1, int root2){
    s[root2] = root1;
}

void DisjSets :: unionSetsByHeight(int root1, int root2){
    if (s[root1] < s[root2]) // root1 is deeper
        s[root1] = root2;
    else{
        if (s[root1] == s[root2])
            --s[root1];
        s[root2] = root1;
    }
}

/**
 * Perform a find.
 * Error checks omitted again for simplicity.
 * Return the set containing x.
*/

int DisjSets :: find(int x) const{
    if (s[x] < 0)
        return x;
    else
        return find(s[x]);
}


// This find implements the path compression technique
int DisjSets :: find(int x){
    if (s[x] < 0)
        return x;
    else
        return s[x] = find(s[x]);
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
