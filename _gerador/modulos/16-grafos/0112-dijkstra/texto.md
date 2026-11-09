## 0112 · Dijkstra: caminho mínimo

Domingo de sol, e você quer sair de casa e chegar à praia o mais rápido
possível. O Waze conhece o tempo de cada rua: Casa até a Padaria são 4 minutos,
Casa até a Escola, 1; da Escola até a Padaria, mais 2. Ir direto para a Padaria
parece óbvio, mas passar pela Escola dá 3 minutos e ganha da rua direta.

Agora o grafo é **ponderado**: cada aresta tem um **peso** (minutos, km,
reais). O menor caminho deixa de ser o de menos arestas e passa a ser o de
**menor soma de pesos**. A BFS não serve mais: ela acharia Casa, Padaria,
Praia (duas ruas, 14 minutos) e perderia o caminho de 11 minutos com quatro
ruas.

O algoritmo de **Dijkstra** resolve isso quando nenhum peso é negativo. Ele
guarda três vetores:

- `dist[v]`: o melhor tempo **conhecido até agora** de Casa até `v`
  (começa com 0 em Casa e INFINITO no resto);
- `fixo[v]`: se `dist[v]` já é definitivo;
- `anterior[v]`: de onde se chega em `v` no melhor caminho (o `pai[]` da BFS).

A cada passo, Dijkstra pega o vértice **não fixo de menor `dist`**, declara
essa distância definitiva e **relaxa** as arestas que saem dele. Relaxar é
perguntar: "passar por `u` encurta o caminho até `v`?" Em código,
`dist[u] + peso[u][v] < dist[v]`. Se sim, atualiza `dist[v]` e `anterior[v]`.
No Cormen, o começo se chama `INITIALIZE-SINGLE-SOURCE`, o teste é o
`RELAX(u, v, w)`, os vetores são `v.d` e `v.π`, e os fixos formam o conjunto S.

Dá para fixar o menor porque, com pesos não negativos, qualquer outro caminho
até ele passaria por um vértice que já tem `dist` maior ou igual, e somar
pesos só aumenta. É um algoritmo **guloso**: a melhor escolha
de agora nunca precisa ser desfeita. Com uma aresta **negativa**, esse
argumento cai e o Dijkstra pode fixar uma distância errada; aí entra o
Bellman-Ford (assunto 0154), que relaxa todas as arestas V - 1 vezes.

No mapa, os números nas arestas são minutos e o número em cima de cada lugar
é a `dist` final. As arestas verdes formam a rota até a Praia; embaixo está o
vetor `dist` no fim:

{{ideia}}

O código usa matriz de pesos (0 quer dizer "sem rua direta") e reconstrói a
rota pelo `anterior[]`, igual à BFS:

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

A estrutura é a da BFS, com a fila trocada por "escolher o menor `dist` não
fixo". O laço termina quando todos estão fixos ou quando o menor que sobrou é
INFINITO:

{{fluxograma}}

### Passo a passo

Cada linha fixa um vértice e relaxa os vizinhos dele. A Padaria começa com 4
(rua direta) e cai para 3; o Mercado cai de 9 para 8:

| Fixa | Casa | Escola | Padaria | Mercado | Praia |
| --- | --- | --- | --- | --- | --- |
| (início) | 0 | ∞ | ∞ | ∞ | ∞ |
| Casa (0) | **0** | 1 | 4 | ∞ | ∞ |
| Escola (1) | | **1** | 3 | 9 | ∞ |
| Padaria (3) | | | **3** | 8 | 13 |
| Mercado (8) | | | | **8** | 11 |
| Praia (11) | | | | | **11** |

O exemplo A223 para o Dijkstra assim que o destino é fixado, sem calcular o
mapa inteiro. O A224 usa Dijkstra num grafo dirigido (passagens de ônibus em
reais), dentro de uma função, e trata uma cidade que nenhuma linha alcança.

> [!WARNING]
> `INT_MAX` como INFINITO é prático, mas `INT_MAX + 3` **estoura**: é
> comportamento indefinido em `int` com sinal, e na prática vira um número
> negativo que "ganha" de todo mundo no `<`. Acontece quando o algoritmo
> escolhe um vértice inalcançável e soma o peso das arestas dele. Por isso o
> código só escolhe `u` com `dist[u] != INFINITO` e para quando não sobra
> ninguém. Outra saída é usar um INFINITO folgado, como `1000000000`, que ainda
> cabe somado a um peso.

> [!TIP]
> **Por dentro do C:** com matriz, cada um dos V passos varre V vértices para
> achar o menor e mais V para relaxar: O(V²). Para um mapa de 5 lugares, nada.
> Para as 100 mil esquinas de uma cidade, 10¹⁰ operações. O Waze de verdade usa
> lista de adjacência e um **heap** (a fila de prioridade do assunto 0102) para
> achar o menor em O(log V): O((V + E) log V). Os três vetores ocupam
> 4 + 4 + 1 bytes por vértice (`int`, `int`, `bool`); a matriz, 4 × V² bytes,
> e é ela que limita o tamanho do grafo.

> [!NOTE]
> **Pergunta para você:** se a rua Padaria–Praia passar a levar 7 minutos em
> vez de 10, qual é a nova rota e o novo tempo até a Praia? Refaça a tabela
> antes de trocar o `10` no programa acima.

{{pratique}}
