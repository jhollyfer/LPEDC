## 0099 · BST: busca e inserção

A catraca da academia precisa achar a matrícula na hora. No vetor ordenado, a
busca binária (assunto 0090) é rápida, mas cada aluno novo empurra metade do
vetor. Na lista encadeada, inserir é barato, mas a busca anda nó a nó. Dá para
ter as duas coisas?

A **árvore binária de busca**, ou **BST** (*binary search tree*), é uma árvore
binária com uma regra em **todo** nó: as chaves da subárvore esquerda são
**menores** que a do nó, e as da direita são **maiores**.

Buscar é a busca binária na árvore: compare com a raiz; igual, achou; menor,
esquerda; maior, direita; `NULL`, a chave não existe. **Inserir** é a mesma
descida: no `NULL` em que a busca falharia, pendure um nó novo, sempre como
**folha**. A inserção recursiva devolve a raiz da subárvore e o pai faz
`r->esq = bst_insere(r->esq, chave)`: no `NULL`, o ponteiro do pai passa a
apontar para o nó novo. Chave repetida é ignorada.

A **em ordem** de uma BST sai crescente. O nó logo depois de outro na em ordem
é o **sucessor**; o logo antes é o **antecessor**. O menor é o nó mais à
esquerda e o maior, o mais à direita (assunto 0175).

A busca custa no máximo **altura** + 1 comparações: numa árvore cheia, perto
de log₂ n (7 chaves: 3 níveis; um milhão: uns 20).

Sete alunos chegaram na ordem 50, 30, 70, 20, 40, 60 e 80. A busca pelo 60
compara com 50 (direita), 70 (esquerda) e acha. A do 45 desce 50, 30, 40 e cai
no `NULL` à direita do 40, onde o 45 entraria:

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

> [!WARNING]
> A forma da BST depende da **ordem de chegada**. As sete matrículas em ordem
> crescente formam uma lista disfarçada, de altura 6, onde buscar o 80 passa
> pelos 7 nós (exemplo A198). O assunto 0101 resolve isso.

> [!TIP]
> Esquecer a atribuição em `raiz = bst_insere(raiz, ...)` perde o nó criado. A
> alternativa é passar o endereço da raiz (`No **`), como no `scanf` (exercício
> E592).

> [!NOTE]
> **Pergunta para você:** em que ordem inserir 10, 20, 30, 40, 50, 60 e 70 para
> a árvore ficar com altura 2? Há mais de uma resposta?

{{pratique}}
