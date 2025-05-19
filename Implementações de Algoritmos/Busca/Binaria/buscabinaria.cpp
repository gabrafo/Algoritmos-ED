#include <iostream>

using namespace std;

int buscaBinaria(int vetor[5], int item, int ultimaPosicao){
    int baixo = 0;
    int alto = ultimaPosicao;
    
    while(baixo<=alto){
        int meio = (baixo+alto)/2;
        int chute = vetor[meio];

        if (chute == item){
            return meio; // Acertou!
        }
        if (chute > item){
            alto = meio-1; // Está na parte direita
        }
        if(chute < item){
            baixo = meio+1; // Está na parte esquerda
        }

        cout << "ITERAÇÃO! Alto = " << alto << ", Meio = " << meio <<
        ", Baixo = " << baixo << ", ITEM = " << item << endl;
    }

    return -1;
}

int main() {

    int vetor[5] = {1, 3, 5, 7, 9};

    int valor = buscaBinaria(vetor, 9, 4);
    if(valor == -1){
        cout << "Erro na busca!" << endl;
    } else {
        cout << vetor[valor] << endl;
    }

    return 0;
}
