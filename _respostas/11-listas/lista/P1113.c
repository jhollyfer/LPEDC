// Lista · Módulo 11 · Listas
// Exercício P1113 · ★★☆ · Desengatar o k-ésimo vagão a partir do fim

#include <stdbool.h>
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

No *remove_k_do_fim(No *inicio, int k, bool *ok) {
    *ok = false;
    if (k < 1) {
        return inicio;
    }
    No *rapido = inicio;
    for (int i = 0; i < k; i++) { // abre uma distância de k nós
        if (rapido == NULL) {
            return inicio; // a lista tem menos de k nós
        }
        rapido = rapido->prox;
    }
    No *ant = NULL, *lento = inicio;
    while (rapido != NULL) {
        ant = lento;
        lento = lento->prox;
        rapido = rapido->prox;
    }
    if (ant == NULL) {
        inicio = lento->prox;
    } else {
        ant->prox = lento->prox;
    }
    free(lento);
    *ok = true;
    return inicio;
}

int main(void) {
    int vagoes[5] = {10, 20, 30, 40, 50};
    No *trem = de_vetor(vagoes, 5);
    printf("trem:  ");
    imprime(trem);

    int ks[3] = {2, 4, 5};
    for (int i = 0; i < 3; i++) {
        bool ok;
        trem = remove_k_do_fim(trem, ks[i], &ok);
        printf("k = %d: ", ks[i]);
        if (ok) {
            imprime(trem);
        } else {
            printf("não existe\n");
        }
    }
    libera(trem);
    return 0;
}
