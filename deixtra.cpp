#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> ipair;

void addEdge(vector<ipair> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
}
void print(vector<ipair>adj[],int V){
   vector<ipair>::iterator it;
    for(int u=0;u<V;++u){
       for (it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = (*it).first;
            int wt = (*it).second;
            cout<<u<<"->"<<v<<" "<<wt<<endl;
        }
    }
}

void deixtra(vector<ipair> adj[], int V, int s) {
    vector<bool> visit(V, false);
    vector<int> dist(V, 999);
    vector<int> parent(V, -1);

    vector<ipair>::iterator it;
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;

    dist[0] = 0;
    pq.push(make_pair(dist[0], 0));

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

    for (int i = 1; i < V; ++i)
        cout << parent[i] << "->" << i << " " << dist[i] << endl;
}

int main() {
    const int V = 5;
    vector<ipair> adj[V];

    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 3, 30);
    addEdge(adj, 0, 4, 100);
    addEdge(adj, 1, 2, 50);
    addEdge(adj, 2, 4, 10);
    addEdge(adj, 3, 2, 20);
    addEdge(adj, 3, 4, 60);

    deixtra(adj,V,0);
    cout<<endl;

    print(adj,V);

    return 0;
}