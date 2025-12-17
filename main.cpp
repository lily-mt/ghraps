#include <iostream>
#include <list>

using namespace std;

class Graph{
    int V;
    list<int>*adj;

    public:
    Graph(int V){
        this->V=V;
        adj=new list<int>[V];
    }
    void addedge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void print_Graph(int);
};
void Graph::print_Graph(int V){
    list<int>::iterator it;
    for(int i=0;i<V; ++i){
        cout<<i<<"";
        for(it=adj[i].begin(); it!=adj[i].end();++it)
         cout<<"->"<<*it;
        cout<<endl;
    }
}


int main() {
    int V=6;
    Graph G(6);
    G.addedge(0, 1);
    G.addedge(0, 2);
    G.addedge(1, 3 );
    G.addedge(1, 4);
    G.addedge(1, 5 );
    G.addedge(2, 3 );
    G.addedge(3, 4 );
    G.addedge(4, 5);
    G.print_Graph(V);
    
    return 0;
}
