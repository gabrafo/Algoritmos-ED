struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Pilha{
    private:
        ListNode* topo;
    
    public:
        Pilha(){
            topo = nullptr;
        }

        void empilhar(int i){
            ListNode* novo = new ListNode(i);
            novo->next = topo;
            topo = novo;
        }

        bool estaVazia() const{
            if(topo!=nullptr)
                return false;
            
            return true;
        }

        void desempilhar(){
            if(!estaVazia()){
                ListNode* aux = topo;
                topo = topo->next;
                aux->next = nullptr;
                delete aux;
            }
        }

        int retornarIntTopo() const{
            return topo->val;
        }

        void limparPilha(){
            while(topo != nullptr){
                desempilhar();
            }
        }

        ~Pilha(){
            limparPilha();
        }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        Pilha pilhaL1, pilhaL2;
        Pilha pilhaAux1;
        Pilha pilhaAux2;

        int topoL1 = 0;
        int topoL2 = 0;
        int acumuladorVaiUm = 0;

        while(l1!=nullptr || l2!=nullptr || acumuladorVaiUm > 0) {
            if(l1!=nullptr){
                pilhaL1.empilhar(l1->val);
                topoL1 = l1->val; 
                l1 = l1->next;
            } else {
                topoL1 = 0; 
            }

            if(l2!=nullptr){
                pilhaL2.empilhar(l2->val);
                topoL2 = l2->val;
                l2 = l2->next;
            } else {
                topoL2 = 0; 
            }

            int soma = topoL1 + topoL2 + acumuladorVaiUm;
            acumuladorVaiUm = soma / 10; // Se soma for 15, vai um
            pilhaAux1.empilhar(soma % 10); // Armazena o dígito menos significativo
        }

        while (!pilhaAux1.estaVazia()) {
            int valor = pilhaAux1.retornarIntTopo();
            pilhaAux2.empilhar(valor);
            pilhaAux1.desempilhar();
        }

        ListNode* inicio = nullptr;
        ListNode* fim = nullptr;

         while (!pilhaAux2.estaVazia()) {
            int valor = pilhaAux2.retornarIntTopo();
            ListNode* novo = new ListNode(valor);

            if (inicio == nullptr) {
                inicio = novo;
                fim = novo;
            } else {
                fim->next = novo;
                fim = novo;
            }
            pilhaAux2.desempilhar();
        }

        return inicio;
    }
};

// Complexidade da solução: O(n).