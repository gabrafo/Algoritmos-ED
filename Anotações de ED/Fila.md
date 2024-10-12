# Fila

Uma fila é uma estrutura de dados que assume a ideia de sequência de objetos para armazenar as informações.
É baseada no princípio ***First In First Out*** (FIFO), que dita que o primeiro elemento a ser adicionado deve, também, ser o primeiro a ser retirado da fila.
A manipulação dessa ED, assim como nas pilhas, deve ser feita exclusivamente a partir das extremidades, não sendo possível acessar diretamente outros elementos.

Alguns exemplos de utilização da estrutura de dados "fila" em modelos computacionais são:
- Escalonamento de processos na CPU;
- Escalonamento de acesso à memória secundária;
- Sincronização de processos assíncronos;
- Gerenciamento de fila de impressão;
- Controle de interrupções de hardware;
- Controle de chamadas em call centers;
- Busca em largura em grafos.

Nesse sentido, a fila de ações no jogo *Dark Souls* (sistema que permite que os jogadores programem uma sequência de comandos) pode se encaixar muito bem em um exemplo computacional/algorítmico de fila. Assim como em uma fila, onde os elementos são processados na ordem em que foram adicionados, em *Dark Souls*, as ações do jogador são executadas na ordem em que são inseridas. Se um jogador decide atacar e, em seguida, esquivar-se, o jogo processa essas ações na mesma sequência.

## Adição de elementos
A adição de um elemento na fila deve ser sempre na posição à frente do último elemento da fila. Ou seja, quando adicionamos um novo elemento na fila, ele se torna o novo último elemento.

## Remoção de elementos
A remoção de elementos na fila, diferentemente da adição, deve remover sempre o **primeiro** elemento da fila. **A retirada de um elemento na pilha é sempre daquele que foi inserido primeiro.** Caso eu deseje acessar outro elemento (que não esteja no início da fila), é necessário que todos os elementos anteriores a ele sejam devidamente desenfileirados.

Outro exemplo figurativo de "Fila":

![Imagem 9](https://github.com/gabrafo/Algoritmos-ED/blob/master/Anota%C3%A7%C3%B5es%20de%20ED/Imagens/Imagem%209.png)

![Imagem 10](https://github.com/gabrafo/Algoritmos-ED/blob/master/Anota%C3%A7%C3%B5es%20de%20ED/Imagens/Imagem%2010.png)

![Imagem 11](https://github.com/gabrafo/Algoritmos-ED/blob/master/Anota%C3%A7%C3%B5es%20de%20ED/Imagens/Imagem%2011.png)

## Implementações comuns
Geralmente, para implementar uma fila, usam-se tais estratégias:
- Implementação usando encadeamento de nós (elementos) da fila.
  Para essa solução, geralmente, usa-se a estrutura de dados **lista encadeada** ou classes que atuem de forma semelhante.
  
- Implementação usando arranjo (vetores) para armazenamento dos elementos.
  As vantagens dessa abordagem são: velocidade de acesso (O(1)) e enfileiramento/desenfileiramento. No entanto, pode ser necessário redimensionamento frequente de vetores, o que tem um custo computacional grande, além da possibilidade de desperdiçar espaço de memória.

Fila e nós são implementados tradicionalmente como estruturas ou classes. Utilizando C++, usaremos a segunda abordagem.

### Implementação usando encadeamento
A implementação mais comum de fila é a usando encadeamento. 
Nesse modelo de implementação, um nó (elemento) contém determinado valor e também o endereço de memória para o próximo nó (servindo como ponteiro). Isso ocorre até chegarmos ao fim da fila, onde o último elemento não aponta para nenhum outro elemento (aponta para `NULL`). 
Nesse sentido, podemos saber apenas onde é o início (primeiro elemento) e o fim (último elemento) da estrutura de dados, visto que para acessar outros, precisaríamos desenfileirar todos os elementos anteriores ao desejado até o encontrarmos, e para adicionar um elemento, precisamos, necessariamente, adicioná-lo ao fim da fila.

#### Classe `Noh`
Cada nó da fila contem como atributos dados armazenados e um apontador para o nó seguinte.

```cpp
// Exemplo simples
class Noh{
	int dado;
	Noh* proximoElemento; // Ponteiro para o próximo nó
}
```

#### Classe `Fila`
A classe fila contém, geralmente, um apontador para o primeiro/último elemento adicionado à ED e um atributo para informar a quantidade de elementos (nós) que ela possui.

```cpp
class Fila{
	int tamanho;
	Noh* primeiroElemento;
	Noh* ultimoElemento;
}
```

#### Operações básicas sobre filas

- Criação/destruição da fila
  O processo de criação da fila se baseia em garantir que o início e o fim da fila não apontem para uma região válida de memória, ou seja, apontem para nulo.
  
- Inserção (*queue*) de um elemento
  Já a inserção em uma fila consiste na criação de um novo nó com com o dado a ser armazenado, assim o colocamos no fim da fila. Para que essa operação seja bem sucedida, o elemento que estava no fim (antes da operação de inserção) deverá ser indicado pelo elemento inserido como o próximo elemento da pilha. Além disso, caso haja alguma contabilização de tamanho da fila, ela também deverá ser atualizada para abarcar o novo elemento.
  
  Caso a fila esteja vazia, o elemento inserido deverá ser o primeiro elemento da fila e, em caso contrário, ele deverá ser o próximo elemento seguinte ao último elemento anterior à sua inserção, como dito anteriormente.
  
- Remoção (*dequeue*) de um elemento 
  Para a remoção, precisamos retirar o primeiro elemento da fila. Assim, caso hajam cinco elementos na fila, devemos apenas retirar o elemento que está no início, seguindo o preceito FIFO.
