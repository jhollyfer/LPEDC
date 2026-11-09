// Lista · Módulo 12 · Pilhas e filas
// Exercício P1202 · ★☆☆ · Os índices da fila circular, passo a passo

#include <stdbool.h>
#include <stdio.h>

#define CAP 5

typedef struct {
    int v[CAP];
    int inicio, fim, n;
} Fila;

bool insere(Fila *f, int x) {
    if (f->n == CAP) {
        return false;
    }
    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % CAP;
    f->n++;
    return true;
}

bool retira(Fila *f, int *x) {
    if (f->n == 0) {
        return false;
    }
    *x = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % CAP;
    f->n--;
    return true;
}

void estado(const Fila *f) {
    printf("inicio=%d fim=%d n=%d\n", f->inicio, f->fim, f->n);
}

void faz_insere(Fila *f, int x) {
    printf("insere %d: ", x);
    if (insere(f, x)) {
        estado(f);
    } else {
        printf("fila cheia\n");
    }
}

void faz_retira(Fila *f) {
    int x;
    if (retira(f, &x)) {
        printf("retira %d: ", x);
        estado(f);
    } else {
        printf("retira: fila vazia\n");
    }
}

int main(void) {
    Fila f = {.inicio = 0, .fim = 0, .n = 0};
    faz_insere(&f, 10);
    faz_insere(&f, 20);
    faz_insere(&f, 30);
    faz_retira(&f);
    faz_retira(&f);
    int mais[4] = {40, 50, 60, 70};
    for (int i = 0; i < 4; i++) {
        faz_insere(&f, mais[i]);
    }
    faz_insere(&f, 80);
    return 0;
}
