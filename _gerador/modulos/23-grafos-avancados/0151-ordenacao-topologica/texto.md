## 0151 · Ordenação topológica

O mestre de obras tem oito serviços para encaixar no cronograma. Não dá para
levantar parede sem fundação, nem pintar com o reboco molhado, nem pôr o
piso antes da hidráulica. Ele precisa de uma lista em que **todo serviço
apareça depois dos que ele espera**. A mesma necessidade aparece na ordem
das disciplinas de um curso com pré-requisitos e na ordem em que um
compilador processa arquivos que dependem uns dos outros.

Cada regra "a vem antes de b" vira uma seta `a -> b` num grafo dirigido. A
lista que o mestre de obras quer é uma **ordenação topológica**: uma ordem
dos vértices em que toda seta aponta para a frente, de um vértice para outro
que aparece depois dele (CORMEN et al., 2024, cap. 20). Ela só existe se o
grafo não tem ciclo: se a Parede espera o Reboco e o Reboco espera a Parede,
nenhum dos dois pode vir primeiro. Um grafo dirigido sem ciclos se chama
**DAG** (*directed acyclic graph*).

Para montar a lista, o algoritmo mais intuitivo faz o que o mestre de obras
faria no papel: começa pelo que não espera ninguém. Para isso, conte, para
cada serviço, quantas setas chegam nele. Esse número é o **grau de
entrada**, e diz quantos serviços ele ainda espera. A Fundação tem grau de
entrada 0; a Pintura, que espera Piso e Reboco, tem 2.

O **algoritmo de Kahn** funciona assim. Ponha numa fila (assunto 0085)
todos os serviços com grau de entrada 0, os que podem começar já. Depois,
repita: tire um serviço da fila e escreva-o na lista. Como ele está feito,
cada serviço que esperava por ele passa a esperar **um a menos**, e o grau
dele diminui (`grau[v]--`). Quem chegar a 0 ficou livre e entra na fila.
Quando a fila esvaziar, a lista está pronta (KAHN, 1962).

O Kahn detecta ciclo de brinde. Num ciclo, cada vértice espera outro do
mesmo ciclo, então nenhum chega a grau 0 e nenhum entra na fila. Se a lista
terminar com menos de V vértices, os que sobraram estão num ciclo ou
dependem de algum. Cada vértice entra na fila uma vez, e cada seta diminui
um grau uma vez: o custo é O(V + E) com lista de adjacência e O(V²) com
matriz, porque achar os vizinhos de um vértice custa uma linha inteira
(SZWARCFITER; MARKENZON, 2010).

A ordenação topológica **não é única**. Depois das Paredes, Elétrica,
Hidráulica e Telhado ficam livres juntos, e qualquer ordem entre os três
respeita as regras. Quem decide é a ordem em que entram na fila, que no
programa segue o índice dos vértices.

Há um segundo caminho, pela DFS do assunto 0111. Pense no momento em que
`dfs(u)` termina: tudo o que `u` alcança, ou seja, tudo o que depende de
`u`, já terminou antes. Então a ordem de término, a **pós-ordem**, lida de
trás para a frente, põe cada vértice antes de tudo o que depende dele. Basta
empilhar `u` no fim de `dfs(u)` e, no final, desempilhar tudo. É a versão do
Cormen, que ordena pelo tempo de término decrescente; o exemplo A301 a
mostra em C (CORMEN et al., 2024, cap. 20).

> [!WARNING]
> O grau que importa é o de **entrada**: `grau[b] += antes[a][b]`, somando pela
> coluna. Pela linha dá o de saída e acusa ciclo que não existe. Sem
> `feitas < V`, um ciclo gera uma lista incompleta que parece certa.

{{exemplo}}

Oito serviços de uma obra: não dá para levantar parede sem fundação nem pintar
com o reboco molhado. O número em cada serviço é a posição dele na lista:

{{ideia}}

A fila é um vetor: cada vértice entra uma vez, então V posições bastam.

```c
#include <stdio.h>

#define V 8

int main(void) {
    const char *tarefas[V] = {"Elétrica", "Fundação", "Hidráulica", "Paredes",
                              "Piso", "Pintura", "Reboco", "Telhado"};
    int antes[V][V] = {0}; // antes[a][b] = 1: a precisa terminar antes de b
    int regras[][2] = {{1, 3}, {3, 7}, {3, 0}, {3, 2}, {7, 6},
                       {0, 6}, {2, 6}, {2, 4}, {6, 5}, {4, 5}};
    for (int k = 0; k < 10; k++) antes[regras[k][0]][regras[k][1]] = 1;

    int grau[V] = {0}; // quantas tarefas cada uma ainda espera
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++) grau[b] += antes[a][b];

    int fila[V], inicio = 0, fim = 0;
    for (int v = 0; v < V; v++)
        if (grau[v] == 0) fila[fim++] = v; // quem não espera ninguém começa

    int feitas = 0;
    while (inicio < fim) {
        int u = fila[inicio++];
        printf("%d. %s\n", ++feitas, tarefas[u]);
        for (int v = 0; v < V; v++) {
            if (!antes[u][v]) continue;
            grau[v]--;                          // u terminou: v espera uma a menos
            if (grau[v] == 0) fila[fim++] = v;  // v ficou livre
        }
    }
    if (feitas < V) printf("Ciclo: %d tarefas nunca ficaram livres\n", V - feitas);
    return 0;
}
// Saída:
// 1. Fundação
// 2. Paredes
// 3. Elétrica
// 4. Hidráulica
// 5. Telhado
// 6. Piso
// 7. Reboco
// 8. Pintura
```

O laço do fluxograma só pergunta "a fila tem alguém?". O ciclo vem no fim:
quantos saíram, comparado com V.

{{fluxograma}}

### Passo a passo

| Sai | Graus que caem | Entram na fila | Fila depois |
| --- | --- | --- | --- |
| (início) | | Fundação | Fundação |
| Fundação | Paredes 1 → 0 | Paredes | Paredes |
| Paredes | Elétrica, Hidráulica e Telhado 1 → 0 | os três | Elétrica, Hidráulica, Telhado |
| Elétrica | Reboco 3 → 2 | | Hidráulica, Telhado |
| Hidráulica | Piso 1 → 0, Reboco 2 → 1 | Piso | Telhado, Piso |
| Telhado | Reboco 1 → 0 | Reboco | Piso, Reboco |
| Piso | Pintura 2 → 1 | | Reboco |
| Reboco | Pintura 1 → 0 | Pintura | Pintura |
| Pintura | | | (vazia) |

O A302 usa o Kahn para contar o mínimo de semestres de um curso.
