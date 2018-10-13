// Topological sorting on a graph

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
  int V;
  list<int>* adj;
  void topologicalSortUtil(int v, bool visited[], stack<int>&);

  public:
    Graph(int v);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int v) {
  this->V = v;
  adj = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) {

  visited[v] = true;

  list<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); ++i)
    if(!visited[*i])
      topologicalSortUtil(*i, visited, Stack);

  Stack.push(v);

}

void Graph::topologicalSort() {

  stack<int> Stack;
  bool* visited = new bool[V];
  for(int i = 0; i < V; i++)
    visited[i] = false;

  for(int i = 0; i < V; i++)
    if(!visited[i])
      topologicalSortUtil(i, visited, Stack);

  while(Stack.empty() == false) {
    cout << Stack.top() << " ";
    Stack.pop();
  }

  cout << endl;

}



int main () {

  Graph g(6);
  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  g.topologicalSort();

  return 0;
}
