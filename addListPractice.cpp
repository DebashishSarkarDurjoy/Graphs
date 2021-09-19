#include <iostream>
using namespace std;
#include <list>

class Graph {
  int V;
  list<int> *l;

public:
  Graph(int V) {
    this->V = V;
    l = new list<int>[V];
  }

  void addEdge(int i, int j, bool unidir = true) {
    this->l[i].push_back(j);
    if (unidir == true) {
      this->l[j].push_back(i);
    }
  }

  void print() {
    for (int i = 0; i < this->V; i++) {
      cout << i << " --> ";
      for (auto node:this->l[i]) {
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

  return 0;
}
