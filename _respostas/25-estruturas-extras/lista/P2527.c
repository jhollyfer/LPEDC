// Lista · Módulo 25 · Estruturas especiais
// Exercício P2527 · ★★★ · A tabela de símbolos que aprende

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BALDES 5
#define N 12

typedef struct No {
    char nome[12];
    struct No *prox;
} No;

const char *nomes[N] = {"total", "soma", "media", "n", "vetor", "aux", "maior", "menor", "k", "x", "i", "j"};
const char *usos[] = {"i", "j", "i", "soma", "i", "j", "i", "j", "k", "i", "j", "i",
                      "soma", "i", "j", "i", "total", "i", "j", "i"};

int h(const char *s) {
    int soma = 0;
    for (; *s; s++) soma += (unsigned char)*s;
    return soma % BALDES;
}

void monta(No *balde[]) {
    for (int b = 0; b < BALDES; b++) balde[b] = NULL;
    for (int k = 0; k < N; k++) { // cada nome entra no FIM do seu balde
        No **p = &balde[h(nomes[k])];
        while (*p != NULL) p = &(*p)->prox;
        *p = malloc(sizeof(No));
        if (*p == NULL) exit(1);
        strcpy((*p)->nome, nomes[k]);
        (*p)->prox = NULL;
    }
}

int procura(No *balde[], const char *nome, int mtf) {
    No **p = &balde[h(nome)];
    int custo = 0;
    while (*p != NULL) {
        custo++;
        if (strcmp((*p)->nome, nome) == 0) {
            if (mtf && p != &balde[h(nome)]) { // tira do lugar e põe no começo do balde
                No *x = *p;
                *p = x->prox;
                x->prox = balde[h(nome)];
                balde[h(nome)] = x;
            }
            return custo;
        }
        p = &(*p)->prox;
    }
    return custo;
}

void mostra(No *balde[]) {
    for (int b = 0; b < BALDES; b++) {
        printf("  balde %d:", b);
        for (No *x = balde[b]; x != NULL; x = x->prox) printf(" %s", x->nome);
        printf("\n");
    }
}

void libera(No *balde[]) {
    for (int b = 0; b < BALDES; b++)
        while (balde[b] != NULL) {
            No *x = balde[b];
            balde[b] = x->prox;
            free(x);
        }
}

int main(void) {
    int u = (int)(sizeof usos / sizeof usos[0]);
    for (int mtf = 0; mtf <= 1; mtf++) {
        No *balde[BALDES];
        monta(balde);
        if (!mtf) {
            printf("Baldes no começo:\n");
            mostra(balde);
        }
        int total = 0;
        for (int k = 0; k < u; k++) total += procura(balde, usos[k], mtf);
        printf("%s: %d comparações em %d buscas\n", mtf ? "Com mover para a frente" : "Lista fixa", total, u);
        if (mtf) {
            printf("Baldes no fim:\n");
            mostra(balde);
        }
        libera(balde);
    }
    return 0;
}
