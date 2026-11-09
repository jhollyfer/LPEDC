// Lista · Módulo 14 · Árvores
// Exercício P1420 · ★★☆ · Em ordem sem recursão

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

void em_ordem_iterativa(const No *r) {
    const No *pilha[32];
    int topo = 0, maior_pilha = 0;
    const No *p = r;
    while (p != NULL || topo > 0) {
        while (p != NULL) { // desce tudo para a esquerda empilhando
            pilha[topo++] = p;
            if (topo > maior_pilha) {
                maior_pilha = topo;
            }
            p = p->esq;
        }
        p = pilha[--topo];   // o de cima é o próximo da em ordem
        printf(" %d", p->chave);
        p = p->dir;          // e agora a subárvore direita dele
    }
    printf("\npilha chegou a %d nós\n", maior_pilha);
}

int main(void) {
    int codigos[] = {41, 20, 65, 11, 29, 50, 91, 32, 72, 99};
    No *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        raiz = insere(raiz, codigos[i]);
    }

    printf("em ordem:");
    em_ordem_iterativa(raiz);
    libera(raiz);
    return 0;
}
