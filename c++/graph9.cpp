// Impelementation of a graph
#include <iostream>
#include <list>
#include <stack>
using namespace std;


class Graph {
  int V; // number of vertices
  list<int>* adj;

  void printGraphUtil(bool visited[], stack<int>& s, int v);

  public:
    Graph(int v);
    void addEdge(int v, int w);
    void printGraph();
};

Graph::Graph(int v) {
  this->V = v;
  adj = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}


void Graph::printGraphUtil(bool visited[], stack<int>& s, int v) {
  visited[v] = true;

  list<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); ++i)
    if(!visited[*i])
      printGraphUtil(visited, s, *i);

  s.push(v);

}

void Graph::printGraph() {

  stack<int> s;
  
  bool* visited = new bool[V];
  for(int i = 0; i < V; i++)
    if(!visited[i])
      printGraphUtil(visited, s, i);
  
  while(!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}


int main () {

  int size = 10;
  Graph g(size);

  for(int i = 0; i < size; i++)
    g.addEdge(i, (i+1)%size);

  g.printGraph();

  return 0;

}
