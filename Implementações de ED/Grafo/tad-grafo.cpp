#include <iostream>
#include "include/grafo.hpp"

// Rodando com GCC = g++ -Wall tad-grafo.cpp src/grafo.cpp -Iinclude -o tad-grafo

int main() {
    cout << "Exemplificando TAD de grafo...\n";

    try {
        Grafo g(6);
        
        g.adicionarAresta(0, 1);
        g.adicionarAresta(1, 2);
        g.adicionarAresta(2, 3);
        
        cout << "Vizinhos do vértice 1: ";
        for (int vizinho : g.obterVizinhos(1)) {
            cout << vizinho << " ";
        }
        cout << endl;

    } catch (const exception& e) {
        cerr << "Ocorreu um erro: " << e.what() << endl;
    }

    return 0;
}