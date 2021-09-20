#include <iostream>

using namespace std;

#include <vector>
#include <unordered_map>
#include <string>
#include <list>

class Node {
public:
  string name;
  list<string> nbrs;
  Node(string name) {
    this->name = name;
  }
};


class Graph {
  unordered_map<string, Node*> m;
public:
  Graph(vector<string> cities) {
    for (auto city:cities) {
      m[city] = new Node(city);
    }
  }

  void addEdge(string x, string y, bool unidir = false) {
    m[x]->nbrs.push_back(y);
    if (unidir) {
      m[y]->nbrs.push_back(x);
    }
  }

  void print() {
    for (auto cityPair:m) {
      string name = cityPair.first;
      Node* node = cityPair.second;
      cout << name << " --> ";
      for (auto city:node->nbrs) {
        cout << city << ", ";
      }
      cout << endl;
    }
  }
};

int main(void) {
  vector<string> cities = {"Delhi", "London", "Paris", "New York"};
  Graph g(cities);

  g.addEdge("Delhi", "London");
  g.addEdge("New York", "London");
  g.addEdge("Delhi", "Paris");
  g.addEdge("Paris", "New York");

  g.print();

  return 0;
}
