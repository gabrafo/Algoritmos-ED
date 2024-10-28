#include <iostream>
#include <stdexcept>
using namespace std;

/*
Nota: Esse é um programa baseado em um exercício da disciplina de Estruturas de Dados da Universidade Federal de Lavras.

Objetivo do programa:
O programa em C++ implementa uma pilha encadeada para gerenciar um inventário de itens em um jogo. O usuário pode adicionar 
itens, remover itens, espiar o item no topo e limpar o inventário. O programa exibe mensagens de erro quando tentativas de 
remoção são feitas em uma pilha vazia e mostra detalhes dos itens ao final da execução.

Entradas:
O programa deve aceitar os seguintes comandos:
    i: inserir um item no inventário (deve ser seguido de uma string, um caractere e um inteiro) 
    r: para retirar um item do inventário
    l: para limpar (remover todos) os itens do inventário
    e: para espiar o topo do inventário (imprime os dados do topo sem removê-lo da pilha)
    o: ordenar pilha alfabeticamente (com base no nome)
    x: para remover (e imprimir) todos os elementos com valor inferiores ao informado (deve ser seguido de um inteiro)
    f: para finalizar a execução do programa

Exemplo de Entrada e Saída juntas:
r
Erro: pilha vazia!
i um a 1
i dois b 2
i quatro d 4
i sete g 7
i oito h 8
r
Nome: oito Tipo: h Valor: 8
e
Nome: sete Tipo: g Valor: 7
r
Nome: sete Tipo: g Valor: 7
x 2
Nome: um Tipo: a Valor: 1
f
Nome: quatro Tipo: d Valor: 4
Nome: dois Tipo: b Valor: 2
*/

class Dados{
    private:
        string nome;
        char tipo;
        int valor;

    public:
        Dados(){}

        Dados(string n, char t, int v) : nome(n), tipo(t), valor(v){}

        string getNome() const{
            return nome;
        }

        void setNome(string n){
            nome = n;
        }

        char getTipo() const{
            return tipo;
        }

        void setTipo(char t){
            tipo = t;
        }

        int getValor() const{
            return valor;
        }

        void setValor(int v){
            valor = v;
        }

        string imprimir() const{
            return "Nome: " + nome + " Tipo: " + tipo + " Valor: " + to_string(valor);
        }
};

class Noh{
    private:
        Dados dados;
        Noh* proximoNoh;
    
    public:
        Noh(Dados d){
            dados = d;
            proximoNoh = nullptr;
        }

        Dados getDados() const{
            return dados;
        }

        Noh* getProximoNoh() const{
            return proximoNoh;
        }
        
        void setProximoNoh(Noh* novoProximoNoh){
            proximoNoh = novoProximoNoh;
        }
};

class Pilha{
    private:
        int tamanho;
        Noh* topo;
    
    public:
        Pilha(){
            topo = nullptr;
        }

        void empilhar(string n, char t, int v){
            Dados d = Dados(n, t, v);
            Noh* novo = new Noh(d);
            novo->setProximoNoh(topo);
            topo = novo;
        }

        void empilhar(Dados d){
            Noh* novo = new Noh(d);
            novo->setProximoNoh(topo);
            topo = novo;
        }

        bool estaVazia(){
            if(topo!=nullptr)
                return false;
            
            return true;
        }

        void desempilhar(){
            string saida = "Erro: pilha vazia!";

            if(!estaVazia()){
                Noh* aux = topo;
                topo = topo->getProximoNoh();
                aux->setProximoNoh(nullptr);
                saida = aux->getDados().imprimir();
                delete aux;
            }

            cout << saida << endl;
        }

        void desempilharSilenciosamente(){
            if(!estaVazia()){
                Noh* aux = topo;
                topo = topo->getProximoNoh();
                aux->setProximoNoh(nullptr);
                delete aux;
            }
        }

        Dados desempilharComRetorno(){
            Dados apagado;

            if(!estaVazia()){
                Noh* aux = topo;
                apagado = aux->getDados();
                topo = topo->getProximoNoh();
                aux->setProximoNoh(nullptr);
                delete aux;
            }
            
            return apagado;
        }

        void imprimirDadosTopo() const{
            string saida = topo->getDados().imprimir();
            cout << saida << endl;
        }

        void limparPilha(){
            while(topo != nullptr){
                desempilhar();
            }
        }

        // Todos os métodos "silenciosos" foram criados para que eu não perca pontuação no DREDD por impressões desnecessárias.
        void limparPilhaSilenciosamente(){
            while(topo != nullptr){
                desempilharSilenciosamente();
            }
        }


        void ordenarAlfabeticamente(){
            if(estaVazia()){
                return;
            }

            Pilha pilhaAux;
            Pilha pilhaRes;
            Dados menorElemento, elementoAtual;

            while (!estaVazia()) {
                menorElemento = desempilharComRetorno();

                while (!estaVazia()) {
                    elementoAtual = desempilharComRetorno();

                    if (elementoAtual.getNome() < menorElemento.getNome()) {
                        pilhaAux.empilhar(menorElemento);
                        menorElemento = elementoAtual;
                    } else {
                        pilhaAux.empilhar(elementoAtual);
                    }
                }

                pilhaRes.empilhar(menorElemento);

                while (!pilhaAux.estaVazia()) {
                    empilhar(pilhaAux.desempilharComRetorno());
                }
            }

            while (!pilhaRes.estaVazia()) {
                empilhar(pilhaRes.desempilharComRetorno());
            }
        }

        ~Pilha(){
            limparPilha();
        }
};


int main() {
    Pilha pilha;
    Dados info;
    char comando;

    do {
        try{
            cin >> comando;

            string n;
            char t;
            int v;

            switch (comando) {
                case 'i': // inserir
                    cin >> n >> t >> v;
                    info.setNome(n);
                    info.setTipo(t);
                    info.setValor(v);
                    pilha.empilhar(info);
                    break;
                case 'r': // remover
                    pilha.desempilhar();
                    break;
                case 'l': // limpar tudo
                    pilha.limparPilha();
                    break;
                case 'e': // espiar                
                    pilha.imprimirDadosTopo();
                    break;
                case 'o':
                    pilha.ordenarAlfabeticamente();
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

    while (not pilha.estaVazia()) {
        pilha.desempilhar();
    }
    return 0;
}
