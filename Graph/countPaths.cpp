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
        void pathCounter(const Hashable &, const Hashable &, size_t &);

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

template <typename Hashable>
void Graph<Hashable> ::countPaths(const Hashable & u, const Hashable & v){
    size_t paths = 0;
    pathCounter(u, v, paths);
    cout << "Paths from " << u << " to " << v << ": " << paths << endl;
} 

template <typename Hashable>
void Graph<Hashable> :: pathCounter(const Hashable & u, const Hashable & v, size_t & paths){
    
    if (u == v){
        paths++;
    }
    else{
        if (adjList.find(u) == adjList.end())
            return;
        
        const list<Hashable> & links = adjList.at(u);
        typename list<Hashable> :: const_iterator itr;

        for (itr = links.begin(); itr != links.end(); ++itr)
            pathCounter(*itr, v, paths);
    }    
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
    g.addEdge('C', 'E');
    
    g.countPaths('A', 'E');

    return 0;
}
