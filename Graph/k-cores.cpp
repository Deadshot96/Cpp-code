# include <iostream>
# include <vector>
# include <list>
# include <unordered_map>
# include <unordered_set>
using namespace std;

/*
    K-cores of the graph are connected components that 
    are left after all vertices of degree less than k 
    have been removed 
*/

template <typename Hashable>
class Graph{
    private:
        size_t V;
        unordered_set<Hashable> vertices;
        unordered_map<Hashable, list<Hashable>> adjList;

        void DFSUtil(const Hashable &, unordered_map<Hashable, bool> &) const;

    public:
        Graph(size_t);
        void DFS() const;
        void DFS(const Hashable &) const;
        void findKCores() const;
};

int main(int argc, char const *argv[])
{
    cout << "Hello, World!\n";
    return 0;
}
