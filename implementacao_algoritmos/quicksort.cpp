// Passo 1: caso-base é o vetor com apenas um/nenhum elemento, pois já está ordenado.
// Passo 2: reduzir nossa lista até ela ter apenas um elemento, somando a quantidade de elementos atuais com a chamada recursiva até atingirmos o caso-base.

#include <iostream>
using namespace std;

// Função para realocar memória dinamicamente
void realocaVetor(int*& vetor, int& cap, int tamanho) {
    cap += 1;
    int* novoVetor = new int[cap];
    for (int i = 0; i < tamanho; i++) {
        novoVetor[i] = vetor[i];
    }
    delete[] vetor;
    vetor = novoVetor;
}

void qsort(int vetor[], int tamanho){

    // Caso-base: array menor que dois elementos.
    if(tamanho<2){
        return;
    }

    // A partir daqui estamos no caso recursivo (quando ainda há elementos a serem ordenados).
    int pivo = vetor[0];

    // Vetor para menores que o pivo
    int capMenores = 1;
    int* menoresQuePivo = new int[capMenores];
    int indiceSubarrayMenores = 0;

    // Vetor para maiores que o pivo
    int capMaiores = 1;
    int* maioresQuePivo = new int[capMaiores];
    int indiceSubarrayMaiores = 0;

    // Montando os vetores maiores/menores
    for(int i = 1; i < tamanho; i++){
        if(vetor[i] < pivo){
            if(indiceSubarrayMenores == capMenores) {
                realocaVetor(menoresQuePivo, capMenores, indiceSubarrayMenores + 1);
            }
            menoresQuePivo[indiceSubarrayMenores++] = vetor[i];
        } else {
            if(indiceSubarrayMaiores == capMaiores) {
                realocaVetor(maioresQuePivo, capMaiores, indiceSubarrayMaiores + 1);
            }
            maioresQuePivo[indiceSubarrayMaiores++] = vetor[i];
        }
    }

    qsort(menoresQuePivo, indiceSubarrayMenores);
    qsort(maioresQuePivo, indiceSubarrayMaiores);

    int indiceVetorOriginal = 0;
    for(int i = 0; i < indiceSubarrayMenores; i++) {
        vetor[indiceVetorOriginal++] = menoresQuePivo[i];
    }

    vetor[indiceVetorOriginal++] = pivo;
    for(int i = 0; i < indiceSubarrayMaiores; i++) {
        vetor[indiceVetorOriginal++] = maioresQuePivo[i];
    }

    delete[] menoresQuePivo;
    delete[] maioresQuePivo;
}

int main(){
    int vetor[] = {3, 7, 1, 4, 2, 9};
    qsort(vetor, 6);
    for(int i = 0; i<6; i++){
        cout << vetor[i] << endl;
    }

    return 0;
}

// OBS: Caso conheça uma melhor maneira de constituir esse algoritmo, sinta-se a vontade para enviar um pull request e contribuir com outra solução.