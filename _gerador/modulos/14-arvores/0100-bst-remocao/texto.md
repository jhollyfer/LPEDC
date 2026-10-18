## 0100 · BST: remoção

Fim do mês na academia: três alunos cancelaram o plano, e as matrículas 30, 40
e 20 precisam sair da árvore. Inserir era fácil porque todo nó novo entra como
folha. Remover é mais delicado: o nó que sai pode estar no meio da árvore, com
filhos pendurados que não podem se perder, e a regra da BST tem que continuar
valendo depois.

Primeiro, a busca de sempre acha o nó. Depois, tudo depende de **quantos
filhos** ele tem. São três casos:

| Caso | O que fazer | No exemplo |
| --- | --- | --- |
| **folha** | dá `free` e o pai passa a apontar para `NULL` | remover o 20 |
| **um filho** | o filho sobe para o lugar dele; o avô "pula" o nó | remover o 40: o 45 sobe |
| **dois filhos** | troca pelo **sucessor** e remove o sucessor | remover o 30: o 35 assume |

Os dois primeiros casos são o mesmo código: "o filho que existe sobe", e na
folha esse filho é `NULL`. O terceiro é o interessante. Quem pode ocupar o lugar
do 30 sem quebrar a regra? Alguém maior que tudo à esquerda e menor que tudo à
direita. Dois candidatos servem: o **sucessor** (a menor chave da subárvore
direita) e o **antecessor** (a maior da esquerda). Este TAD usa o sucessor.

Para achar o sucessor, desça **uma vez à direita** e depois **à esquerda até
não dar mais**. Esse nó nunca tem filho esquerdo (senão não seria o menor), então
removê-lo cai num dos casos fáceis. O truque: copie a chave do sucessor para o
nó do 30 e chame a remoção do 35 na subárvore direita.

Como na inserção, a função devolve a raiz da subárvore depois da mudança, e o
pai faz `r->esq = bst_remove(r->esq, chave)`. É assim que o avô fica sabendo que
o neto subiu. E quando a chave removida é a da raiz da árvore inteira, o
`raiz = bst_remove(raiz, ...)` do cliente atualiza a raiz.

Vamos ver na prática. O 30 tem dois filhos. A partir dele, a busca do sucessor
vai para a direita (40) e depois para a esquerda até o fim (35). O 35 vai para o
lugar do 30, e o 35 de baixo, que era folha, sai:

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

O cliente remove as três matrículas e mostra a pré-ordem depois de cada passo.
A pré-ordem começa pela raiz e desce, então ela revela a **forma** da árvore (a em
ordem sairia sempre crescente e não mostraria nada):

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

Repara no fluxograma: o caminho verde é a chamada que encontra o 30. Ela cai no
caso de dois filhos, copia o 35 e faz uma **segunda remoção**, dessa vez do 35,
que vai terminar no caso fácil (o 35 é folha):

{{fluxograma}}

> [!WARNING]
> Esquecer de atribuir o retorno é o erro clássico. Com `bst_remove(raiz->esq,
> 20);` solto, a função dá `free` no 20, mas o pai continua apontando para o
> endereço antigo: um **ponteiro solto**. A próxima em ordem lê memória
> devolvida e o AddressSanitizer acusa `heap-use-after-free`. A mesma coisa na
> raiz: remover a última chave sem `raiz = ...` deixa `raiz` apontando para o
> nada.

> [!TIP]
> **Por dentro do C:** a remoção com dois filhos não move nó nenhum: ela copia
> **só a chave** e libera o nó do sucessor, lá embaixo. É barato com um `int`.
> Se o nó guardasse uma struct grande (nome, endereço, histórico), copiar
> custaria caro e invalidaria ponteiros que alguém guardou para o nó. Aí a saída
> é religar os ponteiros e mover o nó inteiro, sem copiar dado (o livro do
> Feofiloff faz assim). O custo continua O(altura): uma descida para achar o nó,
> outra para achar o sucessor.

> [!NOTE]
> **Pergunta para você:** na árvore do início, se você remover o **50** (a raiz),
> quem assume o lugar? E se depois remover a nova raiz, quem assume? Confira
> com o exemplo A200.

{{pratique}}
