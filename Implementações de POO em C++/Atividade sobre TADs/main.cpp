#include "ong.hpp"
#include <iostream>

using namespace std;

/*
 * Este programa é desenvolvido para uma organização não governamental (ONG) que cuida de animais abandonados.
 * O sistema permite o registro de doações recebidas de pessoas e instituições, com informações sobre o doador, 
 * o valor da doação e o tipo de material doado. Além disso, possibilita o cadastro de animais acolhidos, 
 * contendo detalhes como nome, espécie, necessidades, local e data de resgate.
 * 
 * As principais entidades do sistema incluem:
 * 
 * 1. Doacao: Representa as doações recebidas. 
 *    Atributos: nome do material, finalidade, quantidade, valor estimado, nome do doador.
 *    Métodos: exibir dados da doação, recuperar nome do benfeitor que fez a doação.
 * 
 * 2. Animal: Representa os animais acolhidos pela ONG.
 *    Atributos: nome do animal, espécie, necessidades, local de resgate, data de resgate.
 *
 * 
 * 3. Benfeitor: Representa as pessoas ou instituições que fazem doações.
 *    Atributos: nome, tipo (física ou jurídica).
 *    Métodos: recuperar nome do benfeitor.
 * 
 * 4. ONG: Representa a organização como um todo.
 *    Atributos: vetores dinâmicos de animais, doações e benfeitores.
 *    Métodos: cadastro de objetos nos vetores citados acima, busca por doações de determinado benfeitor a partir de seu nome.
 * 
 * O objetivo do sistema é facilitar o gerenciamento das doações e dos animais, permitindo à ONG 
 * identificar quais benfeitores contribuíram com mais recursos e quais itens são mais necessários para os animais.
 * 
 * Além disso, esse programa é fruto de uma atividade envolvendo Tipos Abstratos de Dados na disciplina de Estrutura de Dados
 * na Universidade Federal de Lavras (UFLA).
 */

int main(){

    Animal animal_amado_meu1, animal_amado_meu2, animal_amado_comunitario;
    animal_amado_meu1 = Animal("Fiono", "Gato", "Carinho, amor e sossego", "Minha casa", "24/04/2023");
    animal_amado_meu2 = Animal("Suzie", "Cachorra", "Carinho, amor e muita atenção", "Minha casa", "10/03/2024");
    animal_amado_comunitario = Animal("Jeffinho", "Cachorro", "Carinho, amor e muito espaço no Mamute", "UFLA", "Desconhecido");

    Doacao doacao1, doacao2, doacao3, doacao4, doacao5, doacao6, doacao7;
    doacao1 = Doacao("Ração de gato adulto e castrado", "Alimentar os animais", 5, 137.55, "Gabriel");
    doacao2 = Doacao("Ração de cachorro filhote de raça pequena", "Alimentar os animais", 5, 130.99, "Flávia");
    doacao3 = Doacao("Medicamentos para gatos", "Tratamento de doenças", 10, 250.00, "Tailane");
    doacao4 = Doacao("Ração para cães adultos", "Alimentar os animais", 7, 180.50, "Tailane");
    doacao5 = Doacao("Camas para animais", "Conforto e abrigo", 3, 120.00, "CATI - Centro Acadêmico de Tecnologia da Informação");
    doacao6 = Doacao("Ração para gatos filhotes", "Alimentar os animais", 10, 150.00, "Gabriel");
    doacao7 = Doacao("Materiais de limpeza", "Higienização das instalações", 20, 300.00, "CATI - Centro Acadêmico de Tecnologia da Informação");


    Benfeitor benfeitor1, benfeitor2, benfeitor3, benfeitor4;
    benfeitor1 = Benfeitor("Gabriel", "Pessoa física");
    benfeitor2 = Benfeitor("Flávia", "Pessoa física");
    benfeitor3 = Benfeitor("Tailane", "Pessoa física");
    benfeitor4 = Benfeitor("CATI - Centro Acadêmico de Tecnologia da Informação", "Pessoa jurídica");
    

    ONG ong = ONG();

    ong.cadastrarAnimal(animal_amado_meu1);
    ong.cadastrarAnimal(animal_amado_meu2);
    ong.cadastrarAnimal(animal_amado_comunitario);

    ong.cadastrarDoacao(doacao1);
    ong.cadastrarDoacao(doacao2);
    ong.cadastrarDoacao(doacao3);
    ong.cadastrarDoacao(doacao4);
    ong.cadastrarDoacao(doacao5);
    ong.cadastrarDoacao(doacao6);
    ong.cadastrarDoacao(doacao7);

    ong.cadastrarBenfeitor(benfeitor1);
    ong.cadastrarBenfeitor(benfeitor2);
    ong.cadastrarBenfeitor(benfeitor3);
    ong.cadastrarBenfeitor(benfeitor4);

    ong.buscarDoacoesPorBenfeitor("Tailane");
    cout << endl;
    ong.buscarDoacoesPorBenfeitor("CATI - Centro Acadêmico de Tecnologia da Informação");

    return 0;
}