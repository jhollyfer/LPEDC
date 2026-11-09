// Lista · Módulo 11 · Listas
// Exercício P1124 · ★★★ · Inverter só um trecho da fila

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

// monta uma lista com os n valores do vetor, na mesma ordem
No *de_vetor(const int v[], int n) {
    No *inicio = NULL;
    for (int i = n - 1; i >= 0; i--) {
        No *novo = malloc(sizeof *novo);
        if (novo == NULL) {
            fprintf(stderr, "sem memória\n");
            exit(1);
        }
        novo->valor = v[i];
        novo->prox = inicio;
        inicio = novo;
    }
    return inicio;
}

void imprime(const No *inicio) {
    for (const No *p = inicio; p != NULL; p = p->prox) {
        printf("%d -> ", p->valor);
    }
    printf("NULL\n");
}

void libera(No *inicio) {
    while (inicio != NULL) {
        No *seguinte = inicio->prox;
        free(inicio);
        inicio = seguinte;
    }
}

No *inverte_trecho(No *inicio, int a, int b) {
    if (inicio == NULL || a >= b) {
        return inicio;
    }
    No *antes = NULL, *p = inicio;
    for (int i = 1; i < a && p != NULL; i++) {
        antes = p;
        p = p->prox;
    }
    No *prim = p; // vai virar o último do trecho
    No *ant = NULL;
    for (int i = a; i <= b && p != NULL; i++) {
        No *seg = p->prox;
        p->prox = ant;
        ant = p;
        p = seg;
    }
    if (prim != NULL) {
        prim->prox = p; // liga o fim do trecho no resto
    }
    if (antes == NULL) {
        return ant;
    }
    antes->prox = ant;
    return inicio;
}

int main(void) {
    int pessoas[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    No *fila = de_vetor(pessoas, 8);
    printf("fila:   ");
    imprime(fila);
    int trechos[3][2] = {{3, 6}, {1, 2}, {7, 8}};
    for (int t = 0; t < 3; t++) {
        fila = inverte_trecho(fila, trechos[t][0], trechos[t][1]);
        printf("(%d, %d): ", trechos[t][0], trechos[t][1]);
        imprime(fila);
    }
    libera(fila);
    return 0;
}
