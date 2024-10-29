// Nota: Esse é um programa baseado em um exercício da disciplina de Estruturas de Dados da Universidade Federal de Lavras. Está sendo utilizado
// apenas para a minha revisão para a primeira prova do semestre, e parte de sua implementação não foi feita por mim, e sim por quem organizou
// esse exercício, que não é de minha autoria.

#include <iostream>
using namespace std;

struct dado{
    int elemento;
    dado* proximo;
};

class pilha{
	private:
		dado *topo;

	public:
		pilha(){
			topo = NULL;
		}

		void empilha (dado entrada){
			dado *novo = new dado;
			*novo = entrada;
			novo->proximo = topo;
			topo = novo;
		}

		int desempilha(){
			if (topo == NULL) throw runtime_error("Pilha vazia!");
			int removido;
			dado *apagado = topo;
			removido = topo->elemento;
			topo = topo->proximo;
			apagado->proximo = NULL;
			delete apagado;
			return removido;
		}

		~pilha(){
			while (topo != NULL)
				desempilha();
		}		

		void inverte(){
            if(topo==NULL){
                return;
            }

            dado elementoAtual;
            pilha aux1 = pilha();
            pilha aux2 = pilha();

            while(topo!=NULL){
                elementoAtual.elemento = desempilha();
                aux1.empilha(elementoAtual);
            }

            while(aux1.topo!=NULL){
                elementoAtual.elemento = aux1.desempilha();
                aux2.empilha(elementoAtual);
            }

            while(aux2.topo!=NULL){
                elementoAtual.elemento = aux2.desempilha();
                empilha(elementoAtual);
            }
		}

		void imprime(){
            dado elementoAtual;
            while(topo!=NULL){
                elementoAtual.elemento = desempilha();
                cout << elementoAtual.elemento << " ";
            }
            cout << endl;
		}		
	};

int main(){
	int tamanho;
	cin >> tamanho;
	dado entrada;
	pilha mp;
	for (int i=0; i<tamanho; i++){
		cin>>entrada.elemento;
		mp.empilha(entrada);
	}
	mp.inverte();
	mp.imprime();
	return 0;
}