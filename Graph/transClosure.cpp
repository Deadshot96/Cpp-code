# include <iostream>
# include <vector>
# include <unordered_map>
# include <unordered_set>
# include <list>
using namespace std;

template <typename Hashable>
class Graph{
    private:
        size_t numVertices;
        unordered_set<Hashable> vertices;
        unordered_map<Hashable, list<Hashable>> adjList;
        vector<vector<bool>> transClosureMat;
        
        void DFSUtil(const Hashable &, unordered_map<Hashable, bool> &) const;
        void DFSUtil(const Hashable &, const Hashable &);
        void transClosureV1();
        void transClosureV2();

    public:
        Graph(size_t);
        void addEdge(const Hashable &, const Hashable &);
        void DFS() const;
        void DFS(const Hashable &) const;
        void printTransClosure();
};

template <typename Hashable>
Graph<Hashable> :: Graph(size_t numVertices)
    :numVertices(numVertices), transClosureMat(numVertices, vector<bool>(numVertices, false))
    {}

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

    for (auto& vec: transClosureMat)
        std::fill(vec.begin(), vec.end(), false);
    
    transClosureV1();
    cout << "Transitive Closure: O(V^2)\n";
    for (size_t i = 0; i < numVertices; i++){
        for (size_t j = 0; j < numVertices; j++){
            cout << transClosureMat[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;


    for (auto& vec: transClosureMat)
        std::fill(vec.begin(), vec.end(), false);
    transClosureV2();
    cout << "Transitive Closure: O(V^3)\n";
    for (size_t i = 0; i < numVertices; i++){
        for (size_t j = 0; j < numVertices; j++){
            cout << transClosureMat[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

template <typename Hashable>
void Graph<Hashable> :: transClosureV1(){
    for (const Hashable & i : vertices)
        DFSUtil(i, i);
}

template <typename Hashable>
void Graph<Hashable> :: DFSUtil(const Hashable & u, const Hashable & v){
    transClosureMat[u][v] = true;
    
    if (adjList.find(v) == adjList.end())
        return;

    const list<Hashable> & links = adjList.at(v);
    typename list<Hashable> :: const_iterator itr;

    for (itr = links.begin(); itr != links.end(); ++itr)
        if (!transClosureMat[u][*itr])
            DFSUtil(u, *itr);
}

template <typename Hashable>
void Graph<Hashable> :: transClosureV2(){
    typename unordered_set<Hashable>::const_iterator i, j, k;

    for (auto& i : vertices){
        transClosureMat[i][i] = true;
        for (Hashable& j: adjList[i]){
            transClosureMat[i][j] = true;
        }
    }

    for (k = vertices.begin(); k != vertices.end(); ++k){
        for (i = vertices.begin(); i != vertices.end(); ++i){
            for (j = vertices.begin(); j != vertices.end(); ++j){
                transClosureMat[*i][*j] = transClosureMat[*i][*j] || (transClosureMat[*i][*k] && transClosureMat[*k][*j]);
            }
        }
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
    g.printTransClosure();

    return 0;
}
