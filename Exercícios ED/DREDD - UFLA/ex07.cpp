// Torneio, mas a cada etapa, o elemento vencedor irá para a próxima etapa com o seu valor reduzido do valor do oponente.

// Entrada:
// - Número de participantes
// - Valores de cada participante

// Saída:
// - Valor inicial do campeão

// Exemplo de Entrada:
// 8
// 2 7 4 1 3 9 6 8
// Exemplo de Saída:
// 9

// Exemplo de Entrada:
// 13
// 11 5 3 4 2 15 7 9 10 8 12 6 13
// Exemplo de Saída:
// 13

// Nota: Esse é um programa baseado em um exercício da disciplina de Estruturas de Dados da Universidade Federal de Lavras.

#include <iostream>
#include <cstdlib> // Para usar a função swap()
#include <cstring> // Para usar a função memcpy()

using namespace std;

const int INVALIDO = -1; // Considerando um torneio só de valores positivos

struct Dado {
    int id;
    int valAtual;
};

bool operator>(Dado d1, Dado d2) {
    if(d1.valAtual == d2.valAtual){
        return d1.id > d2.id;
    }
    return d1.valAtual > d2.valAtual;
}

bool operator<(Dado d1, Dado d2) {
    if(d1.valAtual == d2.valAtual){
        return d1.id < d2.id;
    }
    return d1.valAtual < d2.valAtual;
}

class Torneio{
    private:
        Dado* heap; // Vetor de dados
        int capacidade;
        int tamanho;
        int inicioDados; // Primeiro nó folha da árvore

        // Funções auxiliares para posição do pai e dos filhos
        inline int pai(int i);
        inline int esquerdo(int i);
        inline int direito(int i);
        
        void arruma(); // Também chamada de heapify ou constroiHeap
        void copiaMaior(int i);
        void copiaSubindo(int i);

    public:
        Torneio(int numFolhas);
        Torneio(Dado vet[], int tam);
        ~Torneio();
        void insere(Dado d);
        void exibeVencedor();
};

Torneio::Torneio(int numFolhas){
    capacidade = 1;

    while(capacidade<numFolhas){
        capacidade *=2;
    }

    // Potência de 2 - 1 + tamanho do vetor
    capacidade = capacidade - 1 + numFolhas;

    heap = new Dado[capacidade];

    inicioDados = capacidade - numFolhas;

    for(int i = 0; i<capacidade; i++){
        heap[i].id = INVALIDO;
        heap[i].valAtual = INVALIDO;
    }
}

Torneio::Torneio(Dado vet[], int tam){
    capacidade = 1;

    while(capacidade<tam){
        capacidade *=2;
    }

    // Potência de 2 - 1 + tamanho do vetor
    capacidade = capacidade - 1 + tam;

    heap = new Dado[capacidade];
    inicioDados = capacidade - tam;

    memcpy(&heap[inicioDados], vet, tam*sizeof(Dado));

    tamanho = tam;
    arruma();
}

Torneio::~Torneio(){
    delete[] heap;
}

void Torneio::arruma(){
    for(int i = inicioDados-1; i>=0; i--){
        copiaMaior(i);
    }
}

int Torneio::pai(int i){
    if(i==0){
        return 0;
    }
    return (i-1)/2;
}

int Torneio::esquerdo(int i){
    return 2*i+1;
}

int Torneio::direito(int i){
    return 2*i+2;
}

void Torneio::copiaMaior(int i){
    int esq = esquerdo(i);
    int dir = direito(i);

    int menor = INVALIDO;
    int maior = INVALIDO;

    if(esq < capacidade){
        if((dir<capacidade) and (heap[dir] > heap[esq])){
            maior = dir;
            menor = esq;
        } else {
            maior = esq;
            menor = dir;
        }

        // O valor atual do elemento vencedor é a subtração entre o valor atual do competidor maior e menor.
        heap[i].valAtual = heap[maior].valAtual-heap[menor].valAtual;

        // O valor do ID do vencedor é o mesmo do maior.
        heap[i].id = heap[maior].id;
    } else {
        heap[i].valAtual = INVALIDO;
    }
}

// !!!
// OBS: Essa função, especificamente, talvez não se adeque ao exercício! Não a modifiquei, por não ser necessária para a resolução.
// Portanto, atenção ao utilizar a construção do Heap por inserção.
void Torneio::copiaSubindo(int i){
    int p = pai(i);
    if(heap[i]>heap[p]){
        heap[p] = heap[i];
        copiaSubindo(p);
    }
}

void Torneio::insere(Dado d){
    if(tamanho==capacidade){
        cerr << "Erro ao inserir elemento" << endl;
        exit(EXIT_FAILURE);
    }

    heap[tamanho + inicioDados] = d;
    copiaSubindo(tamanho + inicioDados);
    tamanho++;
}

void Torneio::exibeVencedor(){
    cout << heap[0].id << endl;
}

int main(){
    unsigned int tam;
    cin >> tam;
    Dado vetor[tam];

    for(unsigned int i = 0; i<tam; i++){
        cin >> vetor[i].id;
        vetor[i].valAtual = vetor[i].id;
    }

    Torneio torneio = Torneio(vetor, tam);
    torneio.exibeVencedor();

    return 0;
}