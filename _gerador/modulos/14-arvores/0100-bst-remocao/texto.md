## 0100 · BST: remoção

Três alunos cancelaram o plano, e as matrículas 30, 40 e 20 saem da árvore.
Inserir era fácil porque todo nó novo entra como folha. Remover é mais
delicado: o nó pode ter filhos, e a regra da BST precisa continuar valendo.

A busca acha o nó. Depois, tudo depende de **quantos filhos** ele tem:

| Caso | O que fazer | No exemplo |
| --- | --- | --- |
| **folha** | dá `free` e o pai passa a apontar para `NULL` | remover o 20 |
| **um filho** | o filho sobe para o lugar dele; o avô "pula" o nó | remover o 40: o 45 sobe |
| **dois filhos** | troca pelo **sucessor** e remove o sucessor | remover o 30: o 35 assume |

Os dois primeiros casos são um código só: "o filho que existe sobe", e na folha
esse filho é `NULL`. No terceiro, o lugar do 30 é de alguém maior que tudo à
esquerda e menor que tudo à direita: o **sucessor** (a menor chave da subárvore
direita) ou o **antecessor** (a maior da esquerda). Este TAD usa o sucessor,
como o Cormen; com o antecessor a árvore final sai diferente.

Para achar o sucessor, desça **uma vez à direita** e depois **à esquerda até
não dar mais**. Esse nó não tem filho esquerdo, então removê-lo cai num caso
fácil. Copie a chave dele para o nó do 30 e remova o 35 da subárvore direita.

Como na inserção, a função devolve a raiz da subárvore e o pai faz
`r->esq = bst_remove(r->esq, chave)`. Para a raiz, o cliente faz
`raiz = bst_remove(raiz, ...)`.

O 30 tem dois filhos. O sucessor sai indo para a direita (40) e depois para a
esquerda (35). O 35 ocupa o lugar do 30, e o 35 de baixo, que era folha, sai:

{{ideia}}

A função completa, no `bst.c`:

```c
No *bst_remove(No *r, int chave) {
    if (r == NULL) {
        return NULL; // não achou: nada a remover
    }
    if (chave < r->chave) {
        r->esq = bst_remove(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = bst_remove(r->dir, chave);
    } else if (r->esq == NULL || r->dir == NULL) {
        // folha ou um filho: o filho (ou NULL) sobe para o lugar do nó
        No *filho = r->esq != NULL ? r->esq : r->dir;
        free(r);
        return filho;
    } else {
        // dois filhos: copia o sucessor (o menor da direita) e remove ele lá
        No *suc = r->dir;
        while (suc->esq != NULL) {
            suc = suc->esq;
        }
        r->chave = suc->chave;
        r->dir = bst_remove(r->dir, suc->chave);
    }
    return r;
}
```

O cliente remove as três matrículas e mostra a pré-ordem, que revela a
**forma** da árvore (a em ordem sairia sempre crescente):

```c
#include <stdio.h>
#include "bst.h"

void pre(const No *r) {
    if (r == NULL) {
        return;
    }
    printf(" %d", r->chave);
    pre(r->esq);
    pre(r->dir);
}

void mostra(const char *rotulo, const No *r) {
    printf("%-11s pré:", rotulo);
    pre(r);
    printf("\n");
}

int main(void) {
    int matriculas[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = bst_insere(raiz, matriculas[i]);
    }
    mostra("Antes", raiz);

    raiz = bst_remove(raiz, 30); // dois filhos: o sucessor 35 assume
    mostra("Remove 30", raiz);
    raiz = bst_remove(raiz, 40); // um filho: o 45 sobe
    mostra("Remove 40", raiz);
    raiz = bst_remove(raiz, 20); // folha: só sai
    mostra("Remove 20", raiz);
    raiz = bst_remove(raiz, 99); // não existe: nada muda
    mostra("Remove 99", raiz);

    raiz = bst_libera(raiz);
    return 0;
}
// Saída:
// Antes       pré: 50 30 20 40 35 45 70 60 80
// Remove 30   pré: 50 35 20 40 45 70 60 80
// Remove 40   pré: 50 35 20 45 70 60 80
// Remove 20   pré: 50 35 45 70 60 80
// Remove 99   pré: 50 35 45 70 60 80
```

O caminho verde é a chamada que encontra o 30: cai no caso de dois filhos,
copia o 35 e faz uma **segunda remoção**, do 35, que termina no caso fácil:

{{fluxograma}}

> [!WARNING]
> `bst_remove(raiz->esq, 20);` sem atribuir o retorno dá `free` no 20 mas deixa
> o pai apontando para o endereço antigo: **ponteiro solto**, que o
> AddressSanitizer acusa como `heap-use-after-free`. Vale também para `raiz`.

> [!TIP]
> A remoção com dois filhos copia **só a chave**. Com uma struct grande, é
> melhor religar ponteiros (a `TRANSPLANT` do Cormen). O custo é O(altura).

> [!NOTE]
> **Pergunta para você:** se você remover o **50** (a raiz), quem assume o
> lugar? E se depois remover a nova raiz? Confira com o exemplo A200.

{{pratique}}
