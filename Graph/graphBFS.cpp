# include <iostream>
# include <list>
# include <unordered_map>
# include <queue>
# include <unordered_set>
// # include <bits/stdc++.h>
using namespace std;

template <typename Hashable>
class Graph{
    private:
        int numVertices;
        unordered_set<Hashable> vertices;
        unordered_map<Hashable, list<Hashable>> adjList;

        void BFSUtil(const Hashable &, unordered_map<Hashable, bool> &) const;

    public:
        Graph(int);
        void addEdge(Hashable, Hashable);
        void BFS() const;
        void BFS(const Hashable &) const;
};

template <typename Hashable>
Graph<Hashable> :: Graph(int numVertices){
    this->numVertices = numVertices;
}

template <typename Hashable>
void Graph<Hashable> :: addEdge(Hashable u, Hashable v){
    vertices.insert(u);
    vertices.insert(v);

    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

template <typename Hashable>
void Graph<Hashable> :: BFS() const{
    unordered_map<Hashable, bool> visited;
    cout << "Breath First Search: \n";

    for(auto& i: adjList)
        if (!visited[i.first])
            BFSUtil(i.first, visited);

    cout << endl;
}

template <typename Hashable>
void Graph<Hashable> :: BFS(const Hashable & v) const{
    cout << "Breadth First Search: \n";
    unordered_map<Hashable, bool> visited;
    BFSUtil(v, visited);
    cout << endl;
}

template <typename Hashable>
void Graph<Hashable> :: BFSUtil(const Hashable & v, unordered_map<Hashable, bool> & visited) const{
    visited[v] = true;

    list<Hashable> queue;
    queue.push_back(v);

    while(!queue.empty()){
        Hashable x = queue.front();
        cout << x << "\t";
        queue.pop_front();

        list<Hashable> links = adjList.at(x);
        typename list<Hashable>::iterator itr;

        for (itr = links.begin(); itr != links.end(); ++itr){
            if (!visited[*itr]){
                visited[*itr] = true;
                queue.push_front(*itr);
            }
        }
    }
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

    g.BFS();
    g.BFS(3);

    return 0;
}
