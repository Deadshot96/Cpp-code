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

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
