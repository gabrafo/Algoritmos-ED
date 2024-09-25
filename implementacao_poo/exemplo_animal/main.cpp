#include "Animal.hpp"
#include <iostream>

using namespace std;
int main(){
    Animal leao, gato, formiga;
    leao.setNome("Leão");
    leao.rugir();

    gato.setNome("Leão"); // Meu gatinho Fiono é um leão.
    gato.rugir();

    formiga.setNome("Formiga");
    formiga.rugir(); // Formiga rugindo? Que mundo é esse!

    if(formiga == leao){
        cout << "Se rugiu é porque são iguais." << endl;
    } else {
        cout << "Esse é um mundo de leões e formigas." << endl;
    }

    if(leao == gato){
        cout << "Felinos são todos ferozes!" << endl;
    }
    return 0;
}