# include <iostream>
# include <list>
# include <unordered_map>
# include <unordered_set>
using namespace std;

/*
    A mother vertex in a graph G = (V,E) is a vertex v 
    such that all other vertices in G can be reached by 
    a path from v.
*/

template <typename Hashable>
class Graph{
    private:
        int numVertices;
        unordered_set<Hashable> vertices;
        unordered_map<Hashable, list<Hashable>> adjList;

        void DFSUtil(const Hashable &, unordered_map<Hashable, bool>) const;

    public:
        Graph(int);
        void addEdge(Hashable, Hashable);
        void DFS() const;
        void DFS(Hashable) const;
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
}

int main()
{
    cout << "Hello, World!" << endl;
    Graph <int> g(7);
    g.addEdge(2, 0);
    g.addEdge(2, 5);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 6);
    g.addEdge(6, 5);
    g.addEdge(3, 2);
    g.addEdge(3, 5);
    g.addEdge(3, 6);
    g.addEdge(3, 4);


    return 0;
}
