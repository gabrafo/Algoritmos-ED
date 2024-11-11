# Tabelas *Hash*
É uma estrutura de dados que utiliza o acesso direto em posições de um arranjo para facilitar o manejo de pares chave/valor. Tem uma velocidade de acesso de O(1).

Para se conseguir essa velocidade de acesso, o *hash* utiliza arranjos para poder acessar diretamente em posições. Portanto, para cada valor armazenado, utiliza-se algum mecanismo (funções *hash*) para encontrarmos a posição correspondente no arranjo. 

## Função *Hash*
É um algoritmo responsável por mapear os dados de comprimento variável para dados de comprimento fixo, ou seja, ao armazenar um texto, por exemplo, independentemente de seu tamanho, haverá o mesmo gasto de memória. Essa função funciona como uma "calculadora de índices", por ditar a forma que armazenaremos informações. **O objetivo de uma tabela hash é possibilitar armazenar os dados e identificar, através de uma chave de busca, a posição na tabela ocupada por determinado dado.**

Uma função *hash* não possui função inversa, ou seja, não é possível encontrar a entrada que a originou. Por isso, ela é uma função muito preciosa para o âmbito de segurança computacional, bem como checagem de integridade de arquivos, etc.

Outro uso das funções *hash* é justamente para as **tabelas *hash***, sendo utilizada para encontrar a posição de uma dada chave no vetor de armazenamento. 

Requisitos para uma função *hash* básica:
- **Consistência**. Imagine que você insere a string “maçã” e recebe o número 0,67. Todas as vezes que você inserir “maçã”, a função deverá retornar o número “0,67”.
- A função **deve mapear diferentes palavras para diferentes números**. Desta forma, uma função *hash* não será útil se ela sempre retornar “1”, independentemente da palavra inserida. No melhor caso, cada palavra diferente deveria ser mapeada e ligada a um número diferente.

Uma função bastante utilizada para chaves baseadas em números inteiros sem sinal/positivos é o **operador de resto**:
`h(k) = k mod m`
Sendo `k` o valor da chave, e `m` a capacidade da tabela. Geralmente, tentamos fazer com que `m`seja um número primo, para que seja mais difícil termos restos iguais (encaminhamento para índices).

Ao construirmos uma tabela *hash* dessa forma, iremos alocar mais espaço do que precisamos, o que pode variar a partir não apenas da quantidade de dados inseridos na tabela, mas também da função *hash* utilizada.

**Uma boa função *hash* pode ajudar em muito a economizar espaço na memória e a evitar colisões!**

Acima de 70% de ocupação em uma tabela *hash* pode acabar trazendo muitos prejuízos para seu funcionamento, o que não é recomendado. Assim, precisaríamos redimensioná-la, copiando seus dados para uma tabela *hash* com maior capacidade.

### O que são colisões?
**Colisões são quando a função *hash* direciona dois elementos para o mesmo espaço de memória**, sobrescrevendo o elemento mais antigo. Colisões em tabelas *hash*, infelizmente, são comuns, mas podem ser diminuídas com uma boa função *hash*. 

Geralmente, quando há uma colisão, a melhor saída é instaurar no *slot* de memória conflitante uma lista encadeada, facilitando a navegação do usuário. No entanto, essa saída pode diminuir (e muito) o desempenho da tabela *hash* caso o número de elementos nessa lista cresça.

### Escolhendo uma função de *hash*...
Um dos primeiros fatores a serem considerados no momento da escolha de uma função *hash* é o tamanho do conjunto de dados a serem inseridos em sua tabela *hash* correspondente. Para entendermos bem isso, precisamos entender o problema!

