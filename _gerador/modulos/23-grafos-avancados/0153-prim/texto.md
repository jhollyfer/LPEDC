## 0153 · Prim: a árvore que cresce

- **Prim**: sai de um vértice e, a cada passo, escolhe a aresta mais leve entre
  um vértice da árvore e um de fora. Mantém **uma árvore só**, que cresce da
  origem; o Kruskal junta florestas (PRIM, 1957).
- **Por que acerta**: é guloso e vale a propriedade do corte (0152)
  (CORMEN et al., 2024, cap. 21).
- **Heap de mínimo** (0102): cada item diz "dá para ligar `v` com `chave` a
  partir de `de`". Quando um vértice entra, as arestas que saem dele entram no
  heap.
- **Versão preguiçosa**: item cujo vértice já está na árvore é **descartado**;
  nada se atualiza dentro do heap (SEDGEWICK; WAYNE, 2011).
- **Versão do Cormen** (`MST-PRIM`): todos os vértices no heap com chave
  infinita, e `DECREASE-KEY` baixa a chave no lugar. Com heap binário, as duas
  custam O(E log V) (CORMEN et al., 2024, cap. 21).
- **Prim e Dijkstra** (0112): mesmo código, muda a chave de quem entra no heap.

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
