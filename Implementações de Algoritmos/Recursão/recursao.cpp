#include <iostream>

using namespace std;

void contagemRecursiva(int contador){
    if(contador==0){ // Parada da recursão
        cout << "Atingimos o caso-base" << endl;
    }
    else {
        cout << "Estamos no caso recursivo" << endl;
        cout << contador << endl;
        contagemRecursiva(contador-1);
    }
}

int main(){

    contagemRecursiva(10);
    return 0;
}