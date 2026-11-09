// Lista · Módulo 25 · Estruturas especiais
// Exercício P2512 · ★★☆ · Amigos em comum

#include <stdio.h>
#include <stdlib.h>

#define V 8

typedef struct Celula {
    int col;
    struct Celula *prox;
} Celula;

const char *nomes[V] = {"Ana", "Beto", "Caio", "Duda", "Edu", "Fábio", "Gabi", "Hugo"};
Celula *linha[V]; // linha[i]: os amigos de i, em ordem de índice

void liga_um(int i, int j) {
    Celula **p = &linha[i];
    while (*p != NULL && (*p)->col < j) p = &(*p)->prox;
    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) exit(1);
    nova->col = j;
    nova->prox = *p;
    *p = nova;
}

void amizade(int a, int b) {
    liga_um(a, b);
    liga_um(b, a);
}

int grau(int i) {
    int g = 0;
    for (Celula *c = linha[i]; c != NULL; c = c->prox) g++;
    return g;
}

// as duas listas estão em ordem: anda nelas como no merge
int em_comum(int a, int b) {
    int n = 0;
    Celula *x = linha[a], *y = linha[b];
    printf("%s e %s:", nomes[a], nomes[b]);
    while (x != NULL && y != NULL) {
        if (x->col < y->col) x = x->prox;
        else if (x->col > y->col) y = y->prox;
        else {
            printf(" %s", nomes[x->col]);
            n++;
            x = x->prox;
            y = y->prox;
        }
    }
    printf(" (%d em comum)\n", n);
    return n;
}

int main(void) {
    int pares[][2] = {{0, 1}, {0, 2}, {0, 4}, {1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 4}, {4, 7}, {5, 7}, {1, 4}};
    for (int k = 0; k < 11; k++) amizade(pares[k][0], pares[k][1]);
    int celulas = 0;
    for (int i = 0; i < V; i++) {
        printf("%s (%d):", nomes[i], grau(i));
        for (Celula *c = linha[i]; c != NULL; c = c->prox) printf(" %s", nomes[c->col]);
        printf("\n");
        celulas += grau(i);
    }
    printf("Células: %d de %d\n", celulas, V * V);
    em_comum(0, 1);
    em_comum(2, 7);
    em_comum(3, 6);
    for (int i = 0; i < V; i++)
        while (linha[i] != NULL) {
            Celula *c = linha[i];
            linha[i] = c->prox;
            free(c);
        }
    return 0;
}
