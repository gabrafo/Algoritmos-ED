Na computação, uma pilha é uma estrutura de dados que assume a forma de **monte** para acomodar informações, sendo baseada no princípio *Last In First Out* (LIFO), que prega que o último elemento a ser adicionado deverá ser o primeiro a ser excluído. **Não é possível o acesso aos demais dados senão a partir das extremidades**, assim, **caso eu deseje acessar um item no meio da pilha, devo desamontoar todos os elementos acima dele em ordem de prioridade até alcançá-lo**.

## Exemplo de pilha:
Vamos imaginar que Gabriel esteja em uma semana difícil na faculdade, e para facilitar o processo de lavagem de roupa, decidiu amontoar suas peças usadas durante a semana em uma cadeira, no canto de seu quarto.

![Imagem 1](https://github.com/gabrafo/Algoritmos-ED/blob/master/Anota%C3%A7%C3%B5es%20de%20ED/Imagens/Imagem%201.png)

Na sexta-feira, Gabriel deveria lavar todas as peças à mão, mas, cansado (ou talvez preguiçoso), decidiu que lavaria apenas uma peça por dia, planejando concluir o trabalho antes da segunda-feira. Como as roupas estavam organizadas em uma pilha, ele sempre lavava a peça que estava no topo.

No entanto, logo ao sábado, Gabriel teve que sair para um compromisso e, inevitavelmente, acabou sujando outra peça de roupa. De volta ao quarto, ele a adicionou ao topo da pilha, aumentando o número de peças a serem lavadas e mantendo o padrão de lavar sempre a peça que estivesse por cima.

![Imagem 2](https://github.com/gabrafo/Algoritmos-ED/blob/master/Anota%C3%A7%C3%B5es%20de%20ED/Imagens/Imagem%202.png)

Assim, o amontoado de roupas de Gabriel na segunda-feira estava assim:

![Imagem 3](https://github.com/gabrafo/Algoritmos-ED/blob/master/Anota%C3%A7%C3%B5es%20de%20ED/Imagens/Imagem%203.png)

Diferentemente, caso o rapaz não tivesse sujado uma nova peça de roupa e adicionado à pilha no sábado...

![Imagem 4.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/Anota%C3%A7%C3%B5es%20de%20ED/Imagens/Imagem%204.png)

Sua pilha de roupas estaria vazia e, portanto, não precisaria lavar mais nenhuma peça durante os dias de semana.

## Implementações comuns
Geralmente, para implementar uma pilha, usam-se tais estratégias:
- Implementação usando encadeamento de nós (elementos) da pilha.
  Para essa solução, geralmente, usa-se a estrutura de dados **lista encadeada** ou classes que atuem de forma semelhante.
  
- Implementação usando arranjo (vetores) para armazenamento dos elementos.
  As vantagens dessa abordagem são: velocidade de acesso (O(1)) e empilhamento/desempilhamento da pilha. No entanto, pode ser necessário redimensionamento frequente de vetores, o que tem um custo computacional grande, além da possibilidade de desperdiçar espaço de memória.

Pilha e nós são implementados tradicionalmente como estruturas ou classes. Utilizando C++, usaremos a segunda abordagem.

### Implementação usando encadeamento
A implementação mais comum de pilha é a usando encadeamento. 
Nesse modelo de implementação, um nó (elemento) contém determinado valor e também o endereço de memória para o próximo nó (servindo como ponteiro). Isso ocorre até chegarmos ao fim da pilha, onde o último elemento não aponta para nenhum outro elemento (aponta para `NULL`). 
Nesse sentido, podemos saber apenas onde é o topo (último elemento) da estrutura de dados, visto que para acessar outros, precisaríamos desempilhar todos os elementos anteriores ao desejado até o encontrarmos.

#### Classe `Noh`
Cada nó da pilha contem como atributos dados armazenados e um apontador para o nó seguinte.

```cpp
// Exemplo simples
class Noh{
	int dado;
	Noh* proximoElemento; // Ponteiro para o próximo nó
}
```

#### Classe `Pilha`
A classe pilha contém, geralmente, um apontador para o último elemento adicionado à ED e um atributo para informar a quantidade de elementos (nós) que ela possui.

```cpp
class Pilha{
	int tamanho;
	Noh* ultimoElemento;
}
```

#### Operações básicas sobre pilhas

- Criação/destruição da pilha
  O processo de criação da pilha se baseia em garantir que o topo da pilha não aponte para uma região válida de memória, ou seja, aponte para nulo.
  
  ![Imagem 5.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/Anota%C3%A7%C3%B5es%20de%20ED/Imagens/Imagem%205.png)
  
  Representação da recém-criada `pilhaDeFrutas`, um objeto da classe `Pilha`.
  Caso adicionemos um elemento a essa pilha recém-criada (veremos mais sobre a operação de inserção a seguir), teremos:
  
  ![Imagem 6.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/Anota%C3%A7%C3%B5es%20de%20ED/Imagens/Imagem%206.png)
  
  A fruta "laranja" apontando, como próximo elemento da pilha, para o valor `NULL`, indicando que não há nenhum elemento abaixo dela. Isso se dará até o momento em que "laranja" for removida da pilha, onde só restará o valor `NULL`.

- Inserção (*push*) de um elemento
  Já a inserção em uma pilha consiste na criação de um novo nó com com o dado a ser armazenado, assim o colocamos no topo. Para que essa operação seja bem sucedida, o elemento que estava no topo (antes da operação de inserção) deverá ser indicado pelo elemento inserido como o próximo elemento da pilha. Além disso, caso haja alguma contabilização de tamanho da pilha, ela também deverá ser atualizada para abarcar o novo elemento.
  
  ![Imagem 7.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/Anota%C3%A7%C3%B5es%20de%20ED/Imagens/Imagem%207.png)
  
  Com a adição da fruta "pera", o antigo elemento que estava no topo da estrutura de dados (a fruta "abacaxi") agora está sendo apontado por "pera" como o próximo elemento, a partir dela, da pilha.

- Remoção (*pop*) de um elemento
  Para a remoção, basta retirarmos o último elemento da pilha. Assim, caso hajam cinco elementos na pilha, como no exemplo acima, devemos apenas retirar o elemento que está no topo (representado pelo atributo `ultimoElemento` da classe `Pilha`), que, no nosso caso, seria "pera" e reatribuir com o elemento anterior ("abacaxi").
  
  ![Imagem 8.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/Anota%C3%A7%C3%B5es%20de%20ED/Imagens/Imagem%208.png)
  
