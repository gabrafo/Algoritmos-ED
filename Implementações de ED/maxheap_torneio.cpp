#include <iostream>
#include <cstdlib> // Para usar a função swap()
#include <cstring> // Para usar a função memcpy()

using namespace std;

typedef int Dado;
const int INVALIDO = -1; // Considerando um torneio só de valores positivos

// Nota: Implementação baseada nas videoaulas do Prof. Joaquim Quintero Uchôa.

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
        void imprime();
        void insere(Dado d);
};

Torneio::Torneio(int numFolhas){
    capacidade = 1;

    while(capacidade<numFolhas){
        capacidade *=2;
    }

    // Portência de 2 - 1 + tamanho do vetor
    capacidade = capacidade - 11 + numFolhas;

    heap = new Dado[capacidade];

    inicioDados = capacidade - numFolhas;

    cout << "inicioDados: " << inicioDados << endl;
    cout << "capacidade: " << capacidade << endl;

    for(int i = 0; i<capacidade; i++){
        heap[i] = INVALIDO;
    }
}

Torneio::Torneio(Dado vet[], int tam){
    capacidade = 1;

    while(capacidade<tam){
        capacidade *=2;
    }

    // Portência de 2 - 1 + tamanho do vetor
    capacidade = capacidade - 1 + tam;

    heap = new Dado[capacidade];
    inicioDados = capacidade - tam;

    cout << "inicioDados: " << inicioDados << endl;
    cout << "capacidade: " << capacidade << endl;

    memcpy(&heap[inicioDados], vet, tam*sizeof(Dado));

    tamanho = tam;
    arruma();
}

Torneio::~Torneio(){
    delete[] heap;
}

void Torneio::arruma(){
    cout << "arruma: " << inicioDados-1 << endl;
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
    
    cout << "copiaMaior" << endl;
    cout << "i: " << i << ", e: " << esq << ", d:" << dir << endl;

    int maior = INVALIDO;

    if(esq < capacidade){
        if((dir<capacidade) and (heap[dir] > heap[esq])){
            maior = dir;
        } else {
            maior = esq;
        }
        heap[i] = heap[maior];
    } else {
        heap[i] = INVALIDO;
    }
}

void Torneio::copiaSubindo(int i){
    int p = pai(i);
    if(heap[i]>heap[p]){
        heap[p] = heap[i];
        copiaSubindo(p);
    }
}

void Torneio::imprime(){
    for(int i=0; i<capacidade; i++){
        cout << heap[i] << " ";
    }
    cout << endl;
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

int main(){
    int tam = 9;
    Dado vet[] = {50,2,90,20,230,43,8,34,66};

    Torneio *h = new Torneio(vet, tam);

    cout << "IMPRIME!" << endl;
    h->imprime();
    delete h;

    cout << endl;

    tam = 13;
    int vet2[] = {50,2,90,20,230,43,8,34,66,100,110,3,13};
    h = new Torneio(vet2, tam);

    cout << "IMPRIME!" << endl;
    h->imprime();
    delete h;

    cout << endl;

    tam = 9;
    h = new Torneio(9);
    for(int i = 0; i<tam; i++){
        h->insere(vet[i]);
        h->imprime();
    }

    cout << "IMPRIME!" << endl;
    h->imprime();
    delete h;

    return 0;
}