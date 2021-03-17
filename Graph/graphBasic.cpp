# include <iostream>
# include <vector>
# include <list>
using namespace std;

class Graph{
    private:
        int V;
        list<int> *adj;

    public:
        Graph(int);
        void addEdge(int, int);
        void BFS(int);
};


int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
