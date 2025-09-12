#pragma once

#include <stdexcept>
#include <vector>

using namespace std;

enum class Cor {
    BRANCO,
    CINZA,
    PRETO
};

class Vertice {
private:
    int id; // Identificação do vértice
    Cor cor;
    int tempoDescoberta;
    int tempoFechamento;
    int predecessor; 
    vector<int> listaAdj;

public:
   Vertice();

    void setCor(Cor novaCor);
    Cor getCor() const;

    void setTempoDescoberta(int tempo);
    int getTempoDescoberta() const;

    void setTempoFechamento(int tempo);
    int getTempoFechamento() const;

    void setPredecessor(int p);
    int getPredecessor() const;

    void adicionarVizinho(int v);
    const vector<int>& obterVizinhos() const;
};

class Grafo {
private:
  int qntVertices;
  int qntLigacoes;

public:
  Grafo(int v);
  vector<Vertice> vertices;
  void adicionarAresta(int v, int w);
  const vector<int>& obterVizinhos(int v) const;
};