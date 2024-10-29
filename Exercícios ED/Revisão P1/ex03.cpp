// Nota: Esse é um programa baseado em um exercício da disciplina de Estruturas de Dados da Universidade Federal de Lavras. Está sendo utilizado
// apenas para a minha revisão para a primeira prova do semestre, e parte de sua implementação não foi feita por mim, e sim por quem organizou
// esse exercício, que não é de minha autoria.

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct dado{
	char operacao;
	int prioridade;
};

class MaxHeap {
    private:
        dado* heap;
        int capacidade;
        int tamanho;
        inline int pai(int i);
        inline int esquerdo(int i);
        inline int direito(int i); 
        void arruma(); // heapify()
        void corrigeDescendo(int i); 
        void corrigeSubindo(int i);

    public:
        MaxHeap(int cap);
        ~MaxHeap();
        void imprime();
        dado retiraRaiz();
        void insere(dado d);
        void alteraPrioridade(char operacaoBuscada, int novaPrioridade);
};

MaxHeap::MaxHeap(int cap) {
    capacidade = cap;
    heap = new dado[cap];
    tamanho = 0;
}

MaxHeap::~MaxHeap() {
    delete[] heap;    
}

void MaxHeap::arruma() {
    for (int i=(tamanho/2-1); i>=0; i--) {
        corrigeDescendo(i);
    }
}

int MaxHeap::pai(int i) {
    return (i-1)/2;
}
    
int MaxHeap::esquerdo(int i) {
    return 2*i+1;
}
    
int MaxHeap::direito(int i) {
    return 2*i+2;
}
    
void MaxHeap::corrigeDescendo(int i) {
    int esq = esquerdo(i);
    int dir = direito(i);
    int maior = i;
    
    if ((esq < tamanho) and (heap[esq].prioridade > heap[maior].prioridade)) {
        maior = esq;
    } 
    
    if ((dir < tamanho) and (heap[dir].prioridade > heap[maior].prioridade)) {
        maior = dir;
    }
    
    if (maior!=i) {
        swap(heap[i], heap[maior]);
        corrigeDescendo(maior);
    }
}

void MaxHeap::corrigeSubindo(int i) {
    int p = pai(i);
    if (heap[i].prioridade > heap[p].prioridade) {
        swap(heap[i],heap[p]);
        corrigeSubindo(p);
    }
}
        
void MaxHeap::imprime() {
    for (int i=0; i<capacidade; i++) {
        cout << heap[i].operacao << " " << heap[i].prioridade<<endl;
    }
    cout << endl;
}

dado MaxHeap::retiraRaiz() {
    if (tamanho == 0){
        cerr << "Erro ao retirar raiz" << endl;
        exit(EXIT_FAILURE);
    }
    dado aux = heap[0];
    swap(heap[0], heap[tamanho-1]);
    tamanho--;
    corrigeDescendo(0);
    return aux;
}

void MaxHeap::insere(dado d){
    if (tamanho == capacidade) {
        cerr << "Erro ao inserir" << endl;
        exit(EXIT_FAILURE);
    }
    heap[tamanho] = d;
    corrigeSubindo(tamanho);
    tamanho++;
}

void MaxHeap::alteraPrioridade(char operacaoBuscada, int novaPrioridade){
    MaxHeap aux(tamanho);
    dado elementoAtual;

    if(tamanho==0){
        return;
    }

    while (tamanho > 0) {
        elementoAtual = retiraRaiz();
        if (elementoAtual.operacao == operacaoBuscada) {
            elementoAtual.prioridade = novaPrioridade;
        }
        aux.insere(elementoAtual);
    }

    while(aux.tamanho>0){
        insere(aux.retiraRaiz());
    }
}

int main () {
    char operacaoBuscada;
    int capacidade, opcao, novaPrioridade;
    cin >> capacidade;
        
    MaxHeap *h = new MaxHeap(capacidade);
    
    dado entrada, saida;
    cin >> opcao;
    while (opcao != 0){
	if (opcao == 1){
	    cin>>entrada.operacao>>entrada.prioridade;
	    h->insere(entrada);
	} else if (opcao == 2){
		saida = h->retiraRaiz();
		cout<<saida.operacao<<" "<<saida.prioridade<<endl;
	} else if (opcao == 3){
		h->imprime();    
	} else if (opcao == 4){
		cin >> operacaoBuscada;
        cin >> novaPrioridade;
        h->alteraPrioridade(operacaoBuscada, novaPrioridade);
	}
	cin >> opcao;
	}
    
    delete h;
    
    return 0;
}