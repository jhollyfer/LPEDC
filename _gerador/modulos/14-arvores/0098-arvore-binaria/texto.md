## 0098 · Árvore binária e percursos

- **Árvore binária**: ou é **vazia** (`NULL`), ou é um nó com uma
  **subárvore esquerda** e uma **subárvore direita**. Cada nó tem no máximo
  dois filhos (CORMEN et al., 2024, cap. 12).
- **O lado importa**: `A` com `B` à esquerda e `A` com `B` à direita são
  árvores diferentes (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 5).
- **Percurso**: um jeito de visitar todos os nós uma vez. Os três recursivos
  só mudam a posição da visita em relação às duas chamadas (FEOFILOFF, 2009).
- **Por nível**: usa uma **fila** (assunto 0085). Tira o nó da frente, mostra
  e põe os filhos no fim (CELES; RANGEL, 2002).
- **Árvore de expressão**: operadores nos nós internos, números nas folhas.
  A pós-ordem é a ordem de calcular (assunto 0084)
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 5).
- **Ponteiros nulos**: uma árvore binária com `n` nós tem `n + 1` ponteiros
  `NULL`. A recursão usa altura + 1 chamadas na pilha
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 7).

| Percurso | Ordem | Em `(8-3)*(4+2)` |
| --- | --- | --- |
| **pré-ordem** | raiz, esquerda, direita | `* - 8 3 + 4 2` (notação prefixa) |
| **em ordem** | esquerda, raiz, direita | `8 - 3 * 4 + 2` (infixa, sem parênteses) |
| **pós-ordem** | esquerda, direita, raiz | `8 3 - 4 2 + *` (pós-fixa, a da calculadora HP) |
| **por nível** | linha por linha, de cima para baixo | `* - + 8 3 4 2` |

> [!WARNING]
> A em ordem **perde os parênteses**: `8 - 3 * 4 + 2` dá `8 - 12 + 2 = -2`, e
> não 30. Para mostrar a fórmula certa, abra `(` antes de cada subárvore e
> feche depois (exemplo A196).

{{exemplo}}

A conta do churrasco, `=(8-3)*(4+2)` = 30: 8 pessoas, 3 não bebem, e cada uma
paga R$ 4 de cerveja e R$ 2 de gelo. Os operadores ficam nos nós internos
(roxo) e os números nas folhas (azul):

{{ideia}}

O nó guarda um `char` (dígito ou operador) e dois ponteiros. O resto é um TAD
(assunto 0074), `arvore.h` e `arvore.c`:

```c
typedef struct No {
    char info;
    struct No *esq; // subárvore da esquerda
    struct No *dir; // subárvore da direita
} No;
```

O cliente monta a árvore de baixo para cima com `arv_cria(info, esq, dir)` e
chama os percursos:

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

O caso base é a árvore vazia. Mover o `printf` dá a pré-ordem ou a pós-ordem:

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
