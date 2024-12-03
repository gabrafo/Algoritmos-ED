// Nota: Esse é um programa baseado em um exercício da disciplina de Estruturas de Dados da Universidade Federal de Lavras. Está sendo utilizado
// apenas para a minha revisão para a segunda prova do semestre, e parte de sua implementação não foi feita por mim, e sim por quem organizou
// esse exercício, que não é de minha autoria.

#include <iostream>
#include <string>

using namespace std;

const int UMPRIMO = 39;

int funcaoHash(string chave, int limite) {
    int pos = 0;
    for (unsigned i = 0; i < chave.length(); i++)
        pos = (UMPRIMO * pos + chave[i]) % limite;
    return pos;
}

class noh {
    friend class tabelaHash;
    private:
        string chave;
        string valor;
        noh* proximo = NULL;
    public:
        noh(string c, string v) {
            chave = c;
            valor = v;
        }
};

class tabelaHash {
    private:
        // vetor de ponteiros de nós
        noh** elementos;
        int capacidade;
    public:
        // construtor padrão
        tabelaHash(int cap = 100);
        // destrutor
        ~tabelaHash();
        // insere um valor v com chave c
        void insere(string c, string v);
        // recupera um valor associado a uma dada chave
        string recupera(string c);
        // altera o valor associado a uma chave
        void altera(string c, string v);
        // retira um valor associado a uma chave
        void remove(string c);
        // percorrendo a tabela hash (para fins de debug)
        void percorre();
};

// construtor padrão
tabelaHash::tabelaHash(int cap) {
    elementos = new noh*[cap];
    capacidade = cap;
    for (int i = 0; i < cap; i++)
        elementos[i] = NULL;
}

// destrutor
tabelaHash::~tabelaHash() {
    for (int i=0; i < capacidade; i++) {
        noh* atual = elementos[i];
        // percorre a lista removendo todos os nós
        while (atual != NULL) {
            noh* aux = atual;
            atual = atual-> proximo;
            delete aux;
        }
    }
    delete[] elementos;
}

// Insere um valor v com chave c.
void tabelaHash::insere(string c, string v) {
    // CÓDIGO A SER DESENVOLVIDO
    int hash = funcaoHash(c, capacidade);
    noh* novo = new noh(c, v);

    if(elementos[hash] != NULL){
        noh* atual = elementos[hash];
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    } else {
        elementos[hash] = novo;
    }
}

// recupera um valor associado a uma dada chave
string tabelaHash::recupera(string c) {
    int h = funcaoHash(c, capacidade);
    if ((elementos[h] != NULL) and (elementos[h]->chave == c)) {
        return elementos[h]->valor;
    } else {
        noh* atual = elementos[h];
        while ((atual != NULL) and (atual->chave != c)) {
            atual = atual->proximo;
        }
        if ((atual != NULL) and (atual->chave == c)) {
            return atual->valor;
        } else {
            return "NAO ENCONTRADO!";
        }
    }
}

// altera o valor associado a uma chave
void tabelaHash::altera(string c, string v) {
    //  CODIGO A SER DESENVOLVIDO
    string elementoBusca = recupera(c);
    if(elementoBusca != "NAO ENCONTRADO!"){
        int hash = funcaoHash(c, capacidade);
        if(elementos[hash]->chave == c){
            elementos[hash]->valor = v;
        } else {
            noh* atual = elementos[hash];

            while ((atual != NULL) and (atual->chave != c)) {
                atual = atual->proximo;
            }

            atual->valor = v;
        }
    } else {
        cout << "ERRO NA ALTERACAO!" << endl;
    }
    // imprime "ERRO NA ALTERACAO!" na saída padrão caso tente alterar
    // elemento não existente na tabela
}

// retira um valor associado a uma chave
void tabelaHash::remove(string c) {
    //  CODIGO A SER DESENVOLVIDO
    int hash = funcaoHash(c, capacidade);

    // Caso não tenha nenhum elemento na lista encadeada (lista nula)
    if(elementos[hash]==NULL){
        cout << "ERRO NA REMOCAO!" << endl;
        return;
    }

    noh* atual = elementos[hash];
    noh* anterior = NULL; // Inicializado como NULL para o caso em que o elemento procurado seja o primeiro da lista

    // Procura o elemento na lista
    while ((atual != NULL) and (atual->chave != c)) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Após a busca na lista, caso não ache o elemento procurado
    if (atual == NULL) {
        cout << "ERRO NA REMOCAO!" << endl;
        return;
    }

    if(anterior == NULL){ // Se o elemento for achado na primeira iteração do while (primeiro da lista)
        elementos[hash] = atual->proximo; // Lista irá começar no próximo elemento, ao invés do atual (o excluímos)
    } else { // Caso não seja o primeiro elemento
        anterior->proximo = atual->proximo; // Anterior agora irá apontar para o elemento posterior a atual (caso exista)
    }

    delete atual;

    // imprime "ERRO NA REMOCAO!" na saída padrão caso tente remover
    // elemento não existente na tabela
}

// percorre a tabela hash, escrevendo as listas de itens (para fins de debug)
void tabelaHash::percorre( ) {
    noh* atual;
    for (int i = 0; i < capacidade; i++) {
        cout << i << ":";
        atual = elementos[i];
        while (atual != NULL) {
            cout << "[" << atual->chave << "/"
                 << atual->valor << "]->";
            atual = atual->proximo;
        }
        cout << "NULL ";
    }
    cout << endl;
}

int main( ) {
    tabelaHash th(10);
    int qtdade;
    string chave;
    string valor;

    // insercao na tabela
    cin >> qtdade;
    for (int i=0; i < qtdade; i++) {
        cin >> chave;
        cin >> valor;
        th.insere(chave,valor);
    }

    // altera valores
    cin >> qtdade;
    for (int i=0; i < qtdade; i++) {
        cin >> chave;
        cin >> valor;
        th.altera(chave,valor);
    }

    // remove valores
    cin >> qtdade;
    for (int i=0; i < qtdade; i++) {
        cin >> chave;
        th.remove(chave);
    }

    // recupera valores
    cin >> qtdade;
    for (int i=0; i < qtdade; i++) {
        cin >> chave;
        cout << th.recupera(chave) << endl;
    }

    // percorre a tabela
    cout << endl;
    th.percorre();
    cout << endl;

    return 0;
}