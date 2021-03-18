# include <iostream>
# include <vector>
# include <list>
# include <unordered_map>
using namespace std;

template <typename Hashable>
class Graph{

    private:
        int V;
        unordered_map<Hashable, vector<Hashable>> adj;

    public:
        Graph(int);
        void addEdge(Hashable, Hashable);
        void DFS(Hashable) const; 
        void DFS() const;
};

template <typename Hashable>
Graph<Hashable> :: Graph(int V){
    this->V = V;
}


template <typename Hashable>
void Graph<Hashable> :: addEdge(Hashable u, Hashable v){
    adj[u].push_back(v);
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
