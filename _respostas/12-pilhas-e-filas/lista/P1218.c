// Lista · Módulo 12 · Pilhas e filas
// Exercício P1218 · ★★☆ · A fila do lava-jato que trava

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CAP 4

typedef struct {
    int *v;
    int inicio, fim, n;
} Fila;

bool insere(Fila *f, int x) {
    if (f->n == CAP) {
        return false;
    }
    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % CAP; // dá a volta
    f->n++;
    return true;
}

bool retira(Fila *f, int *x) {
    if (f->n == 0) { // inicio == fim também acontece com a fila cheia
        return false;
    }
    *x = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % CAP;
    f->n--;
    return true;
}

void entram(Fila *f, int de, int ate) {
    printf("entram");
    for (int c = de; c <= ate; c++) {
        if (insere(f, c)) {
            printf(" %d", c);
        } else {
            printf(" (%d recusado)", c);
        }
    }
    printf("\n");
}

int main(void) {
    Fila f = {malloc(CAP * sizeof(int)), 0, 0, 0};
    if (f.v == NULL) {
        return 1;
    }
    int x;
    entram(&f, 1, 3);
    printf("saem");
    for (int i = 0; i < 2 && retira(&f, &x); i++) {
        printf(" %d", x);
    }
    printf("\n");
    entram(&f, 4, 6);
    printf("saem até esvaziar:");
    while (retira(&f, &x)) {
        printf(" %d", x);
    }
    printf("\n");
    free(f.v);
    return 0;
}
