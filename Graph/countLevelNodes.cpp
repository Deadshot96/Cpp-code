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
        void BFSUtil(const Hashable &, unordered_map<Hashable, bool> &) const;

    public:
        Graph(size_t);
        void addEdge(const Hashable &, const Hashable &);
        void BFS() const;
        void BFS(const Hashable &) const;
};

template <typename Hashable>
Graph<Hashable> :: Graph(size_t numV)
    :numV{numV}

int main()
{
    cout << "Hello, World!\n";
    return 0;
}
