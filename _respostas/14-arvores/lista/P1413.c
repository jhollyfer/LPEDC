// Lista · Módulo 14 · Árvores
// Exercício P1413 · ★★☆ · O k-ésimo menor tempo da maratona

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

// em ordem, parando quando chega no k-ésimo; *k vai sendo gasto
const No *k_esimo(const No *r, int *k) {
    if (r == NULL) {
        return NULL;
    }
    const No *achou = k_esimo(r->esq, k);
    if (achou != NULL) {
        return achou;
    }
    (*k)--;
    if (*k == 0) {
        return r;
    }
    return k_esimo(r->dir, k);
}

int conta(const No *r) {
    return r == NULL ? 0 : 1 + conta(r->esq) + conta(r->dir);
}

int main(void) {
    int tempos[] = {212, 185, 240, 170, 199, 228, 265, 192, 205, 251, 178};
    No *raiz = NULL;
    for (int i = 0; i < 11; i++) {
        raiz = insere(raiz, tempos[i]);
    }

    int pedidos[] = {1, 3, 8, 11, 12};
    for (int i = 0; i < 5; i++) {
        int k = pedidos[i];
        const No *p = k_esimo(raiz, &k);
        if (p != NULL) {
            printf("%dº menor: %d min\n", pedidos[i], p->chave);
        } else {
            printf("%dº menor: não existe\n", pedidos[i]);
        }
    }
    int n = conta(raiz);
    int meio = (n + 1) / 2, k = meio;
    printf("mediana (%dº de %d): %d min\n", meio, n, k_esimo(raiz, &k)->chave);
    libera(raiz);
    return 0;
}
