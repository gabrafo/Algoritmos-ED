Na computação, uma pilha é uma estrutura de dados que assume a forma de **monte** para acomodar informações, sendo baseada no princípio *Last In First Out* (LIFO), que prega que o último elemento a ser adicionado deverá ser o primeiro a ser excluído. **Não é possível o acesso aos demais dados senão a partir das extremidades**, assim, **caso eu deseje acessar um item no meio da pilha, devo desamontoar todos os elementos acima dele em ordem de prioridade até alcançá-lo**.

## Exemplo de pilha:
Vamos imaginar que Gabriel esteja em uma semana difícil na faculdade, e para facilitar o processo de lavagem de roupa, decidiu amontoar suas peças usadas durante a semana em uma cadeira, no canto de seu quarto.

![Imagem 3](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%203.png)

Na sexta-feira, Gabriel deveria lavar todas as peças à mão, mas, cansado (ou talvez preguiçoso), decidiu que lavaria apenas uma peça por dia, planejando concluir o trabalho antes da segunda-feira. Como as roupas estavam organizadas em uma pilha, ele sempre lavava a peça que estava no topo.

No entanto, logo ao sábado, Gabriel teve que sair para um compromisso e, inevitavelmente, acabou sujando outra peça de roupa. De volta ao quarto, ele a adicionou ao topo da pilha, aumentando o número de peças a serem lavadas e mantendo o padrão de lavar sempre a peça que estivesse por cima.

![Imagem 4](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%204.png)

Assim, o amontoado de roupas de Gabriel na segunda-feira estava assim:

![Imagem 5](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%205.png)

Diferentemente, caso o rapaz não tivesse sujado uma nova peça de roupa e adicionado à pilha no sábado...

![Imagem 6.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/anotacoes/alg_ed/anexo/Imagem%206.png)

Sua pilha de roupas estaria vazia e, portanto, não precisaria lavar mais nenhuma peça durante os dias de semana.

## Implementações comuns
Geralmente, para implementar uma pilha, usam-se tais estratégias:
- Implementação usando encadeamento de nós (elementos) da pilha.
  Nesse caso, um nó (elemento) contém determinado valor e também o endereço de memória para o próximo nó (servindo como ponteiro). Isso ocorre até chegarmos ao fim da pilha, onde o último elemento não aponta para nenhum outro elemento.
  Para essa solução, geralmente, usa-se a estrutura de dados **lista encadeada** ou classes que atuem de forma semelhante.
  
- Implementação usando arranjo (vetores) para armazenamento dos elementos.
