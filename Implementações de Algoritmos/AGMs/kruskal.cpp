#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> ii; // pares de inteiros
typedef vector<int> vi; // vetor de inteiros

/* Implementação da ED baseada em um código disponibilizada pelo Prof. Mayron aos alunos da disciplina de Grafos */
class UnionFindDisjointSet 
  {
  public:
    UnionFindDisjointSet(int numConjDisjuntos) {
      rank.assign(numConjDisjuntos, 0);
      pai.assign(numConjDisjuntos, 0);
      for(int elemento = 0; elemento < numConjDisjuntos; elemento++)
        pai[elemento] = elemento;
    }

    /* Dado um elemento do conjunto, busca-se seu pai no conjunto disjunto e o 
    * atualiza (se necessário) para o ancestral de maior nivel na arvore.
    *
    * Parametros
    * elemento: identificacao do elemento cujo o conjunto sera buscado.
    */
    int buscaPai(int elemento) {
      // Se o elemento é o próprio pai, ele é o representante (raiz) do conjunto
      if (pai[elemento] == elemento)
        return elemento;

      // Atualiza o pai do elemento para o ancestral mais alto (raiz),
      // tornando futuras buscas mais rápidas
      pai[elemento] = buscaPai(pai[elemento]);
      
      return pai[elemento];
    }

    /* Dado dois elementos do conjunto, verifica-se se esses elementos possuem o
    * o mesmo pai na floresta disjunta.
    *
    * Parametros
    * elemento1: um elemento qualquer.
    * elemento2: um elemento qualquer.
    */
    bool mesmoConjunto(int elemento1, int elemento2)
    {
        return buscaPai(elemento1) == buscaPai(elemento2); // Mesma raiz do conjunto
    }

    /* Dados dois elementos, une os seus respectivos conjuntos considerando o rank 
    * de maior valor (em caso de empate, o elemento de maio indice)
    *
    * Parametros
    * elemnento1: um elemento qualquer.
    * elemento2: um elemento qualquer.
    */
    void uniao(int elemento1, int elemento2)
    {
        if(!mesmoConjunto(elemento1, elemento2))
        {
            int paiConjunto1 = buscaPai(elemento1);
            int paiConjunto2 = buscaPai(elemento2);
        
            // Se o rank do pai do conjunto 1 for maior que o do pai do conjunto 2, atualizamos o pai do conjunto 2 como sendo o pai do conjunto 1
            if(rank[paiConjunto1] > rank[paiConjunto2])
                pai[paiConjunto2] = paiConjunto1;
        
            // Caso contrário, o conjunto 2 se torna o pai do conjunto 1
            else {
                pai[paiConjunto1] = paiConjunto2;

                // Se os ranks forem iguais, o novo pai ganha +1 de rank
                if(rank[paiConjunto1] == rank[paiConjunto2])
                    rank[paiConjunto2]++;
            }
        }
    }

    /* Imprime as informacoes de quais os elementos estao em cada conjunto.
    * Apresenta-se tambem o rank de cada elemento
    *
    * Parametros
    * pai: vetor que armazena os pais de cada vertice no conjunto disjunto.
    * rank: vetor que armazena o rank de cada elemento do conjunto.
    * n: numero de elementos no conjunto
    */
    friend ostream &operator<<(ostream& saida, const UnionFindDisjointSet& conjunto)
    {
        for(int elemento = 0; elemento < conjunto.pai.size(); elemento++)
          saida << elemento << ": pai(" << conjunto.pai[elemento] << "), rank(" << conjunto.rank[elemento] << ")";
        return saida;
    }

  private:
    // vetor que armazena os pais de cada vertice no conjunto disjunto
    vi pai;

    // vetor que armazena o rank de cada elemento do conjunto
    vi rank;
};

/*
 * Função: kruskal
 * ----------------
 * Implementa o algoritmo de Kruskal para encontrar o custo da Árvore Geradora Mínima (AGM)
 * de um grafo ponderado, utilizando a estrutura Union-Find (Disjoint Set Union - DSU).
 *
 * O algoritmo segue uma abordagem gulosa:
 *   1. Ordena todas as arestas pelo peso (menor para maior);
 *   2. Percorre as arestas em ordem crescente;
 *   3. Adiciona uma aresta à árvore apenas se ela não formar ciclo;
 *   4. O processo termina quando n-1 arestas forem adicionadas.
 *
 * Complexidade:
 *   - Ordenação das arestas: O(m log m)
 *   - Operações de união e busca (com compressão de caminho): O(α(n)) ≈ O(1)
 *   - Complexidade total: O(m log m)
 *
 * Parâmetros:
 *   arestas - vetor de arestas, onde cada aresta é representada como:
 *              (peso, (u, v))
 *   n        - número de vértices do grafo
 *   m        - número de arestas do grafo
 *
 * Retorno:
 *   Retorna o custo total da árvore geradora mínima (soma dos pesos das arestas escolhidas).
 */
int kruskal(vector<pair<int, ii>>& arestas, int n, int m) {
  // Passo 1: Ordena as arestas pelo peso (menor → maior)
  sort(arestas.begin(), arestas.end());

  // Variável que armazenará o custo total da AGM
  int resultado = 0;

  // Cria uma estrutura Union-Find com n elementos (vértices)
  UnionFindDisjointSet ufds(n);

  int u, v;
  pair<int, ii> e; // Aresta representada como (peso, (u, v))

  int i = 0;                      // índice para percorrer as arestas
  int numeroArestas = 0;          // quantas arestas já foram incluídas na AGM
  bool numeroArestasMax = false;  // variável sentinela → indica se já temos n-1 arestas


  // Passo 2: enquanto houver arestas e a AGM ainda não estiver completa
  while (i < m && !numeroArestasMax) {
    e = arestas[i];
    u = e.second.first;
    v = e.second.second;

    // Se os vértices pertencem a conjuntos diferentes, adiciona a aresta
    if (!ufds.mesmoConjunto(u, v)) {
      resultado += e.first;   // soma o peso
      numeroArestas++;        // mais uma aresta na árvore
      ufds.uniao(u, v);       // une os conjuntos

      // Se já temos n - 1 arestas, atingimos o limite da AGM
      if (numeroArestas == n - 1)
        numeroArestasMax = true;
    }

    // passa para a próxima aresta
    i++;
  }

  // Retorna o custo total da Árvore Geradora Mínima
  return resultado;
}
