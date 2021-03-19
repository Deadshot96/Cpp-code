# include <iostream>
# include <list>
# include <unordered_map>
# include <unordered_set>
using namespace std;

template <typename Hashable>
class Graph{
    private:
        int numVertices;
        unordered_set<Hashable> vertices;
        unordered_map<Hashable, list<Hashable>> adjList;

        void BFSUtil(const Hashable &, unordered_map<Hashable, bool>);

    public:
        Graph(int);
        void addEdge(Hashable, Hashable);
        void BFS() const;
        void BFS(const Hashable &) const;
};

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
