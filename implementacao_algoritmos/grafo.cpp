#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Criando o grafo como uma tabela hash (ou mapa) onde cada chave aponta para um vetor de vizinhos (valor)
    unordered_map<string, vector<string>> grafo; // Grafo é uma tabela hash: String (chave), Vetor dinâmico de Strings (valor) 

    // Adicionando vértices e suas arestas
    grafo["voce"] = {"alice", "bob", "claire"};
    grafo["bob"] = {"anuj", "peggy"};
    grafo["alice"] = {"peggy"};
    grafo["claire"] = {"thom", "jonny"};
    grafo["anuj"] = {};
    grafo["peggy"] = {};
    grafo["thom"] = {};
    grafo["jonny"] = {};

    // Acessando os vizinhos de "voce"
    cout << "Vizinhos de 'voce': ";
    for (const string& vizinho : grafo["voce"]) { // Uso de & para previnir cópias (consumiria muita memória por se tratar de Strings)
        cout << vizinho << " ";
    }
    cout << endl;

    return 0;
}