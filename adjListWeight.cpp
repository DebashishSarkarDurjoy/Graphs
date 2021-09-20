#include <iostream>
using namespace std;
#include <list>
#include <set>


class Graph {
  int V;
  list<pair<int,int>> *l;
public:
  Graph(int v) {
    this->V = v;
    this->l = new list<pair<int,int>>[v];
  }

  void addEdge(int i, int j, int wt, bool unidir = true) {
    this->l[i].push_back({wt, j});
    if (unidir) {
      this->l[j].push_back({wt, i});
    }
  }

  void print() {
    for (int i = 0; i < this->V; i++) {
      for (auto it : this->l[i]) {
        cout << i ;
        cout << " -(" << it.first << ")-> " << it.second << endl;
      }

    }
  }
};

int main(void) {
  Graph g(6);

  g.addEdge(0,1,1);
	g.addEdge(1,2,2);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

  g.print();

  return 0;
}
