#include <iostream>
#include <stdexcept>
using namespace std;

// Nota: Esse é um programa baseado em um exercício da disciplina de Estruturas de Dados da Universidade Federal de Lavras.

class Dados{
    private:
        string nome;
        string premio;
        char tipo;
        int tempo;

    public:
        Dados(){}

        Dados(string n, string p, char t, int v) : nome(n), premio(p), tipo(t), tempo(v){}

        string getNome() const{
            return nome;
        }

        void setNome(string n){
            nome = n;
        }

        string getPremio(){
            return premio;
        }

        void setPremio(string p){
            premio = p;
        }

        char getTipo() const{
            return tipo;
        }

        void setTipo(char t){
            tipo = t;
        }

        int getTempo() const{
            return tempo;
        }

        void setTempo(int v){
            tempo = v;
        }

        string imprimir() const{
            return "Nome: " + nome + " Prêmio: " + premio +  " Tipo: " + tipo + " Tempo: " + to_string(tempo);
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

class Fila{
    private:
        Noh* inicio;
        Noh* fim;
    
    public:
        Fila(){
            inicio = nullptr;
            fim = nullptr;
        }

        void enfileirar(string n, string p, char t, int v){
            Dados d = Dados(n, p, t, v);
            Noh* novo = new Noh(d);
            if(estaVazia()){
                inicio = novo; // Encadeamento do último elemento atual com o novo último elemento
            } else {
                fim->setProximoNoh(novo);
            }
            fim = novo;
        }

        void enfileirar(Dados d){
            Noh* novo = new Noh(d);
            if(estaVazia()){
                inicio = novo; // Encadeamento do último elemento atual com o novo último elemento
            } else {
                fim->setProximoNoh(novo);
            }
            fim = novo;
        }

        bool estaVazia(){
            if(inicio!=nullptr)
                return false;
            
            return true;
        }

        void desenfileirar(){
            string saida = "Erro: Fila vazia!";
            Dados apagado;

            if(!estaVazia()){
                Noh* aux = inicio;
                apagado = inicio->getDados();
                inicio = inicio->getProximoNoh();
                aux->setProximoNoh(nullptr);
                saida = apagado.imprimir();
                delete aux;
            }

            cout << saida << endl;
        }

        void desenfileirarSilenciosamente(){
            if(!estaVazia()){
                Noh* aux = inicio;

                inicio = inicio->getProximoNoh();
                aux->setProximoNoh(nullptr);
                delete aux;
            }
        }

        void imprimirDadosFim() const{
            string saida = fim->getDados().imprimir();
            cout << saida << endl;
        }

        void imprimirDadosInicio() const{
            string saida = inicio->getDados().imprimir();
            cout << saida << endl;
        }

        void limparFila(){
            while(inicio != nullptr){
                desenfileirar();
            }
        }

        ~Fila(){
            limparFila();
        }
};


int main() {
    Fila fila;
    Dados info;
    char comando;

    do {
        try{
            cin >> comando;

            string n, p;
            char t;
            int v;

            switch (comando) {
                case 'i': // inserir
                    cin >> n >> p >> t >> v;
                    info.setNome(n);
                    info.setPremio(p);
                    info.setTipo(t);
                    info.setTempo(v);
                    fila.enfileirar(info);
                    break;
                case 'r': // remover
                    fila.desenfileirar();
                    break;
                case 'l': // limpar tudo
                    fila.limparFila();
                    break;
                case 'e': // espiar           
                    fila.imprimirDadosInicio();
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

    while (not fila.estaVazia()) {
        fila.desenfileirar();
    }
    return 0;
}
