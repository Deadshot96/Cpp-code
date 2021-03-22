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
        unordered_map<Hashable, size_t> nodeLevelData;
        unordered_map<size_t, size_t> levelSizeData;
        void BFSUtil(const Hashable &, unordered_map<Hashable, bool> &) const;
        void setLevelData(const Hashable &);

    public:
        Graph(size_t);
        void addEdge(const Hashable &, const Hashable &);
        void BFS() const;
        void BFS(const Hashable &) const;
        void printLevelData(const Hashable &);
};

template <typename Hashable>
Graph<Hashable> :: Graph(size_t numV)
    :numV{numV} {};

template <typename Hashable>
void Graph<Hashable> :: addEdge(const Hashable & u, const Hashable & v){
    vertices.insert(u);
    vertices.insert(v);

    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

template <typename Hashable>
void Graph<Hashable> :: BFS() const{
    cout << "Breath First Search: \n";
    unordered_map<Hashable, bool> visited;
    for (const Hashable & vertex: vertices)
        BFSUtil(vertex, visited);
    cout << endl;
}

template <typename Hashable>
void Graph<Hashable> :: BFS(const Hashable & v) const{
    cout << "Breath First Search: \n";
    unordered_map<Hashable, bool> visited;
    BFSUtil(v, visited);
    cout << endl;
}

template <typename Hashable>
void Graph<Hashable> :: BFSUtil(const Hashable & u, unordered_map<Hashable, bool> & visited) const{
    list<Hashable> queue;
    queue.push_back(u);

    while (!queue.empty()){
        const Hashable & vertex = queue.front();
        queue.pop_front();

        if (!visited[vertex]){
            cout << vertex << "\t";
            visited[vertex] = true;
        }

        if (adjList.find(vertex) == adjList.end())
            continue;

        const list<Hashable> & links = adjList.at(vertex);
        typename list<Hashable> :: const_iterator itr;

        for (itr = links.begin(); itr != links.end(); ++itr)
            if (!visited[*itr])
                queue.push_back(*itr);
    }
}

template <typename Hashable>
void Graph<Hashable> :: setLevelData(const Hashable & root){
    nodeLevelData.clear();
    levelSizeData.clear();

    unordered_map<Hashable, bool> visited;
    list<Hashable> queue;

    nodeLevelData[root] = 0;
    visited[root] = true;
    queue.push_back(root);

    while (!queue.empty()){
        const Hashable & v = queue.front();
        queue.pop_front();

        if (adjList.find(v) == adjList.end())
            continue;

        list<Hashable> links = adjList.at(v);
        typename list<Hashable> :: const_iterator itr;

        for (itr = links.begin(); itr != links.end(); ++itr){
            if (!visited[*itr]){
                visited[*itr] = true;
                nodeLevelData[*itr] = nodeLevelData[v] + 1;
                queue.push_back(*itr);
            }
        }
    }

    for (auto p: nodeLevelData){
        levelSizeData[p.second] += 1;
    }
}

template <typename Hashable>
void Graph<Hashable> :: printLevelData(const Hashable & root){
    this->setLevelData(root);

    cout << "Node's levels: \n";
    for (auto p: this->nodeLevelData)
        cout << p.first << ":\t" << p.second << "\n";
    // cout << endl;

    cout << "Level sizes: \n";
    for (auto p: this->levelSizeData)
        cout << p.first << ":\t" << p.second << "\n";
    // cout << endl;
}

int main()
{
    cout << "Hello, World!\n";

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

    g.BFS();
    g.BFS(4);

    g.printLevelData(3);

    return 0;
}
