#include <iostream>
using namespace std;

// Código feito em sala de aula na disciplina de Estrutura de Dados no dia 25/09/2024.

class Livro{
    private:
        string titulo;
        string autor;
        long isbn;

    public:
        Livro(){
            titulo = "-";
            autor = "-";
            isbn = 0;
        }
        void cadastrar(string tit, string autor, long cod){
            titulo = tit;
            this -> autor = autor;
            isbn = cod;
        };
        void mostrar(){
            cout << "Título: " << titulo << endl 
            << "Autor: " << autor << endl 
            << "ISBN: " << isbn << endl;
        }
        string retornarTitulo();
};

// Exemplo de implementação externa
string Livro::retornarTitulo(){
    return titulo;
}

class Biblioteca{
    private:
        Livro* exemplares;
        int capacidade;
        int tamanho;

    public:
        Biblioteca(int capacidadeInicial){
            exemplares = new Livro[capacidadeInicial];
            capacidade = capacidadeInicial;
            tamanho = 0;
        }
        ~Biblioteca(){
            delete[] exemplares;
        }
        void registrar(string tit, string autor, long cod){
            exemplares[tamanho].cadastrar(tit, autor, cod);
            tamanho++;
        }
        bool consultar(string tit){
            int indice = 0;
            while((indice < tamanho) and (tit!=exemplares[indice].retornarTitulo())){
                indice++;
            }

            if(indice<tamanho){
                exemplares[indice].mostrar();
                return true;
            }
            return false;
        }
        int retornarCapacidade(){
            return capacidade;
        }
        int retornarTamanho(){
            return tamanho;
        }
};

void menu(){
    cout << "1. Cadastrar" << endl << "2. Buscar" << endl;
}

int main(){
    int totalLivro;
    cout << "Total de livros: ";
    cin>>totalLivro;

    Biblioteca acervo(totalLivro);

    int opcao = 3;
    
    menu();
    cin >> opcao;
    while(opcao!=0){

        if(opcao == 1){
            if(acervo.retornarTamanho() < acervo.retornarCapacidade()){
                string titulo, autor;
                long isbn;
                cout << "Título: ";
                cin >> titulo;
                cout << "Autor: ";
                cin >> autor;
                cout << "ISBN: ";
                cin >> isbn;
                acervo.registrar(titulo, autor, isbn);
            } else {
                cout << "Sem espaço disponível" << endl;
            }
        } else if (opcao == 2){
                string titulo;
                cout << "Título: ";
                cin >> titulo;

                if(not acervo.consultar(titulo)){
                    cout << "Livro não encontrado." << endl;
                }
                opcao = 3;
        } else {
            cout << "Opção inválida!" << endl;
        }
        menu();
        cin >> opcao;
    }
    

    return 0;
}
