// Lista · Módulo 11 · Listas
// Exercício P1111 · ★★☆ · Juntar dois rankings já em ordem decrescente

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

No *intercala_decrescente(No *a, No *b) {
    No *resultado = NULL;
    while (a != NULL || b != NULL) {
        No *menor;
        if (b == NULL || (a != NULL && a->valor <= b->valor)) {
            menor = a;
            a = a->prox;
        } else {
            menor = b;
            b = b->prox;
        }
        menor->prox = resultado; // entra no início do resultado
        resultado = menor;
    }
    return resultado;
}

int main(void) {
    int va[4] = {2, 5, 8, 9};
    int vb[5] = {1, 5, 7, 10, 12};
    No *a = de_vetor(va, 4);
    No *b = de_vetor(vb, 5);
    printf("a: ");
    imprime(a);
    printf("b: ");
    imprime(b);

    No *mural = intercala_decrescente(a, b); // a e b não valem mais nada
    printf("mural: ");
    imprime(mural);
    libera(mural);
    return 0;
}
