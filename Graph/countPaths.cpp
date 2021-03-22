# include <iostream>
# include <list>
# include <unordered_map>
# include <unordered_set>
using namespace std;

template <typename Hashable>
class Graph{
    private:
        size_t numV;
        unordered_map<Hashable, list<Hashable>> adjList;
        unordered_set<Hashable> vertices;

    public:
        Graph(size_t);
        addEdge(const Hashable &, const Hashable &);
        void countPaths(const Hashable &, const Hashable &);
};

template <typename Hashable>
Graph<Hashable> :: Graph(size_t numV)
    :numV(numV) {}

int main()
{
    cout << "Hello, World!\n";
    return 0;
}
