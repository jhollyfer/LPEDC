## 0109 · Grafos

- **Grafo**: um conjunto de **vértices** (pontos) e de **arestas** (ligações
  entre pares). O Cormen escreve **G = (V, E)** e usa V e E também para as
  quantidades, de onde vêm Θ(V²) e Θ(V + E) (CORMEN et al., 2024, cap. 20).
- **Diferente da árvore**: toda árvore é um grafo, mas um grafo pode ter
  ciclos e partes soltas (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 8).
- **Vocabulário**: **vizinhos** são ligados por aresta; **grau** é quantas
  arestas tocam o vértice; **caminho** é uma sequência de vizinhos; **ciclo**
  volta ao começo; **conexo** liga todos a todos (ZIVIANI, 2010, cap. 7).
- **Dirigido e ponderado**: com mão única, cada aresta é uma seta e o vértice
  tem **grau de saída** e **de entrada**. Com um número na aresta (minutos,
  reais), o grafo é **ponderado** (CORMEN et al., 2024, cap. 20).
- **Soma dos graus**: cada aresta soma 1 no grau de dois vértices, então a
  soma é o dobro do número de arestas (ZIVIANI, 2010, cap. 7).
- **Vértice no C**: um número de 0 a V-1; os nomes ficam num vetor à parte
  (`nomes[2]` é `"Feira"`) (FEOFILOFF, 2009).

| Representação | Espaço | "i e j são vizinhos?" | Listar vizinhos de `i` |
| --- | --- | --- | --- |
| **matriz** `int adj[V][V]` | O(V²) | O(1) | O(V), a linha inteira |
| **lista de adjacência** | O(V + E) | o grau de `i` | o grau de `i` |

Com 100 mil vértices, a matriz teria 10¹⁰ casas, quase todas zero. Grafo
pequeno ou denso, matriz; grande e esparso, lista.

> [!WARNING]
> Em grafo não dirigido, a aresta entra **nos dois sentidos**: `adj[a][b] = 1`
> e `adj[b][a] = 1`. Esquecer um cria um grafo dirigido sem querer, e o erro
> só aparece quando a busca não acha um caminho que existe.

{{exemplo}}

Cinco ciclovias ligam Centro, Praia, Feira, Parque e Estádio, nos dois
sentidos e sem peso. A matriz sai simétrica; a Feira tem três vizinhos, e a
linha 2 tem três 1:

{{ideia}}

As arestas entram como pares, e o grau sai da soma de cada linha. Soma ímpar
indicaria um sentido esquecido:

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
algoritmo do módulo segue essa ordem. O A217 guarda pesos na matriz e o A218
usa a lista de adjacência como TAD:

{{fluxograma}}
