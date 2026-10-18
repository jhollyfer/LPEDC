## 0153 · Prim: a árvore que cresce

Cinco chácaras de um condomínio vão dividir a água de um poço artesiano. O
encanador mediu os trechos onde dá para passar cano: do Poço até a casa da
Ana são 4 m, da Ana até o Beto 3 m, e assim por diante. A água pode passar
de uma casa para outra, então não precisa de um cano do Poço até cada casa.
O objetivo é o mesmo do Kruskal: ligar todo mundo com o **mínimo de cano**.

O Kruskal resolveria, olhando a lista de trechos inteira. Só que o
encanador pensa diferente: ele sai do Poço e vai **esticando a rede**. A
cada passo, entre todos os canos que ligam uma casa já atendida a uma casa
ainda sem água, ele escolhe o **mais curto**. Esse é o algoritmo de
**Prim**.

Prim é guloso e acerta pelo mesmo motivo do Kruskal: as casas atendidas e
as não atendidas formam dois grupos, e o cano mais curto entre os dois
grupos sempre pode fazer parte de uma árvore mínima (a propriedade do
corte). A diferença é só a ordem: Kruskal junta florestas espalhadas; Prim
mantém **uma árvore só**, que cresce a partir da origem.

Para achar rápido "o cano mais curto que sai da rede", Prim usa a fila de
prioridade do assunto 0102, um **heap de mínimo**. Cada item diz "dá para
ligar `v` com `chave` metros a partir de `de`". Quando uma casa entra na
rede, os canos que saem dela entram no heap. Ao tirar um item cuja casa já
está na rede, é só **descartar**: ela já entrou por um cano melhor. Essa
versão, que não atualiza itens dentro do heap, se chama **preguiçosa**.

Se isso lembrou o Dijkstra (assunto 0112), não é coincidência. O código é
quase o mesmo. A diferença está numa linha só, a chave de quem entra no
heap:

| | chave de `w` ao sair de `v` | o que a árvore minimiza |
| --- | --- | --- |
| Prim | `cano[v][w]` | a soma de **todos** os canos |
| Dijkstra | `dist[v] + cano[v][w]` | a distância de **cada** casa até o Poço |

Vamos ver na prática. Os números em cima são a ordem de entrada na rede, as
arestas verdes são os canos escolhidos, e à direita está o heap logo depois
que a Ana entra:

{{ideia}}

O heap guarda structs e compara pela `chave`; `sobe` e `desce` são as do
assunto 0102, com os sinais trocados para virar heap de mínimo:

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

Repara no fluxograma: é o laço do Dijkstra com heap. A pergunta "já está na
rede?" é o que torna a versão preguiçosa correta: o heap pode ter itens
velhos, e eles são jogados fora na saída:

{{fluxograma}}

### Passo a passo

O heap depois de cada casa que entra (só as chaves e as casas):

| Entra | Itens que entram no heap | Heap depois (do menor) |
| --- | --- | --- |
| Poço (0) | Ana 4, Beto 6 | Ana 4, Beto 6 |
| Ana (4) | Beto 3, Cida 8 | Beto 3, Beto 6, Cida 8 |
| Beto (3) | Cida 5, Davi 8 | Cida 5, Beto 6, Cida 8, Davi 8 |
| Cida (5) | Davi 2, Elza 9 | Davi 2, Beto 6, Cida 8, Davi 8, Elza 9 |
| Davi (2) | Elza 4 | Elza 4, Beto 6, Cida 8, Davi 8, Elza 9 |
| Elza (4) | | sobram 4 itens velhos, todos descartados |

E se fosse o Dijkstra a partir do Poço? Beto ficaria pendurado no Poço (6 m
direto, contra 4 + 3 = 7 passando pela Ana), e o resto seguiria Beto, Cida,
Davi, Elza. Cada casa estaria o mais perto possível do Poço, mas a rede
gastaria 4 + 6 + 5 + 2 + 4 = **21 m**. O Prim gasta **18 m**. Perguntas
diferentes, árvores diferentes.

O A305 faz o Prim sem heap, em O(V²), para um grafo completo de postes de
luz, em que a versão com vetor ganha. O A306 roda Prim e Dijkstra lado a lado
no mesmo mapa e mostra as duas árvores.

> [!WARNING]
> Sem o teste `if (na_rede[it.v]) continue;`, cada item velho que sai do heap
> "entra" de novo na rede: o total soma cano que ninguém vai instalar (aqui
> daria 18 + 6 + 8 + 8 + 9 = 49 m). O mesmo vale para o laço dos vizinhos: sem
> `!na_rede[w]`, o heap enche de itens inúteis, e a capacidade `CAP` pode
> estourar. Prim, como Kruskal, só faz sentido em grafo **não dirigido**: num
> dirigido, "ligar todo mundo pelo mínimo" é outro problema, bem mais difícil.

> [!TIP]
> **Por dentro do C:** `(Item){cano[it.v][w], w, it.v}` é um **literal
> composto** (C99): cria uma struct temporária sem nome, que `insere` recebe
> por valor, copiando os 12 bytes. O heap inteiro é um vetor de `Item`
> contíguo: `heap[i].chave` fica 12 bytes depois de `heap[i - 1].chave`, e o
> pai de `i` está em `(i - 1) / 2`, como no assunto 0102. Com lista de
> adjacência, o Prim preguiçoso custa O(E log E), e como E < V², isso é
> O(E log V). Com matriz, como aqui, varrer os vizinhos já custa O(V²).

> [!NOTE]
> **Pergunta para você:** se o cano Ana-Beto custar 7 m em vez de 3, quem
> pendura o Beto na rede, e qual o novo total? Monte a tabela do heap antes de
> trocar o `{1, 2, 3}`.

{{pratique}}
