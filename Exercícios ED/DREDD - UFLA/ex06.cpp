// Crie uma fila encadeada para gerenciar tarefas de um jogador. 
// Permita as operações: adicionar, remover, espiar o primeiro item e limpar a fila. 
// Ao remover de uma fila vazia, exiba "Erro: fila vazia!".
// Cada tarefa tem: nome (string), recompensa (string), tipo (char) e duração (int).

// Comandos:
// - i <nome> <recompensa> <tipo> <duração>: insere uma tarefa
// - r: remove a tarefa da frente
// - l: limpa todas as tarefas
// - e: exibe a tarefa na frente
// - a <tipo>: contabiliza o tempo total de tarefas desse tipo e as move para frente
// - f: finaliza o programa

// Exemplo de I/O:
// r
// Erro: fila vazia!
// i tarefa1 premio1 a 100
// a a
// 100
// r
// Nome: tarefa1 Recompensa: premio1 Tipo: a Duração: 100
// f

// Nota: Esse é um programa baseado em um exercício da disciplina de Estruturas de Dados da Universidade Federal de Lavras.

#include <iostream>
#include <stdexcept>
using namespace std;

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

        string getPremio() const{
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
            return "Nome: " + nome + " Premio: " + premio +  " Tipo: " + tipo + " tempo: " + to_string(tempo);
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

        void desenfileirarSemImpressao(){ // Para o DREDD não reclamar de impressão desnecessária de dados
            if(!estaVazia()){
                Noh* aux = inicio;

                inicio = inicio->getProximoNoh();
                aux->setProximoNoh(nullptr);
                delete aux;
            }
        }

        // Quero manipular o dado desenfileirado mais facilmente.
        Dados desenfileirarComRetorno(){ // Para o DREDD não reclamar de impressão desnecessária de dados
            Dados apagado;
            if(!estaVazia()){
                Noh* aux = inicio;
                apagado = inicio->getDados();

                inicio = inicio->getProximoNoh();
                aux->setProximoNoh(nullptr);
                delete aux;
            }
            return apagado;
        }

        int contabilizarAtvsTipo(char t){
            Fila aux;
            Fila auxPriorizados;
            Dados auxElemento;
            int contadorTempo = 0;

            while(inicio!=nullptr){
                auxElemento = desenfileirarComRetorno();
                if(auxElemento.getTipo() == t){
                    auxPriorizados.enfileirar(auxElemento);
                    contadorTempo+=auxElemento.getTempo();
                } else {
                    aux.enfileirar(auxElemento);
                }
            }

            while(auxPriorizados.inicio!=nullptr){
                enfileirar(auxPriorizados.desenfileirarComRetorno());
            }

            while(aux.inicio!=nullptr){
                enfileirar(aux.desenfileirarComRetorno());
            }

            return contadorTempo;
        }

        void imprimirDadosInicio(){
            Fila aux;
            Dados primeiro = inicio->getDados();
            while(!estaVazia()){
                aux.enfileirar(inicio->getDados());
                desenfileirarSemImpressao();
            }
            while(!aux.estaVazia()){
                enfileirar(aux.inicio->getDados());
                aux.desenfileirarSemImpressao();
            }
            string saida = primeiro.imprimir();
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
                case 'a':
                    cin >> t;
                    cout << fila.contabilizarAtvsTipo(t) << endl;
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