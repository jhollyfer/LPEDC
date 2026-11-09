// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2210 · ★☆☆ · A árvore B andar por andar

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define T 2
#define MAXC (2 * T - 1)

typedef struct NoB {
    int n;
    int chave[MAXC];
    struct NoB *filho[MAXC + 1];
    bool folha;
} NoB;

NoB *novo_no(bool folha) {
    NoB *x = malloc(sizeof *x);
    if (x == NULL) {
        exit(1);
    }
    x->n = 0;
    x->folha = folha;
    for (int i = 0; i <= MAXC; i++) {
        x->filho[i] = NULL;
    }
    return x;
}

// o filho i de x está cheio: a chave do meio sobe para x
void divide(NoB *x, int i) {
    NoB *y = x->filho[i];
    NoB *z = novo_no(y->folha);
    z->n = T - 1;
    for (int j = 0; j < T - 1; j++) {
        z->chave[j] = y->chave[j + T];
    }
    if (!y->folha) {
        for (int j = 0; j < T; j++) {
            z->filho[j] = y->filho[j + T];
        }
    }
    y->n = T - 1;
    for (int j = x->n; j > i; j--) {
        x->filho[j + 1] = x->filho[j];
    }
    x->filho[i + 1] = z;
    for (int j = x->n - 1; j >= i; j--) {
        x->chave[j + 1] = x->chave[j];
    }
    x->chave[i] = y->chave[T - 1];
    x->n++;
}

void insere_nao_cheio(NoB *x, int k) {
    int i = x->n - 1;
    if (x->folha) {
        while (i >= 0 && k < x->chave[i]) {
            x->chave[i + 1] = x->chave[i];
            i--;
        }
        x->chave[i + 1] = k;
        x->n++;
        return;
    }
    while (i >= 0 && k < x->chave[i]) {
        i--;
    }
    i++;
    if (x->filho[i]->n == MAXC) {
        divide(x, i);
        if (k > x->chave[i]) {
            i++;
        }
    }
    insere_nao_cheio(x->filho[i], k);
}

NoB *insere(NoB *r, int k) {
    if (r == NULL) {
        r = novo_no(true);
    }
    if (r->n == MAXC) {
        NoB *s = novo_no(false);
        s->filho[0] = r;
        divide(s, 0);
        insere_nao_cheio(s, k);
        return s;
    }
    insere_nao_cheio(r, k);
    return r;
}

void libera(NoB *x) {
    if (x == NULL) {
        return;
    }
    for (int i = 0; i <= x->n; i++) {
        libera(x->filho[i]);
    }
    free(x);
}

void mostra_niveis(NoB *r) {
    NoB *fila[64];
    int nivel[64], ini = 0, fim = 0;
    fila[fim] = r;
    nivel[fim++] = 0;
    int atual = 0;
    printf("Nível 0:");
    while (ini < fim) {
        NoB *x = fila[ini];
        int nv = nivel[ini++];
        if (nv != atual) {
            atual = nv;
            printf("\nNível %d:", atual);
        }
        printf(" [");
        for (int i = 0; i < x->n; i++) {
            printf(i ? " %d" : "%d", x->chave[i]);
        }
        printf("]");
        if (!x->folha) {
            for (int i = 0; i <= x->n; i++) {
                fila[fim] = x->filho[i];
                nivel[fim++] = nv + 1;
            }
        }
    }
    printf("\n");
}

int main(void) {
    NoB *r = NULL;
    for (int k = 1; k <= 12; k++) {
        r = insere(r, k);
    }
    mostra_niveis(r);
    libera(r);
    return 0;
}
