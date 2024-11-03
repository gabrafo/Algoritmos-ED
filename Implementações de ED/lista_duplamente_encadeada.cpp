#include <iostream>
#include <stdexcept> // Para tratamento de exceções
using namespace std;

typedef int Dado;

// Nota: Implementação baseada nas videoaulas do Prof. Joaquim Quintero Uchôa.

class Noh{
    friend class Lista;

    private:
        const Dado dado;
        Noh* proximo;
        Noh* anterior;

    public:
        Noh(Dado d = 0);
};

Noh::Noh(Dado d) : dado(d) {
    proximo = NULL;
    anterior = NULL;
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
    bool procura(Dado valor, int& posicao);
    void removeNoFim();
    void removeNoInicio();
    void removeValor(Dado dado);

    void imprime();
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
        novo->anterior = ultimo;
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
        primeiro->anterior = novo;
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
            aux->proximo->anterior = novo;
            aux->proximo = novo;
            novo->anterior = aux;
        }
        tamanho++;
    } else {
        throw runtime_error("ERRO: Posição inexistente!");
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

// Retornando a posição por passagem por referência!
bool Lista::procura(Dado valor, int& posicao){
    posicao = 0;
    Noh* aux = primeiro;

    while((aux!=NULL) and (aux->dado!=valor)){
        aux = aux->proximo;
        posicao++;
    }

    if(aux == NULL){
        posicao = -1;
        return false;
    } else {
        return true;
    }
}

void Lista::removeNoFim(){
    if(estaVazia()){
        cerr << "ERRO: Remoção em lista vazia!" << endl;
        exit(EXIT_FAILURE);
    } 

    Noh* removido = ultimo;
    ultimo = ultimo->anterior;
    if(ultimo!=NULL) ultimo->proximo = NULL;
    delete removido;

    tamanho--;
    if(estaVazia()){
        ultimo = NULL;
        primeiro = NULL;
    }
}

void Lista::removeNoInicio(){
    if(estaVazia()){
        cerr << "ERRO: Remoção em lista vazia!" << endl;
        exit(EXIT_FAILURE);
    } 

    Noh* removido = primeiro;
    primeiro = primeiro->proximo;
    if(primeiro!=NULL) primeiro->anterior = NULL;
    delete removido;

    tamanho--;
    if(estaVazia()){
        ultimo = NULL;
        primeiro = NULL;
    }
}

void Lista::removeValor(Dado dado){
    if(estaVazia()){
        cerr << "ERRO: Remoção em lista vazia!" << endl;
        exit(EXIT_FAILURE);
    } 

    Noh* aux = primeiro;

    while((aux!=NULL) and (aux->dado!=dado)){
        aux = aux->proximo;
    }

    if(aux == NULL){
        cerr << "ERRO: Tentativa de remoção de valor não existente!" << endl;
        exit(EXIT_FAILURE);
    }

    if (aux->anterior != NULL) {
        aux->anterior->proximo = aux->proximo;
    } else {
        // Se `aux` é o primeiro nó, atualize `primeiro`
        primeiro = aux->proximo;
    }

    if (aux->proximo != NULL) {
        aux->proximo->anterior = aux->anterior;
    } else {
        // Se `aux` é o último nó, atualize `ultimo`
        ultimo = aux->anterior;
    }

    delete aux;

    tamanho--;

    if(estaVazia()){
        ultimo = NULL;
        primeiro = NULL;
    }
}

void Lista::imprime(){
    Noh*aux = primeiro;

    while(aux!=NULL){
        cout << aux->dado << " ";
        aux = aux->proximo;
    }
    cout << endl;

    aux = ultimo;
    while(aux!=NULL){
        cout << aux->dado << " ";
        aux = aux->anterior;
    }
    cout << endl;  
}

bool Lista::estaVazia(){
    return (tamanho == 0);
}

int main(){

    Lista minhaLista = Lista();

    cout << "TESTANDO LISTAS!" << endl;
    minhaLista.insere(5);
    minhaLista.insere(3);
    minhaLista.insere(1);
    minhaLista.insere(0);
    minhaLista.insere(6);
    minhaLista.insere(41);

    cout << "IMPRESSÃO!" << endl;
    minhaLista.imprime();
    cout << endl;

    cout << "Inserindo dezoito no início..." << endl;
    minhaLista.insereNoInicio(18);

    cout << "Inserindo vinte e cinco na posição 'três' (quarta posição)..." << endl;
    minhaLista.insereNaPosicao(3,25);

    cout << "Inserindo um na posição 'vinte e nove' (trigésima posição)... Gerará ERRO!" << endl;

    // Tratamento de exceção
    try{
        minhaLista.insereNaPosicao(29,1);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    cout << "IMPRESSÃO!" << endl;
    minhaLista.imprime();
    cout << endl;

    cout << "BUSCA!" << endl;
    int pos = minhaLista.procura(0);
    cout << "Procurando a posição com valor zero: ";
    if(pos == -1){
        cout << "Elemento não encontrado!" << endl;;
    } else {
        cout << pos << endl;
    }
    cout << "Procurando a posição com valor cinquenta: ";
    pos = minhaLista.procura(50);
    if(pos == -1){
        cout << "Elemento não encontrado!" << endl;;
    } else {
        cout << pos << endl;
    }

    // Outra forma de fazer o tratamento de erros será usada naimpressão das duas próximas buscas!
    cout << "Procurando a posição com valor doze: ";
    if (minhaLista.procura(12, pos)){
        cout << pos << endl;
    } else {
        cout << "Elemento não encontrado!" << endl;
    }

    cout << "Procurando a posição com valor quarenta e um: ";
        if (minhaLista.procura(41, pos)){
            cout << pos << endl;
        } else {
            cout << "Elemento não encontrado!" << endl;
        }
        cout << endl;

    cout << "Sobrecarga do construtor de cópia..." << endl;
    Lista outraLista(minhaLista);

    cout << "IMPRESSÃO!" << endl;
    outraLista.imprime();
    cout << endl;

    cout << "Sobrecarga do construtor de atribuição..." << endl;
    Lista maisUmaLista;
    maisUmaLista = outraLista;
    
    cout << "IMPRESSÃO!" << endl;
    maisUmaLista.imprime();
    cout << endl;

    cout << "Remoção no fim da lista (duas vezes)..." << endl;
    maisUmaLista.removeNoFim();
    maisUmaLista.removeNoFim();

    cout << "IMPRESSÃO!" << endl;
    maisUmaLista.imprime();
    cout << endl;

    cout << "Remoção no início da lista (duas vezes)..." << endl;
    cout << "IMPRESSÃO ANTES DA REMOÇÃO..." << endl;
    maisUmaLista.imprime();
    cout << endl;
    maisUmaLista.removeNoInicio();
    maisUmaLista.removeNoInicio();

    cout << "IMPRESSÃO!" << endl;
    maisUmaLista.imprime();
    cout << endl;

    cout << "Remoção TOTAL!" << endl;
    maisUmaLista.removeNoFim();
    cout << "IMPRESSÃO!" << endl;
    maisUmaLista.imprime();
    cout << endl;

    maisUmaLista.removeNoFim();
    cout << "IMPRESSÃO!" << endl;
    maisUmaLista.imprime();
    cout << endl;

    maisUmaLista.removeNoFim();
    cout << "IMPRESSÃO!" << endl;
    maisUmaLista.imprime();
    cout << endl;

    maisUmaLista.removeNoFim();
    cout << "IMPRESSÃO FINAL!" << endl;
    maisUmaLista.imprime();
    cout << "Nada impresso na impressão e impressão reversa nas duas linhas anteriores! Lista vazia!" << endl;
    cout << endl;

    cout << "IMPRESSÃO (de outra lista)!" << endl;
    minhaLista.imprime();
    cout << endl;

    cout << "Remoção do valor cinco..." << endl;
    minhaLista.removeValor(5);
    minhaLista.imprime();
    cout << endl;

    cout << "Remoção do valor dezoito.." << endl;
    minhaLista.removeValor(18);
    minhaLista.imprime();
    cout << endl;

    cout << "Remoção do valor três..." << endl;
    minhaLista.removeValor(3);
    minhaLista.imprime();
    cout << endl;

    cout << "Remoção do valor seis..." << endl;
    minhaLista.removeValor(6);
    minhaLista.imprime();
    cout << endl;

    cout << "Remoção do valor zero..." << endl;
    minhaLista.removeValor(0);
    minhaLista.imprime();
    cout << endl;

    cout << "Remoção do valor um..." << endl;
    minhaLista.removeValor(1);
    minhaLista.imprime();
    cout << endl;

    cout << "Remoção do valor vinte e cinco..." << endl;
    minhaLista.removeValor(25);
    minhaLista.imprime();
    cout << endl;

    cout << "Remoção do valor quarenta e um..." << endl;
    minhaLista.removeValor(41);
    minhaLista.imprime();
    cout << "Nada impresso na impressão e impressão reversa nas duas linhas anteriores! Lista vazia!" << endl;

    return 0;
}