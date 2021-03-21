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
void Graph<Hashable> :: addList(const Hashable &u, const Hashable &v){
    vertices.insert(u);
    vertices.insert(v);

    addList[u].push_back(v);
    addList[v].push_back(u);
}


int main(int argc, char const *argv[])
{
    cout << "Hello, World!\n";
    return 0;
}
