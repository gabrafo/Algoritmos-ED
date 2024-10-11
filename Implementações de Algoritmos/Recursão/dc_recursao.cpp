// Exerício 4.2 do livro Entendendo Algoritmos: Escreva uma função recursiva que conte o número de itens em uma lista.

// Passo 1: caso-base é uma lista com zero ou um elemento, pois sabemos facilmente a sua quantidade de elementos.
// Passo 2: reduzir nossa lista até ela ter apenas um elemento, somando a quantidade de elementos atuais com a chamada recursiva até atingirmos o caso-base.

#include <iostream>
#include <list>

using namespace std;

int contaLista(list<int> lista){
    if(lista.empty()){ // Caso-base: lista vazia
        return 0;
    }
    lista.pop_back(); // Retira o último elemento da lista
    return 1 + contaLista(lista); // Caso recursivo: ainda há elementos a serem contados, soma 1 e chama a função novamente
}

int main(){
    list<int> lista = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << contaLista(lista) << endl;
    return 0;
}