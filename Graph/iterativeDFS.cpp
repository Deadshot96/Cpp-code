# include <iostream>
# include <list>
# include <vector>
# include <unordered_map>
# include <unordered_set>
# include <stack>
using namespace std;

template <typename Hashable>
class Graph{
    private:
        size_t numV;
        unordered_set<Hashable> vertices;
        unordered_map<Hashable, list<Hashable>> adjList;
        void DFSUtil(const Hashable &, unordered_map<Hashable, bool> &) const;

    public:
        Graph(size_t);
        void addEdge(const Hashable &, const Hashable &);
        void DFS() const;
        void DFS(const Hashable &) const;
};

template <typename Hashable>
Graph<Hashable> :: Graph(size_t numV)
    :numV{numV} {};

template <typename Hashable>
void Graph<Hashable> :: addEdge(const Hashable &u, const Hashable &v){
    vertices.insert(u);
    vertices.insert(v);

    adjList[u].push_back(v);
}

template <typename Hashable>
void Graph<Hashable> :: DFS() const{
    unordered_map<Hashable, bool> visited;
    cout << "Depth First Search (Iterative): \n";
    for (const Hashable & vertex: vertices)
        DFSUtil(vertex, visited);
    cout << endl;
}

template <typename Hashable>
void Graph<Hashable> :: DFS(const Hashable & vertex) const{
    unordered_map<Hashable, bool> visited;
    cout << "Depth First Search (Iterative): \n";
    DFSUtil(vertex, visited);
    cout << endl;
}

template <typename Hashable>
void Graph<Hashable> :: DFSUtil(const Hashable &u, unordered_map<Hashable, bool>& visited) const {
    stack<Hashable> st;
    st.push(u);

    while (!st.empty()){
        Hashable vertex = st.top();
        st.pop();

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
                st.push(*itr);
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

    g.DFS();
    g.DFS(5);
    return 0;
}
