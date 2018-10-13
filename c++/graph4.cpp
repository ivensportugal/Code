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
  cout << "hi";
  adj[v].push_back(u);
  cout << "hi2";
  adj[v].push_back(u);
  cout << "hi3";
}

void Graph::BFS(int s) {
  bool* visited = new bool[V];
  for(int i = 0; i < V; i++)
    visited[i] = false;

  list<int> queue;

  queue.push_back(s);
  visited[s] = true;

  list<int>::iterator i;
  while(!queue.empty()) {
    s = queue.front();
    cout << s << " ";
    queue.pop_front();

    for(i = adj[s].begin(); i != adj[s].end(); i++) {
      while(!visited[*i]) {
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
}

int main() {
  Graph g(4);
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(3,4);

  //g.BFS(0);
  cout << endl;

  return 0;
}
