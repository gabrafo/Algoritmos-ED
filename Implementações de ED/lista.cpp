#include <iostream>
using namespace std;

typedef int Dado;

// Nota: Implementação baseada nas videoaulas do Prof. Joaquim Quintero Uchôa.

class Noh{
    friend class Lista;

    private:
        const Dado dado;
        Noh* proximo;

    public:
        Noh(Dado d = 0);
};

Noh::Noh(Dado d) : dado(d) {
    proximo = NULL;
};

// Lista dinamicamente encadeada
class Lista{
    private:
        Noh* primeiro;
        Noh* ultimo;
        int tamanho;
        void removeTodos();
        void imprimeReversoAux(Noh* aux);

    public:
    Lista();
    Lista(const Lista& outraLista);
    ~Lista();
    Lista& operator=(const Lista& outraLista);
    inline void insere(Dado dado);
    void insereNoFim(Dado dado);
    void insereNoInicio(Dado dado);
    void insereNaPosicao(int posicao, Dado dado);
    int procura(Dado valor);
    void removeNoFim();
    void removeNoInicio();

    void imprime();
    void imprimeReverso();
    inline bool estaVazia();
};

Lista::Lista(){
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

Lista::Lista(const Lista& outraLista){
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;

    Noh* aux = outraLista.primeiro;

    while(aux!=NULL){
        insereNoFim(aux->dado);
        aux = aux->proximo;
    }
}

Lista::~Lista(){
    removeTodos();
}

void Lista::removeTodos(){
    Noh* aux = primeiro;
    Noh* tmp;

    while(aux!=NULL){
        tmp = aux;
        aux = aux->proximo;
        delete tmp;
    }

    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

Lista& Lista::operator=(const Lista& outraLista){
    removeTodos();
    Noh* aux = outraLista.primeiro;

    while(aux!=NULL){
        insereNoFim(aux->dado);
        aux = aux->proximo;
    }

    return *this;
}

void Lista::insere(Dado dado){
    insereNoFim(dado);
}

void Lista::insereNoFim(Dado dado){
    Noh* novo = new Noh(dado);

    if(estaVazia()){
        primeiro = novo;
        ultimo = novo;
    } else {
        ultimo->proximo = novo;
        ultimo = novo;
    }

    tamanho++;
}

void Lista::insereNoInicio(Dado dado){
    Noh* novo = new Noh(dado);

    if(estaVazia()){
        primeiro = novo;
        ultimo = novo;
    } else {
        novo->proximo = primeiro;
        primeiro = novo;
    }

    tamanho++;
}

void Lista::insereNaPosicao(int posicao, Dado dado){
    Noh* novo = new Noh(dado);

    if(posicao==0){
        insereNoInicio(dado);
        return;
    }

    if(posicao==tamanho){
        insereNoFim(dado);
        return;
    }

    if(posicao>0 and posicao<tamanho){
        if(estaVazia()){
            primeiro = novo;
            ultimo = novo;
        } else {
            Noh* aux = primeiro;
            int posAux = 0;

            while(posAux<(posicao-1)){
                aux = aux->proximo;
                posAux++;
            }

            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        tamanho++;
    } else {
        cerr << "ERRO: Posição inexistente!" << endl;
        exit(EXIT_FAILURE);
    }
}

int Lista::procura(Dado valor){
    Noh* aux = primeiro;
    int posAux = 0;

    while((aux!=NULL) and (aux->dado!=valor)){
        aux = aux->proximo;
        posAux++;
    }

    if(aux == NULL){
        posAux = -1;
    }

    return posAux;
}

void Lista::removeNoFim(){
    if(estaVazia()){
        cerr << "ERRO: Remoção em lista vazia!" << endl;
        exit(EXIT_FAILURE);
    } 

    Noh* aux = primeiro;
    Noh* anterior;

    while(aux->proximo != NULL){ // Vai até a penúltima posição.
        anterior = aux;
        aux = aux->proximo;
    }

    delete ultimo;
    anterior->proximo = NULL;
    ultimo = anterior;

    tamanho--;
    if(tamanho==0) primeiro = NULL;
}

void Lista::removeNoInicio(){
    if(estaVazia()){
        cerr << "ERRO: Remoção em lista vazia!" << endl;
        exit(EXIT_FAILURE);
    } 

    Noh* removido = primeiro;
    primeiro = primeiro->proximo;
    delete removido;

    tamanho--;
    if(tamanho==0) ultimo = NULL;
}

void Lista::imprime(){
    Noh*aux = primeiro;

    while(aux!=NULL){
        cout << aux->dado << " ";
        aux = aux->proximo;
    }

    cout << endl;
}

void Lista::imprimeReverso(){
    imprimeReversoAux(primeiro);
    cout << endl;
}

void Lista::imprimeReversoAux(Noh* aux){
    if(aux!=NULL){
        imprimeReversoAux(aux->proximo);
        cout << aux->dado << " ";
    }
}

bool Lista::estaVazia(){
    if(tamanho == 0){
        return true;
    }
    return false;
}

int main(){

    Lista minhaLista = Lista();
    int valor, num;

    cout << "TESTANDO LISTAS!" << endl;
    cout << "Quantidade de valores a serem inseridos: ";
    cin >> num;

    for(int i=0; i<num; i++){
        cin >> valor;
        minhaLista.insere(valor);
    }

    cout << endl;

    cout << "IMPRESSÃO!" << endl;
    minhaLista.imprime();
    cout << endl;

    cout << "Inserindo dezoito no início..." << endl;
    minhaLista.insereNoInicio(18);

    cout << "Inserindo vinte e cinco na posição 'três' (quarta posição)..." << endl;
    minhaLista.insereNaPosicao(3,25);

    cout << endl;

    cout << "IMPRESSÃO!" << endl;
    minhaLista.imprime();
    minhaLista.imprimeReverso();
    cout << endl;

    cout << "BUSCA! Caso não haja uma posição com o valor buscado, retornaremos -1." << endl;
    cout << "Procurando a posição com valor zero: " << minhaLista.procura(0) << endl;
    cout << "Procurando a posição com valor cinquenta: " << minhaLista.procura(50) << endl;
    cout << "Procurando a posição com valor doze: " << minhaLista.procura(12) << endl;
    cout << endl;

    cout << "Sobrecarga do construtor de cópia..." << endl;
    cout << endl;
    Lista outraLista(minhaLista);

    cout << "IMPRESSÃO!" << endl;
    outraLista.imprime();
    outraLista.imprimeReverso();
    cout << endl;

    cout << "Sobrecarga do construtor de atribuição..." << endl;
    cout << endl;
    Lista maisUmaLista;
    maisUmaLista = outraLista;
    
    cout << "IMPRESSÃO!" << endl;
    maisUmaLista.imprime();
    maisUmaLista.imprimeReverso();
    cout << endl;

    cout << "Remoção no fim da lista (duas vezes)..." << endl;
    maisUmaLista.removeNoFim();
    maisUmaLista.removeNoFim();
    cout << endl;

    cout << "IMPRESSÃO!" << endl;
    maisUmaLista.imprime();
    maisUmaLista.imprimeReverso();
    cout << endl;

    cout << "Remoção no início da lista (duas vezes)..." << endl;
    maisUmaLista.removeNoInicio();
    maisUmaLista.removeNoInicio();
    cout << endl;

    cout << "IMPRESSÃO!" << endl;
    maisUmaLista.imprime();
    maisUmaLista.imprimeReverso();
    return 0;
}