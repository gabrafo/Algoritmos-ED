#include <iostream>

typedef int dado;

using namespace std;

// Implementação básica INCOMPLETA de árvores ABB. Há de ser atualizada para contemplar a estrutura completa.

struct noh{
        dado elemento;
        noh* pai = NULL;
        noh* esq = NULL;
        noh* dir = NULL;
};

class abb{
    private:
        noh* raiz;
        int tamanho;

        noh* inserirNoh(noh* nohAtual, dado entrada){
            if(nohAtual == NULL){
                noh* novo = new noh;
                novo->elemento = entrada;
                return novo;
            } else {
                if(entrada < nohAtual->elemento){
                    nohAtual->esq = inserirNoh(nohAtual, entrada);
                    nohAtual->esq->pai = nohAtual;
                } else {
                    nohAtual->dir = inserirNoh(nohAtual->dir, entrada);
                    nohAtual->dir->pai = nohAtual;
                }
            }
            return nohAtual;
        }

        noh* buscaNoh(dado buscado){
            noh *nohAtual = raiz;
            while(nohAtual!=NULL){
                if(nohAtual->elemento == buscado){
                    return nohAtual;
                } else if(nohAtual->elemento > buscado)
                    nohAtual = nohAtual->esq;
                else
                    // TODO()
            }
        }

        noh* menorValor(noh* nohAtual){
            while(nohAtual->esq!=NULL){
                nohAtual = nohAtual->esq;
            }

            return nohAtual;
        }

        noh* maiorValor(noh* nohAtual){
            while(nohAtual->dir!=NULL){
                nohAtual = nohAtual->dir;
            }

            return nohAtual;
        }

        void percorreEmOrdem(noh* nohAtual){
            if(nohAtual!=NULL){
                percorreEmOrdem(nohAtual->esq);
                cout << nohAtual->elemento << " ";
                percorreEmOrdem(nohAtual->dir);
            }
        }


    public:
        void busca(dado procurado){
            noh* retornado = buscaNoh(procurado);

            if(retornado!=NULL){
                cout << retornado->elemento;
                if(retornado!=raiz){
                    cout << ": Filho de " << retornado->pai->elemento << endl;
                }
            } else {
                cout << "Não encontrado!" << endl;
            }
        }

        ~abb(){
            while(raiz!=NULL){
                remove(raiz->elemento);
            }
        }

        bool vazia(){
            return (raiz == NULL);
        }


};