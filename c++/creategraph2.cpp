// Creates a graph and traverses it

#include <iostream>
#include <list>
using namespace std;

class Graph {
  int V;                            // number of vertices
  list<int> *adj;                   // adjacency list
  void DFSUtil(int v, bool visited[]);  // Helper function

  public:
    Graph(int v);           // Constructor
    void addEdge(int v, int w);  // Initialization
    void DFS(int v);             // Search
};

Graph::Graph(int v) {
  this->V = v;
  adj = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}


void Graph::DFSUtil(int v, bool visited[]) {

  // Mark current vertice as visited
  visited[v] = true;
  cout << v << " ";

  // Recursively call DFSUtil on adjacent nodes;
  list<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); ++i)
    if(!visited[*i])
      DFSUtil(*i, visited);

}

void Graph::DFS(int v) {

  // Mark every vertice as not visited
  bool* visited = new bool[v];
  for(int i = 0; i < v; i++)
    visited[i] = false;

  DFSUtil(v, visited);

}

int main () {

  Graph g = Graph(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(1, 3);

  g.DFS(0);

  return 0;

}
