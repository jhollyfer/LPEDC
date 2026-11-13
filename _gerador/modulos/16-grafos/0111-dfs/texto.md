## 0111 · DFS: busca em profundidade

- **Busca em profundidade** (DFS, *depth-first search*): vai o mais fundo
  possível e, sem nada novo, **volta** à última escolha pendente, o
  **backtracking** (CORMEN et al., 2024, cap. 20).
- **Pilha**: a DFS usa a pilha de chamadas (0031). A função marca o vértice e
  chama a si mesma para cada vizinho não visitado; ao voltar, o frame lembra
  onde o laço parou (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 8).
- **`visitado[]`**: obrigatório, como na BFS. Num ciclo, sem a marca, a
  recursão nunca acaba (ZIVIANI, 2010, cap. 7).
- **Árvore da DFS e arestas de retorno**: a DFS desce pelas arestas da
  árvore. Uma aresta que leva a um vértice ainda na pilha é **de retorno**; em
  grafo não dirigido, achar uma é achar um ciclo (CORMEN et al., 2024,
  cap. 20).
- **Relógio do Cormen**: cada vértice ganha tempo de **descoberta** `v.d` e de
  **término** `v.f`, com cores branco, cinza (na pilha) e preto. `DFS(G)`
  recomeça de todo vértice branco (CORMEN et al., 2024, cap. 20).
- **Grafo dirigido**: as outras arestas são de **retorno** (para ancestral
  cinza: há ciclo), de **avanço** (descendente preto) ou de **cruzamento**
  (outro preto). A ordem decrescente de `v.f` dá a **ordenação topológica**
  de um grafo acíclico (CORMEN et al., 2024, cap. 20).
- **Custo e caminho**: O(V + E) com lista. A DFS **não** dá o caminho mais
  curto; para isso há a BFS (FEOFILOFF, 2009, cap. 5).

> [!WARNING]
> Recursão funda estoura a pilha (8 MB é o comum no Linux): um labirinto de
> 1000 × 1000 casas pode empilhar um milhão de chamadas. Em grafos grandes,
> use pilha explícita com `malloc`, como no A222.

{{exemplo}}

Da Sede do parque saem trilhas para o Lago e a Ponte. A DFS desce Lago,
Gruta, Topo e Bica, volta e só no fim pega a Ponte. Os números são a ordem da
visita, as arestas verdes são a árvore e à direita fica a pilha na Bica:

{{ideia}}

O código imprime cada vértice com recuo proporcional à profundidade.
`visitado[]` e `adj[]` são globais, e todas as chamadas veem o mesmo vetor:

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
A BFS daria Sede, Lago, Ponte, Gruta, Topo, Bica. O A221 conta ciclos e o
A222 usa pilha explícita:

{{fluxograma}}
