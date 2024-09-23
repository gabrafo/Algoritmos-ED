#include "Animal.hpp"
#include <iostream>

using namespace std;

void Animal::rugir(){
    cout << nome << " está rugindo!" << endl;
}

string Animal::getNome(){
    return nome;
}

void Animal::setNome(string novoNome){
    nome = novoNome;
}