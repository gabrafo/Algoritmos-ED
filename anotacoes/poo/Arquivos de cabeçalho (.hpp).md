# Arquivos de cabeçalho
**OBS**: Essa anotação não se trata, necessariamente, de algo ligado a POO, mas sim de algo ligado à LP C++ como um todo. A deixei aqui, pois ela irá orientar muitos dos exemplos que veremos na implementação dos pilares de POO.

Os nomes dos elementos do programa, como variáveis, funções, classes etc., devem ser declarados para serem usados. Por exemplo, você não pode simplesmente escrever `x = 42` sem primeiro declarar 'x'.

A declaração informa ao compilador se o elemento é um **`int`**, um **`double`**, uma **função**, uma **`class`** ou alguma outra coisa. Além disso, cada nome deve ser declarado (direta ou indiretamente) em cada arquivo .cpp no qual ele é usado.

 Quando você compila um programa, cada arquivo .cpp é **compilado de maneira independente em uma unidade de compilação**. Ou seja, o compilador processa cada arquivo `.cpp` transformando-o em código objeto (.o ou .obj) sem saber o que está acontecendo nos outros arquivos `.cpp` do projeto. O compilador não tem conhecimento de quais nomes são declarados em outras unidades de compilação. Isso significa que, se você definir uma classe ou função ou variável global, **deverá fornecer uma declaração dela em cada arquivo .cpp adicional que a usa com a exata mesma nomenclatura**, qualquer inconsistência poderá gerar erros.

Para minimizar o potencial de erros, o C++ adotou a convenção de usar _arquivos de cabeçalho_ para conter declarações. Você faz as declarações em um arquivo de cabeçalho e depois usa a diretiva `#include` em cada arquivo .cpp ou outro arquivo de cabeçalho que requer essa declaração. **A diretiva `#include` insere uma cópia do arquivo de cabeçalho diretamente no arquivo .cpp antes da compilação.**

## O que colocar em um arquivo de cabeçalho?
Como um arquivo de cabeçalho pode ser incluído por vários arquivos, ele não pode conter definições que possam produzir várias definições de mesmo nome.

Os seguintes não são permitidos ou são considerados uma prática muito ruim:
- definições de tipo internas no namespace ou no escopo global
- definições de função não embutidas
- definições de variáveis não `const`
- definições de agregação
- `namespaces` sem nome
- diretivas `using`

## Guardas de inclusão
Normalmente, os arquivos de cabeçalho têm um _proteção de inclusão_ ou uma diretiva `#pragma once` para garantir que eles não sejam inseridos várias vezes em um só arquivo .cpp.

As guardas de inclusão utilizam diretivas do pré-processador para garantir que o conteúdo de um arquivo de cabeçalho seja incluído apenas uma vez durante a compilação. Isso é importante porque, se um arquivo de cabeçalho for incluído várias vezes, o compilador encontrará definições duplicadas, resultando em erros.

```cpp
#ifndef ANIMAL_HPP    // 1. Verifica se ANIMAL_HPP não foi definido
#define ANIMAL_HPP    // 2. Define ANIMAL_HPP

#include <string>
using namespace std;

class Animal {
private:
    string nome;     // Atributo nome

public:
    void rugir();    // Declaração do método rugir
    string getNome(); // Declaração do getter
    void setNome(string novoNome); // Declaração do setter
};

#endif // ANIMAL_HPP  // 3. Fim da guarda de inclusão
```

1. **Verificação**:
 A linha `#ifndef ANIMAL_HPP` verifica se a macro `ANIMAL_HPP` não está definida. Se não estiver, o compilador prossegue para a próxima linha.
 
2. **Definição**:
`#define ANIMAL_HPP` define a macro `ANIMAL_HPP`. A partir desse ponto, se o arquivo for incluído novamente, essa macro estará definida.

3. **Inclusão de Código**:
`#endif` finaliza a guarda de inclusão, indicando que o bloco de código acima deve ser tratado como um único bloco.

**OBS**: Quaisquer linhas entre `#define` e `#endif` contêm a definição da classe e quaisquer outras declarações necessárias para seu funcionamento/implementação.

**Fonte**: [Arquivos de cabeçalho (C++) | Microsoft Learn](https://learn.microsoft.com/pt-br/cpp/cpp/header-files-cpp?view=msvc-170).