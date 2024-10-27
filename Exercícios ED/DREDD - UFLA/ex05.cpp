/*
    MaxHeap, para alteração de prioridade
    by joukim & bruno, 2019
    alterado em 2023 by Renato
*/

/*
Entrada/saída:

10
r
Erro ao retirar raiz
p
Heap vazia!
i reception r 35 58 5
i cinema t 18 28 8
i galley c 180 200 1
i suiteA x 99 90 2
i suiteB x 33 50 5
i guestroom v 56 80 8
i mainSuite x 56 70 9
i lavatoryA n 32 56 7
i lavatoryB n 44 80 5
i laundry h 15 7 1
i entrance a 10 5 2
Erro ao inserir
p
[mainSuite/x/56/70/9] [lavatoryA/n/32/56/7] [cinema/t/18/28/8] [reception/r/35/58/5] [suiteB/x/33/50/5]
[galley/c/180/200/1] [guestroom/v/56/80/8] [suiteA/x/99/90/2] [lavatoryB/n/44/80/5] [laundry/h/15/7/1] 
a mainSuite 5
p
[cinema/t/18/28/8] [lavatoryA/n/32/56/7] [guestroom/v/56/80/8] [reception/r/35/58/5] [suiteB/x/33/50/5]
[galley/c/180/200/1] [mainSuite/x/56/70/5] [suiteA/x/99/90/2] [lavatoryB/n/44/80/5] [laundry/h/15/7/1] 
r
cinema
p
[guestroom/v/56/80/8] [lavatoryA/n/32/56/7] [mainSuite/x/56/70/5] [reception/r/35/58/5]
[suiteB/x/33/50/5] [galley/c/180/200/1] [laundry/h/15/7/1] [suiteA/x/99/90/2] [lavatoryB/n/44/80/5] 
f
*/

#include <iostream>
#include <utility> // para usar swap
#include <stdexcept> // para usar exceção com runtime_error

using namespace std;

struct dado {
    string nomeTarefa;
    char tipoTarefa;
    int energiaGasta;
    int tempoEstimado;
    int prioridade;
};

bool operator>(dado d1, dado d2) {
    return d1.prioridade > d2.prioridade;
}

bool operator<(dado d1, dado d2) {
    return d1.prioridade < d2.prioridade;
}

ostream& operator<<(ostream& output,const dado& d) {
    output << "[" << d.nomeTarefa << "/" << d.tipoTarefa << "/" << d.energiaGasta << "/" << d.tempoEstimado << "/" << d.prioridade <<"]"; 
    return output;
}

class MaxHeap {
private:
    dado* heap;
    int capacidade;
    int tamanho;
    inline int pai(int i);
    inline int esquerdo(int i);
    inline int direito(int i); 
    void corrigeDescendo(int i); 
    void corrigeSubindo(int i);

public:
    MaxHeap(int cap);
    ~MaxHeap();
    void imprime();
    dado retiraRaiz();
    void insere(dado d);
    void alteraPrioridade(string nomeTarefa, int novaPrioridade);
};

MaxHeap::MaxHeap(int cap){
    capacidade = cap;
    heap = new dado[cap];
    tamanho = 0;
}

MaxHeap::~MaxHeap(){
    delete[] heap;
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
    if(tamanho!=0){
        for(int i=0; i<tamanho; i++){
            cout << heap[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Heap vazia!" << endl;
    }
}

dado MaxHeap::retiraRaiz(){
    if(tamanho>0){
        dado aux = heap[0];
        swap(heap[0], heap[tamanho-1]);
        tamanho--; // Tem que decrementar o tamanho antes de corrigir o heap, para evitar problemas
        corrigeDescendo(0);
        return aux;
    }
    throw runtime_error("Erro ao retirar a raiz");
}

void MaxHeap::insere(dado d){
    if(tamanho==capacidade){
        throw runtime_error("Erro ao inserir");
    }

    heap[tamanho] = d;
    corrigeSubindo(tamanho);
    tamanho++;
}

void MaxHeap::alteraPrioridade(string nomeTarefa, int novaPrioridade){
    MaxHeap auxVetor(tamanho);
    dado elementoAtual;

    if(tamanho==0){
        return;
    }

    while (tamanho > 0) {
        elementoAtual = retiraRaiz();
        if (elementoAtual.nomeTarefa == nomeTarefa) {
            elementoAtual.prioridade = novaPrioridade;
        }
        auxVetor.insere(elementoAtual);
    }

    while(auxVetor.tamanho>0){
        insere(auxVetor.retiraRaiz());
    }
}

int main() {
    int capacidade;
    dado info;
    char comando;
    string nT;
    int nP;

    cin >> capacidade;
    MaxHeap meuHeap(capacidade);

    do {
        try {
            cin >> comando;
            switch (comando) {
                case 'i': // inserir
                    cin >> info.nomeTarefa >> info.tipoTarefa >> info.energiaGasta >> info.tempoEstimado >> info.prioridade;
                    meuHeap.insere(info);
                    break;
                case 'r': // remover
                    cout << meuHeap.retiraRaiz().nomeTarefa << endl;
                    break;
                case 'p': // limpar tudo
                    meuHeap.imprime();
                    break;
                case 'a':
                    cin>> nT >> nP;
                    meuHeap.alteraPrioridade(nT, nP);
                    break;
                case 'f': // finalizar
                    // checado no do-while
                    break;
                default:
                    cerr << "comando inválido\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (comando != 'f'); // finalizar execução
    return 0;
}