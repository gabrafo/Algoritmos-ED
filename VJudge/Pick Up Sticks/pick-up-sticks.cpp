#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct vertex {
  int id;
  int color = 0; // 0 branco, 1 cinza, 2 preto
  int predecessorId = -1;
};

struct graph {
  vector<std::vector<int>> adjList; // Lista de adjacência com IDs
  vector<vertex> vertexes; // Vetor com os dados de cada vértice
  int V; // Número de vértices (palitos)
  int E; // Número de arestas (relações)
};

// DFS para ordenação topológica, retorna false se ciclo
bool DFSVisitTopological(graph &G, int v, vector<int> &order) {
  G.vertexes[v].color = 1;
  for (int u : G.adjList[v]) {
    if (G.vertexes[u].color == 0) {
      if (!DFSVisitTopological(G, u, order)) return false;
    } else if (G.vertexes[u].color == 1) {
      // ciclo detectado
      return false;
    }
  }
  G.vertexes[v].color = 2;
  order.push_back(v);
  return true;
}

bool topologicalSort(graph &G, vector<int> &order) {
  for (int i = 1; i <= G.V; i++) G.vertexes[i].color = 0;
  order.clear();
  for (int i = 1; i <= G.V; i++) {
    if (G.vertexes[i].color == 0) {
      if (!DFSVisitTopological(G, i, order)) return false; // ciclo
    }
  }
  reverse(order.begin(), order.end());
  return true;
}


int main() {
  
  int n, m;
  vector<vector<int>> outputs;
  vector<bool> impossible;

  while (cin >> n >> m && (n != 0 || m != 0)) {
    graph G;
    G.V = n;
    G.E = m;
    G.adjList.assign(n + 1, {});
    G.vertexes.assign(n + 1, {});

    for (int i = 1; i <= n; ++i) {
      G.vertexes[i].id = i;
    }

    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      G.adjList[u].push_back(v);
    }

    vector<int> order;
    if (topologicalSort(G, order)) {
      impossible.push_back(false);
      outputs.push_back(order);
    } else {
      impossible.push_back(true);
      outputs.push_back({});
    }
  }

  for (size_t i = 0; i < outputs.size(); i++) {
    if (impossible[i]) {
      cout << "IMPOSSIBLE\n";
    } else {
      for (int x : outputs[i]) cout << x << "\n";
    }
  }

  return 0;
}