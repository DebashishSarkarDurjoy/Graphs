#include <iostream>
using namespace std;
#include <list>
#include <vector>

class Graph {
  list<int> *l;
  int V;

public:
  Graph (int V) {
    this->V = V;
    this->l = new list<int>[this->V];
  }

  void addEdge(int x, int y) {
    l[x].push_back(y);
  }

  void print() {
    for (int i = 0; i < this->V; i++) {
      cout << i << ": ";
      for (auto j : this->l[i]) {
        cout << j << ", ";
      }
      cout << endl;
    }
  }

  bool dfs(int node, vector<bool> &visited, vector<bool> &stack) {
    //return true if backedge is found, else false
    visited[node] = true;
    stack[node] = true;

    //do some work at node, return true if backedge is found here itself
    for (int nbr : this->l[node]) {
      if (stack[nbr] == true) {
        return true;
      }
      else if (visited[nbr] == false) {
        bool nbrFoundCycle = dfs(nbr, visited, stack);
        if (nbrFoundCycle) {
          return true;
        }
      }
    }

    //going back
    stack[node] = false;
    return false;

  }

  bool contains_cycle() {
    vector<bool> visited(this->V, false);
    vector<bool> stack(this->V, false);

    for (int i = 0; i < this->V; i++) {
      if (!visited[i]) {
        if (dfs(i, visited, stack)) {
          return true;
        }
      }
    }
    return false;
  }
};


int main(void) {
  Graph g(3);
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(2,3);

  g.print();
  cout << g.contains_cycle() << endl;

  return 0;
}
