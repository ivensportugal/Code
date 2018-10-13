#include <iostream>
#include <list>
using namespace std;

class Graph {
  int V;
  list<int>* adj;
  void DFSUtil(int v, bool visited[]);
  public:
    Graph(int V);
    void addEdge(int u, int v);
    void BFS(int v);
    void DFS(int v);
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void Graph::BFS(int v) {
  bool* visited = new bool[V];
  for(int i = 0; i < V; i++)
    visited[i] = false;

  list<int> queue;
  queue.push_back(v);
  visited[v] = true;

  list<int>::iterator i;
  while(!queue.empty()) {
    v = queue.front();
    cout << v << " ";
    queue.pop_front();

    for(i = adj[v].begin(); i != adj[v].end(); i++) {
      if(!visited[*i]) {
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
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
  Graph g(6);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,3);
  g.addEdge(3,4);
  g.addEdge(3,5);
  g.addEdge(4,5);

  cout << "BFS: ";
  g.BFS(0);
  cout << endl;

  cout << "DFS: ";
  g.DFS(0);
  cout << endl;

  return 0;
}
