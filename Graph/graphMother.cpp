# include <iostream>
# include <list>
# include <unordered_map>
# include <unordered_set>
using namespace std;

/*
    A mother vertex in a graph G = (V,E) is a vertex v 
    such that all other vertices in G can be reached by 
    a path from v.
*/

template <typename Hashable>
class Graph{
    private:
        int numVertices;
        unordered_set<Hashable> vertices;
        unordered_map<Hashable, list<Hashable>> adjList;

        void DFSUtil(const Hashable &, unordered_map<Hashable, bool>) const;

    public:
        Graph(int);
        void addEdge(Hashable, Hashable);
        void DFS() const;
        void DFS(Hashable) const;
};

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
