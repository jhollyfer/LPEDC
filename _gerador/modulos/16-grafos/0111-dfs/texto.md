## 0111 · DFS: busca em profundidade

A BFS do assunto 0110 explora o grafo em ondas, camada por camada. Há outro
jeito de visitar todos os vértices alcançáveis, e ele é o jeito de quem
explora uma trilha a pé: escolher um caminho e seguir por ele até não dar mais.

Imagine um parque com várias trilhas saindo da Sede. Você pega a do Lago,
segue para a Gruta, sobe ao Topo e desce à Bica. Na Bica a trilha acaba. Você
volta até a última bifurcação que ainda tem trilha nova e segue por ela. Só
quando tudo daquele lado está visto você volta à Sede e pega a trilha da
Ponte. Essa é a **busca em profundidade**, ou DFS (do inglês *depth-first
search*): ir o mais fundo possível e, quando não há nada novo à frente,
**voltar** à última escolha pendente. Esse movimento de voltar se chama
**backtracking**, retrocesso (CORMEN et al., 2024, cap. 20).

A BFS precisava de uma fila para lembrar a ordem das ondas. A DFS precisa de
uma **pilha**, porque quem foi visitado por último é o primeiro a ser retomado.
O C já tem uma pronta: a pilha de chamadas do assunto 0031. A função recursiva
marca o vértice como visitado e chama a si mesma para cada vizinho ainda não
visitado. Quando `dfs(Bica)` termina, a execução volta para `dfs(Topo)`, que
continua o laço exatamente de onde parou, porque o frame dela guardou o
vizinho da vez (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 8). Cada frame
guarda o endereço de retorno, o vértice `u` e a variável do laço. O vetor
`visitado[]` fica fora das chamadas, global ou passado por ponteiro, para que
todas enxerguem o mesmo vetor; uma cópia local em cada chamada não marcaria
nada para as outras.

Esse vetor é obrigatório, como era o `dist[]` com `-1` na BFS. Se Lago, Gruta e
Topo formam um **ciclo**, sem a marca `dfs(Topo)` chamaria `dfs(Lago)`, que
chamaria `dfs(Gruta)`, que chamaria `dfs(Topo)` de novo, e a recursão nunca
acabaria (ZIVIANI, 2010, cap. 7).

As arestas por onde a DFS desce formam a **árvore da DFS**. As outras arestas
também contam uma história. Uma aresta que leva a um vértice que ainda está
na pilha de chamadas, como Topo–Lago, é uma **aresta de retorno**: ela aponta
para um ancestral na árvore. Num grafo não dirigido, achar uma aresta de
retorno é achar um ciclo (CORMEN et al., 2024, cap. 20).

O Cormen acrescenta um **relógio** à busca. Um contador global sobe a cada
evento, e cada vértice ganha dois carimbos: o tempo de **descoberta** `v.d`,
quando a busca chega nele, e o tempo de **término** `v.f`, quando todos os
vizinhos dele foram resolvidos. As cores acompanham: **branco** é o não
descoberto, **cinza** o que está na pilha e **preto** o terminado. Contando de
1 a partir da Sede, a Sede fica com 1/12 e a Bica com 5/6. O procedimento
`DFS(G)` do livro não para numa origem só: ele recomeça de **todo** vértice
ainda branco, e o resultado é uma floresta, várias árvores (CORMEN et al.,
2024, cap. 20).

Num grafo **dirigido**, as arestas fora da árvore se dividem em três tipos. A
de **retorno** aponta para um ancestral cinza, e a existência dela prova que há
ciclo. A de **avanço** aponta para um descendente que já ficou preto. A de
**cruzamento** aponta para um vértice preto de outro ramo. Os tempos de
término têm um uso famoso: num grafo dirigido sem ciclos, listar os vértices
em ordem decrescente de `v.f` dá a **ordenação topológica**, uma ordem em que
toda seta vai da esquerda para a direita, como as tarefas de uma obra em que
cada uma só começa depois das que ela depende (CORMEN et al., 2024, cap. 20).

Com lista de adjacência, a DFS custa O(V + E), como a BFS. Ela diz quem é
alcançável e encontra ciclos, mas **não** dá o caminho mais curto: a trilha
que ela segue até um vértice pode ser longa só porque foi a primeira tentada.
Para distância, use a BFS (FEOFILOFF, 2009, cap. 5).

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
