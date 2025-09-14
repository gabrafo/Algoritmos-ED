#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

/*
beecrowd | 2230
Pedágio
Por OBI - Olimpíada Brasileira de Informática 2002 BR Brazil
Timelimit: 1s

Como prêmio pela primeira colocação na Olimpíada Brasileira de Informática, Juquinha e sua família ganharam
uma viagem de uma semana à Coréia do Sul. Como o país é deslumbrante, com tradições, cultura, arquitetura
e culinária muito diferentes das do Brasil, o pai de Juquinha, o Sr. Juca, decidiu alugar um carro para conhecer
melhor o país. As estradas são muito bem cuidadas; todas são de sentido duplo, e duas cidades podem ser ligadas
diretamente por mais de uma estrada. No entanto, em todas as estradas paga-se um pedágio de valor fixo
(há um pedágio em cada direção, entre duas cidades). Como o Sr. Juca não tem muito dinheiro para gastar,
as viagens com o carro devem ser muito bem planejadas.

Escreva um programa que, conhecidas as cidades e estradas existentes no país, e a cidade onde Juquinha e sua
família estão, encontre cada cidade (que não a cidade onde eles estão) que possa ser visitada por eles, dada
a restrição de que o Sr. Juca deseja pagar no máximo P pedágios (considerando apenas a viagem de ida).

Entrada:
A entrada é composta de vários conjuntos de teste. A primeira linha de um conjunto de teste contém quatro números
inteiros C (0 ≤ C ≤ 50), E (0 ≤ E ≤ 2500), L (0 ≤ L ≤ C) e P (0 ≤ P ≤ C). Os valores C e E indicam respectivamente
o número de cidades e o número de estradas existentes. As cidades são identificadas por inteiros de 1 a C.
Os valores L e P indicam, respectivamente, a cidade onde a família de Juquinha está no momento e o número máximo
de pedágios que o Sr. Juca está disposto a pagar. As E linhas seguintes contêm cada uma a informação de uma estrada,
representada por um par de números inteiros positivos X e Y (1 ≤ X,Y ≤ C), indicando que há uma estrada
(de sentido duplo) da cidade X para a cidade Y. O final da entrada é indicado por C = E = L = P = 0.

Saída:
Para cada conjunto de teste da entrada seu programa deve produzir três linhas na saída.
A primeira linha deve conter um identificador do conjunto de teste, no formato “Teste n”,
onde n é numerado a partir de 1.
Na segunda linha devem aparecer os identificadores das cidades que podem ser alcançadas,
em ordem crescente, separados por pelo menos um espaço em branco.
A terceira linha deve ser deixada em branco.
A grafia mostrada no Exemplo de Saída deve ser seguida rigorosamente.

Exemplo de Entrada:
5 4 2 1
1 2
2 3
3 4
4 5
9 12 1 2
2 1
1 5
2 1
3 2
9 3
3 4
4 8
4 7
7 6
5 6
4 5
3 7
0 0 0 0

Exemplo de Saída:
Teste 1
1 3

Teste 2
2 3 4 5 6
*/


struct vertex {
  int id;
  int color = 0; // 0 branco, 1 cinza, 2 preto
  int distance = 9999; // Mimetizando o infinito
  int predecessorId = -1;
};

struct graph {
  vector<std::vector<int>> adjList; // Lista de adjacência com IDs
  vector<vertex> vertexes; // Vetor com os dados de cada vértice
  int V; // Número de vértices (palitos)
  int E; // Número de arestas (relações)
};

void BFS(graph &G, int v, int frontierLimit) {
  G.vertexes[v].color = 1;
  G.vertexes[v].distance = 0;
  
  queue<int> Q;
  Q.push(v);

  vector<int> reachable; // Cidades alcançáveis

  while(!Q.empty()) {
    int u = Q.front();
    Q.pop();

    for (int w : G.adjList[u]) {
      int newDistance = G.vertexes[u].distance + 1;
      if (G.vertexes[w].color == 0 and newDistance <= frontierLimit) {
        G.vertexes[w].color = 1;
        G.vertexes[w].distance = newDistance;
        G.vertexes[w].predecessorId = u;
        Q.push(w);
        reachable.push_back(w);
      }
      G.vertexes[u].color = 2;
    }
  }

  sort(reachable.begin(), reachable.end());

  for (int city : reachable) {
    cout << city << " ";
  }
  cout << "\n\n";
}

int main () {
  // C cidades (vértices)
  // E estradas (arestas)
  // L onde Juquinha está (vértice raiz)
  // P pedágios máximos (saltos)
  int C, E, L, P;
  int test = 1;

  // lê cada conjunto de teste até 0 0 0 0
  while (cin >> C >> E >> L >> P && (C || E || L || P)) {
    graph G;
    G.V = C;
    G.E = E;

    // inicializa lista de adjacência e vértices
    G.adjList.resize(C + 1);
    G.vertexes.resize(C + 1);
    for (int i = 1; i <= C; i++) {
      G.vertexes[i].id = i;
    }

    // lê as E arestas (estradas)
    for (int i = 0; i < E; i++) {
      int X, Y; // Cidades (vértices) com ligação (aresta)
      cin >> X >> Y;

      G.adjList[X].push_back(Y);
      G.adjList[Y].push_back(X);
    }

    cout << "Teste " << test++ << "\n";
    BFS(G, L, P);
  }

  return 0;
}