## 0099 · BST: busca e inserção

- **Árvore binária de busca** (**BST**, *binary search tree*): árvore binária
  em que, em **todo** nó, a subárvore esquerda só tem chaves menores e a
  direita só tem chaves maiores (CORMEN et al., 2024, cap. 12).
- **Busca**: compara com a raiz. Igual, achou; menor, desce à esquerda; maior,
  à direita; `NULL`, a chave não existe. É a busca binária (assunto 0090) na
  árvore (FEOFILOFF, 2009).
- **Inserção**: a mesma descida. No `NULL` em que a busca falharia entra o nó
  novo, sempre como **folha**. A função devolve a raiz da subárvore e o pai
  faz `r->esq = bst_insere(r->esq, chave)`. Chave repetida é ignorada
  (FEOFILOFF, 2009).
- **Em ordem crescente**: a em ordem de uma BST sai ordenada. O nó logo depois
  é o **sucessor**, o logo antes é o **antecessor**; o menor fica mais à
  esquerda e o maior, mais à direita (CORMEN et al., 2024, cap. 12).
- **Custo**: no máximo **altura** + 1 comparações. Numa árvore cheia, perto de
  log₂ n: 7 chaves, 3 níveis; um milhão, uns 20 (ZIVIANI, 2010, cap. 5).

> [!WARNING]
> A forma da BST depende da **ordem de chegada**. As sete matrículas em ordem
> crescente formam uma lista disfarçada de altura 6 (exemplo A198). E sem
> `raiz = bst_insere(raiz, ...)` o nó criado se perde.

{{exemplo}}

A catraca da academia procura matrículas. Sete alunos chegaram na ordem 50,
30, 70, 20, 40, 60 e 80. A busca do 60 passa por 50 e 70; a do 45 desce 50,
30, 40 e cai no `NULL` à direita do 40:

{{ideia}}

O TAD fica em `bst.h` e `bst.c`. As duas funções principais:

```c
No *bst_insere(No *r, int chave) {
    if (r == NULL) {
        return novo_no(chave); // achou o lugar vazio: vira folha
    }
    if (chave < r->chave) {
        r->esq = bst_insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = bst_insere(r->dir, chave);
    }
    return r; // igual: já existe, não insere de novo
}

No *bst_busca(No *r, int chave) {
    while (r != NULL && r->chave != chave) {
        r = chave < r->chave ? r->esq : r->dir;
    }
    return r;
}
```

A busca dispensa recursão: um laço desce um nível por volta. O exemplo mostra
o caminho:

```c
#include <stdio.h>
#include "bst.h"

void procura(const No *r, int chave) {
    printf("Busca %d:", chave);
    while (r != NULL) {
        printf(" %d", r->chave);
        if (chave == r->chave) {
            printf(" -> achou\n");
            return;
        }
        r = chave < r->chave ? r->esq : r->dir;
    }
    printf(" -> NULL, não existe\n");
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80};
    No *raiz = NULL;
    for (int i = 0; i < 7; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }

    printf("Em ordem:");
    bst_em_ordem(raiz);
    printf("\n");
    procura(raiz, 60);
    procura(raiz, 45);
    printf("Altura: %d\n", bst_altura(raiz));

    raiz = bst_libera(raiz);
    return 0;
}
// Saída:
// Em ordem: 20 30 40 50 60 70 80
// Busca 60: 50 70 60 -> achou
// Busca 45: 50 30 40 -> NULL, não existe
// Altura: 2
```

Cada volta faz no máximo duas perguntas e desce um nível. O caminho verde é a
busca do 60:

{{fluxograma}}
