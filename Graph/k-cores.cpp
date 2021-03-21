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
        void addEdge(const Hashable &, const Hashable &);
        void DFS() const;
        void DFS(const Hashable &) const;
        void findKCores() const;
};

template <typename Hashable>
Graph<Hashable> :: Graph(size_t V)
    : V(V) {}

template <typename Hashable>
void Graph<Hashable> :: addEdge(const Hashable &u, const Hashable &v){
    vertices.insert(u);
    vertices.insert(v);

    adjList[u].push_back(v);
}


int main(int argc, char const *argv[])
{
    cout << "Hello, World!\n";
    
    Graph<int> g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(5, 1);
    g.addEdge(5, 2);
    g.addEdge(5, 6);
    g.addEdge(5, 8);
    g.addEdge(8, 5);
    g.addEdge(8, 6);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(2, 5);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 6);
    g.addEdge(6, 2);
    g.addEdge(6, 5);
    g.addEdge(6, 8);
    g.addEdge(6, 4);
    g.addEdge(6, 3);
    g.addEdge(4, 2);
    g.addEdge(4, 6);
    g.addEdge(4, 3);
    g.addEdge(4, 7);
    g.addEdge(3, 4);
    g.addEdge(3, 2);
    g.addEdge(3, 6);
    g.addEdge(3, 7);
    g.addEdge(7, 4);
    g.addEdge(7, 3);
    g.addEdge(7, 6);

    return 0;
}
