# Dividir para conquistar
Nesse documento, explicarei mais a fundo essa técnica, além de explicar o funcionamento de dois exercícios/códigos que a utilizam (um em Java, e o outro em C++).

## Documentando o código (Exemplo em Java)...
No arquivo [`dc_recursao.java`](../dc_recursao.java) temos um exemplo da técnica de resolução de problemas dividir para conquistar, a seguir irei explicar o problema que iremos resolver, os passos tomados para que pudéssemos abordá-lo e detalharei sua resolução final. No entanto, antes disso, precisamos aprender o que é essa técnica e qual a sua usabilidade.

**Nota:** O conteúdo desse texto se baseia diretamente em um exemplo dado no livro "Entendendo Algoritmos", é uma leitura extremamente recomendada.

### O que é a técnica dividir para conquistar?
É um paradigma de design de algoritmos que resolve problemas complexos dividindo-os em subproblemas menores e mais simples, resolvendo esses subproblemas **recursivamente**, e então combinando suas soluções para obter a solução do problema original. Para resolvermos um problema utilizando DC, precisamos seguir os seguintes passos:

1. Descubra o caso-base, que deve ser o caso mais simples possível.
2. Divida ou diminua o seu problema até que ele se torne o caso-base.

Essa técnica é utilizada em diversos algoritmos, como a busca binária, o *quicksort*, etc.

### Ok, mas qual é o problema?
É um problema simples: temos uma lista (ou um vetor, utilizamos listas apenas para simplificar a implementação) contendo n valores e queremos retornar sua soma. Para isso, poderíamos utilizar um laço para facilmente chegarmos a um resultado satisfatório, no entanto, para colocarmos em prática a técnica dividir para conquistar, utilizaremos a recursão.

![Representação da lista "lista" contendo os valores 2, 4 e 6](https://github.com/gabrafo/Algoritmos-ED/blob/master/Implementa%C3%A7%C3%B5es%20de%20Algoritmos/Documenta%C3%A7%C3%A3o/Imagens/Imagem%201.png)

### E agora? Como o resolvemos utilizando DC?
Como mencionado anteriormente, precisamos de duas etapas para resolver um problema com a técnica dividir para conquistar: descobrir o caso-base e diminuir o nosso problema até que ele se torne esse caso. Com isso em mente, sabemos também que uma recursão também tem dois casos pré-definidos: o recursivo (que perpetua a repetição da função) e o base (que encerra a função e retorna os valores gerados a partir da pilha para o usuário).

No nosso exemplo, qual seria o caso-base?
**R:** O caso mais simples possível é quando a lista está vazia ou contém apenas um elemento. Se a lista estiver vazia, a soma é 0. Se houver apenas um elemento, a soma é o próprio elemento.

- Caso-base:
![Representação do caso-base (lista sem nenhum elemento)](https://github.com/gabrafo/Algoritmos-ED/blob/master/Implementa%C3%A7%C3%B5es%20de%20Algoritmos/Documenta%C3%A7%C3%A3o/Imagens/Imagem%202.png)

Respondida essa pergunta, precisamos pensar em como gerar um caso recursivo para subdividir o problema até que alcançemos o caso-base. Para isso, podemos reduzir o tamanho da nossa lista, até que ela contenha um único elemento ou fique vazia. A cada passo da recursão, pegamos um elemento da lista (por exemplo, o primeiro) e somamos ao resultado da soma recursiva dos elementos restantes (que será a chamada da função `soma()` descrita a seguir passando como parâmetro uma sublista da lista original).

- Caso recursivo:
![Representação do caso recursivo (valor do primeiro elemento de lista + chamada da função com a sublista de lista)](https://github.com/gabrafo/Algoritmos-ED/blob/master/Implementa%C3%A7%C3%B5es%20de%20Algoritmos/Documenta%C3%A7%C3%A3o/Imagens/Imagem%203.png)

### Resolução final (em Java)

A seguir, apresentamos a implementação final da solução usando Java, baseada na técnica de dividir para conquistar:
```java
    public static int soma(List<Integer> lista){

        if(lista.isEmpty()){ // Caso-base: Tamanho zero
            return 0;
        }

        List<Integer> sublista = lista.subList(1, lista.size());

        // Linhas 16-21 servem apenas para debug do método e podem ser ignoradas
        System.out.println("Valor do primeiro elemento de 'lista': " + lista.get(0));
        System.out.println("Valor dos elementos restantes de 'lista': ");
        for(int i = 0; i<lista.subList(1, lista.size()).size(); i++){
            System.out.println(sublista.get(i));
        }
        System.out.println();

        return lista.get(0) + soma(sublista); // Caso-recursivo: Passo uma sublista como parâmetro que vai do segundo elemento até o último
    }
```

#### Explicação do Código

**Função `soma(List<Integer> lista)`:** Esta função implementa a técnica de dividir para conquistar para somar os elementos de uma lista de inteiros.

##### Estrutura da Função:

1. **Caso Base:** A função verifica se a lista está vazia utilizando o método `isEmpty()`. Se estiver vazia, retorna 0, pois não há elementos para somar.

```java
if(lista.isEmpty()){
    return 0;
}
```

2. **Preparação para o Caso Recursivo:** A função cria uma sublista a partir do segundo elemento até o último, utilizando `subList(1, lista.size())`. Essa sublista é passada na chamada recursiva.

```java
List<Integer> sublista = lista.subList(1, lista.size());
```

3. **Código de Debug:** As linhas de debug (16-21) exibem o valor do primeiro elemento da lista e os elementos da sublista. Essa parte pode ser ignorada para o entendimento da lógica principal.

```java
System.out.println("Valor do primeiro elemento de 'lista': " + lista.get(0));
System.out.println("Valor dos elementos restantes de 'lista': ");
for(int i = 0; i < lista.subList(1, lista.size()).size(); i++){
    System.out.println(sublista.get(i));
}
System.out.println();
```

4. **Caso Recursivo:** A função retorna o primeiro elemento da lista somado ao resultado da chamada recursiva com a sublista. Este passo reduz o problema ao remover o primeiro elemento da lista a cada chamada até que a lista esteja vazia (caso base).

```java
return lista.get(0) + soma(sublista);
```

#### E a pilha de chamadas?
Caso não saiba, sempre que usamos recursão trabalhamos com um empilhamento de chamadas de função. Tratarei brevemente desse conceito agora, para que eu possa explicar como ele se aplica nesse exemplo.

Imagine que você está construindo uma torre de blocos onde cada bloco é colocado em cima do bloco anterior. Este processo pode ser comparado ao conceito de pilha em programação.
(*Push*: adição de elementos) -> Cada vez que você adiciona um bloco à torre, você coloca o novo bloco em cima do bloco que já está lá. Isso é como empilhar chamadas de função na memória, onde cada nova chamada de função é colocada em cima da anterior.
(*Pop*: retirada de elementos) -> Quando você decide remover um bloco da torre, você sempre retira o bloco do topo. Assim, o bloco que estava mais recentemente no topo é o primeiro a ser removido. Isso é semelhante ao desempilhamento de chamadas de função, onde a função que foi chamada mais recentemente é a primeira a retornar seu valor.

##### E no exemplo original (da soma)?
No exemplo original, temos chamadas subsequentes da função `soma()` de uma lista com número de elementos cada vez menor, até não restar nenhum. Nesse processo, há um constante empilhamento de novas chamadas na pilha, até que cheguemos ao cenário do caso-base.

![Pilha de chamadas: empilhamento](https://github.com/gabrafo/Algoritmos-ED/blob/master/Implementa%C3%A7%C3%B5es%20de%20Algoritmos/Documenta%C3%A7%C3%A3o/Imagens/Imagem%204.png)
Após construirmos a pilha de chamadas, precisamos desempilhá-la até retornarmos à função que originou as tantas chamadas recursivas que estamos lidando.

![Pilha de chamadas: desempilhamento](https://github.com/gabrafo/Algoritmos-ED/blob/master/Implementa%C3%A7%C3%B5es%20de%20Algoritmos/Documenta%C3%A7%C3%A3o/Imagens/Imagem%205.png)

---

## Documentando o código (Exemplo em C++)...
Agora vamos explorar um exemplo semelhante ao que vimos em Java, mas desta vez implementado em C++. O código a seguir foi inspirado no exercício 4.2 do livro "Entendendo Algoritmos", o arquivo contendo o código-fonte é: [`dc_recursao.cpp`](../dc_recursao.cpp).

### Qual é o problema?
Esse exemplo utiliza a técnica de dividir para conquistar (DC) para resolver um problema simples: contar o número de elementos em uma lista recursivamente.

### Como o resolvemos utilizando DC?
Como no exemplo em Java, precisamos de duas etapas para resolver um problema com a técnica dividir para conquistar: descobrir o caso-base e diminuir o nosso problema até que ele se torne esse caso. Como estamos tratando de uma contagem recursiva, o caso mais simples é aquele em que a lista está vazia ou contém apenas um elemento. Assim sendo, para chegarmos até esse cenário, precisamos reduzir recursivamente o tamanho da lista, além de acrescer em um o valor retornado (assim iremos contá-la).

### Resolução final (em C++)

A seguir, apresentamos a implementação final da solução usando C++, baseada na técnica de dividir para conquistar:
```cpp
int contaLista(list<int> lista){
    if(lista.empty()){ // Caso-base: lista vazia
        return 0;
    }
    lista.pop_back(); // Retira o último elemento da lista
    return 1 + contaLista(lista); // Caso recursivo: ainda há elementos a serem contados, soma 1 e chama a função novamente
}
```

### Explicação do Código

**Função `contaLista(list<int> lista)`:** Esta função implementa a técnica de dividir para conquistar para contar o número de elementos em uma lista de inteiros.

#### Estrutura da Função:

1. **Caso Base:** A função começa verificando se a lista está vazia usando o método `empty()` (que retorna um booleano `true` ou `false`). Se a lista estiver vazia, a função retorna 0, pois não há elementos para contar.

```cpp
if(lista.empty()){
    return 0;
}
```

2. **Preparação para o Caso Recursivo:** A função utiliza o método `pop_back()` para remover o último elemento da lista. Isso reduz o tamanho da lista em 1, preparando-a para a próxima chamada recursiva.

```cpp
lista.pop_back();
```

3. **Caso Recursivo:** A função retorna 1 (que representa o elemento removido) somado ao resultado da chamada recursiva de `contaLista(lista)`. A cada chamada recursiva, o tamanho da lista diminui até que ela fique vazia, momento em que o caso-base é alcançado.

```cpp
return 1 + contaLista(lista);
```

#### Explicando a pilha de chamadas
Um breve esclarecimento, caso você não seja familiar com o conceito ou não tenha lido/entendido a explicação no exemplo em Java: quando usamos recursão, cada chamada da função cria uma nova entrada na "pilha de chamadas" na memória. Pense nisso como uma pilha de pratos, onde cada prato novo (chamada de função) é colocado em cima dos anteriores (empilhamento). Quando o caso-base é alcançado, as chamadas começam a ser removidas da pilha uma a uma, retornando os valores até que o problema original seja resolvido. No exemplo da louça, ao secarmos os pratos recém-lavados (desempilhamento), começaremos com os primeiros da pilha (mais recentes), por serem os mais acessíveis.

![Ilustração de uma pilha de pratos (não foi feita por mim)](https://github.com/gabrafo/Algoritmos-ED/blob/master/Implementa%C3%A7%C3%B5es%20de%20Algoritmos/Documenta%C3%A7%C3%A3o/Imagens/Imagem%206.png)

Assim como no exemplo em Java, o uso de recursão em C++ resulta em um empilhamento de chamadas de função. A seguir, vamos explorar esse conceito para entender como ele funciona neste exemplo. 

##### E no exemplo original (da contagem de elementos)?
Vejamos o estado da nossa lista antes do início da função recursiva:

![Estrutura 'lista' antes do início da função](https://github.com/gabrafo/Algoritmos-ED/blob/master/Implementa%C3%A7%C3%B5es%20de%20Algoritmos/Documenta%C3%A7%C3%A3o/Imagens/Imagem%207.png)

É esperado que tenhamos um retorno com valor 10, visto que temos 10 elementos ao todo dispostos na lista.

No exemplo original, temos chamadas subsequentes da função `contaLista()` de uma lista com número de elementos cada vez menor, até não restar nenhum. Nesse processo, há um constante empilhamento de novas chamadas na pilha, até que cheguemos ao cenário do caso-base.

![Primeira chamada recursiva](https://github.com/gabrafo/Algoritmos-ED/blob/master/Implementa%C3%A7%C3%B5es%20de%20Algoritmos/Documenta%C3%A7%C3%A3o/Imagens/Imagem%208.png)

Após construirmos a pilha de chamadas, precisamos desempilhá-la até retornarmos à função que originou as tantas chamadas recursivas que estamos lidando.

![Chamadas subsequentes até chegarmos ao caso-base](https://github.com/gabrafo/Algoritmos-ED/blob/master/Implementa%C3%A7%C3%B5es%20de%20Algoritmos/Documenta%C3%A7%C3%A3o/Imagens/Imagem%209.png)

Ao chegarmos ao caso-base, fazemos o caminho reverso, realizando *pops* (retirada de chamadas da pilha) até retornarmos à chamada original da função, com a soma de todos os valores acrescidos.

![Desempilhamento](https://github.com/gabrafo/Algoritmos-ED/blob/master/Implementa%C3%A7%C3%B5es%20de%20Algoritmos/Documenta%C3%A7%C3%A3o/Imagens/Imagem%210.png)