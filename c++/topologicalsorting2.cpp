// Traverses a directed graph and prints its topological sorting

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
  int V;
  list<int>* adj;

  void DFSUtil(stack<int>& s, bool visited[], int v);
 
  public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS();
};


Graph::Graph(int v) {
  this->V = v;
  adj = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::DFSUtil(stack<int> &s, bool visited[], int v) {

  visited[v] = true;

  list<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); i++)
    if(!visited[*i])
      DFSUtil(s, visited, *i);

  s.push(v);

}


void Graph::DFS() {

  stack<int> s;
  bool* visited = new bool[V];

  for(int i = 0; i < V; i++)
    if(!visited[i])
      DFSUtil(s, visited, i);

  while(s.empty() == false) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  
}


int main () {

  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 5);
  g.addEdge(2, 6);

  g.DFS();

  return 0;
}
