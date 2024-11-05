Material bibliográfico adicional recomendado: Entendendo Algoritmos, por Aditya Y. Bhargava.

## O que são variáveis homogêneas?
São um conjunto sequencial de variáveis de um mesmo tipo. A maioria das LPs implementam variáveis homogêneas como vetores e/ou como listas. Além disso, há a possibilidade de implementação por meio de vetores associativos (mapas ou dicionários), como é feito em Python. Geralmente, essa implementação se dá por meio de tabelas *hash*.

### Relembrando arranjos/vetores...
Um arranjo é um conjunto de locais contíguos na memória para armazenamento de elementos de um mesmo tipo. Além disso, arranjos podem ser enxergados como uma variável com várias posições.

A seleção desses elementos pode se dar a partir do acesso direto à sua posição no arranjo (em complexidade de O(1)). Essa é uma de suas **principais vantagens**. Já quanto às suas desvantagens, a mais importante é o fato de que ele não é redimensionado facilmente, justamente por precisar armazenar a memória de maneira contígua e ter um tamanho limitado para que possa realizar tal tarefa.

## Mas e listas?
Uma lista encadeada (ou linear) é uma coleção ordenada (podemos identificar o antecessor e sucessor de cada elemento nessa estrutura de dados) de elementos de um mesmo tipo (homogênea). É uma estrutura de dados linear e **dinâmica**. 

A característica principal de uma lista encadeada é que cada elemento aponta para um elemento subsequente na lista, até apontar para um valor nulo, indicando seu fim. Geralmente, usamos dois indicadores (ponteiros) para o primeiro e último elementos da lista, a fim de facilitar a inserção de novos dados.

A principal vantagem da lista é a **possibilidade/facilidade de redimensionamento**. No entanto, de forma contrastante com os vetores, acessar elementos intermediários pode se provar uma tarefa muito difícil, visto que será necessário perpassar por cada um dos elementos que o precedem até chegarmos ao elemento de interesse.

Assim, **vetores são mais vantajosos para operações de leitura** devido à facilidade de acesso às suas posições na memória e **listas (encadeadas) são melhores no contexto de inserção de dados**, por não demandarem uma alocação contígua de memória, sendo bem mais flexível nesse sentido.

Comumente, listas são encadeadas usando indireção (ponteiros), apesar de haverem outras alternativas. Além disso, por conta de seu tamanho dinâmico e do provável uso de ponteiros, listas encadeadas também são chamadas de **listas dinamicamente encadeadas**.

É extremamente perceptível a semelhança entre pilhas, filas e essa estrutura de dados, visto que as duas primeiras são, na verdade, **tipos especiais de listas** com controle do acesso aos elementos a partir de posições específicas (início ou fim/topo). Em ambas (pilha e fila) não podemos acessar elementos intermediários, diferentemente da lista, em que esse tipo de acesso não representa quebra de estrutura, mas sim uma de suas funções básicas.

## Listas duplamente encadeadas
Parte das implementações de listas utiliza dois encadeamentos: para o **próximo e o anterior**, visto que, às vezes, é importante não apenas avançar nos nós, mas também poder retroceder.

![Imagem 13](https://github.com/gabrafo/Algoritmos-ED/blob/master/Anota%C3%A7%C3%B5es%20de%20ED/Imagens/Imagem%2013.png)

Exemplo de **lista duplamente encadeada**. Retirada das videoaulas do Prof. Joaquim Quintero Uchôa, disponíveis em: [Estruturas de Dados - Aula 8 - Parte 2 - Visão Geral de Implementação de Listas](https://www.youtube.com/watch?v=oDejZrpRoqY&list=PLY-_XMpiC9C3Yn-T5Rg0f0te7X8aVUOO0&index=39&ab_channel=JoaquimQuinteiroUch%C3%B4a).

## Listas estaticamente encadeadas
Apesar de geralmente utilizarmos indireção (com os nós "apontando" um para o outro), é possível utilizar um arranjo para armazenar os dados de uma lista. Nesse caso, utilizamos um **vetor de nós**, em que cada nó armazena, além de seus dados, a **posição para o próximo/anterior**. Esse tipo de implementação é menos usual.

## Implementação
Uma lista possui ao menos um ponteiro, que irá apontar para o seu primeiro elemento. Grande parte das implementações também conta com um ponteiro para seu último elemento, facilitando o acesso a essa posição e o gerenciamento do tamanho da lista. Outro atributo opcional é, justamente, o tamanho da lista, no entanto, o ter facilita muito a implementação.

Cada nó contem um ponteiro para o próximo nó, além dos dados correspondentes a ele.

![Imagem 12](https://github.com/gabrafo/Algoritmos-ED/blob/master/Anota%C3%A7%C3%B5es%20de%20ED/Imagens/Imagem%2012.png)

![Imagem 14](https://github.com/gabrafo/Algoritmos-ED/blob/master/Anota%C3%A7%C3%B5es%20de%20ED/Imagens/Imagem%2014.png)

Exemplos de **listas encadeadas**. Retiradas das videoaulas do Prof. Joaquim Quintero Uchôa, disponíveis em: [Estruturas de Dados - Aula 8 - Parte 2 - Visão Geral de Implementação de Listas](https://www.youtube.com/watch?v=oDejZrpRoqY&list=PLY-_XMpiC9C3Yn-T5Rg0f0te7X8aVUOO0&index=39&ab_channel=JoaquimQuinteiroUch%C3%B4a).

Sem um ponteiro para o último elemento da lista, devemos percorrê-la por inteiro até podermos, por exemplo, inserir um elemento em seu fim. O mesmo vale para a ausência do atributo opcional tamanho, que nos obriga a percorrer a lista toda a lista contando cada um dos nós até chegarmos ao que aponta para "nulo".

### Métodos
**OBS**: Existem métodos que, mesmo quando são disponibilizados, devem ser evitados, como o acesso direto a uma posição.

#### Métodos Usuais
- **Construção**: inicialização dos dados, ponteiro(s) apontando para **nulo**.
- **Destruição**: deleção da lista, liberando memória dinamicamente alocada. É necessário percorrer a lista e apagar os nós.
- **Percorrimento**: percorre os nós de uma lista, realizando alguma ação de interesse (como a impressão).
- **Busca**: percorre a lista procurando por um nó referente a um determinado valor.
- **Acesso a posição**: percorre os nós da lista até determinada posição.
- **Inserção**: inserção de um novo nó na lista, pode ocorrer no **início**, no **final** ou em alguma posição determinada da lista.
- **Remoção**: remoção de determinado nó. Pode ocorrer no **início**, **fim**, ou em um nó com determinado valor (necessário, antes, fazer a **busca**) ou em uma determinada posição (necessário fazer o **percorrimento** até essa posição antes).
