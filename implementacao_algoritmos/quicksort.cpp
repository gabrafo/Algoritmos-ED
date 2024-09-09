// Passo 1: caso-base é o vetor com apenas um/nenhum elemento, pois já está ordenado.
// Passo 2: reduzir nossa lista até ela ter apenas um elemento, somando a quantidade de elementos atuais com a chamada recursiva até atingirmos o caso-base.

#include <iostream>
#include <vector> // Facilitar a manipulação de elementos, com vetores estáticos eu tinha que realocar constantemente a memória
#include <chrono>  // Para medir o tempo
using namespace std;
using namespace std::chrono;

// Complexidade: O(n log n), MELHOR CASO.
void qsort_melhor(vector<int>& vetor){

    if (vetor.size() < 2) {
        return;
    }

    int baixo = 0;
    int alto = vetor.size()-1;
    int meio = (baixo+alto)/2;

    // Pivô é o elemento central
    int pivo = vetor[meio];

    vector<int> menoresQuePivo;
    vector<int> maioresQuePivo;

    for (size_t i = 0; i < vetor.size(); i++) { // Usando size_t para não dar aviso
        if (vetor[i] < pivo) {
            menoresQuePivo.push_back(vetor[i]);
        } else if (vetor[i] > pivo) {
            maioresQuePivo.push_back(vetor[i]);
        }
    }

    qsort_melhor(menoresQuePivo);
    qsort_melhor(maioresQuePivo);

    size_t indiceVetorOriginal = 0;

    for (size_t i = 0; i < menoresQuePivo.size(); i++) {
        vetor[indiceVetorOriginal++] = menoresQuePivo[i];
    }

    vetor[indiceVetorOriginal++] = pivo;

    for (size_t i = 0; i < maioresQuePivo.size(); i++) {
        vetor[indiceVetorOriginal++] = maioresQuePivo[i];
    }
}

// Complexidade: O(n²), PIOR CASO.
void qsort_pior(vector<int>& vetor) {
    // Caso-base: array com menos de dois elementos.
    if (vetor.size() < 2) {
        return;
    }

    // Escolhendo o pivô como o primeiro elemento.
    int pivo = vetor[0];

    vector<int> menoresQuePivo;
    vector<int> maioresQuePivo;

    for (size_t i = 1; i < vetor.size(); i++) { // Usando size_t para não dar aviso
        if (vetor[i] < pivo) {
            menoresQuePivo.push_back(vetor[i]);  // Adiciona ao vetor de menores.
        } else {
            maioresQuePivo.push_back(vetor[i]);  // Adiciona ao vetor de maiores.
        }
    }

    qsort_pior(menoresQuePivo);
    qsort_pior(maioresQuePivo);

    // Reunindo as partes no vetor original.
    size_t indiceVetorOriginal = 0;
    
    for (size_t i = 0; i < menoresQuePivo.size(); i++) {
        vetor[indiceVetorOriginal++] = menoresQuePivo[i];
    }

    // Evita duplicar o pivô se houver elementos iguais
    if (vetor.size() > 0 && vetor[0] != pivo) {
        vetor[indiceVetorOriginal++] = pivo;
    }

    for (size_t i = 0; i < maioresQuePivo.size(); i++) {
        vetor[indiceVetorOriginal++] = maioresQuePivo[i];
    }
}

int main(){

    const size_t TAMANHO_VETOR = 1000000; // Você pode ajustar o tamanho aqui

    // Gerando um vetor com números aleatórios
    vector<int> vetor(TAMANHO_VETOR);
    srand(static_cast<unsigned>(time(0))); // Inicializa o gerador de números aleatórios

    cout << "PIOR CASO" << endl;
    for (size_t i = 0; i < TAMANHO_VETOR; i++) {
        vetor[i] = rand() % 100000; // Preenche com números aleatórios entre 0 e 99999
    }

    auto inicio = high_resolution_clock::now();
    qsort_pior(vetor);
    auto fim = high_resolution_clock::now();
    auto duracao = duration_cast<milliseconds>(fim - inicio);

    // Exibindo o tempo de execução
    cout << "Tempo de execução pior caso: " << duracao.count() << " ms" << endl << endl;

    cout << "MELHOR CASO" << endl;
    vector<int> vetor2(TAMANHO_VETOR);
    for (size_t i = 0; i < TAMANHO_VETOR; i++) {   
        vetor2[i] = rand() % 100000; // Preenche com números aleatórios entre 0 e 99999
    }
    inicio = high_resolution_clock::now();
    qsort_melhor(vetor2);
    fim = high_resolution_clock::now();
    duracao = duration_cast<milliseconds>(fim - inicio);

    cout << "Tempo de execução melhor caso: " << duracao.count() << " ms" << endl;

    return 0;
}

// OBS: Caso conheça uma melhor maneira de constituir esse algoritmo, sinta-se a vontade para enviar um pull request e contribuir com outra solução.