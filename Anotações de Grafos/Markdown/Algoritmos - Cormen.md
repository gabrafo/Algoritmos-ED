Antes de discutir as representações, é fundamental entender o que é um grafo. Um **grafo G é uma estrutura matemática fundamental definida como um par (V, E)**.

• **V** representa o **conjunto finito de vértices** (também conhecidos como nós), que são os objetos individuais no grafo. O número de vértices em um grafo é denotado por **|V|**.

• **E** representa o **conjunto de arestas**, que são as conexões ou relações entre os vértices. O número de arestas em um grafo é denotado por **|E|**.

---

## Tipos de grafos

• **Grafos dirigidos**: As arestas são pares ordenados (u, v), indicando uma conexão com uma direção específica, de u para v. Laços (arestas de um vértice para si mesmo) são possíveis.

• **Grafos não dirigidos**: As arestas são pares não ordenados {u, v}, significando que a conexão entre u e v não tem direção. Por convenção, também usamos a notação (u, v) para arestas não dirigidas, e (u, v) e (v, u) são consideradas a mesma aresta. Nesses grafos, **laços são proibidos**, e cada aresta conecta dois vértices distintos.

### Grafo esparso e Grafo denso

• **Grafos esparsos** são aqueles em que o **número de arestas (|E|) é muito menor que o número máximo possível de arestas (|V|²)**. Para esses grafos, a representação por listas de adjacências é geralmente preferida. Veremos o que são listas de adjacências em breve.

• **Grafos densos** são aqueles em que o **número de arestas (|E|) está próximo do número máximo possível de arestas (|V|²)**. Para esses grafos, a representação por matrizes de adjacências pode ser mais adequada, especialmente quando se precisa verificar rapidamente a existência de uma aresta entre dois vértices dados. Veremos o que são matrizes de adjacências em breve.

O valor **|V|²** é o **número máximo possível de arestas que um grafo com |V| vértices pode ter**. Esse valor serve como um ponto de referência para medir a "densidade" ou quão "cheio" um grafo é em termos de suas conexões.

• **Para entender em um grafo direcionado**:

   ◦ Se existem **|V| vértices**, e cada vértice pode ter uma aresta apontando para **qualquer outro dos |V| vértices** (incluindo ele mesmo, se laços forem permitidos), então o número total máximo de arestas possíveis é **|V| multiplicado por |V|**, o que resulta em **|V|²** arestas.

   ◦ Mesmo se laços não forem permitidos (o que significa que um vértice não pode ter uma aresta para si mesmo), cada vértice ainda pode se conectar a |V|-1 outros vértices. O número total de arestas seria |V| * (|V|-1), que ainda é **assintoticamente da ordem de |V|²**.

• **Para entender em um grafo não dirigido**:

   ◦ Nesse tipo de grafo, **laços são proibidos**, e uma aresta simplesmente conecta um par de vértices distintos.

   ◦ O número de maneiras de escolher dois vértices distintos de um conjunto de |V| vértices para formar uma aresta é dado pela fórmula de combinações: |V| * (|V|-1) / 2.

   ◦ Esta expressão também é **assintoticamente da ordem de |V|²**.

Portanto, **|V|²** fornece uma medida do potencial máximo de conexões de um grafo. Ao comparar o número real de arestas (|E|) com este valor de referência (|V|²), podemos classificar um grafo como esparso ou denso, o que influencia a escolha da representação mais eficiente e a análise do desempenho dos algoritmos.

---

## Lista de adjacência e Matriz de adjacência

Podemos escolher entre dois modos padrões para representar um grafo G = (V, E): como uma coleção de **listas de adjacências** ou como uma **matriz de adjacências**. Qualquer desses modos se aplica a grafos dirigidos e não dirigidos.

Geralmente, **nosso método preferido são as listas de adjacência**. Elas **se destacam em situações em que estamos lidando com grafos esparsos**. No entanto, **para grafos densos**, a **matriz de adjacência pode ser preferível**, ou quando **precisamos saber rapidamente se há uma aresta conectando dois vértices** dados. 

![[./Imagens/22-1.png]]
[Figuras do livro Algoritmos - Teoria e Prática de Cormen.](<Markdown/Grafos, listas e matrizes de adjacência.md>)


