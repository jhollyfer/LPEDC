// Lista · Módulo 12 · Pilhas e filas
// Exercício P1209 · ★☆☆ · Por que a fila em vetor é circular

#include <stdio.h>

#define CAP 8

typedef struct {
    int v[CAP];
    int n;
} FilaIngenua;

typedef struct {
    int v[CAP];
    int inicio, n;
} FilaCircular;

long deslocamentos = 0;

void ing_insere(FilaIngenua *f, int x) {
    if (f->n < CAP) {
        f->v[f->n++] = x;
    }
}

int ing_retira(FilaIngenua *f) {
    int x = f->v[0];
    for (int i = 1; i < f->n; i++) { // todo mundo anda uma casa
        f->v[i - 1] = f->v[i];
        deslocamentos++;
    }
    f->n--;
    return x;
}

void circ_insere(FilaCircular *f, int x) {
    if (f->n < CAP) {
        f->v[(f->inicio + f->n) % CAP] = x;
        f->n++;
    }
}

int circ_retira(FilaCircular *f) {
    int x = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % CAP;
    f->n--;
    return x;
}

int main(void) {
    FilaIngenua a = {.n = 0};
    for (int s = 1; s <= 5; s++) {
        ing_insere(&a, s);
    }
    printf("Deslocando: saíram");
    while (a.n > 0) {
        printf(" %d", ing_retira(&a));
    }
    printf(" com %ld deslocamentos\n", deslocamentos);

    deslocamentos = 0;
    FilaCircular b = {.inicio = 0, .n = 0};
    for (int s = 1; s <= 5; s++) {
        circ_insere(&b, s);
    }
    printf("Circular:   saíram");
    while (b.n > 0) {
        printf(" %d", circ_retira(&b));
    }
    printf(" com %ld deslocamentos\n", deslocamentos);
    return 0;
}
