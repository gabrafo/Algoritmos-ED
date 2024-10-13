#include <string>
#include <unordered_map>
using namespace std;

class Noh{
    private:
        char simbolo;
        Noh* proximoNoh;
    
    public:
        Noh(char s){
            simbolo = s;
            proximoNoh = nullptr;
        }

        char getSimbolo() const{
            return simbolo;
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
        Noh* topo;
    
    public:
        Pilha(){
            topo = nullptr;
        }

        void empilhar(char c){
            Noh* novo = new Noh(c);
            novo->setProximoNoh(topo);
            topo = novo;
        }

        bool estaVazia() const{
            if(topo!=nullptr)
                return false;
            
            return true;
        }

        void desempilhar(){
            if(!estaVazia()){
                Noh* aux = topo;
                topo = topo->getProximoNoh();
                aux->setProximoNoh(nullptr);
                delete aux;
            }
        }

        char retornarCharTopo() const{
            return topo->getSimbolo();
        }

        void limparPilha(){
            while(topo != nullptr){
                desempilhar();
            }
        }

        ~Pilha(){
            limparPilha();
        }
};

class Solution {
public:
    bool isValid(string s) {
        Pilha pilha;
        int tamanho = s.length();
        if(tamanho%2!=0){
            return false; // Não pode ser balanceado por ser ímpar
        }

        int contador = 0;
        unordered_map<char, char> tabelaHash;
        tabelaHash.insert(make_pair(')', '('));
        tabelaHash.insert(make_pair(']', '['));
        tabelaHash.insert(make_pair('}', '{'));
        
        while(contador<tamanho){
            char simbolo = s.at(contador);
            if(simbolo == '(' or simbolo == '[' or simbolo == '{'){
                pilha.empilhar(s.at(contador));
            } else if (simbolo == ')' or simbolo == ']' or simbolo == '}'){
                if(pilha.estaVazia()){
                    return false;
                }

                char topoSimbolo = pilha.retornarCharTopo();
                if(tabelaHash[simbolo] == topoSimbolo){
                    pilha.desempilhar(); // Correspondência correta
                } else {
                    return false; // Correspondência incorreta
                }
            }
            contador++;
        }

        return pilha.estaVazia(); // Se a pilha está vazia, está tudo correto
    }
};

// Complexidade total do algoritmo: O(n). 
// Motivo: A pilha pode armazenar no máximo n elementos no pior caso (por exemplo, se todos os caracteres forem parênteses de abertura).

// Operações na pilha: O(1).
// Operações usando a tabela hash: O(1).