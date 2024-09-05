// Exerício 4.2 do livro Entendendo Algoritmos: Encontre o valor mais alto em uma lista.

// Passo 1: caso-base é uma lista com um elemento, pois sabemos facilmente que ele é o maior.
// Passo 2: reduzir nossa lista até ela ter apenas um elemento, retirando os elementos menores.

#include <iostream>
#include <list>

using namespace std;

int maiorValor(list<int> lista){
    // Caso-base: lista com 1 elemento
    if(lista.size() == 1){
        return lista.front();
    }

    // Caso recursivo: checa o primeiro elemento com o último, caso o primeiro seja maior, elimina o último e chama novamente a função
    if(lista.front() >= lista.back()){
        lista.pop_back();
        return maiorValor(lista);
    }

    // Caso recursivo: checa o último elemento com o primeiro, caso o último seja maior, elimina o primeiro e chama novamente a função
    lista.pop_front();
    return maiorValor(lista);
}

int main(){
    list<int> lista = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << maiorValor(lista) << endl;
    return 0;
}

// OBS: Caso conheça uma melhor maneira de resolver esses problemas, sinta-se a vontade para enviar um pull request. A única coisa que peço
// é que se mantenha no escopo do material original (o livro).