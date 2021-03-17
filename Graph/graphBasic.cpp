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
    bool *visited = new bool[V];

    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while (!queue.empty()){
        s = queue.front();
        cout << s << " ";
        queue.pop_front();


        for (i = adj[s].begin(); i != adj[s].end(); i++){
            if (!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}


int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
