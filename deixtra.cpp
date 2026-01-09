#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> ipair;

void addEdge(vector<ipair> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
}

void deixtra(vector<ipair> adj[], int V, int s) {
    vector<bool> visit(V, false);
    vector<int> dist(V, 999);
    vector<int> parent(V, -1);

    vector<ipair>::iterator it;
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;

    dist[s] = 0;
    pq.push(make_pair(dist[s], s));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visit[u] = true;

        for (it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = (*it).first;
            int wt = (*it).second;


            if (visit[v] == false && dist[v] > dist[u] + wt) {
                parent[v] = u;
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < V; ++i)
        cout << parent[i] << "->" << i << " " << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<ipair> adj[V];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 2, 1, 2);
    addEdge(adj, 1, 3, 1);
    addEdge(adj, 2, 3, 5);
    addEdge(adj, 3, 4, 3);

    deixtra(adj, V, 0);

    return 0;
}
