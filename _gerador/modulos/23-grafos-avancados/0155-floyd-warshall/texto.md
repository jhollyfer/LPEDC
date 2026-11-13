## 0155 · Floyd-Warshall: todos os pares

- **Todos os pares**: a menor distância de cada vértice a cada outro, numa
  matriz `d` (CORMEN et al., 2024, cap. 23).
- **Floyd-Warshall**: programação dinâmica (módulo 21) sobre os vértices que um
  caminho pode usar **como passagem**. Começa com `d[i][j]` = peso da aresta
  direta, INFINITO se não há, 0 na diagonal (FLOYD, 1962).
- **Rodada `k`**: depois dela, `d[i][j]` é o melhor de `i` a `j` usando como
  passagem só os vértices de 0 a `k`. Por isso o `k` é o laço **de fora**.
- **Custo**: **O(V³)** de tempo e O(V²) de memória: 125 passos para 5 vértices,
  64 milhões para 400. Para grafos grandes e esparsos, Dijkstra com heap
  (CORMEN et al., 2024, cap. 23).
- **Pesos negativos**: aceita, sem ciclo negativo; com ciclo, aparece
  `d[i][i] < 0` no fim.
- **Fecho transitivo**: trocar `+` e `min` por `&&` e `||` responde "existe
  caminho?" (algoritmo de Warshall) (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 8).

```text
para cada k:            (o bairro que passa a valer como passagem)
    para cada i, j:
        d[i][j] = mínimo(d[i][j], d[i][k] + d[k][j])
```

> [!WARNING]
> Pôr o `k` no laço de **dentro** compila, roda e erra sem aviso: `d[i][k]` e
> `d[k][j]` ainda não estão prontos. E `d[i][k] + d[k][j]` precisa do teste de
> INFINITO: com `INT_MAX`, estoura.

{{exemplo}}

Um aplicativo de corrida quer o tempo de cada bairro a cada outro, com ruas de
**mão única**. As setas são as ruas em minutos, e o melhor caminho de Centro
até Alto, em verde, passa por três bairros. Embaixo, a tabela final:

{{ideia}}

```c
#include <stdio.h>

#define V 5
#define INFINITO 1000000000

int main(void) {
    const char *bairros[V] = {"Centro", "Porto", "Vila", "Alto", "Feira"};
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = (i == j) ? 0 : INFINITO; // sem rua: infinito

    int ruas[][3] = {{0, 2, 2}, {2, 1, 3}, {0, 1, 6}, {1, 3, 4},
                     {3, 0, 5}, {2, 4, 7}, {4, 3, 1}, {1, 4, 2}};
    for (int r = 0; r < 8; r++) d[ruas[r][0]][ruas[r][1]] = ruas[r][2]; // mão única

    for (int k = 0; k < V; k++)         // k: o bairro que pode servir de passagem
        for (int i = 0; i < V; i++)     // de i
            for (int j = 0; j < V; j++) // para j
                if (d[i][k] != INFINITO && d[k][j] != INFINITO && d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j]; // passar por k é mais rápido

    printf("%-8s", "de\\para");
    for (int j = 0; j < V; j++) printf("%7s", bairros[j]);
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%-8s", bairros[i]);
        for (int j = 0; j < V; j++) printf("%7d", d[i][j]);
        printf("\n");
    }
    return 0;
}
// Saída:
// de\para  Centro  Porto   Vila   Alto  Feira
// Centro        0      5      2      8      7
// Porto         8      0     10      3      2
// Vila         11      3      0      6      5
// Alto          5     10      7      0     12
// Feira         6     11      8      1      0
```

O fluxograma tem três contadores e uma comparação no miolo, repetida V³
vezes:

{{fluxograma}}

### Passo a passo

A casa `d[Centro][Alto]`, rodada a rodada:

| Rodada (passagem liberada) | `d[Centro][Alto]` | Caminho por trás do número |
| --- | --- | --- |
| início | ∞ | (nenhuma rua direta) |
| k = Centro | ∞ | ninguém chega ao Alto pelo Centro ainda |
| k = Porto | 10 | Centro → Porto → Alto: 6 + 4 |
| k = Vila | 9 | Centro → Vila → Porto → Alto: 2 + 3 + 4 |
| k = Alto | 9 | passar pelo próprio destino não ajuda |
| k = Feira | 8 | Centro → Vila → Porto → Feira → Alto: 2 + 3 + 2 + 1 |

Cada rodada aproveita as anteriores: na da Vila, `d[Vila][Alto]` já vale 7,
calculado na rodada do Porto.
