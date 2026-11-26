## 0153 · Prim: a árvore que cresce

Cinco chácaras vão dividir a água de um poço artesiano. O encanador mediu
os trechos por onde dá para passar cano: do Poço à chácara da Ana são 4 m,
da Ana ao Beto 3 m, do Poço ao Beto 6 m, e assim por diante. O objetivo é o
mesmo do Kruskal (0152): ligar todo mundo com o **mínimo de cano**. O que
muda é o jeito de trabalhar.

O encanador não sai comprando o cano mais barato da lista inteira. Ele
começa no Poço e vai **esticando a rede**: a cada passo, olha os canos que
ligam uma casa que já tem água a uma que ainda não tem, e instala o **mais
curto**. A casa nova passa a ter água, e o passo se repete. Esse é o
**algoritmo de Prim**: parte de um vértice e, a cada passo, escolhe a
aresta mais leve entre um vértice da árvore e um de fora (PRIM, 1957).

A diferença para o Kruskal está na forma da solução enquanto ela se monta.
O Kruskal junta pedaços espalhados, uma floresta de grupos que vão se
fundindo. O Prim mantém **uma árvore só**, que cresce a partir da origem e
nunca se separa. No fim, os dois chegam a uma árvore geradora mínima.

O Prim também é guloso, e acerta pelo mesmo motivo do Kruskal, a
propriedade do corte (0152). Em cada passo, o corte separa as casas com
água das casas sem água. O cano mais curto que cruza esse corte é uma
aresta leve, e uma aresta leve sempre cabe numa árvore mínima (CORMEN et
al., 2024, cap. 21).

O trabalho de cada passo é achar o cano mais curto que sai da rede. Para
não procurar na lista toda, o Prim guarda os candidatos num **heap de
mínimo** (assunto 0102), que entrega o menor na hora. Cada item do heap diz
"dá para ligar `v` com `chave` metros a partir de `de`". Quando uma casa
entra na rede, os canos que saem dela para casas de fora entram no heap.

Um item pode envelhecer. O Beto entra no heap com 6 m, pelo Poço, e depois
com 3 m, pela Ana. Quando o de 3 m sai, o Beto entra na rede, e o item de 6
m continua no heap, inútil. Na **versão preguiçosa**, ninguém atualiza nada
dentro do heap: quando um item sai e a casa dele já está na rede, ele é
simplesmente **descartado** (SEDGEWICK; WAYNE, 2011).

A versão do Cormen, `MST-PRIM`, faz diferente. Ela põe todos os vértices no
heap desde o começo, com chave infinita, e, quando acha um cano mais curto
para um vértice, baixa a chave dele no lugar, com a operação
`DECREASE-KEY`. Não sobram itens velhos. Com heap binário, as duas versões
custam O(E log V) (CORMEN et al., 2024, cap. 21).

Se o código lembrou o Dijkstra (0112), não é por acaso: é o mesmo laço, e só
muda a chave com que um vizinho entra no heap. No Prim, a chave é o cano que
liga o vizinho à rede. No Dijkstra, é a distância acumulada desde a origem.
Por isso as árvores saem diferentes: no exemplo, o Prim gasta 18 m de cano e
a árvore do Dijkstra, 21 m. A tabela resume:

| | chave de `w` ao sair de `v` | o que a árvore minimiza |
| --- | --- | --- |
| Prim | `cano[v][w]` | a soma de **todos** os canos |
| Dijkstra | `dist[v] + cano[v][w]` | a distância de **cada** casa até o Poço |

> [!WARNING]
> Sem `if (na_rede[it.v]) continue;`, o total soma cano que ninguém instala
> (aqui, 49 m). Sem `!na_rede[w]`, o heap enche de itens inúteis e `CAP` pode
> estourar. Prim e Kruskal só valem para grafo **não dirigido**.

{{exemplo}}

Cinco chácaras vão dividir a água de um poço com o mínimo de cano. Os números
são a ordem de entrada na rede, as arestas verdes são os canos escolhidos, e à
direita está o heap logo depois que a Ana entra:

{{ideia}}

O heap guarda structs e compara pela `chave`, com `sobe` e `desce` do
assunto 0102 em sinais trocados:

```c
#include <stdbool.h>
#include <stdio.h>

#define V 6
#define CAP 32 // cada aresta entra no heap no máximo duas vezes

typedef struct {
    int chave, v, de; // "dá para ligar v à rede com chave metros, a partir de de"
} Item;

Item heap[CAP];
int n = 0;

void troca(int i, int j) {
    Item t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}

void insere(Item x) { // heap de MÍNIMO: sobe enquanto for menor que o pai
    int i = n++;
    heap[i] = x;
    while (i > 0 && heap[(i - 1) / 2].chave > heap[i].chave) {
        troca(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

Item tira(void) { // tira o menor e desce o último pelo menor filho
    Item menor = heap[0];
    heap[0] = heap[--n];
    int i = 0;
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && heap[f + 1].chave < heap[f].chave) f++;
        if (heap[i].chave <= heap[f].chave) break;
        troca(i, f);
        i = f;
    }
    return menor;
}

int main(void) {
    const char *nomes[V] = {"Poço", "Ana", "Beto", "Cida", "Davi", "Elza"};
    int cano[V][V] = {0}; // metros; 0 = sem caminho para cano
    int trechos[][3] = {{0, 1, 4}, {0, 2, 6}, {1, 2, 3}, {1, 3, 8}, {2, 3, 5},
                        {2, 4, 8}, {3, 4, 2}, {3, 5, 9}, {4, 5, 4}};
    for (int k = 0; k < 9; k++) {
        cano[trechos[k][0]][trechos[k][1]] = trechos[k][2];
        cano[trechos[k][1]][trechos[k][0]] = trechos[k][2];
    }

    bool na_rede[V] = {false};
    int total = 0;
    insere((Item){0, 0, -1}); // começa pelo Poço, de graça
    while (n > 0) {
        Item it = tira();
        if (na_rede[it.v]) { // já entrou por um cano mais curto
            printf("  descarta %s (%d)\n", nomes[it.v], it.chave);
            continue;
        }
        na_rede[it.v] = true;
        total += it.chave;
        if (it.de >= 0) printf("%s <- %s (%d m)\n", nomes[it.v], nomes[it.de], it.chave);
        for (int w = 0; w < V; w++) // candidatos novos: canos que saem de v
            if (cano[it.v][w] && !na_rede[w]) insere((Item){cano[it.v][w], w, it.v});
    }
    printf("Total: %d m de cano\n", total);
    return 0;
}
// Saída:
// Ana <- Poço (4 m)
// Beto <- Ana (3 m)
// Cida <- Beto (5 m)
// Davi <- Cida (2 m)
// Elza <- Davi (4 m)
//   descarta Beto (6)
//   descarta Cida (8)
//   descarta Davi (8)
//   descarta Elza (9)
// Total: 18 m de cano
```

O fluxograma é o laço do Dijkstra com heap. "Já está na rede?" descarta os
itens velhos:

{{fluxograma}}

### Passo a passo

| Entra | Itens que entram no heap | Heap depois (do menor) |
| --- | --- | --- |
| Poço (0) | Ana 4, Beto 6 | Ana 4, Beto 6 |
| Ana (4) | Beto 3, Cida 8 | Beto 3, Beto 6, Cida 8 |
| Beto (3) | Cida 5, Davi 8 | Cida 5, Beto 6, Cida 8, Davi 8 |
| Cida (5) | Davi 2, Elza 9 | Davi 2, Beto 6, Cida 8, Davi 8, Elza 9 |
| Davi (2) | Elza 4 | Elza 4, Beto 6, Cida 8, Davi 8, Elza 9 |
| Elza (4) | | sobram 4 itens velhos, todos descartados |

O Dijkstra a partir do Poço ligaria o Beto direto ao Poço (6 m, contra 7 pela
Ana) e gastaria **21 m**; o Prim gasta **18 m**. Outra pergunta, outra árvore.
