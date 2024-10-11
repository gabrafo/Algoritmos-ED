#include <iostream>
#include <stdexcept>

#define MAX 6

using namespace std;

/*
Nota: Esse é um programa baseado em um exercício da disciplina de Estruturas de Dados da Universidade Federal de Lavras.

Objetivo do programa:
O programa em C++ implementa uma pilha para gerenciar uma lista de tarefas para um robô doméstico. O usuário pode adicionar 
tarefas, remover tarefas, visualizar a tarefa no topo e limpar a lista. Mensagens de erro são exibidas quando há tentativas de 
remoção em uma pilha vazia e detalhes das tarefas são mostrados ao final da execução.

Entradas:
O programa deve aceitar os seguintes comandos:

    i: inserir uma tarefa na lista (deve ser seguido de uma string, um caractere e um inteiro)
    r: para remover uma tarefa da lista
    l: para limpar (remover todas) as tarefas da lista
    e: para espiar o topo da lista (imprime os dados do topo sem removê-lo)
    f: para finalizar a execução do programa

Exemplo de Entrada e Saída:
r
Erro: pilha vazia!
i limpeza l 30
i compras c 45
i cozinha k 60
i sala s 90
i jardim j 120
r
Nome: jardim Tipo: j Valor: 120
e
Nome: sala Tipo: s Valor: 90
r
Nome: sala Tipo: s Valor: 90
f
Nome: cozinha Tipo: k Valor: 60
Nome: compras Tipo: c Valor: 45
Nome: limpeza Tipo: l Valor: 30
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

class Pilha{
    private:
        Dados itens[MAX];
        int posicaoTopo;
    
    public:
        Pilha(){
            posicaoTopo = -1;
        }

        void empilhar(string n, char t, int v){
            if(posicaoTopo >= MAX-1) {
                throw runtime_error("Erro: pilha cheia!");
            }
            posicaoTopo+=1;
            itens[posicaoTopo] = Dados(n, t, v);
        }

        void empilhar(Dados d){
            if(posicaoTopo >= MAX-1) {
                throw runtime_error("Erro: pilha cheia!");
            }
            posicaoTopo+=1;
            itens[posicaoTopo] = d;
        }

        bool estaVazia(){
            if(posicaoTopo>-1)
                return false;
            
            return true;
        }

        void desempilhar(){
            if(posicaoTopo == -1) {
                throw runtime_error("Erro: pilha vazia!");
            }

            if(!estaVazia()){
                string saida = itens[posicaoTopo].imprimir();
                posicaoTopo-=1;
                cout << saida << endl;
            }
        }

        void imprimirDadosTopo() const{
            string saida = itens[posicaoTopo].imprimir();
            cout << saida << endl;
        }

        void limparPilha(){
            while(posicaoTopo!=-1){
                desempilhar();
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
