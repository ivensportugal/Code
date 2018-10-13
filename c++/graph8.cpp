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
    void BFS(int);
    void DFS(int);
};

Graph::Graph(int V) {
  this->V = V;
  this->adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void Graph::BFS(int v) {
  bool* visited = new bool[V];
  for(int i = 0; i < V; i++)
    visited[V] = false;

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
        queue.push_back(*i);
        visited[*i] = true;
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
  Graph g(3);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.BFS(0);
  cout << endl;

  g.DFS(0);
  cout << endl;

  return 0;
}
