## 0112 · Dijkstra: caminho mínimo

Rumo à praia, o Waze conhece o tempo de cada rua: Casa até a Padaria, 4
minutos; Casa até a Escola, 1; Escola até a Padaria, 2. A rua direta parece
óbvia, mas passar pela Escola dá 3.

O grafo agora é **ponderado**: cada aresta tem um **peso** (minutos, km, reais)
e o menor caminho é o de **menor soma de pesos**, não o de menos arestas. A BFS
erra: acharia Casa, Padaria, Praia (duas ruas, 14 minutos) e perderia o caminho
de 11 minutos com quatro ruas.

O **Dijkstra** resolve isso quando nenhum peso é negativo. Ele guarda:

- `dist[v]`: o melhor tempo **conhecido** de Casa até `v` (0 em Casa, INFINITO
  no resto);
- `fixo[v]`: se `dist[v]` já é definitivo;
- `anterior[v]`: de onde se chega em `v` no melhor caminho (o `pai[]` da BFS).

A cada passo, pega o vértice **não fixo de menor `dist`**, fixa essa distância
e **relaxa** as arestas que saem dele: se `dist[u] + peso[u][v] < dist[v]`,
atualiza `dist[v]` e `anterior[v]`. No Cormen, o teste é `RELAX(u, v, w)`, os vetores são `v.d` e `v.π` e os
fixos formam o conjunto S.

Fixar o menor é seguro: sem pesos negativos, qualquer outro caminho até ele
passa por um vértice de `dist` maior ou igual. O algoritmo é **guloso**: a
escolha nunca se desfaz. Com aresta **negativa** o
argumento cai; aí entra o Bellman-Ford (assunto 0154), que relaxa todas as
arestas V - 1 vezes.

No mapa, os números das arestas são minutos, o de cada lugar é a `dist` final e
as arestas verdes formam a rota até a Praia:

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

> [!WARNING]
> `INT_MAX + 3` **estoura**: comportamento indefinido em `int` com sinal, que na
> prática vira negativo e "ganha" no `<`. Por isso o código só escolhe `u` com
> `dist[u] != INFINITO` e para quando não sobra ninguém. Um INFINITO folgado
> (`1000000000`) também evita o estouro.

> [!TIP]
> **Por dentro do C:** com matriz, cada um dos V passos varre V vértices para
> achar o menor e V para relaxar: O(V²). Com lista de adjacência e **heap**
> (assunto 0102), cai para O((V + E) log V).

> [!NOTE]
> **Pergunta para você:** com a rua Padaria–Praia em 7 minutos em vez de 10,
> qual é a nova rota e o novo tempo até a Praia?

{{pratique}}
