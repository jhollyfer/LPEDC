## 0112 · Dijkstra: caminho mínimo

A BFS acha o caminho com menos arestas. No trânsito, isso não basta. Um
aplicativo de rotas sabe que ir de Casa até a Padaria pela rua direta leva 4
minutos, mas que ir de Casa até a Escola leva 1 e da Escola até a Padaria leva
2. A rua direta parece óbvia, e passar pela Escola dá 3 minutos.

O grafo agora é **ponderado**: cada aresta carrega um **peso**, que pode ser
minutos, quilômetros ou reais. O custo de um caminho é a soma dos pesos das
arestas dele, e o caminho mínimo é o de **menor soma**, não o de menos arestas
(CORMEN et al., 2024, cap. 22). A BFS erra aqui sem avisar, porque ela para no
primeiro caminho que chega, e o primeiro a chegar é o de menos ruas.

O algoritmo de **Dijkstra** resolve esse problema. A partir de uma origem, ele
acha o caminho mínimo até todos os outros vértices, desde que **nenhum peso
seja negativo** (DIJKSTRA, 1959). Ele trabalha com três vetores. `dist[v]`
guarda o melhor custo **conhecido até agora** da origem até `v`: começa em 0 na
origem e em INFINITO no resto, que quer dizer "ainda não sei chegar".
`fixo[v]` diz se esse custo já é definitivo. `anterior[v]` guarda de onde se
chega em `v` no melhor caminho, com o mesmo papel do `pai[]` da BFS (ZIVIANI,
2010, cap. 7).

A operação central se chama **relaxar** uma aresta. Você tem `dist[u]` e uma
aresta de `u` para `v`. Se `dist[u] + peso[u][v] < dist[v]`, passar por `u`
melhora o caminho até `v`, e você atualiza `dist[v]` com a soma e anota
`anterior[v] = u`. Se não melhora, nada muda. No Cormen, esse teste é o
procedimento `RELAX(u, v, w)`, os vetores são os campos `v.d` e `v.π` e os
vértices fixos formam o conjunto S (CORMEN et al., 2024, cap. 22). No exemplo
da padaria, `dist[Padaria]` começa em 4 pela rua direta; quando a Escola é
fixada com 1, relaxar a aresta Escola–Padaria dá 1 + 2 = 3, que é menor, e o
4 vira 3.

O algoritmo repete um passo só. Entre os vértices não fixos, pega o de menor
`dist`, marca como fixo e relaxa todas as arestas que saem dele. Ele é
**guloso**: em cada passo, faz a escolha que parece melhor naquele momento e
nunca a desfaz. Fixar o menor é seguro por um motivo simples. Qualquer outro
caminho até esse vértice teria de sair dos fixos por algum vértice não fixo,
que já tem `dist` maior ou igual. Sem pesos negativos, andar mais só soma, e o
outro caminho não fica mais barato (CORMEN et al., 2024, cap. 22).

O argumento depende de "andar mais só soma". Com uma aresta de peso negativo,
um caminho mais longo pode ficar mais barato depois de um vértice já fixado, e
o Dijkstra devolve uma resposta errada sem dar nenhum sinal. Para esse caso
existe o algoritmo de Bellman-Ford, no assunto 0154, que relaxa todas as
arestas V - 1 vezes (CORMEN et al., 2024, cap. 22).

O custo depende de como você acha o menor `dist`. Com matriz de adjacência,
cada um dos V passos varre os V vértices para achar o menor não fixo e mais V
para relaxar a linha: O(V²). Com lista de adjacência e um **heap** de mínimo
(assunto 0102), que entrega o menor em O(log V), o total cai para
O((V + E) log V) (CORMEN et al., 2024, cap. 22).

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
