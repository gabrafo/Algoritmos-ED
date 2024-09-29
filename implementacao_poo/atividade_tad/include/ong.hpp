#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class Animal
{
    private:
        std::string nome;
        std::string especie;
        std::string necessidades;
        std::string localDeResgate;
        std::string dataDeResgate;

    public:
        Animal();

        Animal(const std::string& nome, const std::string& especie, const std::string& necessidades,
        const std::string& localDeResgate, const std::string& dataDeResgate); // Usado para cadastrar animais
};

class Doacao
{
    private:
        std::string nome;
        std::string finalidade;
        int quantidade;
        float valorDoacao; // É um valor estimado em caso de doação de materiais
        std::string nomeBenfeitor;

    public:
        Doacao();

        Doacao(const std::string& nome, const std::string& finalidade, const int& quantidade,
        const float& valorDoacao, const std::string& nomeBenfeitor); // Usado para cadastrar doações

        const std::string& recuperarNomeBenfeitor() const;

        void exibirDados() const;
};

class Benfeitor
{
    private:
        std::string nome;
        std::string tipo;
    
    public:
        Benfeitor();

        // Usado para cadastrar benfeitores
        Benfeitor(const std::string& nome, const std::string& tipo);

        const std::string& recuperarNome() const;
};

class ONG{
    private:
        Animal* animais;
        Doacao* doacoes;
        Benfeitor* benfeitores;
        unsigned int qntdAnimais, qntdDoacoes, qntdBenfeitores;
        unsigned int capAnimais, capDoacoes, capBenfeitores;

        void copiarRecursos(const ONG& outra);

        void redimensionarAnimais();
        void redimensionarDoacoes();
        void redimensionarBenfeitores();

    public:
        ONG();
        ~ONG();
        ONG(const ONG& outraONG);
        ONG& operator=(const ONG& ong);

        void cadastrarAnimal(const Animal& animal);
        void cadastrarDoacao(const Doacao& doacao);
        void cadastrarBenfeitor(const Benfeitor& benfeitor);
        void buscarDoacoesPorBenfeitor(const std::string& nomeBenfeitor) const;
};