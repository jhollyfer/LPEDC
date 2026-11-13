## 0113 · Juntando tudo: a central de entregas

Uma transportadora com um centro de distribuição e vários pontos de entrega
faz perguntas diferentes sobre o mesmo mapa. Dá para chegar em todos os
pontos? Qual rota tem menos trechos? Qual roda menos quilômetros? Como ligar
todos os pontos com o mínimo de estrada? Cada pergunta pede um algoritmo do
módulo, e a graça deste assunto é ver que eles são parentes.

Olhe para os três primeiros lado a lado. DFS, BFS e Dijkstra marcam quem já
foi visto, anotam em `pai[]` de onde cada vértice veio e repetem um laço que
tira um vértice e descobre os vizinhos dele. O que muda é a **ordem** em que os
vértices saem: na DFS, sai o mais recente, como numa pilha; na BFS, o mais
antigo, como numa fila; no Dijkstra, o de menor `dist` (CORMEN et al., 2024,
caps. 20 e 22). Trocar a estrutura que guarda os pendentes troca o algoritmo.

Antes de calcular rota, convém perguntar se o destino é alcançável. A DFS
responde isso: tudo o que ela visita a partir do centro de distribuição dá
para alcançar, e o que fica de fora, como uma ilha que só tem balsa, não tem
rota nenhuma a calcular (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 8).

Para a rota em si, a pergunta decisiva é "menor em quê?". Se todo trecho custa
o mesmo, o caminho mínimo é o de menos trechos, e a BFS resolve em O(V + E).
Se os trechos têm quilometragens diferentes, a BFS ainda devolve um caminho,
só que o errado, e não avisa (FEOFILOFF, 2009, cap. 5). Aí é Dijkstra.

A última pergunta é de outra natureza. A transportadora não quer ir de um
ponto a outro; quer escolher estradas que deixem **todos** os pontos ligados
gastando o mínimo. Esse conjunto de arestas se chama **árvore geradora
mínima**: geradora porque alcança todos os vértices, árvore porque não tem
ciclo (um ciclo teria uma estrada sobrando) e mínima porque a soma dos pesos é
a menor possível (CORMEN et al., 2024, cap. 21).

O algoritmo de **Prim** constrói essa árvore e é quase o Dijkstra. Ele também
fixa, a cada passo, o vértice não fixo de menor valor e atualiza os vizinhos.
A diferença está numa linha. O Dijkstra compara o custo do caminho inteiro,
`dist[u] + custo < dist[v]`. O Prim compara só o custo da aresta que liga `v`
à árvore, `custo < chave[v]`, porque o que importa é o preço de pendurar `v`
na árvore, não a distância até a origem (CORMEN et al., 2024, cap. 21). A
tabela resume quem responde o quê:

| Pergunta | Algoritmo | Estrutura auxiliar |
| --- | --- | --- |
| Quem dá para alcançar? Quantos grupos? Tem ciclo? | DFS | pilha (a recursão) |
| Menor caminho em número de arestas | BFS | fila |
| Menor caminho em soma de pesos (pesos >= 0) | Dijkstra | vetor `dist` (ou heap) |
| Ligar todos com o menor custo total | Prim | vetor `chave` |

No código, o mapa vira um tipo. A struct `Grafo` junta o número de vértices,
os nomes e a matriz de quilômetros, e cada algoritmo é uma função que recebe
`const Grafo *`. O ponteiro passa 8 bytes em vez de copiar os 328 da struct, e
o `const` promete que nenhuma função altera o mapa (KERNIGHAN; RITCHIE, 1989).
Com 1000 vértices a matriz teria 4 MB, e a struct teria de ir para o heap com
`malloc`.

Para preencher a struct, o exemplo usa um **inicializador designado**, recurso
do C99: `{.n = 7, .nomes = {...}}` cita pelo nome só os campos que interessam,
e todo campo não citado, como `km`, começa zerado (ISO/IEC, 2018).

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
