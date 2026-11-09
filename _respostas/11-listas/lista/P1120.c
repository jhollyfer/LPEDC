// Lista · Módulo 11 · Listas
// Exercício P1120 · ★★☆ · Girar a escala de plantão

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

No *gira(No *inicio, int k) {
    if (inicio == NULL || k <= 0) {
        return inicio;
    }
    int n = 1;
    No *ultimo = inicio;
    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
        n++;
    }
    k = k % n;
    if (k == 0) {
        return inicio;
    }
    ultimo->prox = inicio; // fecha o círculo
    No *novo_ultimo = ultimo;
    for (int i = 0; i < n - k; i++) {
        novo_ultimo = novo_ultimo->prox;
    }
    No *novo_inicio = novo_ultimo->prox;
    novo_ultimo->prox = NULL; // corta o círculo
    return novo_inicio;
}

int main(void) {
    int dias[5] = {1, 2, 3, 4, 5};
    No *escala = de_vetor(dias, 5);
    printf("escala: ");
    imprime(escala);
    int ks[3] = {2, 7, 0};
    for (int i = 0; i < 3; i++) {
        escala = gira(escala, ks[i]);
        printf("k = %d:  ", ks[i]);
        imprime(escala);
    }
    libera(escala);
    return 0;
}
