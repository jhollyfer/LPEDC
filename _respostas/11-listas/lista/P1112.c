// Lista · Módulo 11 · Listas
// Exercício P1112 · ★★☆ · O leitor de código de barras que repete

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

int remove_repetidos(No *inicio) {
    int removidos = 0;
    for (No *atual = inicio; atual != NULL; atual = atual->prox) {
        No *q = atual;
        while (q->prox != NULL) {
            if (q->prox->valor == atual->valor) {
                No *morto = q->prox;
                q->prox = morto->prox; // desliga antes do free
                free(morto);
                removidos++;
            } else {
                q = q->prox;
            }
        }
    }
    return removidos;
}

int main(void) {
    int lidos[8] = {7, 3, 7, 9, 3, 3, 1, 9};
    No *caixa = de_vetor(lidos, 8);
    printf("antes:  ");
    imprime(caixa);

    int r = remove_repetidos(caixa);
    printf("depois: ");
    imprime(caixa);
    printf("%d leituras repetidas removidas\n", r);
    libera(caixa);
    return 0;
}
