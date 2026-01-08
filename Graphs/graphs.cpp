#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int V;
    list<int>* l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print_AdjList() {
        for (int i = 0; i < V; i++) {
            cout << i << " --> ";
            for (int neigh : l[i]) {
                cout << neigh << " ";
            }
            cout << endl;
        }
    }

    void bfs() {
        queue<int> Q;
        vector<bool> vis(V, false);
        Q.push(0);
        vis[0] = true;

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            cout << u << " ";
            for (int v : l[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        cout << endl;
    }

    void dfsHelper(int u, vector<bool> &vis) {
        cout << u << " ";
        vis[u] = true;

        for (int v : l[u]) {
            if (!vis[v]) { 
                dfsHelper(v, vis);
            }
        }
    }
    void dfs() {
        vector<bool> vis(V, false);
        dfsHelper(0, vis); 
        cout << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    cout << "Adjacency List:" << endl;
    g.print_AdjList();

    cout << "\nBFS Traversal: ";
    g.bfs();

    cout << "DFS Traversal: ";
    g.dfs(); 

    return 0;
}