# *Heap*

Como já visto anteriormente, a estrutura de dados *heap* representa uma árvore **binária** **balanceada** e **completa**. Isto é, uma árvore em que todos os níveis, exceto o último, estão completamente preenchidos, e os nós do último nível são adicionados da esquerda para a direita.

Existem dois tipos principais: *max-heap* (cada nó é maior ou igual aos seus filhos) e *min-heap* (cada nó é menor ou igual aos seus filhos). Nesse exemplo, estaremos tratando de um *max-heap*.

Essas anotações são baseadas no [exemplo de *max-heap*](https://github.com/gabrafo/Algoritmos-ED/blob/master/Implementa%C3%A7%C3%B5es%20de%20ED/maxheap.cpp) já disponível no repositório.

## Para que serve um *heap*?

Um *heap* é uma forma prática e eficiente de implementar filas de prioridade. Sua propriedade garante que o elemento de maior prioridade (ou seja, a raiz) pode ser acessado, removido e substituído pelo último elemento de forma eficiente. Ele é usado em algoritmos de ordenação (como *Heap Sort*) e em diversos contextos onde é necessário acesso rápido ao maior ou menor elemento.

## Implementando um *heap*

Para maior desempenho nas operações, utilizaremos arranjos para a implementação. Essa escolha é eficiente, pois um *heap* é uma árvore binária completa, o que permite mapear suas relações entre pais e filhos através de índices simples. Com isso, todas as operações realizadas em um heap têm custo logarítmico (O(log n)), considerando a profundidade da árvore.


## Operações básicas em um *heap*  

Em nossa implementação, realizaremos as seguintes operações:  

- **`criarHeap()`** e **`destruirHeap()`**: Criam e destroem a estrutura de dados, alocando ou liberando memória.  

- **`corrigeDescendo(int i)`**: Quando a raiz é removida, o último elemento toma seu lugar, mas pode não respeitar a propriedade do *heap*. Esse método é responsável por **reorganizar o elemento** ao **comparar o nó atual com seus filhos e trocar com o maior deles**, repetindo até que a propriedade de *heap* seja restaurada.  

- **`corrigeSubindo(int i)`**: Quando um novo elemento é inserido, ele é **adicionado na primeira posição disponível** (a última folha). **Se esse novo elemento for maior que seu pai, ocorre uma troca**, e o processo se repete até encontrar a posição correta.  

- **`insere(Dado d)`**: Insere um novo valor `d` na última posição e utiliza o método `corrigeSubindo()` para garantir a propriedade de *heap*.  

- **`retiraRaiz()`**: Retira o elemento raiz (o maior no *max-heap*) e o substitui pelo último elemento. O método `corrigeDescendo()` é então utilizado para reorganizar o *heap*.  

- **`arruma()`/`heapify()`**: Método auxiliar para **construir o *heap***. **Recebe um vetor arbitrário e reorganiza seus elementos**, garantindo que a estrutura resultante siga as propriedades de um *heap*. 

### Mapeamento de pais e filhos  
Em um *heap* implementado com um arranjo começando da posição zero, as fórmulas para encontrar os índices dos pais e filhos são:  

- **`nohPai(i)`** ← `(i-1)/2`  

- **`nohEsquerdo(i)`** ← `2*i + 1`  

- **`nohDireito(i)`** ← `2*i + 2`  

### Explicação do Código

A implementação prática do *max-heap* utiliza um vetor dinâmico e é definida em uma classe `MaxHeap`, que contém vários métodos para gerenciar e manipular os dados:

- **Atributos**:  

  - `heap`: vetor que armazena os elementos do *heap*.  

  - `capacidade`: tamanho máximo do vetor.  

  - `tamanho`: número atual de elementos.  

- **Construtores**:  

  1. **`MaxHeap(int cap)`**: Inicializa um *heap* vazio com capacidade `cap`.  

  2. **`MaxHeap(Dado vet[], int tam)`**: Constrói um *heap* a partir de um vetor arbitrário, copiando seus valores para o vetor `heap` e chamando o método `arruma()`.  

- **Funções de Navegação**:  

  - `pai(int i)`: Retorna o índice do nó pai de `i` (ou zero, se `i` for a raiz). 

  - `esquerdo(int i)`: Retorna o índice do filho esquerdo de `i`.  

  - `direito(int i)`: Retorna o índice do filho direito de `i`.  

- **Reorganização do Heap**:  

  - **`corrigeDescendo(int i)`**: Ao remover a raiz, o **último elemento é movido para a posição zero**. Esse método **ajusta o *heap***, comparando o valor em `i` com seus filhos esquerdo e direito, e trocando com o maior deles se necessário.  

  - **`corrigeSubindo(int i)`**: Ao inserir um novo valor, o método compara o valor em `i` com seu pai e faz trocas se `heap[i]` for maior.  

- **Outras Operações**:  

  - **`imprime()`**: Percorre o vetor e exibe os elementos.  

  - **`espiaRaiz()`**: Retorna o valor na raiz, que é o maior valor do *heap*.  

  - **`retiraRaiz()`**: Remove o maior valor (a raiz), ajusta o *heap* e retorna o valor removido.  

  - **`insere(Dado d)`**: Insere um novo elemento no *heap*, corrige-o subindo o novo valor e aumenta o tamanho.  

## *Heap Sort*  

O algoritmo de ordenação *Heap Sort* utiliza um *heap* para ordenar elementos em um vetor. Ele constrói um *heap* a partir dos dados e, em seguida, remove repetidamente o maior elemento, reorganizando o *heap* a cada retirada. Isso resulta em um vetor ordenado.

## Complexidade de Tempo do *Heap* (`Big-O`)

A complexidade de tempo das operações de um *heap* está relacionada à profundidade máxima da árvore binária. Como um *heap* é uma **árvore binária completa**, sua profundidade máxima é de `log₂(n)`, onde `n` é o número de elementos. Assim:

- A operação de **inserção** (`insere`) insere um novo elemento na última posição e pode precisar corrigir a estrutura subindo pela árvore até a raiz. Como a altura da árvore é `log₂(n)`, o tempo máximo para corrigir a estrutura é `O(log n)`.

- A operação de **remoção da raiz** (`retiraRaiz`) substitui a raiz pelo último elemento, seguido de uma correção descendo pela árvore até a folha, o que também leva `O(log n)`.

- A operação de **construção de um *heap* (`arruma`)** percorre cada nó não folha da árvore, aplicando o processo de correção para cada um. Esse processo leva `O(n)` no pior caso. A intuição por trás disso é que a maior parte do trabalho ocorre apenas nos níveis superiores da árvore, enquanto a quantidade de trocas diminui significativamente nos níveis inferiores.
