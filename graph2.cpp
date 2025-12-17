#include <iostream>
#include <vector>
using namespace std;

void addedge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void ptr(vector<int> adj[], int V) {
    for (int i = 0; i < V; ++i) {
        cout << i;
        for (int v : adj[i]) {
            cout << " -> " << v;
        }
        cout << endl;
    }
}

int main() {
    int V = 6;
    vector<int> adj[6];

    
    addedge(adj, 0, 1);
    addedge(adj, 0, 2);
    addedge(adj, 1, 3);
    addedge(adj, 1, 4);
    addedge(adj, 1, 5);
    addedge(adj, 2, 3);
    addedge(adj, 3, 4);
    addedge(adj, 4, 5);

    ptr(adj, V);
    cout<<endl;

    return 0;
}
