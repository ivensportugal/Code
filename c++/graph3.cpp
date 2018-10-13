#include <iostream>
#include <list>
using namespace std;

class Graph {
  int V;
  list <int>* adj;
  void DFSUtil(int, bool[]);

  public:
    Graph(int);
    void addEdge(int, int);
    void BFS(int);
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

void Graph::BFS(int s) {
  bool* visited = new bool[V];
  for(int i = 0; i < V; i++)
    visited[i] = false;

  list<int> q;

  q.push_back(s);
  visited[s] = true;

  list<int>::iterator i;
  while(!q.empty()) {
    s = q.front();
    cout << s << " ";
    q.pop_front();

    for(i = adj[s].begin(); i != adj[s].end(); i++) {
      if(!visited[*i]) {
        q.push_back(*i);
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
  Graph g(6);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(0,3);
  g.addEdge(1,4);
  g.addEdge(1,5);
  g.addEdge(5,4);
  cout << "BFS" << endl;
  g.BFS(0);
  cout << "test" << endl;
  g.BFS(3);
  cout << "test" << endl;
  g.BFS(6);
  cout << "test" << endl;
  cout << "DFS" << endl;
  g.DFS(0);
  g.DFS(3);
  g.DFS(6);

  return 0;
}
