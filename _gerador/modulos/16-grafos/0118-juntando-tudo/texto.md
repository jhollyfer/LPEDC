## 0118 · Juntando tudo: a central de entregas

Você está escrevendo o backend de uma transportadora pequena. O centro de
distribuição (CD) atende seis lugares, e o gerente faz três perguntas: dá para
chegar em todos de caminhão? Qual rota passa por menos trechos (menos
paradas, menos chance de atraso)? E qual rota roda menos quilômetros (menos
diesel)?

Cada pergunta tem o seu algoritmo, e o módulo inteiro serve para você
escolher sem pensar duas vezes:

| Pergunta | Algoritmo | Estrutura auxiliar |
| --- | --- | --- |
| Quem dá para alcançar? Quantos grupos? Tem ciclo? | DFS | pilha (a recursão) |
| Menor caminho em número de arestas | BFS | fila |
| Menor caminho em soma de pesos (pesos >= 0) | Dijkstra | vetor `dist` (ou heap) |
| Ligar todos com o menor custo total | Prim | vetor `chave` |

As três primeiras usam o mesmo esqueleto: um vetor de marcas, um vetor
`pai[]` para reconstruir o caminho e um laço que "descobre" vizinhos. O que
muda é a **ordem** em que os vértices saem: pilha, fila ou "menor `dist`".

O programa do módulo junta tudo num tipo `Grafo` (uma `struct` com o número
de vértices, os nomes e a matriz de km) e numa função para cada algoritmo.
As funções recebem `const Grafo *`: a struct passa de 300 bytes, e copiá-la
inteira a cada chamada seria desperdício. O `const` promete
que ninguém mexe no mapa.

Vamos ver na prática. A Ilha só tem balsa, então a DFS a deixa de fora. A BFS
acha a rota de 2 trechos pelo Centro, com a estrada longa de 12 km. Dijkstra
acha a de 4 trechos, em verde, com 10 km:

{{ideia}}

O código completo. Repare como `bfs` e `dijkstra` preenchem o mesmo tipo de
vetor `pai[]`, e por isso uma única `mostrar_rota` serve para os dois:

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

Repara no fluxograma: a DFS vem primeiro, como um porteiro. Se a Vila
estivesse fora da rede, não faria sentido procurar rota nenhuma:

{{fluxograma}}

A diferença entre as duas rotas é a lição do módulo. "Menor caminho" não
existe sozinho: menor em quê? Se toda aresta custa o mesmo, a BFS resolve em
O(V + E) e é mais simples. Se os pesos variam, a BFS dá uma resposta errada
com toda a confiança, como os 16 km acima.

O exemplo A236 traz um quarto problema: ligar cinco cidades com fibra óptica
gastando o mínimo. Não é caminho de A até B, é uma **árvore geradora
mínima**: um conjunto de cabos que conecta todo mundo com a menor soma. O
algoritmo de **Prim** faz isso com o código do Dijkstra trocando uma linha: em
vez de `dist[u] + custo < dist[v]`, compara só `custo < chave[v]`.

> [!WARNING]
> Na matriz de pesos, `0` quer dizer "sem aresta". Isso só funciona se nenhum
> peso real puder ser zero. Se um trecho pode custar R$ 0 (um pedágio isento,
> uma conexão gratuita), use outra marca, como `-1`, ou uma matriz `bool`
> separada para dizer se a aresta existe. Senão o algoritmo some com a
> estrada sem avisar.

> [!TIP]
> **Por dentro do C:** `Grafo g` mora inteiro na pilha de `main`: 4 bytes do
> `n`, 8 ponteiros de 8 bytes para os nomes (as strings em si ficam na área
> de literais, só de leitura) e 64 `int` da matriz: 328 bytes, contando 4 de
> alinhamento depois do `n`. Passar `&g` copia só 8 bytes. A inicialização
> `{.n = 7, .nomes = {...}}` usa **inicializadores designados** do C99: o que
> não foi citado, como a matriz `km`, começa zerado. Com `MAX` 1000 a matriz
> teria 4 MB, metade da pilha inteira: aí a struct vai para o heap, com
> `malloc`.

> [!NOTE]
> **Pergunta para você:** se a estrada Centro–Vila cair de 12 para 5 km, as
> duas rotas viram a mesma? Quantos km e quantos trechos? Preveja antes de
> mudar o A235.

{{pratique}}
