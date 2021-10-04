#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <climits>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>> *l;

public:
    Graph (int v) {
        this->V = v;
        this->l = new list<pair<int, int>> [this->V];
    }

    void addEdge(int v, int u, int wt, bool unidir = true) {
        l[u].push_back({wt, v});
        if (unidir) {
            l[v].push_back({wt, u});
        }
    }

    void print() {
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (auto node : l[i]) {
                cout << "(" << node.first << ", " << node.second << ")" << "  ";
            }
            cout << endl;
        }
    }

    int dijkshtra(int src, int dest) {
        vector <int> dist(V, INT_MAX);
        set <pair<int, int>> s;

        dist[src] = 0;
        s.insert({dist[src], 0});

        while(!s.empty()) {
            auto it = s.begin();
            int distTillNow = it->first;
            int node = it->second;
            s.erase(it);

            for (auto nbrPair : l[node]) {
                int nbrEdge = nbrPair.first;
                int nbr = nbrPair.second;

                if (nbrEdge + distTillNow < dist[nbr]) {
                    auto f = s.find({dist[nbr], nbr});
                    if (f!=s.end()) {
                        s.erase(f);
                    }
                    dist[nbr] = nbrEdge + distTillNow;
                    s.insert({dist[nbr], nbr});
                }
            }
        }

        for (int i = 0; i < V; i++) {
            cout << "node " << i << " min distance is " << dist[i] << endl;
        }

        return dist[dest];
    }

};


int main(void) {
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);

    g.print();
    g.dijkshtra(0, 4);
    return 0;
}
