## 0151 · Ordenação topológica

O mestre de obras tem oito serviços para encaixar no cronograma: não dá para
levantar parede sem fundação, nem pintar com o reboco molhado. Ele precisa de
uma lista em que **todo serviço apareça depois dos que ele espera**.

Cada regra "a antes de b" é uma seta `a -> b`. A lista é a **ordenação
topológica**: uma ordem dos vértices em que toda seta aponta para a frente.
Ela só existe se o grafo não tem ciclo. Um grafo dirigido sem ciclos é um
**DAG** (*directed acyclic graph*).

O **algoritmo de Kahn** faz o que o mestre de obras faria:

1. conte, para cada serviço, quantos ele espera: o **grau de entrada**;
2. ponha numa fila (assunto 0085) todos com grau 0;
3. tire um da fila e escreva na lista. Quem esperava por ele passa a esperar
   **um a menos**: `grau[v]--`. Quem chegar a 0 entra na fila;
4. repita até a fila esvaziar.

Se a lista terminar com menos de V serviços, sobraram os que estão num ciclo
ou depois dele: o Kahn detecta o ciclo sem custo extra. Cada vértice e cada
seta são tratados uma vez: O(V + E) com lista de adjacência, O(V²) com
matriz.

A resposta **não é única**: Elétrica, Hidráulica e Telhado ficam livres
juntos, e a fila e a ordem de índice decidem o empate.

O segundo caminho usa a DFS (assunto 0111). Quando `dfs(u)` termina, tudo o
que depende de `u` já terminou. A ordem de término (**pós-ordem**), de trás
para a frente, é uma ordenação topológica: empilhe `u` no fim de `dfs(u)` e
desempilhe tudo no final, como no A301. É a versão do Cormen (tempo de
término `u.f` decrescente).

No desenho, o número em cada serviço é a posição dele na lista:

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

O A302 reaproveita o Kahn: quantos semestres, no mínimo, um curso precisa,
cursando em paralelo tudo que já está liberado.

> [!WARNING]
> O grau que importa é o de **entrada**: `grau[b] += antes[a][b]`, somando
> pela coluna. Somar pela linha dá o grau de saída, e o programa acusa um
> ciclo que não existe. Sem `feitas < V`, um ciclo de verdade gera uma lista
> incompleta que parece certa.

> [!NOTE]
> **Pergunta para você:** se o Piso também passar a esperar o Telhado
> (acrescente `{7, 4}` nas regras e troque o 10 por 11), em que posição o
> Piso sai? E se a Fundação passar a esperar a Pintura (`{5, 1}`), o que o
> programa mostra?

{{pratique}}
