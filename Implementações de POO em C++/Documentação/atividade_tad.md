# Documentação do Sistema de Gestão de ONG

Este sistema foi desenvolvido para auxiliar uma organização não governamental (ONG) que acolhe cães e gatos abandonados no gerenciamento de seus animais resgatados, doações recebidas e benfeitores. Através deste sistema, a ONG pode cadastrar novos animais, registrar doações e consultar informações sobre seus benfeitores.
Exercício da disciplina de **Estruturas de Dados** na **Universidade Federal de Lavras** (**UFLA**).
**Implementação por**: Gabriel Fagundes Mesquita Sousa.

## Classes Principais

### 1. Classe Animal
Representa os animais acolhidos pela ONG.

**Atributos:**
- std::string nome: Nome do animal.
- std::string especie: Espécie do animal (e.g., cão, gato).
- std::string necessidades: Descrição das necessidades especiais do animal (e.g., ração especial, medicamentos).
- std::string localDeResgate: Local onde o animal foi resgatado.
- std::string dataDeResgate: Data em que o animal foi resgatado.

**Métodos:**
- Construtor padrão: Inicializa um objeto Animal vazio.
- Construtor parametrizado: Inicializa um objeto Animal com os valores passados como parâmetro (nome, espécie, necessidades, local de resgate e data de resgate).
```cpp
Animal(const std::string& nome, const std::string& especie, const std::string& necessidades, const std::string& localDeResgate, const std::string& dataDeResgate);
```

### 2. Classe Doacao
Representa as doações feitas à ONG, que podem ser em dinheiro ou materiais, e são associadas a um benfeitor.

**Atributos:**
- std::string nome: Nome do item doado.
- std::string finalidade: Finalidade da doação (e.g., alimentação, cuidados médicos).
- int quantidade: Quantidade do material doado.
- float valorDoacao: Valor estimado da doação (caso seja material).
- std::string nomeBenfeitor: Nome do benfeitor que fez a doação.

**Métodos:**
- Construtor padrão: Inicializa um objeto Doacao vazio.
- Construtor parametrizado: Inicializa um objeto Doacao com os valores fornecidos (nome, finalidade, quantidade, valor estimado e nome do benfeitor).
```cpp
Doacao(const std::string& nome, const std::string& finalidade, const int& quantidade, const float& valorDoacao, const std::string& nomeBenfeitor);
```
- recuperarNomeBenfeitor(): Retorna o nome do benfeitor responsável pela doação.
```cpp
const std::string& recuperarNomeBenfeitor() const;
```
- exibirDados(): Exibe as informações detalhadas da doação.
```cpp
void exibirDados() const;
```

### 3. Classe Benfeitor
Representa os benfeitores (pessoas físicas ou jurídicas) que fazem doações para a ONG.

**Atributos:**
- std::string nome: Nome do benfeitor.
- std::string tipo: Tipo do benfeitor (pessoa física ou jurídica).

**Métodos:**
- Construtor padrão: Inicializa um objeto Benfeitor vazio.
- Construtor parametrizado: Inicializa um objeto Benfeitor com nome e tipo fornecidos.
Benfeitor(const std::string& nome, const std::string& tipo);
- recuperarNome(): Retorna o nome do benfeitor.
```cpp
const std::string& recuperarNome() const;
```

### 4. Classe ONG
Gerencia as operações gerais da ONG, como cadastro de animais, doações e benfeitores.

**Atributos:**
- Animal* animais: Vetor dinâmico de objetos Animal.
- Doacao* doacoes: Vetor dinâmico de objetos Doacao.
- Benfeitor* benfeitores: Vetor dinâmico de objetos Benfeitor.
- unsigned int qntdAnimais, qntdDoacoes, qntdBenfeitores: Quantidade de animais, doações e benfeitores cadastrados.
- unsigned int capAnimais, capDoacoes, capBenfeitores: Capacidades atuais dos vetores.

**Métodos:**
- Construtor e destrutor: Inicializam e liberam os recursos alocados para os vetores dinâmicos.
```cpp
ONG();
~ONG();
```
- Operador de cópia e atribuição: Define como um objeto ONG deve ser copiado ou atribuído.
```cpp
ONG(const ONG& outraONG);
ONG& operator=(const ONG& ong);
```
- redimensionarAnimais(), redimensionarDoacoes(), redimensionarBenfeitores(): Métodos privados para redimensionar os vetores dinâmicos quando necessário.
```cpp
void redimensionarAnimais();
void redimensionarDoacoes();
void redimensionarBenfeitores();
```
- cadastrarAnimal(): Cadastra um novo animal no vetor de animais.
```cpp
void cadastrarAnimal(const Animal& animal);
```
- cadastrarDoacao(): Cadastra uma nova doação no vetor de doações.
```cpp
void cadastrarDoacao(const Doacao& doacao);
```
- cadastrarBenfeitor(): Cadastra um novo benfeitor no vetor de benfeitores.
```cpp
void cadastrarBenfeitor(const Benfeitor& benfeitor);
```
- buscarDoacoesPorBenfeitor(): Exibe todas as doações feitas por um benfeitor específico a partir de seu nome.
```cpp
void buscarDoacoesPorBenfeitor(const std::string& nomeBenfeitor) const;
```