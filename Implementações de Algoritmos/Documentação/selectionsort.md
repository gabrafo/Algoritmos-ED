# Documentando o código...
No arquivo [`selectionsort.cpp`](../selectionsort.cpp) temos um exemplo de método de ordenação (ordenação por seleção), a seguir irei explicar o funcionamento desse algoritmo. Esse algoritmo não utiliza a técnica "dividir para conquistar", e sim uma abordagem iterativa.

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

**Nota:** O conteúdo desse texto se baseia diretamente em um exemplo dado no livro "Entendendo Algoritmos", é uma leitura extremamente recomendada.

## Descrição do Algoritmo
Utilizamos uma estrutura de laços `for` aninhados para checar cada elemento do vetor (`i`) e compará-lo com os elementos seguintes (`j`). Portanto, se a variável local `i` vale 0, a `j` valerá, durante seu loop de execução, de 1 até o valor da última posição do vetor (representado por tamanhoVetor). 

### Primeira Iteração
- **Primeira Iteração do Loop Externo (`i = 0`):**

1. **Inicialização:**
   - `posMenor` é definido como `0` (o índice de "Kendrick Lamar").
   - `aux` é uma variável temporária usada para a troca.

2. **Loop Interno (`j` de `i+1` a `tamanhoVetor`):**
   - **Para `j = 1`:**
     - Comparação: `artistasVetor[1].getContadorDePlays()` (Yun Li, 300) > `artistasVetor[posMenor].getContadorDePlays()` (Kendrick Lamar, 150)
     - Resultado: Verdadeiro, então `posMenor` é atualizado para `1`.

   - **Para `j = 2`:**
     - Comparação: `artistasVetor[2].getContadorDePlays()` (Mitski, 100) > `artistasVetor[posMenor].getContadorDePlays()` (Yun Li, 300)
     - Resultado: Falso, `posMenor` permanece `1`.

   - **Para `j = 3`:**
     - Comparação: `artistasVetor[3].getContadorDePlays()` (Pullovers, 250) > `artistasVetor[posMenor].getContadorDePlays()` (Yun Li, 300)
     - Resultado: Falso, `posMenor` permanece `1`.

   - **Para `j = 4`:**
     - Comparação: `artistasVetor[4].getContadorDePlays()` (Martinho da Vila, 50) > `artistasVetor[posMenor].getContadorDePlays()` (Yun Li, 300)
     - Resultado: Falso, `posMenor` permanece `1`.

3. **Troca:**
   - Após o loop interno, `artistasVetor[0]` (Kendrick Lamar) é trocado com `artistasVetor[1]` (Yun Li).

### Segunda Iteração
- **Segunda Iteração do Loop Externo (`i = 1`):**

1. **Inicialização:**
   - `posMenor` é definido como `1` (o índice de "Kendrick Lamar" já movido).

2. **Loop Interno (`j` de `i+1` a `tamanhoVetor`):**
   - **Para `j = 2`:**
     - Comparação: `artistasVetor[2].getContadorDePlays()` (Mitski, 100) > `artistasVetor[posMenor].getContadorDePlays()` (Kendrick Lamar, 150)
     - Resultado: Falso, `posMenor` permanece `1`.

   - **Para `j = 3`:**
     - Comparação: `artistasVetor[3].getContadorDePlays()` (Pullovers, 250) > `artistasVetor[posMenor].getContadorDePlays()` (Kendrick Lamar, 150)
     - Resultado: Verdadeiro, então `posMenor` é atualizado para `3`.

   - **Para `j = 4`:**
     - Comparação: `artistasVetor[4].getContadorDePlays()` (Martinho da Vila, 50) > `artistasVetor[posMenor].getContadorDePlays()` (Pullovers, 250)
     - Resultado: Falso, `posMenor` permanece `3`.

3. **Troca:**
   - Após o loop interno, `artistasVetor[1]` (Kendrick Lamar) é trocado com `artistasVetor[3]` (Pullovers).

### Resumo
Esse processo continua até que todo o vetor esteja ordenado. A cada iteração do loop externo, o elemento com o maior número de plays é movido para a posição correta, resultando em uma ordenação decrescente ao final do algoritmo.

## Intenção do Programa
Para além da ordenação por seleção, a intenção do programa era realizar uma operação de tempo de execução O(n²) semelhante à apresentada no segundo capítulo do livro "Entendendo Algoritmos" para que seja possível ordenar de maneira decrescente os meus artistas mais ouvidos no mês de agosto de 2024. Portanto, ao fim do programa, é exibido o vetor ordenado de todos os artistas de maneira decrescente (mais ouvido ao menos ouvido).

Utilizei um vetor ao invés de uma lista encadeada pela maior facilidade no acesso de elementos, que é O(1), tornando mais eficiente o processo de troca de posições com o uso de um objeto auxiliar (`aux`). Por fim, o mais custoso, em termos de tempo de execução, são as operações de comparação, que representam O(n²).

É importante mencionar o uso de conceitos de programação orientada a objetos para facilitar a representação dos artistas, tendo sido utilizado também um atributo estático responsável por contabilizar a quantidade de instâncias da classe `Artista`. No entanto, a forma como a utilizamos não é uma boa prática, visto que poderiam haver instâncias dessa mesma classe fora do vetor em que realizamos a ordenação por seleção, para resolver esse problema uma alternativa seria atribuir à variável `tamanhoVetor` algo como `sizeof(artistasVetor) / sizeof(artistasVetor[0])`, dividindo o tamanho em bytes do vetor pelo tamanho padrão de seus elementos. 
