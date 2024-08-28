#include <iostream>

using namespace std;

void sauda2(string nome){
    cout << "Como vai " << nome << "?" << endl;
}

void tchau(){
    cout << "ok, tchau!" << endl;
}

void sauda(string nome){
    cout << "Olá, " << nome << "!" << endl;
    sauda2(nome);
    cout << "preparando para dizer tchau..." << endl;
    tchau();
}

int main(){

    sauda("Gabriel");
    return 0;
}

