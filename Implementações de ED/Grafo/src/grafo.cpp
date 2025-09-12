#include "grafo.hpp"

Vertice::Vertice() {
    cor = Cor::BRANCO;
    tempoDescoberta = 0;
    tempoFechamento = 0;
    predecessor = -1; // Equivalente a NIL
    // listaAdj é inicializada como um vetor vazio por padrão
}

void Vertice::setCor(Cor novaCor) { cor = novaCor; }
Cor Vertice::getCor() const { return cor; }

void Vertice::setTempoDescoberta(int tempo) { tempoDescoberta = tempo; }
int Vertice::getTempoDescoberta() const { return tempoDescoberta; }

void Vertice::setTempoFechamento(int tempo) { tempoFechamento = tempo; }
int Vertice::getTempoFechamento() const { return tempoFechamento; }

void Vertice::setPredecessor(int p) { predecessor = p; }
int Vertice::getPredecessor() const { return predecessor; }

void Vertice::adicionarVizinho(int v) {
    listaAdj.push_back(v);
}
const vector<int>& Vertice::obterVizinhos() const {
    return listaAdj;
}

Grafo::Grafo(int v) {
    if (v <= 0) {
        throw std::invalid_argument("O número de vértices deve ser positivo.");
    }
    qntVertices = v;
    qntLigacoes = 0;
    vertices.resize(qntVertices); // Redimensiona o vetor principal de vértices
}

void Grafo::adicionarAresta(int v, int w) {
    // Verifica se os vértices de origem e destino são válidos
    if (v >= 0 and v < qntVertices and w >= 0 and w < qntVertices) {
        // Acessa o objeto Vertice de origem e adiciona o vizinho
        vertices[v].adicionarVizinho(w);
        qntLigacoes++;
    }
}

const vector<int>& Grafo::obterVizinhos(int v) const {
    // Verifica se o índice do vértice é válido
    if (v < 0 or v >= qntVertices) {
        throw std::out_of_range("Índice de vértice inválido.");
    }
    // Acessa o objeto Vertice e retorna sua lista de vizinhos
    return vertices[v].obterVizinhos();
}