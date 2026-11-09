// Lista · Módulo 11 · Listas
// Exercício P1117 · ★★☆ · Pares na frente, sem mudar a ordem

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

No *pares_primeiro(No *inicio) {
    No *pi = NULL, *pf = NULL; // pares: início e fim
    No *ii = NULL, *if_ = NULL; // ímpares: início e fim
    No *p = inicio;
    while (p != NULL) {
        No *seguinte = p->prox;
        p->prox = NULL;
        if (p->valor % 2 == 0) {
            if (pf == NULL) {
                pi = p;
            } else {
                pf->prox = p;
            }
            pf = p;
        } else {
            if (if_ == NULL) {
                ii = p;
            } else {
                if_->prox = p;
            }
            if_ = p;
        }
        p = seguinte;
    }
    if (pi == NULL) {
        return ii;
    }
    pf->prox = ii;
    return pi;
}

int main(void) {
    int senhas[7] = {7, 2, 9, 4, 4, 1, 6};
    No *guiche = de_vetor(senhas, 7);
    printf("antes:  ");
    imprime(guiche);

    guiche = pares_primeiro(guiche);
    printf("depois: ");
    imprime(guiche);
    libera(guiche);
    return 0;
}
