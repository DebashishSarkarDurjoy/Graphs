#include <iostream>
using namespace std;
#include <list>
#include <queue>

class Graph {
private:
  int V;
  list<int> *l;
public:
  Graph(int nodes) {
    this->V = nodes;
    l = new list<int>[V];
  }

  void addEdge(int i, int j, bool unidir = true) {
    l[i].push_back(j);
    if (unidir == true) {
      l[j].push_back(i);
    }
  }

  void print() {
    for (int i = 0; i < this->V; i++) {
      cout << i << " --> ";
      for (auto node : this->l[i]) {
        cout << node << ", ";
      }
      cout << endl;
    }
  }

  void bfs(int source) {
    queue<int> q;
    int *dist = new int[this->V]{0};
    int *parent = new int[this->V];
    for (int i = 0; i < this->V; i++) {
      parent[i] = -1;
    }

    bool *visited = new bool[this->V]{0};
    q.push(source);
    visited[source] = true;

    parent[source] = source;
    dist[source] = 0;

    while (!q.empty()) {
      int f = q.front();
      cout << f << endl;
      q.pop();
      for (auto nbr : this->l[f]) {
        if (!visited[nbr]) {
          q.push(nbr);
          visited[nbr] = true;

          parent[nbr] = f;
          dist[nbr] = dist[f] + 1;
        }
      }
    }

    for (int i = 0; i < this->V; i++) {
      cout << "Distance of " << i << " from source is " << dist[i] << endl;
    }
  }


};


int main() {
  Graph g(6);
  g.addEdge(0,1);
  g.addEdge(0,4);
  g.addEdge(2,1);
  g.addEdge(3,4);
  g.addEdge(4,5);
  g.addEdge(2,3);
  g.addEdge(3,5);

  g.print();
  g.bfs(0);

  return 0;
}
