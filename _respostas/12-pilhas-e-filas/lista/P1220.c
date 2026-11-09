// Lista · Módulo 12 · Pilhas e filas
// Exercício P1220 · ★★☆ · Um painel para dois guichês

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct {
    No *inicio, *fim;
    int n;
} Fila;

void entra(Fila *f, int x) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = x;
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    f->n++;
}

int sai(Fila *f) {
    No *velho = f->inicio;
    int x = velho->valor;
    f->inicio = velho->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(velho);
    f->n--;
    return x;
}

int frente(const Fila *f) {
    return f->inicio->valor;
}

bool vazia(const Fila *f) {
    return f->inicio == NULL;
}

void junta(Fila *a, Fila *b, Fila *painel) {
    while (!vazia(a) && !vazia(b)) {
        if (frente(a) <= frente(b)) {
            entra(painel, sai(a));
        } else {
            entra(painel, sai(b));
        }
    }
    while (!vazia(a)) {
        entra(painel, sai(a));
    }
    while (!vazia(b)) {
        entra(painel, sai(b));
    }
}

void mostra(const char *rotulo, Fila *f) {
    printf("%s:", rotulo);
    int n = f->n;
    for (int i = 0; i < n; i++) {
        int x = sai(f);
        printf(" %d", x);
        entra(f, x);
    }
    printf("\n");
}

int main(void) {
    Fila a = {NULL, NULL, 0}, b = {NULL, NULL, 0}, painel = {NULL, NULL, 0};
    int va[3] = {5, 12, 20}, vb[4] = {7, 8, 25, 30};
    for (int i = 0; i < 3; i++) {
        entra(&a, va[i]);
    }
    for (int i = 0; i < 4; i++) {
        entra(&b, vb[i]);
    }
    mostra("guichê A", &a);
    mostra("guichê B", &b);
    junta(&a, &b, &painel);
    mostra("painel", &painel);
    printf("A e B vazias: %s\n", vazia(&a) && vazia(&b) ? "sim" : "não");
    while (!vazia(&painel)) {
        sai(&painel);
    }
    return 0;
}
