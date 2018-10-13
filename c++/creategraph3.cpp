// create a graph and traverses it in DFS

#include <iostream>
#include <list>
using namespace std;

struct Vertice {
  int data;
};

class Graph {
  int V;
  list<int>* adj;
  Vertice** vertices;

  void DFSUtil(int, bool []);

  public:
    Graph(int);
    void addEdge(int, int);
    void addVertice(int, Vertice*);
    void DFS(int);
};

Graph::Graph(int v) {
  this->V = v;
  adj = new list<int>[v];
  vertices = new Vertice*[v];
}

Vertice* createVertice(int data) {
  Vertice* v = new Vertice;
  v->data = data;
  return v;
}

void Graph::addVertice(int v, Vertice* vert) {
  vertices[v] = vert;
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]) {

  visited[v] = true;
  cout << vertices[v]->data << " ";

  // Recursion
  list<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); ++i)
    if(!visited[*i])
      DFSUtil(*i, visited);

}

void Graph::DFS(int v) {

  bool* visited = new bool[V];
  for(int i = 0; i < v; i++)
    visited[i] = false;

  DFSUtil(v, visited);
  cout << endl;
}

int main () {

  Graph g = Graph(3);

  // Add vertices
 
  g.addVertice(0, createVertice(10));
  g.addVertice(1, createVertice(9));
  g.addVertice(2, createVertice(8));

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 0);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 1);

  g.DFS(2);
  g.DFS(1);
  g.DFS(0);

  return 0;

}
