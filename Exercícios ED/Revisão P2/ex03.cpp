// Nota: Esse é um programa baseado em um exercício da disciplina de Estruturas de Dados da Universidade Federal de Lavras. Está sendo utilizado
// apenas para a minha revisão para a primeira prova do semestre, e parte de sua implementação não foi feita por mim, e sim por quem organizou
// esse exercício, que não é de minha autoria.

#include <iostream>
using namespace std;

struct Dado{
    string nomeEquipe, lider, linguagem;
    int qtdMembros;
};

class Noh{
    friend class Lista;

    private:
        const Dado dado;
        Noh* proximo;

    public:
        Noh(Dado d);
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

    public:
        Lista();
        Lista(const Lista& outraLista);
        ~Lista();
        Lista& operator=(const Lista& outraLista);
        inline void insere(Dado dado);
        void insereNoFim(Dado dado);
        void insereNoInicio(Dado dado);
        void insereNaPosicao(int posicao, Dado dado);
        int procura(string equipe);
        void removeNoFim();
        void removeNoInicio();
        void removePorNome(string nome);
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
        cout << "Posição inexistente!" << endl;
        return;
    }
}

int Lista::procura(string equipe){
    if(estaVazia()){
        return -2;
    }

    Noh* aux = primeiro;
    int posAux = 0;

    while((aux!=NULL) and (aux->dado.nomeEquipe!=equipe)){
        aux = aux->proximo;
        posAux++;
    }

    if(aux == NULL){
        return -1;
    }

    return posAux;
}

void Lista::removeNoFim(){
    if(estaVazia()){
        cout << "Remoção em lista vazia!" << endl;
        return;
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
        cout << "Remoção em lista vazia!" << endl;
        return;
    } 

    Noh* removido = primeiro;
    primeiro = primeiro->proximo;
    delete removido;

    tamanho--;
    if(tamanho==0) ultimo = NULL;
}

void Lista::removePorNome(string nomeEquipe){
    int indice = procura(nomeEquipe);

    if (indice == -2) {
        cout << "Lista vazia!" << endl;
        return;
    }
    
    if (indice == -1) {
        cout << "Não encontrado" << endl;
        return;
    }
    if(indice == 0){
        removeNoInicio();
        return;
    }

    if(indice == tamanho-1){
        removeNoFim();
        return;
    }

    Noh* aux = primeiro;

    for (int i = 0; i < indice - 1; ++i) {
        aux = aux->proximo;
    }

    Noh* removido = aux->proximo;
    aux->proximo = removido->proximo;

    delete removido;
    tamanho--;
}

void Lista::imprime(){
    if(tamanho == 0){
        cout << "Lista vazia!" << endl;
        return;
    }

    Noh*aux = primeiro;

    while(aux!=NULL){
        cout << "(" << aux->dado.nomeEquipe << ", " << aux->dado.lider << ", " << aux->dado.linguagem << ", " << aux->dado.qtdMembros << ")" << endl;
        aux = aux->proximo;
    }
}

bool Lista::estaVazia(){
    if(tamanho == 0){
        return true;
    }
    return false;
}

int main() {
    Lista minhaLista;
    Dado info;
    char comando;
    int posicao, indice;
    string nomeEquipe;

    do {
        try {
            cin >> comando;
            switch (comando) {
                case 'i': // inserir
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNoInicio(info);
                    break;
                case 'h': // inserir
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNoFim(info);
                    break;             
                case 'm': // inserir
                    cin >> posicao;
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNaPosicao(posicao,info);
                    break;             
                case 's': // remover
                    cin >> nomeEquipe;
                    indice = minhaLista.procura(nomeEquipe);
                    if (indice == -2) {
                        cout << "Lista vazia!" << endl;
                    } else if (indice == -1) {
                        cout << "Não encontrado" << endl;
                    } else {
                        cout << indice << endl; // Imprime apenas se encontrado.
                    }
                    break;  
                case 'x':
                    cin >> nomeEquipe;
                    minhaLista.removePorNome(nomeEquipe);
                    break;                  
                case 'r': // remover
                    minhaLista.removeNoInicio();
                    break;
                case 'a': // remover
                    minhaLista.removeNoFim();
                    break;               
                case 'p': // limpar tudo
                    minhaLista.imprime();
                    break;
                case 'f': // finalizar
                    // checado no do-while
                    break;
                default:
                    cout << "comando inválido\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (comando != 'f'); // finalizar execução
    cout << endl;
    return 0;
}