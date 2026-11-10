## 0153 · Prim: a árvore que cresce

Cinco chácaras vão dividir a água de um poço artesiano. O encanador mediu os
trechos por onde passa cano: do Poço à Ana são 4 m, da Ana ao Beto 3 m, e
assim por diante. O objetivo é o do Kruskal: ligar todo mundo com o **mínimo
de cano**.

O encanador sai do Poço e vai **esticando a rede**: a cada passo, entre os
canos que ligam uma casa atendida a uma sem água, escolhe o **mais curto**.
Esse é o algoritmo de **Prim**.

O Prim é guloso e acerta pela propriedade do corte (assunto 0152): o cano
mais curto entre casas atendidas e não atendidas sempre cabe numa árvore
mínima. O Kruskal junta florestas espalhadas; o Prim mantém **uma árvore
só**, que cresce da origem.

Para achar o cano mais curto que sai da rede, o Prim usa o **heap de mínimo**
do assunto 0102. Cada item diz "dá para ligar `v` com `chave` metros a
partir de `de`". Quando uma casa entra, os canos que saem dela entram no
heap. Item cuja casa já está na rede é **descartado**. Essa versão, que não
atualiza itens dentro do heap, é a **preguiçosa**. A do Cormen (`MST-PRIM`)
põe todos os vértices no heap com chave infinita e baixa a chave no lugar
(`DECREASE-KEY`). Com heap binário, as duas custam O(E log V).

O código lembra o Dijkstra (assunto 0112); muda a chave de quem entra no
heap:

| | chave de `w` ao sair de `v` | o que a árvore minimiza |
| --- | --- | --- |
| Prim | `cano[v][w]` | a soma de **todos** os canos |
| Dijkstra | `dist[v] + cano[v][w]` | a distância de **cada** casa até o Poço |

No desenho, os números são a ordem de entrada na rede, as arestas verdes são
os canos escolhidos, e à direita está o heap logo depois que a Ana entra:

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

No Dijkstra a partir do Poço, o Beto ficaria no Poço (6 m direto, contra
4 + 3 = 7 pela Ana), e o resto seguiria Beto, Cida, Davi, Elza. Cada casa
ficaria o mais perto possível do Poço, e a rede gastaria
4 + 6 + 5 + 2 + 4 = **21 m**. O Prim gasta **18 m**: outra pergunta, outra
árvore.

O A305 faz o Prim sem heap, em O(V²), para um grafo completo, onde a versão
com vetor ganha. O A306 roda Prim e Dijkstra no mesmo mapa.

> [!WARNING]
> Sem `if (na_rede[it.v]) continue;`, o total soma cano que ninguém instala
> (aqui, 18 + 6 + 8 + 8 + 9 = 49 m). Sem `!na_rede[w]` nos vizinhos, o heap
> enche de itens inúteis e `CAP` pode estourar. Prim e Kruskal só valem para
> grafo **não dirigido**.

> [!NOTE]
> **Pergunta para você:** se o cano Ana-Beto custar 7 m em vez de 3, quem
> pendura o Beto na rede, e qual o novo total? Monte a tabela do heap antes de
> trocar o `{1, 2, 3}`.

{{pratique}}
