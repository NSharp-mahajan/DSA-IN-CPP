#include<iostream>
#include<vector>
#include<list>
#include<queue>
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

    bool isCycleUndirected(int src, int par, vector<bool> &vis) {
        vis[src] = true;

        for (int v : l[src]) {
            if (!vis[v]) {
                if (isCycleUndirected(v, src, vis)) {
                    return true;
                }
            } 
            else if (v != par) {
                return true;
            }
        }
        return false;
    }

    bool isCycle() {
        vector<bool> vis(V, false); 

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycleUndirected(i, -1, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2); 
    g.addEdge(3, 4);

    if (g.isCycle()) {
        cout << "Cycle detected in the graph!" << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}