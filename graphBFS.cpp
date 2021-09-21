#include <iostream>
using namespace std;
#include <list>
#include <queue>

class Graph {
  int V;
  list<int> *l;

public:
  Graph(int v) {
    this->V = v;
    l = new list<int>[v];
  }

  void addEdge(int i, int j, bool unidir = true) {
    l[i].push_back(j);
    if (unidir) {
      l[j].push_back(i);
    }
  }

  void print() {
    for (int i = 0; i < this->V; i++) {
      cout << i << " --> ";
      for (int value : this->l[i]) {
        cout << value << ", ";
      }
      cout << endl;
    }
  }

  void bfs(int source) {
    queue<int> q;
    bool *visited = new bool[this->V]{0};
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
      int f = q.front();
      cout << f << endl;
      q.pop();
      for (auto nbr : this->l[f]) {
        if (!visited[nbr]) {
          q.push(nbr);
          visited[nbr] = true;
        }
      }
    }
  }
};


int main(void) {

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
