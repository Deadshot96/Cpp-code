# include <iostream>
# include <map>
# include <list>
# include <vector>
# include <unordered_map>
# include <unordered_set>
using namespace std;

template <typename Hashable>
class Graph{

    private:
        int V;
        unordered_set<Hashable> vertices;
        unordered_map<Hashable, list<Hashable>> adj;

        void DFSUtil(Hashable, unordered_map<Hashable, bool> &) const; 

    public:
        Graph(int);
        void addEdge(Hashable, Hashable);
        void DFS() const;
        void DFS(Hashable) const;
};

template <typename Hashable>
Graph<Hashable> :: Graph(int V){
    this->V = V;
}


template <typename Hashable>
void Graph<Hashable> :: addEdge(Hashable u, Hashable v){
    
    vertices.insert(u);
    vertices.insert(v);

    adj[u].push_back(v);
    // adj[v].push_back(u);
}

template <typename Hashable>
void Graph<Hashable> :: DFS() const{
    unordered_map<Hashable, bool> visited;

    for(auto& i : adj)
        if (visited[i.first] == false)
            DFSUtil(i.first, visited);

    cout << endl;
}

template <typename Hashable>
void Graph<Hashable> :: DFS(Hashable v) const{
    unordered_map<Hashable, bool> visited;
    DFSUtil(v, visited);
    cout << endl;
}


template <typename Hashable>
void Graph<Hashable> :: DFSUtil(Hashable v, unordered_map<Hashable, bool>& visited) const{
    visited[v] = true;
    cout << v << "\t";

    if (adj.find(v) == adj.end())
        return;

    typename list<Hashable>::iterator i;
    list<Hashable> links = adj.at(v);

    for (i = links.begin(); i != links.end(); ++i)
		if (!visited[*i])
		    DFSUtil(*i, visited);
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

    g.DFS();
    g.DFS(6);
    return 0;
}
