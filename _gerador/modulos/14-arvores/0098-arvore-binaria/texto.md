## 0098 · Árvore binária e percursos

No churrasco, vão 8 pessoas, 3 não bebem, e quem bebe paga R$ 4 de cerveja mais
R$ 2 de gelo. A planilha calcula `=(8-3)*(4+2)` = 30 montando uma **árvore** com
a fórmula, para saber o que vem antes.

Uma **árvore binária** tem em cada nó **no máximo dois filhos**, um à
**esquerda** e outro à **direita**. Recursivamente: é **vazia** (`NULL`) ou é
um nó com uma **subárvore esquerda** e uma **subárvore direita**. O lado
importa: `A` com filho `B` à esquerda e `A` com filho `B` à direita são árvores
**diferentes**.

Em C, o nó é uma struct com o dado (um `char`: dígito ou operador) e dois
ponteiros:

```c
typedef struct No {
    char info;
    struct No *esq; // subárvore da esquerda
    struct No *dir; // subárvore da direita
} No;
```

O resto vira um **TAD** (assunto 0074): `arvore.h` com os protótipos e
`arvore.c` com a implementação. `arv_cria(info, esq, dir)` monta um nó com as
duas subárvores prontas, então a árvore se constrói de baixo para cima.

Visitar todos os nós tem quatro ordens, os **percursos**:

| Percurso | Ordem | Na fórmula |
| --- | --- | --- |
| **pré-ordem** | raiz, esquerda, direita | `* - 8 3 + 4 2` (notação prefixa) |
| **em ordem** | esquerda, raiz, direita | `8 - 3 * 4 + 2` (infixa, sem parênteses) |
| **pós-ordem** | esquerda, direita, raiz | `8 3 - 4 2 + *` (pós-fixa, a da calculadora HP) |
| **por nível** | linha por linha, de cima para baixo | `* - + 8 3 4 2` |

Os três primeiros são recursivos e mudam só a posição do `printf` em relação às
duas chamadas. O por nível usa uma **fila** (assunto 0085): tira um nó da
frente, mostra e põe os filhos no fim. A pós-ordem é a ordem de **calcular**:
o `*` só se aplica depois das duas subárvores (assunto 0084).

Os operadores ficam nos nós internos (roxo) e os números nas folhas (azul):

{{ideia}}

O cliente monta a árvore de baixo para cima e chama os percursos:

```c
#include <stdio.h>
#include "arvore.h"

int main(void) {
    // (8 - 3) * (4 + 2): 8 pessoas, 3 não bebem; cerveja R$ 4 + gelo R$ 2
    No *menos = arv_cria('-', arv_cria('8', NULL, NULL), arv_cria('3', NULL, NULL));
    No *mais = arv_cria('+', arv_cria('4', NULL, NULL), arv_cria('2', NULL, NULL));
    No *raiz = arv_cria('*', menos, mais);

    printf("Pré-ordem:");
    arv_pre_ordem(raiz);
    printf("\nEm ordem: ");
    arv_em_ordem(raiz);
    printf("\nPós-ordem:");
    arv_pos_ordem(raiz);
    printf("\nPor nível:");
    arv_por_nivel(raiz);
    printf("\nNós: %d, altura: %d\n", arv_conta(raiz), arv_altura(raiz));

    raiz = arv_libera(raiz);
    return 0;
}
// Saída:
// Pré-ordem: * - 8 3 + 4 2
// Em ordem:  8 - 3 * 4 + 2
// Pós-ordem: 8 3 - 4 2 + *
// Por nível: * - + 8 3 4 2
// Nós: 7, altura: 2
```

Dentro do `arvore.c`, a em ordem tem três linhas de verdade:

```c
void arv_em_ordem(const No *r) {
    if (r == NULL) {
        return;
    }
    arv_em_ordem(r->esq);
    printf(" %c", r->info);
    arv_em_ordem(r->dir);
}
```

O caso base é a árvore vazia. Num nó que existe, a função resolve a esquerda,
mostra a raiz e resolve a direita. Mover o `printf` dá a pré-ordem ou a
pós-ordem:

{{fluxograma}}

### Passo a passo

A pilha de chamadas da em ordem, a partir da raiz `*`. Cada linha é um
`printf`:

| Pilha de chamadas (topo à direita) | Mostra | Na tela até aqui |
| --- | --- | --- |
| `*` → `-` → `8` | 8 | `8` |
| `*` → `-` | - | `8 -` |
| `*` → `-` → `3` | 3 | `8 - 3` |
| `*` | * | `8 - 3 *` |
| `*` → `+` → `4` | 4 | `8 - 3 * 4` |
| `*` → `+` | + | `8 - 3 * 4 +` |
| `*` → `+` → `2` | 2 | `8 - 3 * 4 + 2` |

> [!WARNING]
> A em ordem **perde os parênteses**: `8 - 3 * 4 + 2` dá `8 - 12 + 2 = -2`, e
> não 30. Para mostrar a fórmula certa, a em ordem abre `(` antes de
> cada subárvore e fecha depois (exemplo A196).

> [!TIP]
> Uma árvore com `n` nós tem `n + 1` ponteiros `NULL`. A recursão usa altura +
> 1 frames: uns 20 numa árvore equilibrada de um milhão de nós, mas um milhão
> numa árvore em fila indiana, e a pilha estoura.

> [!NOTE]
> **Pergunta para você:** se a em ordem é `B A C` e a pré-ordem é `A B C`, quem
> é a raiz? E com em ordem `A B C` e pré-ordem `A B C`, como fica a árvore?

{{pratique}}
