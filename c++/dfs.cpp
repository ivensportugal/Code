#include<iostream>
#include<list>
using namespace std;

class Graph {
  int V;
  list<int>* adj;
  void DFSUtil(int, bool[]);

  public:
    Graph(int);
    void addEdge(int, int);
    void DFS(int);
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void Graph::DFSUtil(int v, bool visited[]) {
  visited[v] = true;
  cout << v << " ";

  list<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); i++)
    if(!visited[*i])
      DFSUtil(*i, visited);
}

void Graph::DFS(int v) {
  bool* visited = new bool[V];
  for(int i = 0; i < V; i++)
    visited[i] = false;

  DFSUtil(v, visited);
}

int main() {

  Graph g(4);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,3);

  g.DFS(0);
  cout << endl;

  return 0;



}

