## 0112 · Dijkstra: caminho mínimo

- **Grafo ponderado**: cada aresta tem um **peso** (minutos, km, reais). O
  menor caminho é o de **menor soma de pesos**, não o de menos arestas; aí a
  BFS erra (CORMEN et al., 2024, cap. 22).
- **Dijkstra**: acha os menores caminhos a partir de uma origem quando
  **nenhum peso é negativo** (DIJKSTRA, 1959).
- **O que ele guarda**: `dist[v]`, o melhor tempo **conhecido** até `v` (0 na
  origem, INFINITO no resto); `fixo[v]`, se ele já é definitivo; `anterior[v]`,
  de onde se chega em `v` (o `pai[]` da BFS) (ZIVIANI, 2010, cap. 7).
- **Relaxar**: se `dist[u] + peso[u][v] < dist[v]`, atualiza `dist[v]` e
  `anterior[v]`. No Cormen é `RELAX(u, v, w)`, com `v.d`, `v.π` e o conjunto S
  dos fixos (CORMEN et al., 2024, cap. 22).
- **Guloso**: a cada passo fixa o não fixo de menor `dist` e relaxa as arestas
  dele; a escolha nunca se desfaz. É seguro porque, sem pesos negativos, outro
  caminho até ele passaria por um vértice de `dist` maior ou igual
  (CORMEN et al., 2024, cap. 22).
- **Peso negativo**: o argumento cai e o Dijkstra erra sem avisar. Aí entra o
  Bellman-Ford (0154), que relaxa todas as arestas V - 1 vezes
  (CORMEN et al., 2024, cap. 22).
- **Custo**: com matriz, cada um dos V passos varre V vértices, O(V²). Com
  lista e **heap** (0102), O((V + E) log V) (CORMEN et al., 2024, cap. 22).

> [!WARNING]
> `INT_MAX + 3` **estoura**: comportamento indefinido em `int` com sinal, que
> na prática vira negativo e "ganha" no `<`. Por isso o código só escolhe `u`
> com `dist[u] != INFINITO`. Um INFINITO folgado (`1000000000`) também evita o
> estouro (CPPREFERENCE, s.d.).

{{exemplo}}

Rumo à praia, o Waze sabe que Casa até Padaria leva 4 minutos, mas Casa,
Escola, Padaria leva 3. A BFS acharia Casa, Padaria, Praia (14 minutos). Os
números das arestas são minutos, o de cada lugar é a `dist` final e as arestas
verdes formam a rota de 11 minutos:

{{ideia}}

O código usa matriz de pesos (0 é "sem rua direta") e reconstrói a rota pelo
`anterior[]`:

```c
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5
#define INFINITO INT_MAX // "ainda não sei chegar"

int main(void) {
    const char *nomes[V] = {"Casa", "Escola", "Padaria", "Mercado", "Praia"};
    int peso[V][V] = {0}; // minutos; 0 = sem rua direta
    int ruas[][3] = {{0, 2, 4}, {0, 1, 1}, {1, 2, 2}, {2, 3, 5}, {1, 3, 8}, {3, 4, 3}, {2, 4, 10}};
    for (int k = 0; k < 7; k++) {
        peso[ruas[k][0]][ruas[k][1]] = ruas[k][2];
        peso[ruas[k][1]][ruas[k][0]] = ruas[k][2]; // mão dupla
    }

    int dist[V], anterior[V];
    bool fixo[V]; // distância definitiva?
    for (int v = 0; v < V; v++) {
        dist[v] = INFINITO;
        anterior[v] = -1;
        fixo[v] = false;
    }
    dist[0] = 0; // saindo de Casa

    for (int passo = 0; passo < V; passo++) {
        // escolhe o vértice não fixo com a menor distância conhecida
        int u = -1;
        for (int v = 0; v < V; v++)
            if (!fixo[v] && dist[v] != INFINITO && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break; // o que sobrou é inalcançável
        fixo[u] = true;

        // relaxa: passar por u encurta o caminho até v?
        for (int v = 0; v < V; v++) {
            if (peso[u][v] && !fixo[v] && dist[u] + peso[u][v] < dist[v]) {
                dist[v] = dist[u] + peso[u][v];
                anterior[v] = u;
            }
        }
    }

    for (int v = 0; v < V; v++) printf("%s: %d min\n", nomes[v], dist[v]);

    int rota[V], n = 0;
    for (int v = 4; v != -1; v = anterior[v]) rota[n++] = v;
    printf("Rota até a Praia:");
    for (int i = n - 1; i >= 0; i--) printf(" %s%s", nomes[rota[i]], i > 0 ? " ->" : "");
    printf("\n");
    return 0;
}
// Saída:
// Casa: 0 min
// Escola: 1 min
// Padaria: 3 min
// Mercado: 8 min
// Praia: 11 min
// Rota até a Praia: Casa -> Escola -> Padaria -> Mercado -> Praia
```

É a estrutura da BFS, com a fila trocada por "menor `dist` não fixo". O laço
acaba com todos fixos ou quando o menor que sobrou é INFINITO:

{{fluxograma}}

### Passo a passo

Cada linha fixa um vértice e relaxa os vizinhos: a Padaria cai de 4 para 3 e o
Mercado de 9 para 8:

| Fixa | Casa | Escola | Padaria | Mercado | Praia |
| --- | --- | --- | --- | --- | --- |
| (início) | 0 | ∞ | ∞ | ∞ | ∞ |
| Casa (0) | **0** | 1 | 4 | ∞ | ∞ |
| Escola (1) | | **1** | 3 | 9 | ∞ |
| Padaria (3) | | | **3** | 8 | 13 |
| Mercado (8) | | | | **8** | 11 |
| Praia (11) | | | | | **11** |

O exemplo A223 para ao fixar o destino. O A224 usa grafo dirigido (ônibus, em
reais) e trata uma cidade que nenhuma linha alcança.
