// Passo 1: caso-base é o vetor com apenas um/nenhum elemento, pois já está ordenado.
// Passo 2: reduzir nossa lista até ela ter apenas um elemento, somando a quantidade de elementos atuais com a chamada recursiva até atingirmos o caso-base.

#include <iostream>
#include <vector> // Facilitar a manipulação de elementos, com vetores estáticos eu tinha que realocar constantemente a memória
#include <chrono>  // Para medir o tempo
#include <algorithm> // Para usar std::sort e std::shuffle
#include <random>    // Para shuffle
using namespace std;
using namespace std::chrono;

// Usa o elemento mediano como pivô.
void quicksort(vector<int>& vetor, int inicio, int fim) {
    if (inicio >= fim) return; // Caso-base: percorreu todos os elementos do vetor.

    // Caso recursivo: ainda há elementos a serem ordenados.
    int pivo = vetor[(inicio + fim) / 2];
    int i = inicio, j = fim;

    // Particionamento in-place
    while (i <= j) {
        while (vetor[i] < pivo) i++;
        while (vetor[j] > pivo) j--;
        if (i <= j) {
            swap(vetor[i], vetor[j]);
            i++;
            j--;
        }
    }

    quicksort(vetor, inicio, j);
    quicksort(vetor, i, fim);
}

// Usa o primeiro elemento como pivô.
void quicksort_pior(vector<int>& vetor, int inicio, int fim) {
    if (inicio >= fim) return;

    int pivo = vetor[(inicio)];
    int i = inicio, j = fim;

    // Particionamento in-place
    while (i <= j) {
        while (vetor[i] < pivo) i++;
        while (vetor[j] > pivo) j--;
        if (i <= j) {
            swap(vetor[i], vetor[j]);
            i++;
            j--;
        }
    }

    // Recursão nas subpartes
    quicksort_pior(vetor, inicio, j);
    quicksort_pior(vetor, i, fim);
}

int main(){

    const size_t TAMANHO_VETOR = 100000; // Tamanho ajustável

    // Vetor aleatório
    vector<int> vetor(TAMANHO_VETOR);
    srand(static_cast<unsigned>(time(0)));

    for (size_t i = 0; i < TAMANHO_VETOR; i++) {
        vetor[i] = rand() % 100000;
    }

    // Simulando o pior caso (vetor ordenado): O(n²)
    cout << "PIOR CASO" << endl;
    vector<int> vetorPiorCaso = vetor;
    sort(vetorPiorCaso.begin(), vetorPiorCaso.end()); // Ordena para simular o pior caso
    auto inicio = high_resolution_clock::now();
    quicksort_pior(vetorPiorCaso, 0, vetorPiorCaso.size() - 1);
    auto fim = high_resolution_clock::now();
    auto duracao = duration_cast<milliseconds>(fim - inicio);
    cout << "Tempo de execução pior caso: " << duracao.count() << " ms" << endl << endl;

    // Simulando o melhor caso (vetor aleatório): O(n log n)
    cout << "MELHOR CASO" << endl;
    vector<int> vetorMelhorCaso = vetor;
    auto rng = default_random_engine{};
    shuffle(vetorMelhorCaso.begin(), vetorMelhorCaso.end(), rng); // Aleatoriza para simular o melhor caso
    inicio = high_resolution_clock::now();
    quicksort(vetorMelhorCaso, 0, vetorMelhorCaso.size() - 1);
    fim = high_resolution_clock::now();
    duracao = duration_cast<milliseconds>(fim - inicio);
    cout << "Tempo de execução melhor caso: " << duracao.count() << " ms" << endl;

    return 0;
}

// OBS: Caso conheça uma melhor maneira de constituir esse algoritmo, sinta-se a vontade para enviar um pull request e contribuir com outra solução.