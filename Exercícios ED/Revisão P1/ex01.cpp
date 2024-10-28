// Nota: Esse é um programa baseado em um exercício da disciplina de Estruturas de Dados da Universidade Federal de Lavras. Está sendo utilizado
// apenas para a minha revisão para a primeira prova do semestre, e parte de sua implementação não foi feita por mim, e sim por quem organizou
// esse exercício, que não é de minha autoria.

#include <iostream>
using namespace std;

struct dado{
	string nome = "vazio";
	string tipo;
	dado *proximo;
};

class fila{
	private:
		dado *inicio;
		dado *fim;

	public:
		fila(){
			inicio = NULL;
			fim = NULL;			
		}

		void enfileirar (dado entrada){
			dado *novo = new dado;
			*novo = entrada;
			if (fim != NULL)
				fim->proximo = novo;
			else
				inicio = novo;
			fim = novo;
		}

		dado desenfileirar(){
			if (inicio == NULL) throw runtime_error("Fila vazia!");
			dado *retornado = new dado;
			dado *removido = inicio;
			if (inicio == fim)
				fim = NULL;
			retornado->nome = inicio->nome;
			retornado->tipo = inicio->tipo;
			inicio = inicio->proximo;
			removido->proximo = NULL;
			delete removido;
			return *retornado;
		}

		~fila(){
			while (inicio != NULL)
				desenfileirar();
		}

        void reordenarPrioridade(){
            // 3 prioritárias p/ 1 normal

            int contador = 0;
            fila auxPrioridade = fila();
            fila auxNormal = fila();
            dado clienteAtual;

            while(inicio!=NULL){
                clienteAtual = desenfileirar();
                if(clienteAtual.tipo == "prioridade"){
                    auxPrioridade.enfileirar(clienteAtual);
                } else {
                    auxNormal.enfileirar(clienteAtual);
                }
            }

            while(auxPrioridade.inicio!=NULL or auxNormal.inicio!=NULL){
                if(auxPrioridade.inicio!=NULL and contador < 3){
                    enfileirar(auxPrioridade.desenfileirar());
                    contador++;
                }

                contador = 0;

                if(auxNormal.inicio!=NULL){
                    enfileirar(auxNormal.desenfileirar());
                }
            }

        }

		dado atendimento (){
		    if (inicio == NULL) throw runtime_error("AGUARDE");

            reordenarPrioridade();
            return desenfileirar();
		}
};
		int main(){
			fila banco;
			string comando,tipo;
			dado entrada, atendido;
			cin>>comando;

			while (comando != "fim"){
					if (comando == "normal"){
						cin>>entrada.nome;
						entrada.tipo = "normal";
						banco.enfileirar(entrada);
					} else if (comando == "prioridade"){
						cin>>entrada.nome;
						entrada.tipo = "prioridade";
						banco.enfileirar(entrada);
					} else if (comando == "atender"){
                        atendido = banco.atendimento();
                        cout << atendido.nome << endl;
					}
					cin>>comando;
			}

	return 0;
}