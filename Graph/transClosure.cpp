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
        vector<vector<Hashable>> transClosure;
        bool transClosureFlag = false;

        void DFSUtil(const Hashable &, unordered_map<Hashable, bool> &);
        void transClosure();

    public:
        Graph(int);
        void DFS() const;
        void DFS(const Hashable &) const;
        void printTransClosure() const;
};

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
