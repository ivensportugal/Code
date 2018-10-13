// The implementation of a graph

#include <iostream>
#include <list>
#include <stack>
using namespace std;

// The graph
class Graph {
  int V;           // the number of vertices
  list<int> *adj;   // an adjacency matrix
  void topologicalSortUtil(stack<int>, bool [], int);

  public:
    Graph(int v);
    void addEdge(int v, int w);
    void topologicalSort(int);
};

// Constructor
Graph::Graph(int v) {
  this->V = v;
  adj = new list<int>(v);
}

// Method to add edges to the graph
void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::topologicalSortUtil(stack<int> s, bool visited[], int v) {

  visited[v] = true;

  list<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); i++)
    if(!visited[*i])
      s.push(*i);

  s.push(v);

}

// Traverses the graph
void Graph::topologicalSort(int root) {

  bool visited = new bool[V];
  stack<int> s;

  // Recursively adds nodes to the stack
  list<int>::iterator i;
  for(i = adj[root].begin(); i != adj[root].end(); i++)
    if(!visited[*i])
      topologicalSortUtil(s, visited, *i);

  while(!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }

  cout << endl;
  
}


int main() {

  Graph g(5);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(0,3);
  g.addEdge(0,4);
  g.addEdge(0,5);

  g.topologicalSort(0);

  return 0;
}
