## 0111 · DFS: busca em profundidade

Sábado no parque estadual. Da Sede saem duas trilhas, uma para o Lago e outra
para a Ponte. Você escolhe o Lago e vai em frente: Gruta, Topo, Bica. Na Bica
a trilha acaba. Você volta pelo mesmo caminho até achar uma bifurcação com
trilha nova. Só no fim, já de volta à Sede, você pega a trilha da Ponte.

Esse jeito de explorar é a **busca em profundidade** (DFS, de *depth-first
search*): seguir um caminho o mais fundo possível e, quando não há mais nada
novo, **voltar** até a última escolha que ficou pendente. A volta tem nome,
**backtracking**, e é o fio de Ariadne no labirinto do Minotauro.

A BFS explora em ondas, com uma fila. A DFS explora em mergulhos, com uma
**pilha**, e a pilha de chamadas (assunto 0031) já vem de graça. Por isso a
DFS cabe numa função recursiva de quatro linhas: marca o vértice e, para cada
vizinho não visitado, chama a si mesma.

Quando a chamada de `dfs(Bica)` termina, o C volta sozinho para `dfs(Topo)`,
que continua o laço de onde parou. Esse "continua de onde parou" é o
backtracking, e quem guarda o ponto de parada é o frame de cada chamada.

Como na BFS, o vetor `visitado[]` é obrigatório. Lago, Gruta e Topo formam um
**ciclo**; sem a marca, `dfs(Topo)` chamaria `dfs(Lago)` de novo, que chamaria
`dfs(Gruta)`, e a recursão nunca acabaria.

As arestas por onde a DFS desce formam a **árvore da DFS**. As outras, que
levam a um vértice que já está na pilha (como Topo–Lago), são **arestas de
retorno**. Num grafo não dirigido, achar uma aresta de retorno é achar um
ciclo. A DFS também conta componentes, resolve labirintos e ordena tarefas
com pré-requisitos.

O Cormen põe um **relógio** na DFS: cada vértice ganha um tempo de
**descoberta** `v.d` (a chamada começa) e um de **término** `v.f` (ela acaba),
e as cores branco, cinza (na pilha) e preto (terminado). Contando de 1, a Sede
fica com 1/12 e a Bica com 5/6. O `DFS(G)` dele ainda recomeça de **todo**
vértice branco, formando uma floresta que cobre as partes soltas. Num grafo
**dirigido**, as arestas fora da árvore são de **retorno** (para um ancestral
cinza: há ciclo), de **avanço** (para um descendente preto) ou de
**cruzamento** (para outro preto). Os vértices em ordem decrescente de `v.f`
dão a **ordenação topológica** de um grafo dirigido acíclico. Com lista de
adjacências, tudo custa O(V + E).

No desenho, os números mostram a ordem da visita e as arestas verdes são as
da árvore. À direita está a pilha de chamadas no momento mais fundo, quando a
Bica é visitada:

{{ideia}}

O código imprime cada vértice com um recuo proporcional à profundidade da
chamada. Dá para ver a árvore na saída:

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

Aqui não existe a pergunta "acabou?" da fila da BFS. Cada chamada pergunta
apenas "tenho vizinho novo?": se tem, desce; se não tem, volta para quem
chamou. O programa termina quando a primeira chamada, a da Sede, não tem mais
para onde descer:

{{fluxograma}}

Compare as ordens a partir da Sede. A DFS visita Sede, Lago, Gruta, Topo,
Bica, Ponte: a Ponte, vizinha direta da Sede, fica para o fim. A BFS visitaria
Sede, Lago, Ponte, Gruta, Topo, Bica. Nenhuma está errada; servem a perguntas
diferentes. A DFS **não** dá o caminho mais curto: ela chegou ao Topo pela
Gruta (três trilhas), mas o Lago liga direto no Topo (duas).

O exemplo A221 usa a DFS para separar as arestas de árvore das de retorno e
contar os ciclos de uma rede de cabos. O A222 faz a mesma DFS sem recursão,
com uma pilha explícita, e mostra a pilha a cada passo.

> [!WARNING]
> Recursão funda estoura a pilha. Cada chamada ocupa um frame, e a pilha do
> programa tem poucos megabytes (8 MB é o comum no Linux). Uma DFS recursiva
> num labirinto de 1000 × 1000 casas pode empilhar um milhão de chamadas e
> morrer com *stack overflow*. Para grafos grandes, use a versão com pilha
> explícita alocada com `malloc`, como no A222.

> [!TIP]
> **Por dentro do C:** cada `dfs(u, nivel)` empilha um frame com o endereço
> de retorno, os parâmetros `u` e `nivel` e o `v` do laço: algumas dezenas de
> bytes. No ponto mais fundo deste exemplo há cinco frames de `dfs` sobre o de
> `main`. O `v` de cada frame é o "qual trilha eu já testei nesta
> bifurcação". Já `visitado[]` e `adj[]` são globais: ficam na área de dados,
> fora da pilha, e todas as chamadas enxergam o mesmo vetor. Se `visitado`
> fosse local dentro de `dfs`, cada chamada teria a sua cópia, zerada, e a
> marca não serviria para nada.

> [!NOTE]
> **Pergunta para você:** se a trilha Lago–Gruta for interditada, qual passa a
> ser a ordem da DFS a partir da Sede, e qual o recuo de cada linha? Preveja
> antes de apagar o par `{1, 2}` no programa acima.

{{pratique}}
