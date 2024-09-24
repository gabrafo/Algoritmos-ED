#include <iostream>

using namespace std;

// Classes em C++ são privadas por padrão
class Funcionario{ // Nome da classe
    private: // Modificador de acesso
        string nome; // Atributos
        string empresa;
        int idade;

    public: // Modificador de acesso
        Funcionario() : nome(""), empresa(""), idade(0) {} // Construtor padrão com valores pré-definidos
        Funcionario(string nome, string empresa, int idade) : nome(nome), empresa(empresa), idade(idade) {} // Construtor com atributos por parâmetro

        void setNome(string nome){ // Métodos getters/setters
            this->nome = nome;
        }

        string getNome(){
            return nome;
        }

        void setEmpresa(string empresa){
            this->empresa = empresa;
        }

        string getEmpresa(){
            return empresa;
        }

        void setIdade(int idade){
            this->idade = idade;
        }

        int getIdade(){
            return idade;
        }

        void exibirInformacoes() {
            cout << "Nome: " << nome << endl;
            cout << "Empresa: " << empresa << endl;
            cout << "Idade: " << idade << endl;
        }
};

int main()
{
    Funcionario funcionario1("Josias", "Carluxo Confecções LTDA", 46);
    funcionario1.exibirInformacoes();
}