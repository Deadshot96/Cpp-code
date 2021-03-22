# include <iostream>
# include <list>
# include <vector>
# include <unordered_map>
# include <unordered_set>
using namespace std;

template <typename Hashable>
class Graph{
    private:
        size_t numV;
        unordered_set<Hashable> vertices;
        unordered_map<Hashable, list<Hashable>> adjList;
        void DFSUtil(const Hashable &, unordered_map<Hashable, bool> &);

    public:
        Graph(size_t);
        void addEdge(const Hashable &, const Hashable &);
        void DFS() const;
        void DFS(const Hashable &) const;
};

template <typename Hashable>
Graph<Hashable> :: Graph(size_t numV)
    :numV{numV} {};

template <typename Hashable>
void Graph<Hashable> :: addEdge(const Hashable &u, const Hashable &v){
    vertices.insert(u);
    vertices.insert(v);

    adjList[u].push_back(v);
}

int main()
{
    cout << "Hello, World!\n";

    Graph<int> g(8);
    return 0;
}
