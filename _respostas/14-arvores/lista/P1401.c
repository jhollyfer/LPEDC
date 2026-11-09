// Lista · Módulo 14 · Árvores
// Exercício P1401 · ★☆☆ · O organograma, nível por nível

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char nome[10];
    struct No *esq, *dir;
} No;

No *novo(const char *nome, No *esq, No *dir) {
    No *p = malloc(sizeof(No));
    if (p == NULL) {
        exit(1);
    }
    snprintf(p->nome, sizeof p->nome, "%s", nome);
    p->esq = esq;
    p->dir = dir;
    return p;
}

int altura(const No *r) {
    if (r == NULL) {
        return -1;
    }
    int he = altura(r->esq), hd = altura(r->dir);
    return 1 + (he > hd ? he : hd);
}

// pré-ordem levando a profundidade junto
void mostra(const No *r, int prof) {
    if (r == NULL) {
        return;
    }
    printf("%*s%s (profundidade %d, altura %d)\n", 2 * prof, "", r->nome, prof, altura(r));
    mostra(r->esq, prof + 1);
    mostra(r->dir, prof + 1);
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    No *raiz = novo("Diretora",
                    novo("Vendas", novo("Loja", NULL, NULL), novo("Online", NULL, novo("Site", NULL, NULL))),
                    novo("TI", novo("Suporte", NULL, NULL), NULL));

    mostra(raiz, 0);
    printf("altura da árvore: %d\n", altura(raiz));
    libera(raiz);
    return 0;
}
