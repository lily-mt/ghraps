#include <iostream>
#include <vector>
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
       
    }

    void print_Graph(int);
    void DFS();
    
};


void Graph::DFS(){
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i)
        visited[i] = false;

    stack<int> ST;
    vector<int>::iterator it;

    for(int i = 0; i < V; i++) 
        if(!visited[i]) { 
            cout << "xis wvwro-"<<i <<endl;
            ST.push(i);
            visited[i] = true;
            while(!ST.empty()) {
                int m= ST.top();
                ST.pop();
                
                for(it = adj[m].begin(); it <adj[m].end(); ++it) 
                    if(!visited[*it]) {
                        ST.push(*it);
                        visited[*it] = true;
                        cout << m<<"->"<<*it <<endl;
                    }
                }
        }
                
           
    }
    


   


int main() {
    int V = 6;
    Graph G(V);

    G.addedge(0, 1);
    G.addedge(1, 3);
    G.addedge(1, 4);
    G.addedge(2, 1);
    G.addedge(5, 4);
    G.addedge(5, 0);

    
    G.DFS();

  

    return 0;
}
