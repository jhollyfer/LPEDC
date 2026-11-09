// Lista · Módulo 14 · Árvores
// Exercício P1412 · ★★☆ · Remoções em sequência na BST
//
// Os armários do clube ficam numa BST montada com 50, 30, 70, 20, 40, 60, 80,
// 35, 45, 65. Escreva No *remove_chave(No *r, int chave) com os três casos
// (folha, um filho, dois filhos) e, no caso de dois filhos, use o SUCESSOR
// (o menor da subárvore direita), como no Cormen: copie a chave dele para o
// nó e remova o sucessor da subárvore direita. Remova 20, 60, 30 e 50, nesta
// ordem, mostrando a pré-ordem depois de cada remoção.
//
//   Saída esperada:
//   início:    50 30 20 40 35 45 70 60 65 80
//   sem o 20: 50 30 40 35 45 70 60 65 80
//   sem o 60: 50 30 40 35 45 70 65 80
//   sem o 30: 50 40 35 45 70 65 80
//   sem o 50: 65 40 35 45 70 80
//
// Dicas:
// 1. Folha e um filho se resolvem juntos: o filho (que pode ser NULL) toma o
//    lugar do nó, e o nó é liberado.
// 2. O 30 tem dois filhos; o sucessor dele é o 35, que tem 0 filhos. Depois
//    da cópia, o 35 sai da subárvore direita do 30.
// 3. O 50, na raiz, é trocado pelo 65 (o menor à direita depois de o 60 ter
//    saído). Com o antecessor, a raiz seria o 45: as duas respostas são
//    válidas, e a prova diz qual convenção usar.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

No *insere(No *r, int chave) {
    if (r == NULL) {
        No *p = malloc(sizeof(No));
        if (p == NULL) {
            exit(1);
        }
        p->chave = chave;
        p->esq = p->dir = NULL;
        return p;
    }
    if (chave < r->chave) {
        r->esq = insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = insere(r->dir, chave);
    }
    return r;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

void pre(const No *r) {
    if (r != NULL) {
        printf(" %d", r->chave);
        pre(r->esq);
        pre(r->dir);
    }
}

int main(void) {
    int armarios[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65};
    No *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        raiz = insere(raiz, armarios[i]);
    }
    printf("início:   ");
    pre(raiz);
    printf("\n");

    libera(raiz);
    return 0;
}
