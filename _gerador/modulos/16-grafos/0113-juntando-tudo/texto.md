## 0113 · Juntando tudo: a central de entregas

- **Um esqueleto, três buscas**: DFS, BFS e Dijkstra usam marcas, `pai[]` e um
  laço que descobre vizinhos. Muda a **ordem** de saída: pilha, fila ou "menor
  `dist`" (CORMEN et al., 2024, caps. 20 e 22).
- **"Menor em quê?"**: com arestas de mesmo custo, a BFS basta, em O(V + E).
  Com pesos variados, ela erra sem aviso (FEOFILOFF, 2009, cap. 5).
- **Alcance primeiro**: a DFS diz quem dá para alcançar. Se o destino está
  fora, não há rota a calcular (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 8).
- **Árvore geradora mínima**: o conjunto de arestas que liga todos os
  vértices com a menor soma de pesos (CORMEN et al., 2024, cap. 21).
- **Prim**: é o Dijkstra com uma linha trocada. Em vez de
  `dist[u] + custo < dist[v]`, compara só `custo < chave[v]`
  (CORMEN et al., 2024, cap. 21).
- **Grafo como struct**: `Grafo` junta vértices, nomes e matriz de km. As
  funções recebem `const Grafo *`: passa 8 bytes em vez de 328 e promete não
  mexer no mapa (KERNIGHAN; RITCHIE, 1989).
- **Inicializador designado** (C99): `{.n = 7, .nomes = {...}}` cita só os
  campos que quer; o resto, como `km`, começa zerado (ISO/IEC, 2018).

| Pergunta | Algoritmo | Estrutura auxiliar |
| --- | --- | --- |
| Quem dá para alcançar? Quantos grupos? Tem ciclo? | DFS | pilha (a recursão) |
| Menor caminho em número de arestas | BFS | fila |
| Menor caminho em soma de pesos (pesos >= 0) | Dijkstra | vetor `dist` (ou heap) |
| Ligar todos com o menor custo total | Prim | vetor `chave` |

> [!WARNING]
> Na matriz de pesos, `0` quer dizer "sem aresta", o que só funciona se nenhum
> peso real for zero. Se um trecho pode custar R$ 0, use outra marca,
> como `-1`.

{{exemplo}}

Uma transportadora tem um centro de distribuição (CD) e seis lugares a
atender. A Ilha só tem balsa, e a DFS a deixa de fora. A BFS acha a rota de 2
trechos pelo Centro (16 km); o Dijkstra, a de 4 trechos, em verde (10 km):

{{ideia}}

`bfs` e `dijkstra` preenchem o mesmo `pai[]`, e uma só `mostrar_rota` serve aos
dois:

```c
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 8
#define INFINITO INT_MAX

typedef struct {
    int n;
    const char *nomes[MAX];
    int km[MAX][MAX]; // 0 = sem estrada
} Grafo;

void ligar(Grafo *g, int a, int b, int km) {
    g->km[a][b] = km;
    g->km[b][a] = km;
}

// DFS: marca tudo que dá para alcançar a partir de u
void dfs(const Grafo *g, int u, bool visitado[]) {
    visitado[u] = true;
    for (int v = 0; v < g->n; v++)
        if (g->km[u][v] && !visitado[v]) dfs(g, v, visitado);
}

// BFS: menor número de trechos
void bfs(const Grafo *g, int origem, int pai[]) {
    int fila[MAX], inicio = 0, fim = 0;
    bool visto[MAX] = {false};
    for (int v = 0; v < g->n; v++) pai[v] = -1;
    visto[origem] = true;
    fila[fim++] = origem;
    while (inicio < fim) {
        int u = fila[inicio++];
        for (int v = 0; v < g->n; v++)
            if (g->km[u][v] && !visto[v]) {
                visto[v] = true;
                pai[v] = u;
                fila[fim++] = v;
            }
    }
}

// Dijkstra: menor soma de km
void dijkstra(const Grafo *g, int origem, int pai[]) {
    int dist[MAX];
    bool fixo[MAX] = {false};
    for (int v = 0; v < g->n; v++) {
        dist[v] = INFINITO;
        pai[v] = -1;
    }
    dist[origem] = 0;
    for (int passo = 0; passo < g->n; passo++) {
        int u = -1;
        for (int v = 0; v < g->n; v++)
            if (!fixo[v] && dist[v] != INFINITO && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1) break;
        fixo[u] = true;
        for (int v = 0; v < g->n; v++)
            if (g->km[u][v] && !fixo[v] && dist[u] + g->km[u][v] < dist[v]) {
                dist[v] = dist[u] + g->km[u][v];
                pai[v] = u;
            }
    }
}

// mostra o caminho guardado em pai[] e soma trechos e km
void mostrar_rota(const Grafo *g, const int pai[], int destino) {
    int rota[MAX], n = 0, total = 0;
    for (int v = destino; v != -1; v = pai[v]) rota[n++] = v;
    for (int i = n - 1; i >= 0; i--) {
        printf("%s%s", g->nomes[rota[i]], i > 0 ? " -> " : "");
        if (i > 0) total += g->km[rota[i]][rota[i - 1]];
    }
    printf(" (%d trechos, %d km)\n", n - 1, total);
}

int main(void) {
    Grafo g = {.n = 7, .nomes = {"CD", "Centro", "Feira", "Porto", "Morro", "Vila", "Ilha"}};
    ligar(&g, 0, 1, 4);
    ligar(&g, 0, 2, 2);
    ligar(&g, 2, 1, 1);
    ligar(&g, 1, 3, 7);
    ligar(&g, 2, 4, 3);
    ligar(&g, 4, 3, 2);
    ligar(&g, 3, 5, 3);
    ligar(&g, 1, 5, 12);
    // a Ilha (6) só tem balsa: nenhuma estrada

    int cd = 0, vila = 5;
    bool visitado[MAX] = {false};
    dfs(&g, cd, visitado);
    int alcancaveis = 0;
    for (int v = 0; v < g.n; v++) alcancaveis += visitado[v];
    printf("Alcançáveis a partir do CD: %d de %d (fora:", alcancaveis, g.n);
    for (int v = 0; v < g.n; v++)
        if (!visitado[v]) printf(" %s", g.nomes[v]);
    printf(")\n");

    if (!visitado[vila]) {
        printf("Sem rota até %s\n", g.nomes[vila]);
        return 0;
    }
    int pai[MAX];
    bfs(&g, cd, pai);
    printf("Menos trechos: ");
    mostrar_rota(&g, pai, vila);
    dijkstra(&g, cd, pai);
    printf("Menos km:      ");
    mostrar_rota(&g, pai, vila);
    return 0;
}
// Saída:
// Alcançáveis a partir do CD: 6 de 7 (fora: Ilha)
// Menos trechos: CD -> Centro -> Vila (2 trechos, 16 km)
// Menos km:      CD -> Feira -> Morro -> Porto -> Vila (4 trechos, 10 km)
```

A DFS vem primeiro, como porteiro: com a Vila fora da rede, não há rota. O
A225 conta as partes soltas de um mapa e o A226 liga cinco cidades com fibra
óptica pelo Prim:

{{fluxograma}}
