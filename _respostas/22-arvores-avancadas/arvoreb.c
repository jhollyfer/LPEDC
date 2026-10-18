// arvoreb.c · implementação do TAD árvore B (inserção com divisão na descida)
#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

static int divisoes = 0;

static NoB *novo_no(bool folha) {
    NoB *x = malloc(sizeof(NoB));
    if (x == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    x->n = 0;
    x->folha = folha;
    return x;
}

// divide o filho i de pai, que está cheio (AB_MAX chaves): a chave do meio
// sobe para pai, e a metade da direita vai para um nó novo
static void divide(NoB *pai, int i) {
    NoB *y = pai->filho[i];
    NoB *z = novo_no(y->folha);
    z->n = AB_T - 1;
    for (int j = 0; j < AB_T - 1; j++) {
        z->chave[j] = y->chave[j + AB_T]; // as chaves depois do meio
    }
    if (!y->folha) {
        for (int j = 0; j < AB_T; j++) {
            z->filho[j] = y->filho[j + AB_T]; // e os filhos delas
        }
    }
    y->n = AB_T - 1; // y fica com as chaves antes do meio

    for (int j = pai->n; j > i; j--) { // abre espaço no pai
        pai->filho[j + 1] = pai->filho[j];
    }
    pai->filho[i + 1] = z;
    for (int j = pai->n - 1; j >= i; j--) {
        pai->chave[j + 1] = pai->chave[j];
    }
    pai->chave[i] = y->chave[AB_T - 1]; // a chave do meio sobe
    pai->n++;
    divisoes++;
}

// insere num nó que com certeza NÃO está cheio
static void insere_nao_cheio(NoB *x, int chave) {
    int i = x->n - 1;
    if (x->folha) {
        while (i >= 0 && chave < x->chave[i]) { // empurra as maiores
            x->chave[i + 1] = x->chave[i];
            i--;
        }
        x->chave[i + 1] = chave;
        x->n++;
        return;
    }
    while (i >= 0 && chave < x->chave[i]) {
        i--;
    }
    i++; // a chave desce pelo filho i
    if (x->filho[i]->n == AB_MAX) {
        divide(x, i); // divide ANTES de descer
        if (chave > x->chave[i]) {
            i++;
        }
    }
    insere_nao_cheio(x->filho[i], chave);
}

NoB *ab_insere(NoB *raiz, int chave) {
    if (ab_busca(raiz, chave, NULL)) {
        return raiz; // repetida
    }
    if (raiz == NULL) {
        raiz = novo_no(true);
    }
    if (raiz->n == AB_MAX) { // raiz cheia: a árvore cresce por cima
        NoB *s = novo_no(false);
        s->filho[0] = raiz;
        divide(s, 0);
        raiz = s;
    }
    insere_nao_cheio(raiz, chave);
    return raiz;
}

bool ab_busca(const NoB *r, int chave, int *visitados) {
    int lidos = 0;
    bool achou = false;
    while (r != NULL) {
        lidos++;
        int i = 0;
        while (i < r->n && chave > r->chave[i]) {
            i++;
        }
        if (i < r->n && chave == r->chave[i]) {
            achou = true;
            break;
        }
        r = r->folha ? NULL : r->filho[i];
    }
    if (visitados != NULL) {
        *visitados = lidos;
    }
    return achou;
}

int ab_altura(const NoB *r) {
    if (r == NULL) {
        return -1;
    }
    int h = 0;
    while (!r->folha) { // todas as folhas estão no mesmo nível
        r = r->filho[0];
        h++;
    }
    return h;
}

static void mostra_nivel(const NoB *r, int nivel) {
    if (nivel == 0) {
        printf(" [");
        for (int i = 0; i < r->n; i++) {
            printf(i > 0 ? " %d" : "%d", r->chave[i]);
        }
        printf("]");
        return;
    }
    for (int i = 0; i <= r->n; i++) {
        mostra_nivel(r->filho[i], nivel - 1);
    }
}

void ab_mostra(const NoB *r) {
    for (int d = 0; d <= ab_altura(r); d++) {
        printf("  nível %d:", d);
        mostra_nivel(r, d);
        printf("\n");
    }
}

int ab_divisoes(void) {
    return divisoes;
}

NoB *ab_libera(NoB *r) {
    if (r != NULL) {
        if (!r->folha) {
            for (int i = 0; i <= r->n; i++) {
                ab_libera(r->filho[i]);
            }
        }
        free(r);
    }
    return NULL;
}
