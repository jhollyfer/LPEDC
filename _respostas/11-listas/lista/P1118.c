// Lista · Módulo 11 · Listas
// Exercício P1118 · ★★☆ · Desengatar o último vagão sem quebrar o trem

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

// tira o último nó, guarda o valor dele e devolve o início
No *remove_ultimo(No *inicio, int *valor) {
    if (inicio == NULL) {
        return NULL;
    }
    if (inicio->prox == NULL) { // um nó só: a lista fica vazia
        *valor = inicio->valor;
        free(inicio);
        return NULL;
    }
    No *p = inicio;
    while (p->prox->prox != NULL) { // para no penúltimo
        p = p->prox;
    }
    *valor = p->prox->valor;
    free(p->prox);
    p->prox = NULL; // o penúltimo vira o último
    return inicio;
}

int main(void) {
    int vagoes[3] = {1, 2, 3};
    No *trem = de_vetor(vagoes, 3);
    printf("Trem: ");
    imprime(trem);
    while (trem != NULL) {
        int v;
        trem = remove_ultimo(trem, &v);
        printf("Saiu %d: ", v);
        imprime(trem);
    }
    return 0;
}
