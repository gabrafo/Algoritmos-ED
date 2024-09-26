#include <iostream>
#include <cstdlib>

using namespace std;

/* Código baseado na classe vectorx de Joaquim Quintero Uchôa (professor da disciplina de Estruturas de Dados na 
Universidade Federal de Lavras). */

class VectorX{
    private:
        int capacidade;
        int tamanho;
        int* vetor;

    public:
        VectorX(int cap);
        VectorX(const VectorX& vec);
        ~VectorX();
        VectorX& operator=(const VectorX& vec);
        int& operator[](int pos);
        void preencher();
        void imprimir();

        friend ostream& operator<<( ostream& saida, const VectorX& vec); // Quebra de encapsulamento
};

VectorX::VectorX(int cap){
    cout << "Objeto criado!" << endl;
    capacidade = cap;
    tamanho = 0;
    vetor = new int[cap];
}

VectorX::~VectorX(){
    cout << "Objeto destruído." << endl;
    delete[] vetor;
    capacidade = 0;
    tamanho = 0;
}

VectorX::VectorX(const VectorX& vec) {
    cout << "Objeto copiado..." << endl;
    capacidade = vec.tamanho;
    tamanho = vec.tamanho;
    vetor = new int[tamanho];
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = vec.vetor[i];
    }
}

VectorX& VectorX::operator=(const VectorX& vec){
    cout << "Objeto atribuído..." << endl;

    // Apaga elementos antigos
    delete[] vetor;

    // Reatribui tamanho e capacidade
    tamanho = vec.tamanho;
    capacidade = tamanho;

    // Cria o novo vetor
    vetor = new int[tamanho];

    // Cópia dos dados
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = vec.vetor[i];
    }

    // Retorno de derreferência
    return *this;
}

int& VectorX::operator[](int pos){
    if(pos > tamanho || pos < 0){
        cout << "Posição inválida!" << endl;
        exit(EXIT_FAILURE);
    }
    return vetor[pos];
}

void VectorX::preencher(){
    for(int i=0; i<capacidade; i++){
        vetor[i] = random()%100; // Número aleatório entre 0 e 99
        tamanho++;
    }
}

void VectorX::imprimir(){
    for (int i = 0; i < tamanho; i++) {  // Usamos um loop tradicional
        cout << vetor[i] << " ";  // Imprimimos cada elemento
    }
    cout << endl;
}

ostream& operator<<( ostream& saida, const VectorX& vec) {
    for (int i = 0; i < vec.tamanho; i++){
        saida << vec.vetor[i] << " ";
    }  
    saida << endl;
    return saida;
}

int main(){
    srand(time(NULL)); // Inicialização do gerador de números aleatórios

    int capacidade = 5;
    VectorX v1(capacidade);

    v1.preencher();

    cout << "V1:" << endl;
    v1.imprimir();

    // Construtor de cópia
    VectorX v2 = v1;
    cout << "V2 (cópia de V1):" << endl;
    v2.imprimir();

    capacidade = 10;
    VectorX v3(capacidade);

    cout << "V3:" << endl;
    v3.preencher();
    v3.imprimir();

    cout << "V1 (cópia de V3):" << endl;
    v1 = v3;
    v1.imprimir();
    return 0;
}