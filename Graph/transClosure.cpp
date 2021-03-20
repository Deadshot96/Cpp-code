# include <iostream>
# include <vector>
# include <unordered_map>
# include <unordered_set>
# include <list>
using namespace std;

template <typename Hashable>
class Graph{
    private:
        int numVertices;
        unordered_set<Hashable> vertices;
        unordered_map<Hashable, list<Hashable>> adjList;
        vector<vector<Hashable>> transClosureMat;
        
        void DFSUtil(const Hashable &, unordered_map<Hashable, bool> &) const;
        void DFSUtil(const Hashable &, const Hashable &);
        void transClosure();

    public:
        Graph(int);
        void addEdge(const Hashable &, const Hashable &);
        void DFS() const;
        void DFS(const Hashable &) const;
        void printTransClosure() const;
};

template <typename Hashable>
Graph<Hashable> :: Graph(int numVertices){
    this->numVertices = numVertices;
    vector<vector<bool>> transClosureMat(numVertices, vector<bool>(numVertices, false));
}

template <typename Hashable>
void Graph<Hashable> :: DFS() const{
    cout << "Depth First Search: \n";
    unordered_map<Hashable, bool> visited;
    
    for (auto &i: adjList){
        if (!visited[i.first]){
            DFSUtil(i.first, visited);
            cout << endl;
        }
    }
}

template <typename Hashable>
void Graph<Hashable> :: addEdge(const Hashable & u, const Hashable & v){
    vertices.insert(u);
    vertices.insert(v);

    adjList[u].push_back(v);
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

template <typename Hashable>
void Graph<Hashable> :: printTransClosure(){
    transClosure();

    cout << "Transitive Closure: \n";
    for (size_t i = 0; i < numVertices; i++){
        for (size_t j = 0; j < numVertices; j++){
            cout << transClosureMat[i][j] << "\t";
        }
        cout << endl;
    }
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
