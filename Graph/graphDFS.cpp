# include <iostream>
# include <vector>
# include <list>
using namespace std;

template <typename Comparable>
class Graph{

    private:
        int V;
        list<Comparable> *adj;

    public:
        Graph(int);
        addEdge(Comparable, Comparable);
        BFS(Comparable) const; 
        BFS() const;
};

template <typename Comparable>
Graph<Comparable> :: Graph(int V){
    this->V = V;
    adj = new list<Comparable> [V];
}





int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
