# Documentação de Solução – Promessa de Campanha (Beecrowd 1835)

**Link do problema:** [Beecrowd 1835](https://judge.beecrowd.com/pt/problems/view/1835)

---

## Descrição do Problema

O problema descreve a situação de um prefeito que quer **pavimentar estradas** de forma que seja possível viajar entre quaisquer dois pontos da cidade **sem passar por estrada de terra**.

* Cada ponto principal é um **vértice** do grafo.
* Cada estrada existente é uma **aresta** entre dois vértices.
* Pergunta-se:

1. Todos os pontos já estão conectados por estradas pavimentadas?
2. Caso contrário, quantas estradas adicionais seriam necessárias para garantir a conectividade?

**Em termos de grafos:** o problema se reduz a **contar componentes conexos** em um grafo não-direcionado.

---

## Estratégia de Solução

### 1. Representação do grafo

* Usamos **lista de adjacência**: `vector<vector<int>> adj`.
* Cada índice do vetor representa um vértice, cada vetor interno armazena os vizinhos daquele vértice.
* `N+1` posições são usadas para acessar os vértices de 1 a N diretamente (sem ajuste de índice).

### 2. Identificação de componentes conexos

* Utilizamos **DFS iterativa** com uma pilha (`stack<int>`).

  * Evita estouro de pilha em grafos grandes, comparado à DFS recursiva.
* Cada vértice visitado é marcado em `visited`.
* Para cada vértice não visitado, iniciamos uma DFS:

  * Todos os vértices alcançáveis a partir dele pertencem ao **mesmo componente**.
  * Cada DFS iniciada a partir de um vértice não visitado representa **uma nova ilha de vértices conectados**.

### 3. Cálculo do número mínimo de estradas adicionais

Se existem `components` componentes conectados:

`E = components - 1`

* Cada estrada conecta duas ilhas, então precisamos de **uma estrada a menos que o número de ilhas** para conectá-las todas.
* Caso `E == 0`, todos os pontos já estão conectados.

---

## Estruturas e Conceitos Importantes

* **Lista de adjacência:** eficiente para grafos esparsos.
* **DFS iterativa:** percorre todos os vértices de um componente.
* **Componentes isolados:** um vértice sem nenhuma estrada ainda conta como componente.
* **Estradas faltantes:** `components - 1`.
* **Otimizações do C++:**

  * `reserve(M)` evita realocações no vetor.
  * `emplace_back` constrói os pares diretamente no local.

---

## Explicação do Código

### Função `dfs`

**Objetivo:** calcular o número de componentes conectos no grafo.

**Passo a passo:**

1. Cria a lista de adjacência `adj`.
2. Preenche `adj` com base nas conexões (`connections`).
3. Inicializa `visited` para marcar vértices já visitados.
4. Inicializa `components = 0`.
5. Para cada vértice `u` de 1 a N:

   * Se `u` não foi visitado:

     * Incrementa `components`.
     * Executa DFS iterativa a partir de `u` usando uma pilha.
     * Marca todos os vértices alcançáveis a partir de `u` como visitados.
6. Retorna `components`.

---

### Função `main`

**Objetivo:** processar múltiplos casos de teste e produzir saída formatada.

1. Lê `T`, número de casos de teste.
2. Para cada caso:

   * Lê `N` (vértices) e `M` (arestas).
   * Lê `M` pares `(X, Y)` e armazena em `connections`.
   * Chama `dfs(N, connections)` para obter `components`.
   * Calcula `E = components - 1`.
   * Imprime:

     * Se `E == 0`, a promessa foi cumprida.
     * Caso contrário, informa quantas estradas faltam.

---

## Testcase Explicativo

```
5 3
1 2
2 3
4 5
```

### Visualização do Grafo

```
1 - 2 - 3     4 - 5
```

* Componentes:

  * Componente 1: {1, 2, 3}
  * Componente 2: {4, 5}

---

### Passo a Passo da DFS

**Inicialização:**

* `visited = [false, false, false, false, false, false]`
* `components = 0`

---

**Vértice 1:**

* Não visitado → novo componente
* `components = 1`
* Pilha: `[1]`

Iteração da pilha:

1. Pop 1 → vizinhos: `[2]`

   * `2` não visitado → `visited[2]=true`, empilhar `2`
2. Pop 2 → vizinhos: `[1, 3]`

   * `1` visitado → ignorar
   * `3` não visitado → `visited[3]=true`, empilhar `3`
3. Pop 3 → vizinhos: `[2]`

   * `2` visitado → ignorar

* Pilha vazia → DFS do componente 1 terminou
* `visited = [false, true, true, true, false, false]`

---

**Vértices 2 e 3:**

* Já visitados → pular

---

**Vértice 4:**

* Não visitado → novo componente
* `components = 2`
* Pilha: `[4]`

Iteração da pilha:

1. Pop 4 → vizinhos: `[5]`

   * `5` não visitado → `visited[5]=true`, empilhar `5`
2. Pop 5 → vizinhos: `[4]`

   * `4` visitado → ignorar

* Pilha vazia → DFS do componente 2 terminou
* `visited = [false, true, true, true, true, true]`

---

**Vértice 5:**

* Já visitado → pular

---

### Resultado

* Total de componentes: `components = 2`
* Estradas faltando: `E = components - 1 = 1`

**Saída:**

```
Caso #1: ainda falta(m) 1 estrada(s)
```