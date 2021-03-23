# include <iostream>
# include <cstring>
# include <list>
# include <vector>
# include <queue>
using namespace std;

/*
    Given two four digit prime numbers, suppose 1033
    and 8179, we need to find the shortest path from 1033
    to 8179 by altering only single digit at a time such
    that every number that we get after changing a digit is 
    prime. For example a solution is 1033, 1733, 3733, 3739,
    3779, 8779, 8179
*/

void SieveOfEratosthenes (vector<size_t> &);
size_t shortestPath (size_t, size_t);
bool compare (const size_t, const size_t);

class Graph{
    private:
        size_t V;
        list<size_t> *adjList;
    public:
        Graph(size_t);
        void addEdge(const size_t &, const size_t &);
        size_t BFS(const size_t &, const size_t &);
};

Graph :: Graph(size_t V){
    this->V = V;
    this->adjList = new list<size_t> [V];
}

void Graph :: addEdge(const size_t & u, const size_t & v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

size_t Graph :: BFS(const size_t & u, const size_t & v){
    size_t visited[V];
    memset(visited, 0, sizeof(visited));

    queue<size_t> q;
    visited[u] = 1;
    q.push(u);

    list<size_t> :: iterator itr;
    while (!q.empty()){
        size_t p = q.front();
        q.pop();

        for (itr = adjList[p].begin(); itr != adjList[p].end(); ++itr){
            if (!visited[*itr]){
                visited[*itr] = visited[p] + 1;
                q.push(*itr);
            }

            if (*itr == v)
                return visited[*itr] - 1;
        }
    }
    return 0;
}

bool compare(const size_t num1, const size_t num2){

    // returns true if both numbers differ by a single digit

    string s1 = to_string(num1);
    string s2 = to_string(num2);
    size_t c = 0;
    
    if (s1[0] != s2[0])
        c++;
    if (s1[1] != s2[1])
        c++;
    if (s1[2] != s2[2])
        c++;
    if (s1[3] != s2[3])
        c++;

    return (c == 1);
}

void SieveOfEratosthenes(vector<size_t>& v){
    // put all primes less than 9999 into vector v
    size_t n = 9999;
    bool primes[n + 1];
    memset(primes, true, sizeof(primes));

    for (size_t p = 2; p * p <= n; ++p)
        if (primes[p])
            for (size_t i = p * p; i <= n; i += p)
                primes[i] = false;

    for (size_t p = 1000; p <= n; ++p)
        if (primes[p])
            v.push_back(p);
}

size_t shortestPath(size_t u, size_t v){
    vector<size_t> pset;
    SieveOfEratosthenes(pset);

    Graph g(pset.size());

    for (size_t i = 0; i < pset.size(); ++i)
        for (size_t j = i + 1; j < pset.size(); ++j)
            if (compare(pset[i], pset[j]))
                g.addEdge(i, j);

    size_t index1, index2;

    for (size_t j = 0; j < pset.size(); ++j){
        if (pset[j] == u){
            index1 = j;
            break;
        }
    }

    for (size_t j = 0; j < pset.size(); ++j){
        if (pset[j] == v){
            index2 = j;
            break;
        }
    }
    return g.BFS(index1, index2);
}

int main()
{
    cout << "Hello, World!" << endl;
    vector<size_t> pset;
    SieveOfEratosthenes(pset);
    cout << "Path: " << shortestPath(1033, 8179) << endl;
    return 0;
}
