## 0151 · Ordenação topológica

O mestre de obras tem oito serviços para encaixar no cronograma da casa. Não
dá para levantar parede sem fundação, nem rebocar antes de passar os canos e
os fios, nem pintar com o reboco molhado. Ele precisa de uma lista, em fila
indiana, em que **todo serviço apareça depois dos que ele espera**.

Cada regra "a antes de b" é uma seta `a -> b`, e o conjunto vira um grafo
dirigido. A lista pedida é a **ordenação topológica**: uma ordem dos
vértices em que toda seta aponta para a frente. Ela só existe se o grafo não
tem ciclo. Se a pintura espera o reboco e o reboco espera a pintura, ninguém
começa. Um grafo dirigido sem ciclos tem até sigla: **DAG** (*directed
acyclic graph*).

O jeito mais natural é o **algoritmo de Kahn**, que faz o que o mestre de
obras faria:

1. conte, para cada serviço, quantos ele espera: o **grau de entrada**;
2. ponha numa fila (assunto 0085) todos com grau 0, os que já podem começar;
3. tire um da fila e escreva na lista. Ele terminou, então cada serviço que
   esperava por ele espera **um a menos**: `grau[v]--`. Quem chegar a 0 entra
   na fila;
4. repita até a fila esvaziar.

Se a lista terminar com menos de V serviços, sobrou gente esperando para
sempre: os que estão num ciclo, ou depois de um. Kahn já detecta o ciclo de
graça. Cada vértice entra e sai da fila uma vez e cada seta é descontada uma
vez: O(V + E) com lista de adjacência, O(V²) com matriz.

A resposta **não é única**. Elétrica, Hidráulica e Telhado ficam livres ao
mesmo tempo, e qualquer ordem entre eles serve. A fila e a ordem de índice
dos vizinhos decidem o empate; mude a numeração e a lista muda, sem estar
errada.

Existe um segundo caminho, pela DFS do assunto 0111. Quando a chamada
`dfs(u)` termina, tudo o que depende de `u` já terminou antes. Então a ordem
em que as chamadas **terminam** (a **pós-ordem**), lida de trás para a
frente, é uma ordenação topológica. Na prática: empilhe `u` no fim de
`dfs(u)` e, no final, desempilhe tudo. O exemplo A301 faz assim.

Vamos ver na prática. O número em cima de cada serviço é a posição dele na
lista. Repare no Reboco, que espera três serviços e só entra em sétimo:

{{ideia}}

O código guarda as regras numa matriz, conta os graus e roda Kahn com uma
fila num vetor (cada vértice entra uma vez, então V posições bastam):

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

Repara no fluxograma: o laço só pergunta "a fila tem alguém?". A pergunta
sobre o ciclo fica para o fim, quando se compara quantos saíram com V:

{{fluxograma}}

### Passo a passo

Cada linha tira um serviço da fila e desconta os que esperavam por ele:

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

O A302 aproveita o mesmo Kahn para outra pergunta: em vez de uma fila
indiana, quantos semestres no mínimo um curso precisa, cursando em paralelo
tudo que já está liberado.

> [!WARNING]
> O grau que importa é o de **entrada** (quantas setas **chegam**), e a conta
> é `grau[b] += antes[a][b]`, somando pela coluna. Somar pela linha dá o grau
> de saída, e aí "grau 0" passa a querer dizer "ninguém depende de mim": só
> a Pintura começa na fila, ela sai, não libera ninguém, e o programa acusa
> um ciclo que não existe. E não esqueça o teste `feitas < V` no fim: sem
> ele, um ciclo de verdade produz uma lista incompleta que parece certa.

> [!TIP]
> **Por dentro do C:** a fila daqui nunca dá a volta, por isso não precisa ser
> circular como a do assunto 0085: cada vértice entra exatamente uma vez,
> então `fim` nunca passa de V. No fim do laço, `fila[0..fim-1]` é a própria
> ordenação, guardada em ordem. O vetor `grau[]` é a única coisa que o
> algoritmo destrói: depois de rodar, ele está todo zerado (ou com sobras nos
> vértices do ciclo). Se precisar dos graus de novo, conte outra vez ou
> trabalhe numa cópia.

> [!NOTE]
> **Pergunta para você:** se o Piso também passar a esperar o Telhado
> (acrescente `{7, 4}` nas regras e troque o 10 por 11), em que posição o
> Piso sai? E se a Fundação passar a esperar a Pintura (`{5, 1}`), o que o
> programa mostra?

{{pratique}}
