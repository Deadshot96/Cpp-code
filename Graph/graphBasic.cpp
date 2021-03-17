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

Graph :: Graph(int V){
    this->V = V;
    adj = new list<int> [V];
}

void Graph :: addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph :: BFS(int s){

}


int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
