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

  void dfsHelper(int node, bool *visited) {
    visited[node] = true;
    cout << node << ", ";
    for (int nbr : this->l[node]) {
      if (!visited[nbr]) {
        dfsHelper(nbr, visited);
      }
    }
    return;
  }

  void dfs(int source) {
    bool *visited = new bool[this->V]{0};
    dfsHelper(source, visited);
    cout << endl;
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
  g.dfs(1);

  return 0;
}
