Um algoritmo é um conjunto de instruções que realizam uma tarefa.

## Pesquisa binária
Se trata de uma forma otimizada de busca de dados em uma lista ordenada, usando a estratégia "dividir para conquistar". Resumidamente, com base no feedback de cada iteração do algoritmo de busca, calibramos o intervalo de dados que pode conter o objeto de interesse.

![Imagem 7.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%207.png)

Vamos dizer que você esteja tentando encontrar um número de 1 a 100 e, a cada erro, recebe uma dica se a resposta é um valor "muito alto" ou "muito baixo" comparativamente ao número desejado.

![Imagem 8.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%208.png)

![Imagem 9.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%209.png)

Para encontrarmos o pior caso de uma busca binária, utilizamos a fórmula log₂(n). Em uma lista de 128 nomes, demoraríamos, no pior caso, 7 passos para encontrar o item desejado. Já o dobro de nomes (256) levariam, apenas, 8 passos, evidenciando a efetividade do método.
Caso utilizássemos busca linear, no pior caso, teríamos, respectivamente, 128 passos e 256 passos até encontrarmos o nome que estamos procurando.

Exemplo de algoritmo de busca binária em C++:
```cpp 
#include <iostream>
using namespace std;

int buscaBinaria(int vetor[5], int item, int ultimaPosicao){

    int baixo = 0;
    int alto = ultimaPosicao;

    while(baixo<=alto){
        int meio = (baixo+alto)/2;
        int chute = vetor[meio];

        if (chute == item){
            return meio; // Acertou!
        }

        if (chute > item){
            alto = meio-1; // Está na parte direita
        }

        if(chute < item){
            baixo = meio+1; // Está na parte esquerda
        }

        cout << "ITERAÇÃO! Alto = " << alto << ", Meio = " << meio <<
        ", Baixo = " << baixo << ", ITEM = " << item << endl;
    }
  
    return -1;
}

int main() {

    int vetor[5] = {1, 3, 5, 7, 9};
    int valor = buscaBinaria(vetor, 9, 4);
    
    if(valor == -1){
        cout << "Erro na busca!" << endl;
    } else {
        cout << vetor[valor] << endl;
    }
  
    return 0;
}
```

## Tempo de execução
Quando o número máximo de tentativas é igual ao tamanho da lista, temos um exemplo de algoritmo com tempo **linear**. Já quando utilizamos o número máximo de tentativas é igual a log₂(n), com n sendo o número máximo de tentativas, temos um exemplo de algoritmo com tempo **logarítmico**.

Exemplo utilizando algoritmos de busca:

![Imagem 10.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2010.png)

![Imagem 11.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2011.png)

### Notação Big O
Essa é uma notação utilizada especificamente para dizer o quão rápido é um algoritmo. A notação Big O permite que você compare o número de operações e, portanto, não utiliza medidas de tempo (segundos, milissegundos, etc) como métrica. 
É chamada Big O justamente porque coloca-se um "grande O" na frente do número de operações.

![Imagem 12.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2012.png)

**Exemplo de uso da Big O**:  Suponha que você tenha que desenhar uma grade com 16 divisões. Com isso em mente, uma forma de desenhar essa grade de 16 divisões é desenhar uma divisão de cada vez. Nesse exemplo, desenhar uma divisão é uma operação, portanto, você precisa desenhar 16 divisões, ou seja, realizar 16 operações distintas.

![Imagem 13.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2013.png)

Agora, digamos que eu pegue um papel vazio e o dobre quatro vezes consecutivas:
![Imagem 14.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2014.png)

Ao fim das quatro dobras, igualmente, teremos 16 divisões no papel, no entanto com apenas 1/4 do número de operações necessárias do primeiro algoritmo. Assim, o algoritmo 1 tem tempo de execução O(n) e o algoritmo 2 tem tempo de execução O(log n), que é mais veloz.

**OBS**: É importante mencionar que a **Big O leva em conta sempre a pior das hipóteses**, ou seja, o caso em que o algoritmo utiliza o maior número de operações possíveis para chegar em sua conclusão. Assim sendo, mesmo que uma pesquisa simples acerte logo na primeira tentativa a posição de um objeto de desejo (por esse ser o primeiro de uma lista ordenada), o tempo de execução desse algoritmo em Big O ainda seria O(n). Dessa forma, temos a garantia apenas que a pesquisa simples não terá um tempo de execução mais lento do que O(n), mas nada nos garante que ela possa cumprir seu papel em um tempo de execução menor.

![Imagem 15.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2015.png)

Levando em consideração que podemos realizar, no máximo, dez operações em um segundo, aqui estariam gráficos ilustrando o desempenho dos cinco tempos de execução acima:
![Imagem 16.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2016.png)

Lembrando que isso é uma simplificação, visto que, na realidade, você não pode converter um tempo de execução na notação Big O para um número de operações, mas a aproximação serve de exemplo para vislumbrarmos a realidade.

#### Pontos importantes:
- A rapidez de um algoritmo não é medida em segundos, mas pelo crescimento do número de operações.
- A notação Big O expressa o tempo de execução de um algoritmo.
- A notação Big O mede justamente a velocidade de um algoritmo no caso em que ele demanda o maior número possível de operações.
- O(log n) é mais rápido do que O(n), e O(log n) ca ainda mais rápido conforme a lista aumenta por ser um tempo de execução logarítmico.

Exemplo de algoritmo com tempo de execução fatorial O(n!): o caixeiro viajante.

![Imagem 17.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2017.png)

![Imagem 18.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2018.png)

![Imagem 19.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2019.png)

A quantidade de número de operações com 100 cidades é tanta que é impossível calcular a resposta em função do tempo, ou seja, o sol entrará em colapso antes que possamos achar a melhor via para o caixeiro viajar.

## Ordenação por seleção
Para entendermos algoritmos de ordenação, é importante também termos conhecimento quanto a vetores e listas.

![Imagem 20.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2020.png)

Para armazenarmos itens na memória do computador, geralmente pedimos a ele determinada quantidade de bytes para tal. Tomando como exemplo a linguagem C++, um inteiro equivale a 4 bytes e, portanto, quando vamos atribuir um valor a uma variável desse tipo, estamos separando 4 bytes na memória que irão armazenar esse inteiro.

Nesse sentido, quando precisamos armazenar múltiplos inteiros temos como possibilidades: 1 - armazená-los em várias variáveis separadas; 2 - utilizar uma estrutura de dados para facilitar esse processo. Com isso em mente, é óbvio que a primeira alternativa é extremamente custosa, além de dificultar o gerenciamento dos valores de interesse. Assim, é mais fácil utilizar vetores, listas, dicionários, ou tantas outras ferramentas para pedir ao computador por mais armazenamento de memória. No entanto, como o enfoque será em vetores e listas, irei explicar a diferença entre esses dois tipos de estrutura de dados. 

### Vetores
Um vetor é uma forma de armazenar contiguamente (de maneira adjacente/lado a lado) memória. Tomando como exemplo uma lista de afazeres, ao guardarmos nossas tarefas em um vetor, teríamos um resultado semelhante a esse:

![Imagem 21.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2021.png)

É como se você estivesse indo ao cinema com os seus amigos e encontrasse um lugar para sentar, mas outro amigo se juntasse a vocês e não houvesse lugar para ele. Assim sendo, vocês precisariam encontrar outra sequência de cadeiras que pudessem contemplar a todos vocês, possivelmente em outra fileira da sala de cinema. No entanto, e se outro amigo aparecesse? O processo teria que se repetir.
Uma forma de evitar essa fadiga seria reservando mais assentos (memória), no entanto, isso traria mais gasto a vocês, já que pode ser que nem todos possam comparecer ao filme, o que traria um desperdício de dinheiro e de espaço.

Dessa forma, ainda considerando o exemplo da lista de afazeres, esses seriam as possíveis desvantagens de se usar um vetor para seu gerenciamento:

![Imagem 22.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2022.png)

### Listas encadeadas
As listas encadeadas, diferentemente dos vetores, não armazenam dados de maneira necessariamente contígua na memória, dessa forma, não há um tamanho pré-estabelecido de reserva de recursos computacionais (memória). 

![Imagem 23.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2023.png)

![Imagem 24.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2024.png)

Cada um dos itens de interesse aponta para o próximo endereço na memória em que há um integrante da lista, até que não haja mais nenhum.

Seguindo o exemplo do cinema, ao usar uma lista encadeada você e seus amigos não se importam de estarem ou não juntos durante a sessão, o que seria como dizer “vamos nos dividir e assistir ao filme”. Desde que haja espaço no cinema/na memória, haverá espaço para a lista encadeada.

Essa flexibilidade na alocação de memória é uma vantagem das listas encadeadas, pois não exige que os itens sejam armazenados de forma contígua. No entanto, essa mesma característica também representa uma limitação: para acessar um item específico na lista, você precisa percorrer todos os itens anteriores, um por um, até chegar ao desejado. Isso ocorre porque cada item na lista só sabe onde está o próximo, sem informações diretas sobre os itens subsequentes.

Listas encadeadas são ótimas se você quiser ler todos os itens, um de cada vez: você pode ler um item, seguir para o endereço do próximo item e fazer isso até o fim da lista. Mas se você quiser pular de um item para outro, as listas encadeadas são terríveis. Já com vetores, por estarem contíguos na memória, é bem mais fácil de acessar, por exemplo, o quinto item, já que não é necessário que passemos por cada um dos itens anteriores, visto que sabemos como apontar facilmente para seu endereço de memória: usando o índice 4 do vetor. 

![Imagem 25.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2025.png)

Vetores, diferentemente da lista encadeada, são ótimos se você deseja ler elementos aleatórios, pois pode encontrar qualquer elemento instantaneamente em um vetor bastando que saiba seu índice (que vai de zero até 1 - a capacidade máxima do vetor).

Levando em conta um vetor de capacidade máxima 4, temos seus índices indo de 0 até 3, como exemplificado abaixo:

![Imagem 26.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2026.png)

![Imagem 27.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2027.png)

Assim, **vetores são mais vantajosos para operações de leitura** devido à facilidade de acesso às suas posições na memória e **listas (encadeadas) são melhores no contexto de inserção de dados**, por não demandarem uma alocação contígua de memória, sendo bem mais flexível nesse sentido.
Além disso, **deleção de elementos também é mais eficiente com o uso de listas**, visto que é necessário mudar apenas o endereço para o qual o elemento anterior da estrutura de dados está apontando. Já com vetores, tudo precisa ser movido quando um elemento é eliminado.
#### Inserção de elementos (Vetor vs. Lista encadeada)
Para inserir elementos no meio de uma lista de tarefas, por exemplo, seria mais vantajoso o uso de um vetor ou de uma lista encadeada?

![Imagem 28.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2028.png)

A resposta é simples: usando listas encadeadas, basta mudar o endereço para o qual o elemento anterior está apontando, já usando vetores, seria necessário encontrar outro endereço na memória que pudesse abarcar lado a lado todas as informações de afazeres (o que é bem mais complicado). Assim, listas encadeadas seriam melhores nesse contexto!

Exemplo com uma lista encadeada: Note que apenas alteramos para onde "jogar bocha" aponta, sendo fácil as operações de inserção/renomeio das demais tarefas.

![Imagem 29.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2029.png)

Exemplo usando um vetor: Note que, como não há memória livre de maneira contígua que possa abarcar a nova tarefa, será necessário mover todos os dados para outro local na memória.

![Imagem 30.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2030.png)

#### Qual é mais usado? Vetores ou listas encadeadas?
Os vetores são mais comuns porque permitem acesso aleatório. Existem dois tipos de acesso: o aleatório e o sequencial. O sequencial significa ler os elementos, um por um, começando pelo primeiro. Listas encadeadas só podem lidar com acesso sequencial. 

Se você quiser ler o décimo elemento de uma lista encadeada, primeiro precisará ler os nove elementos anteriores para chegar ao endereço do décimo elemento. O aleatório permite que você pule direto para o décimo elemento. Muitos casos requerem o acesso aleatório, o que faz os arrays (vetores) serem mais utilizados. No entanto, é importante mencionar que ambos (vetores e listas) são utilizados para implementar outras estruturas de dados.

### Retornando à ordenação por seleção...
Digamos que estamos querendo ordenar qual o artista mais tocado de uma lista de artistas, para isso, podemos utilizar o seguinte algoritmo: perpassar por cada elemento da lista (busca simples, tempo de execução O(n)) para encontrar o artista mais tocado, o retirar dessa lista de artistas e o adicionar a uma nova lista (que será nossa lista ordenada).

![Imagem 31.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2031.png)

![Imagem 32.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2032.png)

Esse processo iria se repetir diversas vezes, até termos então uma lista plenamente ordenada:

![Imagem 33.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2033.png)

Como dito anteriormente, checar cada artista da lista original a fim de encontrar o com maior número de "plays" é uma tarefa com tempo de execução O(n), sendo n o número de itens (artistas) da lista. Dito isso, a cada nova iteração da busca um item é retirado e, portanto, a verificação passar de n elementos a n – 1, n - 2 … 2, até enfim um único elemento, com um resultado de O(n × ½ × n). No entanto, em Big O ignoramos constantes como ½, o que gera um resultado final de O(n²).

![Imagem 34.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2034.png)

Exemplo de algoritmo de ordenação por seleção em C++:
```cpp
void selectionSort(Artista artistasVetor[], int tamanhoVetor){
    int posMenor;
    Artista aux;
    
    for(int i = 0; i<tamanhoVetor; i++){
        posMenor = i;

        for (int j=i+1; j < tamanhoVetor; j++) {
            if (artistasVetor[j].getContadorDePlays() > artistasVetor[posMenor].getContadorDePlays()){
                posMenor = j;
            }
        }

        aux = artistasVetor[i];
        artistasVetor[i] = artistasVetor[posMenor];
        artistasVetor[posMenor] = aux;
    }
}
```

#### Pontos importantes
- Quando se quer armazenar múltiplos elementos, usa-se um array ou uma lista.
- No array, todos os elementos são armazenados um ao lado do outro.
- Na lista, os elementos estão espalhados e um elemento armazena o endereço do próximo elemento.
- Arrays permitem leituras rápidas, mas tem inserções/deleções menos eficientes (devido à forma em que aloca a memória).
- Listas encadeadas permitem rápidas inserções e eliminações, mas tem acesso difícil, devido à sua natureza semelhante à lógica de ponteiros.

## Recursão
É, resumidamente, a chamada de um método (função) dentro de outro método. A recursão é usada para tornar trechos de código mais simples de entender, não havendo nenhum benefício quanto ao desempenho ao ser utilizada. Em muitos casos, utilizar laços de repetição pode ser mais eficiente.

“Os loops podem melhorar o desempenho do seu programa. A recursão melhora o desempenho do seu programador. Escolha o que for mais importante para a sua situação.” - Leigh Caldwell, do Stack Overflow.

Algo importante de se notar em uma função recursiva é que precisamos sempre delimitar o momento de parada, para não acabarmos com execuções infinitas. Por isso, toda função recursiva tem duas partes: o caso-base e o caso recursivo.
- Caso recursivo: quando a função chama a si mesma.
- Caso-base: quando a função não chama a si mesma, interrompendo o loop.

Exemplo de recursão em C++:
```cpp
#include <iostream>

using namespace std;

void contagemRecursiva(int contador){

    if(contador==0){ // Parada da recursão
        cout << "Atingimos o caso-base" << endl;
    }

    else {
        cout << "Estamos no caso recursivo" << endl;
        cout << contador << endl;
        contagemRecursiva(contador-1);
    }
}

int main(){

    contagemRecursiva(10);

    return 0;
}
```

Caso não houvesse o caso-base no método `contagemRecursiva()`, seria impresso infinitamente a variável `contador`, sendo, a cada impressão, subtraído 1 do seu valor total.

- Com caso-base:

![Imagem 35.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2035.png)

- Sem caso-base:

![Imagem 36.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2036.png)

Primeiro, temos uma acusação do compilador que haverá uma recursão infinita.

![Imagem 37.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2037.png)

Caso decidamos ignorar o aviso, o programa irá executar até chegar a uma falha de segmentação.

### Pilha de chamada (*call stack*)
Quando empilhamos, por exemplo, tarefas em uma lista de afazeres, temos uma situação onde o último item a ser colocado (ou seja, o que está no topo da pilha) é o primeiro a ser lido por nós.

![Imagem 38.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2038.png)

Algo semelhante ocorre com nossos e-mails, onde os mais recentes são os que vimos primeiro ao abrirmos, por exemplo, o Gmail. 

Uma pilha funciona da seguinte maneira: Quando você insere um item, ele é colocado no topo da pilha. Quando você lê um item, lê apenas o item do topo da pilha e ele é retirado da lista. Logo, temos apenas duas ações ao empilharmos itens, que seria inserir (*push*) e removê-los/lê-los (*pop*).

![Imagem 39.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2039.png)

![Imagem 40.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2040.png)

A pilha funciona com o protocolo LIFO (*Last In, First Out*) como já explicado previamente.

![Imagem 41.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2041.png)

![Imagem 42.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2042.png)

![Imagem 43.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2043.png)

Código descrito no exemplo acima:
```python
# -*- coding: utf-8 -*-

# Pyhon 2.7, exemplo do livro Entendendo Algoritmos.

def sauda(nome):
    print ("Olá, " + nome + "!")
    sauda2(nome)
    print ("preparando para dizer tchau...")
    tchau()

def sauda2(nome):
    print ("Como vai " + nome + "?")

def tchau():
    print ("ok, tchau!")

sauda("Gabriel")
```

Mesmo código, mas em C++:
```cpp
#include <iostream>

using namespace std;

void sauda2(string nome){
    cout << "Como vai " << nome << "?" << endl;
}

void tchau(){
    cout << "ok, tchau!" << endl;
}

void sauda(string nome){
    cout << "Olá, " << nome << "!" << endl;
    sauda2(nome);
    cout << "preparando para dizer tchau..." << endl;
    tchau();
}

int main(){
    sauda("Gabriel");
    return 0;
}
```

Funções recursivas também utilizam a pilha de chamada. Abaixo, veremos um exemplo dessa situação, analisando um código em Python disponibilizado no livro "Entendendo Algoritmos".

```python
# Pyhon 2.7, exemplo do livro Entendendo Algoritmos.

def fat(x):
    if x == 1:
        return 1
    else:
        return x * fat(x-1)

print(fat(3))
```

Na primeira execução do código, podemos ver que já há a chamada da função `fat()` outra vez no código, a partir de uma recursão, o que faz com que já haja uma sobreposição de chamadas na pilha, com os valores de `x` armazenados em memória.

![Imagem 44.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2044.png)

Há então mais uma sobreposição, agora estamos com 3 chamadas na pilha, com a variável `x` valendo, respectivamente, em cada uma delas, 3 (primeira chamada), 2 (segunda chamada) e 1 (última chamada).

![Imagem 45.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2045.png)

Agora, na terceira vez em que executamos o fluxo de código da função, temos a finalização da última chamada recursiva que fizemos (a que nos deu `x = 1`) a partir do caso-base. Logo, o último item a ser adicionado na pilha, é o primeiro a ser retirado. 

![Imagem 46.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2046.png)

Na chamada de `fat()` onde `x = 2`, a partir da interpretação do código, temos 2 (valor de `x`) vezes 1 (valor do retorno do último *pop*, o caso em que `x` valia 1), que resulta em 2. Ao retornar 2, podemos retirar essa chamada da pilha, e utilizar seu retorno para o cálculo final da função recursiva.
Se `x` equivale a 3 nessa última chamada, e o `fat(x-1)` é `fat(2)`, que retorna 2, temos que `3 * fat(2)` é igual a 6.

![Imagem 47.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2047.png)

Digamos que estejamos procurando uma chave em um monte de caixa (qualquer uma delas pode conter o objeto). Aqui vai um exemplo de algoritmos sem a utilização de recursão:

![Imagem 48.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2048.png)

![Imagem 49.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2049.png)

Para resolvermos isso em uma abordagem recursiva, teríamos o seguinte caso:

![Imagem 50.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2050.png)

![Imagem 51.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2051.png)

![Imagem 52.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2052.png)

![Imagem 53.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2053.png)

![Imagem 54.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2054.png)

Vantagens da pilha recursiva (segundo caso):
- Não demandar administração constante, por parte do programador, de todas as chamadas a serem executadas.

Desvantagens da pilha recursiva (segundo caso):
- Pode acabar ocupando muita memória, por sempre estar salvando os valores das variáveis de cada chamada da função recursiva.

**Resumo da diferença entre as pilhas:**
- **Iterativa (primeiro caso)**: Geralmente mais eficiente em termos de memória e pode ser mais rápida devido à redução do overhead de chamadas de função.
- **Recursiva (segundo caso)**: Mais intuitiva em muitos casos, mas pode consumir mais memória e ser mais lenta devido ao overhead de chamadas de função e ao risco de estouro de pilha em casos de recursão profunda.

A escolha entre uma abordagem iterativa ou recursiva deve considerar tanto os recursos disponíveis (como memória) quanto a complexidade do problema que está sendo resolvido.

#### Pontos importantes:
- Recursão é quando uma função chama a si mesma.
- Toda função recursiva tem dois casos: o caso-base e o caso recursivo.
- Uma pilha tem duas operações: *push* (colocar algo na pilha) e *pop* (tirar algo da pilha).
- Todas as chamadas de função vão para a pilha de chamada, e cada chamada tem seu próprio conjunto de variáveis e valores. 
- Não é possível acessar diretamente as variáveis de uma chamada anterior, a não ser que sejam passadas como parâmetros ou estejam em um escopo mais amplo.
- A pilha de chamada pode ficar muito grande e ocupar muita memória.

## Dividir para Conquistar
Algoritmos que utilizam a técnica DC são recursivos, e seguem os seguintes passos para que possamos analisá-los:
1. Descubra o caso-base, que deve ser o caso mais simples possível.
2. Divida ou diminua o seu problema até que ele se torne o caso-base.

### Exemplo 1
Desejamos dividir em porções quadradas e iguais um terreno de 400x240. Para isso, podemos usar a técnica de dividir para conquistar, aplicando o Algoritmo de Euclides. O objetivo é realizar divisões sucessivas até encontrarmos o Máximo Divisor Comum entre 400 e 240, que será representado pelas dimensões iguais do último quadrado resultante. O caso-base neste problema é encontrar um quadrado cujas dimensões resultem em uma divisão exata, ou seja, com resto zero.

**Algoritmo de Euclides (Máximo Divisor Comum):** Usamos a versão geométrica para encontrar o maior quadrado que divide determinado segmento. Para encontrá-lo, utilizamos o método de dividir para conquistar, repetindo divisões sucessivas (recursivamente) até que o resto seja zero, indicando que as dimensões restantes formam um quadrado perfeito.

Ao encontrarmos o maior quadrado possível nessa área de 400x240, temos como resultado uma área restante não quadricular de 160x240.

![Imagem 55.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2055.png)

Agora, temos que dividir essa nova área de 160x240, visando encontrar o maior quadrado possível a partir dessas novas dimensões.

![Imagem 56.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2056.png)

Ao fazermos isso, percebemos que os valores de altura e largura (160x80) são múltiplos entre si e, portanto, quando os dividimos, o resultado é um resto zero, que é a condição de parada das nossas divisões recursivas. Ao dividirmos 160x80, obtemos dois quadrados iguais ocupando toda essa área, cada um medindo 80x80, sem seguimentos não-quadriculares sobrando. Portanto, a área original de 400x240 pode ser dividida em quadrados de 80x80, sendo eles as maiores unidades possíveis para cobrir a área igualmente.

### Exemplo 2

![Imagem 57.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2057.png)

Para responder essa pergunta, precisamos, primeiro, descobrir o caso-base do nosso problema. Para isso, podemos pensar em maneiras de simplificar a qualidade de elementos na soma, pois quanto menos elementos, mais eficiente e rápida será a nossa soma.
A forma mais simples de somar esse vetor seria caso ele tivesse um ou nenhum elemento. Então nossa tarefa agora é reduzir o nosso problema até que ele atinja a condição descrita.

![Imagem 58.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2058.png)

Como faremos isso? Existem diversas maneiras, no entanto, a utilizada no livro é algo semelhante ao que se vê a seguir:

![Imagem 59.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2059.png)

![Imagem 60.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2060.png)

![Imagem 61.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2061.png)

Dica do autor: Quando estiver escrevendo uma função de recursão que envolva um array, o caso-base será, muitas vezes, um array vazio ou um array com apenas um elemento. Se estiver com problemas, use este caso como base.

## Quicksort
É um algoritmo de ordenação, mais rápido que a ordenação por seleção. Este algoritmo utiliza a técnica dividir para conquistar.

![Imagem 62.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2062.png)

Dito isso, precisamos escolher um pivô (elemento usado para comparação). No momento, iremos pegar o primeiro elemento do vetor (nesse caso, seu valor é 33) e encontrar os elementos maiores e menores do que ele.

![Imagem 63.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2063.png)

![Imagem 64.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2064.png)

![Imagem 65.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2065.png)

Para ordenarmos o array, precisamos ordenar os subarrays que o orbitam, até chegarmos a um resultado satisfatório com a combinação das 3 partes.

Com o Quicksort, conseguimos, a partir do caso-base, ordenar arrays de dois elementos ou de um/nenhum elemento, assim, precisamos quebrar os arrays que circundam o pivô até que eles se encaixem nessa condição.

Fluxo de execução:
1. Escolha um pivô.
2. Particione o array em dois subarrays, separando-os entre elementos menores do que o pivô e elementos maiores do que o pivô.
3. Execute o quicksort recursivamente em ambos os subarrays.
Seguindo este fluxo de execução, independentemente do tamanho do array, conseguiremos ordená-lo a partir da utilização recursiva do Quicksort nos subarrays orbitantes.

Breve texto explicando o uso de provas por indução no material original para provar o algoritmo Quicksort:

![Imagem 66.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2066.png)

Provas por indução são importantíssimas, justamente por serem parte da matemática discreta.

 O algoritmo Quicksort, em termos de tempo de execução, tem em seu caso médio O(n log n), que é o mesmo tempo do merge sort. Já em seu pior caso: O(n²), que é o mesmo tempo do selection sort.

### Merge sort vs Quicksort
Revisando a notação Big O (que tem como propósito mostrar o tempo de execução de determinado algoritmo no pior caso possível), sabemos que ele não utiliza nenhuma medida de tempo para ser comparado. Isso se dá pelo uso de uma constante (número, previamente decidido pelo programador, para servir como base para o número de operações realizadas).
Portanto, dizendo que temos duas funções que façam a exata mesma coisa: imprimir itens de um vetor. Nesse sentido, a primeira (`imprime_itens`) os imprime normalmente, já a segunda (`imprime_itens2`) aguarda 1 segundo após imprimir um item. Ambas as funções passam por toda a lista uma vez, portanto elas têm tempo de execução O(n). No entanto, uma dessas funções é visivelmente mais rápida que a outra, devido à constante utilizada para o cálculo de sua notação.

![Imagem 67.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2067.png)

Geralmente ignoramos as constantes quando avaliamos dois algoritmos com diferentes notações Big O, já que elas não importam nesse caso.

![Imagem 68.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2068.png)

Assim, mesmo a pesquisa simples tendo uma constante bem menor que a da pesquisa binária, ainda é evidente a diferença de tempo de execução.

No entanto, quando estamos tratando de dois algoritmos com tempo de execução igual (Quicksort e merge sort), a constante faz diferença na escolha de qual dos dois utilizar.

#### Caso médio
O Quicksort depende bastante da escolha do pivô para que sua eficiência seja a maior possível. Ao escolhermos sempre, por exemplo, o primeiro elemento, teremos algo semelhante a isso:

![Imagem 69.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2069.png)

Na imagem acima, temos uma pilha de execução enorme, visto que o algoritmo não checa previamente se o array está ordenado ou não. Esse seria o pior caso do Quicksort (pilha de chamadas com tamanho O(n)).

![Imagem 70.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2070.png)

Ao escolhermos o elemento central como pivô, temos uma pilha com metade do tamanho da original, aumentando em muito a eficiência do algoritmo. Esse seria o melhor caso do Quicksort (pilha de chamadas com tamanho O(log n)).

No pior caso, temos O(n) chamadas na pilha, cada uma com O(n) elementos, o que resulta em O(n²). Já no melhor caso, temos O(log n) chamadas na pilha, cada uma com O(n) elementos, visto que cada nível de recursão ainda requer a verificação de todos os n elementos, resultando em um tempo de execução O(n log n).

O caso médio, por sua vez, ocorre quando escolhemos um elemento aleatório do vetor como pivô. Nesse cenário, o desempenho também é O(n log n) em termos de notação Big O (a constante temporal pode ser maior comparado ao melhor caso).

#### Pontos importantes
- A estratégia DC funciona por meio da divisão do problema em problemas menores. Se você estiver utilizando DC em uma lista, o caso-base provavelmente será um array vazio ou um array com apenas um elemento.
- A constante, na notação Big O, pode ser relevante em alguns casos. Esta é a razão pela qual o quicksort é mais rápido do que o merge sort. No entanto, ela dificilmente será relevante na comparação entre pesquisa simples e pesquisa binária, pois O(log n) é muito mais rápido do que O(n) quando sua lista é grande.
- Se você estiver implementando o quicksort, escolha um elemento aleatório (ou mediano) como o pivô. O tempo de execução médio do quicksort é O(n log n).

## Hash
Uma tabela hash é uma estrutura de dados que armazena dados chave-valor. Ela é usada para implementar [arrays associativos](https://pt.wikipedia.org/wiki/Vetor_associativo), onde as chaves são mapeadas para valores (exemplo: produto "maçã", com preço R$0,67). Para isso, temos o uso de uma função hash (que será definida posteriormente) e um vetor.
Ao contrário dos arrays tradicionais, onde os elementos são acessados por índices numéricos, nos arrays associativos, cada valor é associado a uma chave única definida pelo usuário. Além disso, tabelas hash, por utilizarem-se das funções hash, são "inteligentes", sabendo onde armazenar elementos na memória eficientemente.

### Função Hash
Uma função hash é uma função na qual você insere uma string e, depois disso, a função retorna um número. Em uma terminologia mais técnica, diríamos (como anteriormente já dissemos) que uma função hash “mapeia strings e números”.

Requisitos para uma função hash:
- **Consistência**. Imagine que você insere a string “maçã” e recebe o número 0,67. Todas as vezes que você inserir “maçã”, a função deverá retornar o número “0,67”.
- A função **deve mapear diferentes palavras para diferentes números**. Desta forma, uma função hash não será útil se ela sempre retornar “1”, independentemente da palavra inserida. No melhor caso, cada palavra diferente deveria ser mapeada e ligada a um número diferente.

Trabalhando com o exemplo de um supermercado, onde devemos armazenar produtos e seus respectivos preços, teremos o seguinte:

![Imagem 71.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2071.png)

![Imagem 72.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2072.png)

Com essa estrutura, não é necessário procurar o preço de determinado produto no vetor. Para acharmos, por exemplo, a maçã, basta que insiramos "maçã" na função hash, e ela irá nos retornar o índice em que seu preço está inserido (índice 3).

![Imagem 73.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2073.png)

![Imagem 74.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2074.png)

Exemplo ilustrado (utilizando Python no código) de uma tabela hash:

![Imagem 75.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2075.png)

Na hash "caderno", os nomes dos produtos são as chaves e os preços são os valores.

Outros exemplos de tabela hash incluem: listas telefônicas, websites (de URL para IP), ou até mesmo cache.

Para o uso de hashing em caches, o servidor do website relaciona a URL de determinada página com os dados que deveriam estar contidos nela. Assim, é menos trabalhoso recuperar essas informações, evitando requisições desnecessárias.

![Imagem 76.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2076.png)

#### Pontos importantes:
- As tabelas hash são úteis para modelar relações entre dois itens.
- Facilitam a filtragem para checar se há duplicatas.
- São muito usadas em caching/memorização de dados, em vez de solicitar estes dados do servidor.

### Colisões em tabelas hash
Colisões são quando a função hash direciona dois elementos para o mesmo espaço de memória, sobrescrevendo o elemento mais antigo. Colisões em tabelas hash, infelizmente, são comuns, mas podem ser diminuídas com uma boa função hash. Geralmente, quando há uma colisão, a melhor saída é instaurar no slot de memória conflitante uma lista encadeada, facilitando a navegação do usuário. No entanto, essa saída pode diminuir (e muito) o desempenho da tabela hash caso o número de elementos nessa lista cresça.

### Desempenho em tabelas hash
Destaque: Tabelas hash, em seu caso médio, são extremamente velozes, lidando com um tempo de execução de O(1).

![Imagem 77.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2077.png)

![Imagem 78.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2078.png)

Nesse sentido, o tempo de execução constante da tabela hash no caso médio significa que não importa se a sua tabela hash tem 1 elemento ou 1 bilhão de elementos, visto que o **retorno da tabela hash sempre levará a mesma quantidade de tempo**. É o mesmo caso com o retorno de um item em um vetor, por exemplo. Não importa o tamanho do vetor, ele sempre levará a mesma quantidade de tempo para retornar um elemento.

No entanto, no pior caso, uma tabela hash tem tempo de execução O(n), ou seja, tempo de execução linear para tudo, o que é bem lento.

![Imagem 79.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2079.png)

As tabelas hash são tão velozes quanto os arrays na busca (pegar um valor em algum índice), e elas são tão velozes quanto as listas na inserção e na remoção de itens. Porém, no pior dos casos, é bastante lenta. Portanto, precisamos evitar o pior caso, e podemos fazer isso com:
- uma boa função hash;
- um baixo fator de carga.

#### Fator de carga
O cálculo do fator de carga em uma tabela hash é: `número de itens na tabela/número total de espaços`.

![Imagem 80.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2080.png)

Ter um fator de carga maior que um indica que você tem mais itens do que espaços em seu array. Se o fator de carga começar a crescer, será necessário adicionar mais espaços em sua tabela hash (ou seja, redimensioná-la). 

Suponhamos que temos uma tabela hash quase cheia e queremos redimensioná-la.

![Imagem 81.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2081.png)

Com um fator de carga menor haverá menos colisões e sua tabela terá melhor desempenho. **Uma boa regra geral é: redimensione quando o fator de carga for maior do que 0,7**. No entanto, é importante lembrar que redimensionamentos tomam tempo e, portanto, não devem ser feitos com frequência.

#### Como uma boa função hash deve ser?
Uma boa função hash distribui igualmente/simetricamente os elementos na memória.

Exemplo de uma função hash boa e uma ruim:

![Imagem 82.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2082.png)

**OBS:** Não entraremos em detalhes de como confeccionar uma boa função hash, visto que praticamente todas as linguagens de programação tem uma implementada por padrão para uso.

### Pontos importantes
- Você pode fazer uma tabela hash ao combinar uma função hash com um array.
- Colisões são problemas. É necessário haver uma função hash que minimize colisões.
- As tabelas hash são extremamente rápidas para pesquisar, inserir e remover itens, além de serem boas para modelar relações entre dois itens.
- Se o seu fator de carga for maior que 0,7, será necessário redimensionar a sua tabela hash.
- Tabelas hash são ótimas para localizar duplicatas.

## Pesquisa em largura (*breadth-first search*, *BFS*)
A pesquisa em largura permite encontrar o menor caminho entre dois objetos.

Supondo que queremos ir de Twin Peaks até a ponte Golden Gate fazendo o menor número possível de transferência de ônibus, como poderíamos resolver esse problema?

![Imagem 83.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2083.png)

A resposta simples é: utilizando algum algoritmo capaz de resolver esse problema (popularmente chamado de problema do caminho mínimo).  Para que possamos chegar a essa solução, temos que seguir, obrigatoriamente, duas etapas.

![Imagem 84.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2084.png)

### O que é um grafo?
É uma rede de conexões. Usando como exemplo um jogo de pôquer, podemos descrever quem deve dinheiro a quem a partir de um modelo de grafos. Assim, diríamos algo como: “Alex deve dinheiro à Rama”.

![Imagem 85.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2085.png)

E essa conexão poderia se ligar a tantas outras, como: "Rama deve dinheiro a Adit", "Tom deve dinheiro a Rama e a Adit".

![Imagem 86.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2086.png)

Nesse sentido, cada grafo é constituído de vértices e arestas.

![Imagem 87.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2087.png)

Grafos são formados por vértices e arestas, e um vértice pode ser diretamente conectado a muitos outros vértices, por isso os chamamos de vizinhos. Neste grafo, Rama é vizinha de Alex. Já Adit não é vizinho de Alex, pois eles não estão diretamente conectados, mas Adit é vizinho de Rama e de Tom.

### Retornando à pesquisa em largura...
O algoritmo de pesquisa em largura responde perguntas como:
- 1: Existe algum caminho do vértice A até o vértice B?
- 2: Qual o caminho mínimo do vértice A até o vértice B?

Vamos supor que estejamos procurando um vendedor de mangas no Facebook (para que possamos vender nossa colheita). Para isso, inicialmente, iremos perguntar em nosso círculo de amizades se alguém conhece um vendedor de mangas e, caso não conheçam, perguntarei aos amigos deles, repetindo esse ciclo até enfim encontrar um vendedor.

![Imagem 88.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2088.png)

![Imagem 89.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2089.png)

Agora, adicionaremos à lista de consulta amigos de seus amigos até encontrarmos um vendedor.

![Imagem 90.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2090.png)

![Imagem 91.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2091.png)

Isso é um exemplo do algoritmo de pesquisa em largura em ação.

#### Encontrando o caminho mínimo
Levando em conta que o algoritmo de pesquisa em largura tem como principal função responder a dois tipos de perguntas:
- 1: Existe um caminho do vértice A até o vértice B? (Existe um vendedor de manga na minha rede?)
- 2: Qual o caminho mínimo do vértice A até o vértice B? (Quem é o vendedor de manga mais próximo?)

Para responder a segunda pergunta, precisamos considerar qual a distância entre os vértices das extremidades (amigos dos nossos amigos) e a posição inicial (nós) no contexto da rede. Para isso, elencaremos graus de conexão.

![Imagem 92.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2092.png)

Iremos preferir uma conexão de primeiro grau em vez de uma conexão de segundo grau, e uma conexão de segundo grau a uma de terceiro grau, e assim por diante. Portanto, no exemplo das mangas, não se deve pesquisar nenhuma conexão de segundo grau antes de você ter certeza de que não existe uma conexão de primeiro grau com um vendedor de mangas (isto é, nenhum amigo seu vende mangas).

Nesse contexto, quem será verificado primeiro, Claire ou Anuj? Resposta: Claire é uma conexão de primeiro grau e Anuj é uma conexão de segundo grau, logo Claire será verificada antes de Anuj.

Você apenas segue a lista e verifica se a pessoa é uma vendedora de mangas. As conexões de primeiro grau serão procuradas antes das de segundo grau, e, dessa forma, você encontrará o vendedor de mangas mais próximo. Assim, a pesquisa em largura não encontra apenas um caminho entre A e B, ela encontra o caminho mais curto.

![Imagem 93.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2093.png)

Repare que isso só funciona se você procurar as pessoas na mesma ordem em que elas foram adicionadas. Ou seja, se Claire (sua amiga) foi adicionada à lista antes de Anuj (amigo da sua amiga), deve-se pesquisar Claire antes de Anuj. Se essa lógica não for seguida, não podemos garantir que encontraremos o vértice mais próximo possível.

Portanto é necessário pesquisar as pessoas na ordem em que elas foram adicionadas; para isso existe uma estrutura de dados específica: a **fila**.

##### Filas
A estrutura de dados fila funciona da mesma maneira que uma fila na vida real: o primeiro a entrar é o primeiro a sair (sendo uma lógica diretamente oposta à das pilhas).

Suponha que você e um amigo estejam em uma fila em uma parada de ônibus. Se você está antes dele na fila, entrará primeiro no ônibus.

As filas funcionam da mesma maneira, tendo funcionamento similar ao das pilhas. Por isso não é possível acessar elementos aleatórios em uma fila. Em vez disso, apenas duas operações são possíveis: *enqueue* (enfileirar) e *dequeue* (desenfileirar)

![Imagem 94.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2094.png)

A fila é uma estrutura de dados *FIFO* (acrônimo para *First In, First Out*, que em português significa Primeiro a Entrar, Primeiro a Sair). Já a pilha é uma estrutura de dados *LIFO* (*Last In, First Out*, que em português significa Último a Entrar, Primeiro a Sair). Isso também já foi trabalhado nas anotações sobre o curso [[CS50]].

![Imagem 95.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2095.png)

#### Implementando um grafo

![Imagem 96.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%2096.png)
