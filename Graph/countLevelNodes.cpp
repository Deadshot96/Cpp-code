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
        void BFSUtil(const Hashable &, unordered_map<Hashable, bool> &) const;

    public:
        Graph(size_t);
        void addEdge(const Hashable &, const Hashable &);
        void BFS() const;
        void BFS(const Hashable &) const;
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
    g.BFS(5);

    return 0;
}
