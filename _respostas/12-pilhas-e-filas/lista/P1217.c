// Lista · Módulo 12 · Pilhas e filas
// Exercício P1217 · ★★☆ · Embaralhar a fila como um baralho

#include <stdbool.h>
#include <stdio.h>

#define CAP 16

typedef struct {
    int v[CAP];
    int inicio, n;
} Fila;

bool insere(Fila *f, int x) {
    if (f->n == CAP) {
        return false;
    }
    f->v[(f->inicio + f->n) % CAP] = x;
    f->n++;
    return true;
}

int retira(Fila *f) {
    int x = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % CAP;
    f->n--;
    return x;
}

int tamanho(const Fila *f) {
    return f->n;
}

void intercala_metades(Fila *f) {
    Fila aux = {.inicio = 0, .n = 0};
    int metade = tamanho(f) / 2;
    for (int i = 0; i < metade; i++) {
        insere(&aux, retira(f));
    }
    for (int i = 0; i < metade; i++) {
        insere(f, retira(&aux)); // um da primeira metade
        insere(f, retira(f));    // um da segunda
    }
}

void mostra(const char *rotulo, Fila *f) {
    printf("%s", rotulo);
    int n = tamanho(f);
    for (int i = 0; i < n; i++) {
        int x = retira(f);
        printf(" %d", x);
        insere(f, x);
    }
    printf("\n");
}

void testa(const int v[], int n) {
    Fila f = {.inicio = 0, .n = 0};
    for (int i = 0; i < n; i++) {
        insere(&f, v[i]);
    }
    mostra("antes: ", &f);
    intercala_metades(&f);
    mostra("depois:", &f);
}

int main(void) {
    int pares[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int dezenas[4] = {10, 20, 30, 40};
    testa(pares, 8);
    testa(dezenas, 4);
    return 0;
}
