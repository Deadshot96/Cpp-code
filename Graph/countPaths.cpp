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
        void addEdge(const Hashable &, const Hashable &);
        void countPaths(const Hashable &, const Hashable &);
};

template <typename Hashable>
Graph<Hashable> :: Graph(size_t numV)
    :numV(numV) {}

template <typename Hashable>
void Graph<Hashable> :: addEdge(const Hashable & u, const Hashable & v){
    vertices.insert(u);
    vertices.insert(v);

    adjList[u].push_back(v);
}

int main()
{
    cout << "Hello, World!\n";
    Graph<char> g(5);
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('A', 'E');
    g.addEdge('B', 'D');
    g.addEdge('B', 'E');
    g.addEdge('D', 'C');

    return 0;
}
