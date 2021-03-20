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

        void DFSUtil(const Hashable &, unordered_map<Hashable, bool> &) const;

    public:
        Graph(int);
        void addEdge(Hashable, Hashable);
        void DFS() const;
        void DFS(const Hashable &) const;
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

template <typename Hashable>
void Graph<Hashable> :: DFS() const{
    unordered_map<Hashable, bool> visited;
    cout << "Depth First Search: \n";
    
    for (auto item: adjList)
        if (!visited[item.first]){
            DFSUtil(item.first, visited);
            cout << endl;
        }
}

template <typename Hashable>
void Graph<Hashable> :: DFS(const Hashable & v) const{
    cout << "Depth First Search: \n";
    unordered_map<Hashable, bool> visited;
    DFSUtil(v, visited);
    cout << endl;
}

template <typename Hashable>
void Graph<Hashable> :: DFSUtil(const Hashable & v, unordered_map<Hashable, bool> & visited) const{
    visited[v] = true;
    cout << v << "\t";

    if (adjList.find(v) == adjList.end())
        return;

    const list<Hashable> & links = adjList.at(v);
    typename list<Hashable>::const_iterator itr;

    for (itr = links.begin(); itr != links.end(); ++itr)
        if (!visited[*itr])
            DFSUtil(*itr, visited);
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

    g.DFS();
    g.DFS(4);

    return 0;
}
