#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addedge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void print_Graph(int);
    void BFS(int s);
    void DFS(int s);
};

void Graph::print_Graph(int V) {
    vector<int>::iterator it;
    for (int i = 0; i < V; ++i) {
        cout << i << " ";
        for (it = adj[i].begin(); it != adj[i].end(); ++it)
            cout << "->" << *it;
        cout << endl;
    }
}

void Graph::BFS(int s) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i)
        visited[i] = false;

    queue<int> Q;
    vector<int>::iterator it;

    Q.push(s);
    visited[s] = true;

    while (!Q.empty()) {
        s = Q.front();
        Q.pop();

        for (it = adj[s].begin(); it != adj[s].end(); ++it) {
            if (!visited[*it]) {
                Q.push(*it);
                visited[*it] = true;
                cout << s << "->" << *it << endl;
            }
        }
    }

    delete[] visited;
}

void Graph::DFS(int s) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i)
        visited[i] = false;

    stack<int> ST;
    vector<int>::iterator it;

    ST.push(s);
    visited[s] = true;

    while (!ST.empty()) {
        int u = ST.top();
        ST.pop();

        for (it = adj[u].begin(); it != adj[u].end(); ++it) {
            if (!visited[*it]) {
                visited[*it] = true;
                ST.push(*it);
                cout << u << "->" << *it << endl;
            }
        }
    }

    delete[] visited;
}


int main() {
    int V = 6;
    Graph G(V);

    G.addedge(0, 1);
    G.addedge(0, 2);
    G.addedge(1, 3);
    G.addedge(2, 4);
    G.addedge(2, 5);
    G.addedge(3, 4);
    G.addedge(3, 5);

    cout << "BFS starting from 2:" << endl;
    G.BFS(2);


    cout << endl << "DFS starting from 2:" << endl;
    G.DFS(2);

    return 0;
}