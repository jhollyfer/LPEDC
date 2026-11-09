// Lista · Módulo 15 · Tabelas hash
// Exercício P1514 · ★★☆ · A tabela que cresce sozinha

#include <stdio.h>
#include <stdlib.h>

#define VAZIO -1

typedef struct {
    int *t;
    int m, n;
} Tabela;

int eh_primo(int x) {
    if (x < 2) {
        return 0;
    }
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            return 0;
        }
    }
    return 1;
}

int proximo_primo(int x) {
    while (!eh_primo(x)) {
        x++;
    }
    return x;
}

int *cria(int m) {
    int *t = malloc(m * sizeof(int));
    if (t == NULL) {
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        t[i] = VAZIO;
    }
    return t;
}

void coloca(int t[], int m, int k) {
    int pos = k % m;
    while (t[pos] != VAZIO) {
        pos = (pos + 1) % m;
    }
    t[pos] = k;
}

void mostra(const Tabela *tb) {
    printf("  m = %2d:", tb->m);
    for (int i = 0; i < tb->m; i++) {
        if (tb->t[i] == VAZIO) {
            printf(" _");
        } else {
            printf(" %d", tb->t[i]);
        }
    }
    printf("\n");
}

void insere(Tabela *tb, int k) {
    if (2 * (tb->n + 1) > tb->m) { // alfa passaria de 0.5: cresce antes
        int novo_m = proximo_primo(2 * tb->m);
        int *novo = cria(novo_m);
        for (int i = 0; i < tb->m; i++) {
            if (tb->t[i] != VAZIO) {
                coloca(novo, novo_m, tb->t[i]); // todo mundo é re-espalhado
            }
        }
        free(tb->t);
        tb->t = novo;
        printf("rehash: %d -> %d\n", tb->m, novo_m);
        tb->m = novo_m;
    }
    coloca(tb->t, tb->m, k);
    tb->n++;
}

int main(void) {
    Tabela tb = {cria(5), 5, 0};
    int chaves[] = {12, 7, 33, 21, 18, 40, 9};
    for (int i = 0; i < 7; i++) {
        insere(&tb, chaves[i]);
        printf("+%d\n", chaves[i]);
        mostra(&tb);
    }
    printf("n = %d, alfa = %.2f\n", tb.n, (double)tb.n / tb.m);
    free(tb.t);
    return 0;
}
