// Lista · Módulo 11 · Listas
// Exercício P1129 · ★★★ · Palíndromo com memória O(1)

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

No *inverte(No *inicio) {
    No *ant = NULL, *p = inicio;
    while (p != NULL) {
        No *seg = p->prox;
        p->prox = ant;
        ant = p;
        p = seg;
    }
    return ant;
}

bool palindromo(No *inicio) {
    if (inicio == NULL || inicio->prox == NULL) {
        return true;
    }
    No *lento = inicio, *rapido = inicio;
    while (rapido->prox != NULL && rapido->prox->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }
    No *segunda = inverte(lento->prox);
    bool igual = true;
    for (No *a = inicio, *b = segunda; b != NULL; a = a->prox, b = b->prox) {
        if (a->valor != b->valor) {
            igual = false;
            break;
        }
    }
    lento->prox = inverte(segunda); // devolve a lista como estava
    return igual;
}

void mostra(const No *inicio) {
    for (const No *p = inicio; p != NULL; p = p->prox) {
        printf(p == inicio ? "%d" : " %d", p->valor);
    }
}

void testa(const int v[], int n) {
    No *l = de_vetor(v, n);
    mostra(l);
    bool r = palindromo(l);
    printf(": %s | depois: ", r ? "sim" : "não");
    mostra(l);
    printf("\n");
    libera(l);
}

int main(void) {
    int a[5] = {1, 2, 3, 2, 1};
    int b[4] = {4, 7, 7, 4};
    int c[4] = {1, 2, 3, 1};
    int d[1] = {9};
    testa(a, 5);
    testa(b, 4);
    testa(c, 4);
    testa(d, 1);
    return 0;
}
