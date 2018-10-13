// Given a dictionary of alien works, this algorithm finds the order of characters in the language.

#include <iostream>
#include <string>
#include <list>
#include <stack>
using namespace std;

#define NUM_LETTERS 27

class Graph {
  list<int>* adj;
  bool* valid;

  void topologicalSortUtil(int, bool [], stack<int>&);

  public:
    Graph();
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph() {
  adj = new list<int>[NUM_LETTERS];
  valid = new bool[NUM_LETTERS];
  for(int i = 0; i < NUM_LETTERS; i++)
    valid[i] = false;
}
    
void Graph::addEdge(int v, int w) {
  valid[v] = true;
  valid[w] = true;

  adj[v].push_back(w);
}


void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& s) {

  visited[v] = true;

  list<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); i++)
    if(valid[*i] && !visited[*i])
      topologicalSortUtil(*i, visited, s);

  s.push(v);

}




void Graph::topologicalSort() {

  stack<int> s;

  bool* visited = new bool[NUM_LETTERS];
  for(int i = 0; i < NUM_LETTERS; i++)
    visited[i] = false;

  for(int i = 0; i < NUM_LETTERS; i++)
    if(valid[i] && !visited[i])
      topologicalSortUtil(i, visited, s);

  while(!s.empty()) {
    cout << (char)('a' + s.top()) << " ";
    s.pop();
  }

  cout << endl;

}


int main () {

  //string words[] = {"baa", "abcd", "abca", "cab", "cad"};
  //int num = 5;

  string words[] = {"caa", "aaa", "aab"};
  int num = 3;

  Graph g = Graph();

  for(int i = 0; i < num-1; i++) {
    int min = words[i].size() <= words[i+1].size() ? words[i].size() : words[i+1].size();
    for(int j = 0; j < min; j++) {
      if(words[i].at(j) != words[i+1].at(j)) {
        g.addEdge(words[i].at(j) - 'a', words[i+1].at(j) - 'a');
        break;
      }
    }
  }

  g.topologicalSort();

  return 0;
}
  
