## 0151 · Ordenação topológica

- **Ordenação topológica**: ordem dos vértices em que toda seta `a -> b` aponta
  para a frente. Só existe se o grafo não tem ciclo (CORMEN et al., 2024, cap. 20).
- **DAG** (*directed acyclic graph*): grafo dirigido sem ciclos.
- **Grau de entrada**: quantas setas chegam ao vértice, ou quantos serviços ele
  espera.
- **Algoritmo de Kahn**: ponha numa fila (0085) todos com grau 0; tire um,
  escreva na lista e faça `grau[v]--` em quem esperava por ele; quem chegar a 0
  entra na fila. Repita até esvaziar (KAHN, 1962).
- **Detecta ciclo**: se a lista terminar com menos de V vértices, sobraram os
  que estão num ciclo ou depois dele. Custo O(V + E) com lista, O(V²) com
  matriz (SZWARCFITER; MARKENZON, 2010).
- **Não é única**: vértices livres ao mesmo tempo saem na ordem da fila.
- **Pela DFS**: empilhe `u` quando `dfs(u)` termina; a pós-ordem de trás para a
  frente é uma ordenação topológica (tempo de término decrescente, no Cormen;
  A301) (CORMEN et al., 2024, cap. 20).

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
