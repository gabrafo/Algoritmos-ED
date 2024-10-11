#include <ong.hpp>
#include <iostream>
#include <cstring>

using namespace std;

// CLASSE ANIMAL

Animal::Animal(){}

Animal::Animal(const string& nome, const string& especie, const string& necessidades,
const string& localDeResgate, const string& dataDeResgate){

    this->nome = nome;
    this->especie = especie;
    this->necessidades = necessidades;
    this->localDeResgate = localDeResgate;
    this->dataDeResgate = dataDeResgate;
}

// ---

// CLASSE DOACAO

Doacao::Doacao(){}

Doacao::Doacao(const string& nome, const string& finalidade, const int& quantidade, const float& valorDoacao,
const std::string& nomeBenfeitor){
    this->nome = nome;
    this->finalidade = finalidade;
    this->quantidade = quantidade;
    this->valorDoacao = valorDoacao;
    this->nomeBenfeitor = nomeBenfeitor;
}

const string& Doacao::recuperarNomeBenfeitor() const{
    return nomeBenfeitor;
}

void Doacao::exibirDados() const{
    cout << "Nome: " << nome << "; "
    << "Finalidade: " << finalidade << "; "
    << "Quantidade: " << quantidade << "; "
    << "Valor estimado da doação: " << valorDoacao << "; "
    << "Benfeitor responsável pela doação: " << nomeBenfeitor << "."
    << endl;
}

// ---

// CLASSE BENFEITOR

Benfeitor::Benfeitor(){}

Benfeitor::Benfeitor(const std::string& nome, const std::string& tipo){
    this->nome = nome;
    this->tipo = tipo;
}

const string& Benfeitor::recuperarNome() const{
    return nome;
}

// ---

// CLASSE ONG

ONG::ONG(){
    capAnimais = 5;
    capDoacoes = 5;
    capBenfeitores = 5;

    animais = new Animal[capAnimais];
    doacoes = new Doacao[capDoacoes];
    benfeitores = new Benfeitor[capBenfeitores];

    qntdAnimais = 0;
    qntdDoacoes = 0;
    qntdBenfeitores = 0;
}

ONG::~ONG(){
    delete[] animais;
    delete[] doacoes;
    delete[] benfeitores;
}

void ONG::copiarRecursos(const ONG& outraONG){
    qntdAnimais = outraONG.qntdAnimais;
    qntdDoacoes = outraONG.qntdDoacoes;
    qntdBenfeitores = outraONG.qntdBenfeitores;

    capAnimais = outraONG.capAnimais;
    capDoacoes = outraONG.capDoacoes;
    capBenfeitores = outraONG.capBenfeitores;

    animais = new Animal[capAnimais];
    doacoes = new Doacao[capDoacoes];
    benfeitores = new Benfeitor[capBenfeitores];

    for (unsigned int i = 0; i < qntdAnimais; ++i) {
        animais[i] = outraONG.animais[i]; // Usa o operador de atribuição
    }

    for (unsigned int i = 0; i < qntdDoacoes; ++i) {
        doacoes[i] = outraONG.doacoes[i]; // Usa o operador de atribuição
    }

    for (unsigned int i = 0; i < qntdBenfeitores; ++i) {
        benfeitores[i] = outraONG.benfeitores[i]; // Usa o operador de atribuição
    }
}

ONG::ONG(const ONG& outraONG) {
    copiarRecursos(outraONG);
}

ONG& ONG::operator=(const ONG& outraONG){
    if (this != &outraONG) {
        delete[] animais;
        delete[] doacoes;
        delete[] benfeitores;

        copiarRecursos(outraONG);
    }

    // Retorno de derreferência
    return *this;
}

void ONG::redimensionarAnimais() {
    unsigned int novaCapacidade = capAnimais * 2;
    Animal* novoVetor = new Animal[novaCapacidade];

    for (unsigned int i = 0; i < qntdAnimais; ++i) {
        novoVetor[i] = animais[i];
    }

    delete[] animais;

    animais = novoVetor;
    capAnimais = novaCapacidade;
}

void ONG::redimensionarDoacoes() {
    unsigned int novaCapacidade = capDoacoes * 2;
    Doacao* novoVetor = new Doacao[novaCapacidade];

    for (unsigned int i = 0; i < qntdDoacoes; ++i) {
        novoVetor[i] = doacoes[i];
    }

    delete[] doacoes;

    doacoes = novoVetor;
    capDoacoes = novaCapacidade;
}

void ONG::redimensionarBenfeitores() {
    unsigned int novaCapacidade = capBenfeitores * 2;
    Benfeitor* novoVetor = new Benfeitor[novaCapacidade];

    for (unsigned int i = 0; i < qntdBenfeitores; ++i) {
        novoVetor[i] = benfeitores[i];
    }

    delete[] benfeitores;

    benfeitores = novoVetor;
    capBenfeitores = novaCapacidade;
}

void ONG::cadastrarAnimal(const Animal& animal) {
    if (qntdAnimais >= capAnimais) {
        redimensionarAnimais();
    }
    animais[qntdAnimais] = animal;
    qntdAnimais+=1;
}

void ONG::cadastrarDoacao(const Doacao& doacao) {
    if (qntdDoacoes >= capDoacoes) {
        redimensionarDoacoes();
    }
    doacoes[qntdDoacoes] = doacao;
    qntdDoacoes+=1;
}

void ONG::cadastrarBenfeitor(const Benfeitor& benfeitor) {
    if (qntdBenfeitores >= capBenfeitores) {
        redimensionarBenfeitores();
    }
    benfeitores[qntdBenfeitores] = benfeitor; 
    qntdBenfeitores+=1;
}

void ONG::buscarDoacoesPorBenfeitor(const std::string& nomeBenfeitor) const{
    cout << "Doações feitas por " << nomeBenfeitor << ":" << endl;

    int contadorDoacoes = 0;

    for(unsigned int i = 0; i<qntdDoacoes; i++){
        if(doacoes[i].recuperarNomeBenfeitor() == nomeBenfeitor){
            doacoes[i].exibirDados();
            contadorDoacoes+=1;
        }
    }

    if(contadorDoacoes == 0){
        cout << "Nenhuma doação encontrada :(" << endl;
    }
}