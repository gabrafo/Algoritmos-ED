// Header-file (arquivo de cabeçalho), é incluído no início de Animal.cpp

#ifndef ANIMAL_HPP // 1. Verifica se ANIMAL_HPP não foi definido
#define ANIMAL_HPP // 2. Define ANIMAL_HPP

#include <string>

class Animal
{
    private:
        std::string nome;

    public:
        void rugir();
        std::string getNome();
        void setNome(std::string novoNome);

        // Sobrecarga do operador de igualdade (semelhante ao .equals em Java)
        bool operator==(const Animal& outro) const; // O último const garante que o método não mudará o estado de nenhum objeto
};

#endif // 3. Fim da guarda de inclusão
