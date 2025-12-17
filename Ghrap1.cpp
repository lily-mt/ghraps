#include <iostream>
using namespace std;

int adj[20][20] ;

void add(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void ptr(int V) {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 6;

    add(0, 1);
    add(0, 2);
    add(1, 3);
    add(1, 4);
    add(1, 5);
    add(2, 3);
    add(3, 4);
    add(4, 5);

    ptr(V);

    return 0;
}
