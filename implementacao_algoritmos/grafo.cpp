#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <deque> // Double ended queue
#include <unordered_set> // Para rastrear nós visitados
#include <algorithm>

using namespace std;

struct Vizinho{
    string nome;
    bool vendeManga;

    bool operator==(const Vizinho& outro) const {
        return this->nome == outro.nome; // Compara os nomes dos objetos para dizer se são iguais ou não
    }
};

// Função para imprimir o estado atual da fila
void imprimirFila(const deque<Vizinho>& fila) {
    cout << "Estado atual da fila: ";
    for (const Vizinho& vizinho : fila) {
        cout << vizinho.nome << ", ";
    }
    cout << endl;
}

bool filaDePesquisa(unordered_map<string, vector<Vizinho>> grafo){
    deque<Vizinho> fila;
    unordered_set<string> visitados;

    // Adiciona todos os vizinhos do nó inicial à fila
    if (grafo.find("voce") != grafo.end()) {
        for (const Vizinho& vizinho : grafo.at("voce")) {
            fila.push_back(vizinho);
        }
    }

    while(!fila.empty()){

        imprimirFila(fila);

        Vizinho vizinhoAtual = fila.front();
        fila.pop_front();

        // Verifica se o vizinho já foi visitado
        if (visitados.find(vizinhoAtual.nome) == visitados.end()) {
            visitados.insert(vizinhoAtual.nome); // Marca como visitado

            if (vizinhoAtual.vendeManga) {
                cout << "Vizinho que vende manga mais próximo: " << vizinhoAtual.nome << endl;
                return true; // Encontra o primeiro vizinho que vende manga
            }

            // Adiciona os vizinhos do vizinho atual à fila
            if (grafo.find(vizinhoAtual.nome) != grafo.end()) {
                for (const Vizinho& proximosVizinhos : grafo.at(vizinhoAtual.nome)) {
                    // Adiciona vizinhos não visitados à fila
                    if (find(fila.begin(), fila.end(), proximosVizinhos) == fila.end()) {
                        fila.push_back(proximosVizinhos);
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    // Criando o grafo como uma tabela hash (ou mapa) onde cada chave aponta para um vetor de vizinhos (valor)
    unordered_map<string, vector<Vizinho>> grafo; // Grafo é uma tabela hash: String (chave), Vetor dinâmico da estrutura Vizinho (valor) 

    // Adicionando vértices e suas arestas
    grafo["voce"] = {{"alice", false}, {"bob", false}, {"claire", false}};
    grafo["bob"] = {{"anuj", false}, {"peggy", false}};
    grafo["alice"] = {{"peggy", false}};
    grafo["claire"] = {{"thom", true}, {"jonny", false}};
    grafo["anuj"] = {};
    grafo["peggy"] = {};
    grafo["thom"] = {};
    grafo["jonny"] = {};

    filaDePesquisa(grafo);

    return 0;
}