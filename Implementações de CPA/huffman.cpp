#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
PROBLEMA: O CÓDIGO DE HUFFMAN
================================================================================
O objetivo do algoritmo de Huffman é compactar um texto. 
Em vez de usar o mesmo número de bits (geralmente 8 bits / 1 byte) para cada caractere,
nós usamos códigos menores (menos bits) para caracteres que aparecem MUITO,
e códigos maiores (mais bits) para caracteres que aparecem POUCO.
Usaremos uma abordagem gulosa, a do código de Huffman mesmo.
*/

struct node {
    int freq;
    node* left;
    node* right;
};

struct greaterFreq {
    bool operator()(const node* a, const node* b) const { // Pra conseguir comparar na hora de criar a fila, como são ponteiros n dá pra colocar dentro da struct node
        return a->freq > b->freq;
    }
};

void kill(node* n){ // Função recursiva pra liberar memória ao fim da Codificação de Huffman
    if (n == nullptr) return;
    kill(n->right);
    kill(n->left);
    delete n;
}

int huffman(vector<node> element, int n) {
    priority_queue<node*, vector<node*>, greaterFreq> Q;
    for(int i = 0; i<n; i++) {
        Q.push(new node{element[i].freq, nullptr, nullptr});
    }
    for(int i = 0; i<n-1; i++) {
        node *x, *y, *z;
        x = Q.top();
        Q.pop();
        y = Q.top();
        Q.pop();
        z = new node();
        z->freq = x->freq + y->freq;
        z->left = x;
        z->right = y;
        Q.push(z);
    }
    int totalSum = Q.top()->freq;
    kill(Q.top());
    return totalSum;
}

int main() {
    int n;

    while (cin >> n && n != 0) {
        vector<node> element(n);
        for (int i = 0; i < n; i++) {
            cin >> element[i].freq;
        }
        int totalSum = huffman(element, n);
        cout << totalSum << endl;
    }
    return 0;
}
