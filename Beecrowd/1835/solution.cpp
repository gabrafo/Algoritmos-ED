// https://judge.beecrowd.com/pt/problems/view/1835
// Exercício Promessa de Campanha

#include <bits/stdc++.h>
using namespace std;

int dfs(int N, const vector<pair<int,int>>& connections) {
    // Monta a lista de adjacência
    vector<vector<int>> adj(N + 1);
    for (int xy = 0; xy < connections.size(); xy++) {
      int x = connections[xy].first;   // pega o primeiro elemento do par
      int y = connections[xy].second;  // pega o segundo elemento do par

      adj[x].push_back(y);  // adiciona y como vizinho de x
      adj[y].push_back(x);  // adiciona x como vizinho de y (grafo não-direcionado)
    }

    // Vetor para controlar quais pontos já foram visitados
    vector<bool> visited(N + 1, false);

    int components = 0; // contador de ilhas

    for (int u = 1; u <= N; u++) {
        if (!visited[u]) { // a cada u não visitado temos uma nova DFS
            components++; // achamos uma nova ilha

            // DFS iterativa usando pilha
            stack<int> s;
            s.push(u);
            visited[u] = true;

            while (!s.empty()) {
                int curr = s.top();
                s.pop();

                for (int v : adj[curr]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        s.push(v);
                    }
                }
            }
        }
    }

    return components;
}
 
int main() {
  // Desativa a sincronização entre as streams do C++ (cin/cout) e as do C (scanf/printf).
  // Isso deixa as operações de entrada/saída (I/O) mais rápidas, mas não devemos misturar cin/cout com scanf/printf depois disso.
  ios::sync_with_stdio(false);

  // Remove a "amarração" entre cin e cout, ou seja, cin não vai mais forçar um flush (esvaziar buffer) de cout automaticamente.
  // Isso também acelera a leitura, mas se precisar garantir que algo seja impresso antes da leitura, use cout.flush() manualmente.
  cin.tie(nullptr);

  int T; 
  if (!(cin >> T)) return 0;

  for (int t = 0; t < T; t++) {
    // Para cada um dos testcases...

    int N; // Número de pontos principais
    int M; // Número de arestas

    cin >> N >> M; 

    vector<pair<int,int>> connections;
    connections.reserve(M); // Reserva espaço na memória para armazenar pelo menos M elementos, evitando realocações

    for (int m = 0; m < M; m++){
      // Para cada uma das ligações do testcase...

      int X, Y; // Ligação entre ponto x e y, existem M ligações no total
      cin >> X >> Y;

      // Cria e adiciona um std::pair<int,int>(X, Y) diretamente no vetor.
      // Diferente do push_back(std::make_pair(X, Y)), que cria um par temporário e depois copia/move,
      // o emplace_back constrói o par no local, evitando essa etapa extra.
      connections.emplace_back(X, Y); 
    }

    int components = dfs(N, connections);
    int E = components - 1;

    if (E == 0)
        cout << "Caso #" << t+1 << ": a promessa foi cumprida\n";
    else
        cout << "Caso #" << t+1 << ": ainda falta(m) " << E << " estrada(s)\n";
  }

  return 0;
}