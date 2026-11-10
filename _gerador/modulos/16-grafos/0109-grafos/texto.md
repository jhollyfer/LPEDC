## 0109 · Grafos

A prefeitura inaugurou cinco ciclovias ligando Centro, Praia, Feira, Parque e
Estádio. De onde dá para ir direto para onde? Qual ponto tem mais ligações?

Lista é fila indiana, e árvore tem um pai só e nenhuma volta. Aqui o Centro
liga na Praia **e** na Feira, e a Praia liga na Feira, fechando um triângulo.
Para isso existe o **grafo**: **vértices** (os pontos) e **arestas** (as
ligações entre pares de pontos). Toda árvore é um grafo, mas um grafo pode
ter ciclos e partes soltas. O Cormen escreve **G = (V, E)** e usa V e E também
para as quantidades, de onde vêm o Θ(V²) e o Θ(V + E) deste módulo.

Vocabulário:

- **vizinhos** (adjacentes): vértices ligados por uma aresta;
- **grau**: quantas arestas tocam o vértice (a Feira tem grau 3);
- **caminho**: sequência de vértices vizinhos (Praia, Feira, Parque);
- **ciclo**: caminho que volta ao começo (Centro, Praia, Feira, Centro);
- **conexo**: dá para ir de qualquer vértice a qualquer outro.

Com mão única, o grafo é **dirigido**: cada aresta é uma seta, e cada vértice
tem **grau de saída** e **grau de entrada** (a soma dos graus de saída é o
número de arestas). Com um número na aresta (minutos, reais), é **ponderado**.
As ciclovias valem nos dois sentidos e não têm peso.

No C, vértice é um **número de 0 a V-1**, e os nomes ficam num vetor à parte
(`nomes[2]` é `"Feira"`). Há duas representações clássicas:

- **matriz de adjacência**: `int adj[V][V]`, com `adj[i][j] = 1` quando há
  aresta de `i` para `j`. Perguntar "i e j são vizinhos?" custa O(1); listar
  os vizinhos de `i` custa O(V), a linha inteira.
- **lista de adjacência**: um vetor de V listas encadeadas, a de `i` com só os
  vizinhos de `i`. Ocupa O(V + E) e listar os vizinhos custa o grau.

Cada ciclovia marca `adj[a][b]` e `adj[b][a]`: a matriz de um grafo não
dirigido é simétrica. A Feira tem três vizinhos, e a linha 2 tem três 1:

{{ideia}}

As arestas entram como pares, e o grau sai da soma de cada linha:

```c
#include <stdio.h>

#define V 5 // número de vértices (pontos da cidade)

int main(void) {
    const char *nomes[V] = {"Centro", "Praia", "Feira", "Parque", "Estadio"};
    int adj[V][V] = {0}; // adj[i][j] == 1: existe ciclovia entre i e j

    // as ciclovias, como pares de vértices
    int ciclovias[][2] = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}};
    int total = (int)(sizeof ciclovias / sizeof ciclovias[0]);

    for (int k = 0; k < total; k++) {
        int a = ciclovias[k][0];
        int b = ciclovias[k][1];
        adj[a][b] = 1;
        adj[b][a] = 1; // não dirigido: vale nos dois sentidos
    }

    printf("     0 1 2 3 4\n");
    int soma_graus = 0;
    for (int i = 0; i < V; i++) {
        int grau = 0;
        printf("  %d ", i);
        for (int j = 0; j < V; j++) {
            printf(" %d", adj[i][j]);
            grau += adj[i][j]; // o grau é a soma da linha
        }
        printf("  %-8s grau %d\n", nomes[i], grau);
        soma_graus += grau;
    }
    printf("Soma dos graus: %d = 2 x %d ciclovias\n", soma_graus, total);
    return 0;
}
// Saída:
//      0 1 2 3 4
//   0  0 1 1 0 0  Centro   grau 2
//   1  1 0 1 0 0  Praia    grau 2
//   2  1 1 0 1 0  Feira    grau 3
//   3  0 0 1 0 1  Parque   grau 2
//   4  0 0 0 1 0  Estadio  grau 1
// Soma dos graus: 10 = 2 x 5 ciclovias
```

Primeiro monta-se a estrutura, depois respondem-se as perguntas; todo
algoritmo do módulo segue essa ordem:

{{fluxograma}}

Cada aresta soma 1 no grau de dois vértices: a soma dos graus é o dobro do
número de arestas, e soma ímpar indica um sentido esquecido.

O exemplo A217 guarda o tamanho de cada estrada na matriz (grafo ponderado); o
A218 usa a lista de adjacência como TAD (`grafo.h` e `grafo.c`), com arestas
dirigidas.

> [!WARNING]
> Em grafo não dirigido, a aresta entra **nos dois sentidos**: `adj[a][b] = 1`
> e `adj[b][a] = 1`. Esquecer um deles cria um grafo dirigido sem querer, e o
> erro só aparece quando a busca não acha um caminho que existe.

> [!TIP]
> **Por dentro do C:** `int adj[5][5]` são 25 `int` seguidos (100 bytes). Com
> 100 mil vértices, a matriz teria 10¹⁰ casas (40 GB), quase todas zero. Regra
> prática: grafo pequeno ou denso, matriz; grande e esparso, lista.

> [!NOTE]
> **Pergunta para você:** com uma ciclovia entre Praia e Estádio, quais números
> da saída mudam?

{{pratique}}
