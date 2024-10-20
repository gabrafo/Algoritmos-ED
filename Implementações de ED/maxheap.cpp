#include <iostream>
#include <cstdlib> // Para usar a função swap()
#include <cstring> // Para usar a função memcpy()

using namespace std;

typedef int Dado;

// Nota: Implementação baseada nas videoaulas do Prof. Joaquim Quintero Uchôa.

class MaxHeap{
    private:
        Dado* heap; // Vetor de dados
        int capacidade;
        int tamanho;

        // Funções auxiliares para posição do pai e dos filhos
        inline int pai(int i);
        inline int esquerdo(int i);
        inline int direito(int i);
        
        void arruma(); // Também chamada de heapify ou constroiHeap
        void corrigeDescendo(int i);
        void corrigeSubindo(int i);

    public:
        MaxHeap(int cap);
        MaxHeap(Dado vet[], int tam);
        ~MaxHeap();
        void imprime();
        Dado espiaRaiz();
        Dado retiraRaiz();
        void insere(Dado d);
};

MaxHeap::MaxHeap(int cap){
    capacidade = cap;
    heap = new Dado[cap];
    tamanho = 0;
}

MaxHeap::MaxHeap(Dado vet[], int tam){
    capacidade = tam;

    heap = new Dado[capacidade];

    memcpy(heap, vet, tam*sizeof(Dado));

    /*
    Outra forma de copiar os dados (sem o uso de memcpy):

    for(int i=0; i<tam; i++){
        heap[i] = vet[i];
    }

    OBS: Essa segunda maneira é menos eficiente.
    */

    tamanho = tam;
    arruma(); // Corrige o heap
}

MaxHeap::~MaxHeap(){
    delete[] heap;
}

void MaxHeap::arruma(){
    for(int i = (tamanho/2-1); i>=0; i--){ // O uso de tamanho/2-1 se dá pelo fato de estarmos iniciando o heap em 0
        corrigeDescendo(i);
    }
}

int MaxHeap::pai(int i){
    if(i==0){
        return 0;
    }
    return (i-1)/2;
}

int MaxHeap::esquerdo(int i){
    return 2*i+1;
}

int MaxHeap::direito(int i){
    return 2*i+2;
}

void MaxHeap::corrigeDescendo(int i){
    int esq = esquerdo(i);
    int dir = direito(i);
    int maior = i;

    if((esq<tamanho) and (heap[esq]>heap[maior])){
        maior = esq;
    }

    if((dir<tamanho) and (heap[dir]>heap[maior])){
        maior = dir;
    }

    if(maior!=i){
        swap(heap[i], heap[maior]);
        corrigeDescendo(maior);
    }
}

void MaxHeap::corrigeSubindo(int i){
    int p = pai(i);
    if(heap[i]>heap[p]){
        swap(heap[i], heap[p]);
        corrigeSubindo(p);
    }
}

void MaxHeap::imprime(){
    for(int i=0; i<tamanho; i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}

Dado MaxHeap::espiaRaiz(){
    return heap[0];
}

Dado MaxHeap::retiraRaiz(){
    if(tamanho==0){
        cerr << "Erro ao retirar a raíz" << endl;
        exit(EXIT_FAILURE);
    }
    Dado aux = heap[0];
    swap(heap[0], heap[tamanho-1]);
    tamanho--; // Tem que decrementar o tamanho antes de corrigir o heap, para evitar problemas
    corrigeDescendo(0);
    return aux;
}

void MaxHeap::insere(Dado d){
    if(tamanho==capacidade){
    cerr << "Erro ao inserir elemento" << endl;
    exit(EXIT_FAILURE);
    }

    heap[tamanho] = d;
    corrigeSubindo(tamanho);
    tamanho++;
}

int main(){
    int tam = 10;
    Dado vet[] = {13,55,98,12,1,92,17,44,65,77};

    MaxHeap *h = new MaxHeap(vet, tam);

    for(int i=0; i<tam; i++){
        cout << h->retiraRaiz() << " ";
    }
    cout << endl;

    for(int i=0; i<tam; i++){
        h->insere(vet[i]);
    }

    h->imprime();

    return 0;
}