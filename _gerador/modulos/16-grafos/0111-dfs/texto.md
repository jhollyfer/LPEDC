## 0111 · DFS: busca em profundidade

No parque estadual, da Sede saem duas trilhas, para o Lago e para a Ponte. Você
vai pelo Lago: Gruta, Topo, Bica. Na Bica a trilha acaba, e você volta à última
bifurcação com trilha nova. Só no fim pega a da Ponte.

É a **busca em profundidade** (DFS, *depth-first search*): ir o mais fundo
possível e, sem nada novo, **voltar** à última escolha pendente (o
**backtracking**).

A BFS explora em ondas, com fila; a DFS, em mergulhos, com a **pilha** de
chamadas (assunto 0031). A função recursiva marca o vértice e chama a si mesma
para cada vizinho não visitado. Quando `dfs(Bica)` termina, o C volta para
`dfs(Topo)`, que continua o laço de onde parou: o frame guarda o ponto de
parada.

Como na BFS, `visitado[]` é obrigatório. Lago, Gruta e Topo formam um
**ciclo**; sem a marca, `dfs(Topo)` chamaria `dfs(Lago)` e a recursão nunca
acabaria.

As arestas por onde a DFS desce formam a **árvore da DFS**. As que levam a um
vértice já na pilha (Topo–Lago) são **arestas de retorno**: num grafo não
dirigido, achar uma é achar um ciclo.

O Cormen põe um **relógio**: cada vértice ganha o tempo de **descoberta** `v.d`
e o de **término** `v.f`, com as cores branco, cinza (na pilha) e preto
(terminado). Contando de 1, a Sede fica com 1/12 e a Bica com 5/6. O `DFS(G)`
dele recomeça de **todo** vértice branco (uma floresta). Num grafo **dirigido**,
as arestas fora da árvore são de **retorno** (para ancestral cinza: há ciclo),
de **avanço** (para descendente preto) ou de **cruzamento** (para outro preto).
Os vértices em ordem decrescente de `v.f` dão a **ordenação topológica** de um
grafo dirigido acíclico. Com lista de adjacência, tudo custa O(V + E).

No desenho, os números são a ordem da visita, as arestas verdes são a árvore e
à direita fica a pilha de chamadas na Bica:

{{ideia}}

O código imprime cada vértice com recuo proporcional à profundidade:

```c
#include <stdbool.h>
#include <stdio.h>

#define V 6

const char *nomes[V] = {"Sede", "Lago", "Gruta", "Ponte", "Topo", "Bica"};
int adj[V][V];
bool visitado[V];

void dfs(int u, int nivel) {
    visitado[u] = true;
    printf("%*s%s\n", 2 * nivel, "", nomes[u]); // recuo = profundidade
    for (int v = 0; v < V; v++)
        if (adj[u][v] && !visitado[v]) dfs(v, nivel + 1); // desce antes de olhar o próximo
}

int main(void) {
    int trilhas[][2] = {{0, 1}, {0, 3}, {1, 2}, {1, 4}, {2, 4}, {4, 5}};
    for (int k = 0; k < 6; k++) {
        adj[trilhas[k][0]][trilhas[k][1]] = 1;
        adj[trilhas[k][1]][trilhas[k][0]] = 1;
    }

    dfs(0, 0); // começa na Sede
    return 0;
}
// Saída:
// Sede
//   Lago
//     Gruta
//       Topo
//         Bica
//   Ponte
```

Cada chamada só pergunta "tenho vizinho novo?": se tem, desce; se não, volta.
O programa acaba quando a chamada da Sede não tem mais para onde descer:

{{fluxograma}}

A DFS visita Sede, Lago, Gruta, Topo, Bica, Ponte; a BFS, Sede, Lago, Ponte,
Gruta, Topo, Bica. Ambas estão certas e servem a perguntas diferentes. A DFS
**não** dá o caminho mais curto: chegou ao Topo pela Gruta (três trilhas), mas
o Lago liga direto (duas).

O exemplo A221 separa as arestas de árvore das de retorno e conta os ciclos de
uma rede de cabos. O A222 faz a mesma DFS com pilha explícita.

> [!WARNING]
> Recursão funda estoura a pilha (8 MB é o comum no Linux): um labirinto de
> 1000 × 1000 casas pode empilhar um milhão de chamadas e causar *stack
> overflow*. Em grafos grandes, use pilha explícita com `malloc`, como no A222.

> [!TIP]
> **Por dentro do C:** cada `dfs(u, nivel)` empilha um frame com endereço de
> retorno, `u`, `nivel` e o `v` do laço. `visitado[]` e `adj[]` são globais, e
> todas as chamadas enxergam o mesmo vetor; local, a marca não serviria.

> [!NOTE]
> **Pergunta para você:** sem a trilha Lago–Gruta, qual passa a ser a ordem da
> DFS a partir da Sede, e qual o recuo de cada linha?

{{pratique}}
