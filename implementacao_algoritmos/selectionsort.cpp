#include <iostream>

using namespace std;

class Artista{ // Nome da classe
    private: // Modificador de acesso
        string nome; // Atributos
        int contadorDePlays;
        static int contadorArtistasMes;

    public:
        // CONSTRUTORES
        Artista() : nome(""), contadorDePlays(0) {} // Construtor padrão com valores pré-definidos
        Artista(string nome, int contadorDePlays) : nome(nome), contadorDePlays(contadorDePlays) {
            contadorArtistasMes++;
        } // Construtor com atributos por parâmetro

        // GETTERS
        string getNome(){
            return nome;
        }

        int getContadorDePlays(){
            return contadorDePlays;
        }

        static int getContadorArtistasMes(){
            return contadorArtistasMes;
        }

        void setContadorDePlays(int contadorDePlays){
            this->contadorDePlays = contadorDePlays;
        }

        // MÉTODOS
        void exibirInformacoes() {
            cout << "Nome: " << nome << endl;
            cout << "Contador de plays: " << contadorDePlays << endl;
        }
};

int Artista::contadorArtistasMes = 0; // Inicializando o contador de instâncias de Artista

// Ordenação por seleção
void selectionSort(Artista artistasVetor[], int tamanhoVetor){
    int posMenor;
    Artista aux;
    
    for(int i = 0; i<tamanhoVetor; i++){
        posMenor = i;

        for (int j=i+1; j < tamanhoVetor; j++) { 
            if (artistasVetor[j].getContadorDePlays() > artistasVetor[posMenor].getContadorDePlays()){
                posMenor = j;
            }
        }

        aux = artistasVetor[i];
        artistasVetor[i] = artistasVetor[posMenor];
        artistasVetor[posMenor] = aux;
    }
}

int main()
{
    Artista artistasVetor[] = {
        Artista("Kendrick Lamar", 150),
        Artista("Yun Li", 300),
        Artista("Mitski", 100),
        Artista("Pullovers", 250),
        Artista("Martinho da Vila", 50)
    };

    int tamanhoVetor = artistasVetor[0].getContadorArtistasMes() - 1; // Considerando que nenhum artista foi adicionado fora do vetor!
    selectionSort(artistasVetor, tamanhoVetor);
    
    for(int i = 0; i<tamanhoVetor; i++){
        artistasVetor[i].exibirInformacoes();
        cout << endl;
    }

    return 0;
}