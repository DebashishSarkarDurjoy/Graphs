#include <iostream>
using namespace std;
#include <climits>
#include <vector>
#include <set>
#include <list>

class Graph {
    int V;
    list<pair<int, int>> *l;
public:
    Graph(int v) {
        this->V = v;
        l = new list<pair<int, int>> [this->V];
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
            for (auto it : l[i]) {
                cout << "(" << it.first << ", " << it.second << ")  ";
            }
            cout << endl;
        }
    }

    int dijkshtra(int src, int dest) {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> s;
        dist[src] = 0;
        s.insert({dist[src], 0});

        while (!s.empty()) {
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            s.erase(it);

            for (auto nbrPair : l[node]) {
                int nbr = nbrPair.second;
                int edge = nbrPair.first;

                if (distTillNow + edge < dist[nbr]) {
                    dist[nbr] = distTillNow + edge;

                    auto f = s.find({dist[nbr], nbr});
                    if (f!=s.end()) {
                        s.erase(f);
                    }
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " min dist is " << dist[i] << endl;
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
