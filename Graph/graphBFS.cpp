# include <iostream>
# include <list>
# include <unordered_map>
# include <unordered_set>
using namespace std;

template <typename Hashable>
class Graph{
    private:
        int numVertices;
        unordered_set<Hashable> vertices;
        unordered_map<Hashable, list<Hashable>> adjList;

        void BFSUtil(const Hashable &, unordered_map<Hashable, bool>);

    public:
        Graph(int);
        void addEdge(Hashable, Hashable);
        void BFS() const;
        void BFS(const Hashable &) const;
};

template <typename Hashable>
Graph<Hashable> :: Graph(int numVertices){
    this->numVertices = numVertices;
}

template <typename Hashable>
void Graph<Hashable> :: addEdge(Hashable u, Hashable v){
    vertices.insert(u);
    vertices.insert(v);

    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int main()
{
    cout << "Hello, World!" << endl;

    Graph<int> g(7);

    g.addEdge(3, 0);
    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(3, 6);
    g.addEdge(3, 5);
    g.addEdge(3, 2);
    g.addEdge(0, 1);
    g.addEdge(1, 4);
    g.addEdge(4, 6);
    g.addEdge(6, 5);
    g.addEdge(5, 2);
    g.addEdge(2, 0);

    return 0;
}
