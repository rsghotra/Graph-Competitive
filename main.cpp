#include <iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {
  int V=0;
  list<int> *l=0;
public:
  Graph(int v) {
    V = v;
    l = new list<int>[V];
  }

  void addEdge(int u, int v, bool undir=true) {
    l[u].push_back(v);
    if(undir) {
      l[v].push_back(u);
    }
  }

  void printAdjList() {
    //Iterate over all the rows
    for(int i = 0; i < V; i++) {
      cout << i << "--->"; //seq number of a list repr vtx number
      for(int node: l[i]) {
        //auto for loop will handlie the next
        //every element of the ith linked list
        cout << node << ",";
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
  g.printAdjList();
  return 0;
}