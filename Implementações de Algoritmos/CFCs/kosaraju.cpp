#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct vertex {
  int id;
  int color = 0; // 0 branco, 1 cinza, 2 preto
  int predecessorId = -1;
  int discoveryT; // Tempo de descoberta
  int finalT; // Tempo de fechamento
};

struct graph {
  vector<std::vector<int>> adjList; // Lista de adjacência com IDs
  vector<vertex> vertexes; // Vetor com os dados de cada vértice
  int V; // Número de vértices (palitos)
  int E; // Número de arestas (relações)
};

int dfsTime = 0;

void DFSVisit(graph& G, int v) {
  G.vertexes[v].discoveryT = ++dfsTime;
  G.vertexes[v].color = 1;

  for (int u : G.adjList[v]) {
    if (G.vertexes[u].color == 0) {
      G.vertexes[u].predecessorId = G.vertexes[v].id;
      DFSVisit(G, u);
    }
  }

  G.vertexes[v].color = 2;
  G.vertexes[v].finalT = ++dfsTime;
}

void DFS(graph& G) {
  dfsTime = 0;
  for (int i = 0; i<G.V; i++){
    for (int v : G.adjList[i]){
      if (G.vertexes[v].color == 1){
        DFSVisit(G, v);
      }
    }
  }
}

graph buildTranspose(const graph& G) {
    graph GT;
    GT.V = G.V;
    GT.E = G.E;
    GT.adjList.resize(G.V + 1);
    GT.vertexes.resize(G.V + 1);

    for (int u = 1; u <= G.V; ++u) {
        for (int v : G.adjList[u]) {
            // Se existe uma aresta u -> v em G,
            // adiciona uma aresta v -> u em GT.
            GT.adjList[v].push_back(u);
        }
    }
    return GT;
}

// DFSVisit simplificada para apenas coletar os nós de um CFC
void collectSCCsVisit(const graph& GT, int u, vector<bool>& visited, vector<int>& currentSCC) {
    visited[u] = true;
    currentSCC.push_back(u);

    for (int v : GT.adjList[u]) {
        if (!visited[v]) {
            collectSCCsVisit(GT, v, visited, currentSCC);
        }
    }
}

vector<vector<int>> kosarajuSCC(graph& G) {
    // PASSO 1: Executar DFS no grafo original para obter os tempos de finalização
    DFS(G);

    // Cria uma lista de vértices para ordenar pela ordem de finalização
    vector<int> processingOrder(G.V);
    for(int i = 0; i < G.V; ++i) {
      processingOrder[i] = i + 1;
    }

    // Ordena os vértices em ordem DECRESCENTE de tempo de finalização
    sort(processingOrder.begin(), processingOrder.end(), [&](int a, int b) {
        return G.vertexes[a].finalT > G.vertexes[b].finalT;
    });

    // PASSO 2: Cria o grafo transposto
    graph GT = buildTranspose(G);

    // PASSO 3: Executa DFS em GT na ordem calculada para encontrar os CFCs
    vector<vector<int>> allSCCs;
    vector<bool> visited(G.V + 1, false);
    for (int u : processingOrder) {
        if (!visited[u]) {
            vector<int> currentSCC;
            collectSCCsVisit(GT, u, visited, currentSCC);
            allSCCs.push_back(currentSCC);
        }
    }

    return allSCCs;
}


int main() {
  int n, m;
  graph G;
  vector<vector<int>> sccs;

  while (cin >> n >> m and (n != 0 and m != 0)) {
      G.V = n;
      G.E = m;

      // Redimensiona ambas as estruturas para n+1 posições
      G.adjList.resize(n + 1);
      G.vertexes.resize(n + 1);

      for (int i = 1; i <= n; ++i) {
          G.vertexes[i].id = i;
      }

      for (int i = 0; i < m; ++i) {
          int u, v;
          cin >> u >> v;

          // CORREÇÃO: Adiciona apenas o ID 'v' na lista de adjacência de 'u'
          G.adjList[u].push_back(v);
      }
    vector<vector<int>> sccs = kosarajuSCC(G);
  }

  if (sccs.empty()) {
    cout << "No SCCs" << endl;
  } else {
    // Laço externo: itera sobre cada CFC (que é um vector<int>).
    for (const auto& scc : sccs) {
        // Laço interno: itera sobre cada vértice (int) dentro do CFC atual.
        for (int vertexId : scc) {
            cout << vertexId << endl;
        }
    }
  }

  return 0;
}