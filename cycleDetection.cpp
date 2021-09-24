#include <iostream>
using namespace std;
#include <list>
#include <vector>

class Graph {
  int V;
  list<int> *l;
public:
  Graph(int v) {
    this->V = v;
    l = new list<int>[this->V];
  }

  void addEdge(int i, int j) {
    l[i].push_back(j);
    l[j].push_back(i);
  }

  bool contains_cycle() {
    vector<int> visited(this->V, false);
    return dfs(0, visited, -1);
  }

  bool dfs(int node, vector<int> &visited, int parent) {
    visited[node] = true;
    cout << node << ", ";
    for (auto nbr : this->l[node]) {
      if (!visited[nbr]) {
        bool foundCycle = dfs(nbr, visited, node);
        if (foundCycle) {
          return true;
        }
      }
      else if (nbr != parent) {
        return true;
      }
    }
    return false;
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
  cout << (g.contains_cycle()) << endl;

  return 0;
}
