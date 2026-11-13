## 0098 · Árvore binária e percursos

A planilha recebe `=(8-3)*(4+2)` e precisa decidir o que calcular primeiro.
Os parênteses dizem que a subtração e a soma vêm antes, e a multiplicação
junta os dois resultados. Essa estrutura de "a conta de cima depende das duas
contas de baixo" é uma árvore em que cada operador tem exatamente dois
operandos. Árvores com no máximo dois filhos por nó aparecem tanto, na prova e
nos programas, que ganharam nome próprio.

Uma **árvore binária** é uma árvore em que cada nó tem no máximo dois filhos,
um à **esquerda** e outro à **direita**. A definição recursiva diz melhor:
uma árvore binária ou é **vazia**, o que em C se representa com `NULL`, ou é
um nó com uma **subárvore esquerda** e uma **subárvore direita**, cada uma
delas também uma árvore binária (CORMEN et al., 2024, cap. 12). A árvore vazia
é o caso base que encerra toda recursão sobre a árvore.

Aqui o lado importa. Um nó `A` com o filho `B` à esquerda e um nó `A` com o
filho `B` à direita são árvores **diferentes**, mesmo tendo os mesmos nós
(TENENBAUM; LANGSAM; AUGENSTEIN, 1995, cap. 5). Na conta, isso é óbvio:
`8 - 3` e `3 - 8` têm os mesmos números e o mesmo operador, e dão resultados
diferentes. Em C, o nó é uma `struct` com o dado e dois ponteiros, `esq` e
`dir`, e um filho ausente é um ponteiro `NULL`.

Para mostrar, contar ou somar o que está numa árvore, você precisa passar por
todos os nós. Um **percurso** é um jeito de visitar cada nó exatamente uma
vez. Os três percursos clássicos são recursivos e só diferem na posição da
visita em relação às duas chamadas (FEOFILOFF, 2009). Na **pré-ordem**, você
visita a raiz antes das subárvores; na **em ordem**, entre a esquerda e a
direita; na **pós-ordem**, depois das duas:

```c
void em_ordem(No *r) {
    if (r == NULL) return;   // árvore vazia: nada a visitar
    em_ordem(r->esq);
    printf("%c ", r->info);  // na pré-ordem, esta linha vem antes; na pós, depois
    em_ordem(r->dir);
}
```

O quarto percurso, **por nível**, visita a árvore linha por linha, de cima
para baixo, e não é recursivo. Ele usa uma **fila** (assunto 0085): põe a raiz
na fila e, enquanto a fila não esvazia, tira o nó da frente, mostra o nó e
põe os filhos dele no fim (CELES; RANGEL, 2002). Como a fila atende por ordem
de chegada, todos os nós de um nível saem antes dos nós do nível seguinte.

A conta do churrasco vira uma **árvore de expressão**: os operadores ficam nos
nós internos e os números nas folhas. Cada percurso dela produz uma notação
conhecida, e a pós-ordem dá exatamente a pós-fixa do assunto 0084. Isso não é
coincidência: o `*` só pode ser aplicado depois que as duas subárvores foram
calculadas, e a pós-ordem visita a raiz depois das duas (TENENBAUM; LANGSAM;
AUGENSTEIN, 1995, cap. 5).

| Percurso | Ordem | Em `(8-3)*(4+2)` |
| --- | --- | --- |
| **pré-ordem** | raiz, esquerda, direita | `* - 8 3 + 4 2` (notação prefixa) |
| **em ordem** | esquerda, raiz, direita | `8 - 3 * 4 + 2` (infixa, sem parênteses) |
| **pós-ordem** | esquerda, direita, raiz | `8 3 - 4 2 + *` (pós-fixa, a da calculadora HP) |
| **por nível** | linha por linha, de cima para baixo | `* - + 8 3 4 2` |

Dois números ajudam a prever o comportamento. Uma árvore binária com `n` nós
tem `n + 1` ponteiros `NULL`: são `2n` ponteiros no total, e só `n - 1` deles
apontam para algum nó, porque todo nó menos a raiz tem um pai. E a recursão
empilha altura + 1 chamadas de uma vez (TENENBAUM; LANGSAM; AUGENSTEIN, 1995,
cap. 7). Numa árvore equilibrada de um milhão de nós, isso dá uns 20 quadros
na pilha; numa árvore em fila indiana, com cada nó tendo um filho só, dá um
milhão, e a pilha estoura.

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
