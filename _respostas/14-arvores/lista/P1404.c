// Lista · Módulo 14 · Árvores
// Exercício P1404 · ★☆☆ · A árvore genealógica, uma geração por linha

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char nome[10];
    struct No *esq, *dir;
} No;

No *novo(const char *nome, No *esq, No *dir) {
    No *p = malloc(sizeof(No));
    if (p == NULL) {
        exit(1);
    }
    snprintf(p->nome, sizeof p->nome, "%s", nome);
    p->esq = esq;
    p->dir = dir;
    return p;
}

void por_nivel(No *raiz) {
    No *fila[32];
    int ini = 0, fim = 0, nivel = 0;
    if (raiz == NULL) {
        return;
    }
    fila[fim++] = raiz;
    while (ini < fim) {
        int tamanho = fim - ini; // quantos estão neste nível
        printf("nível %d:", nivel);
        for (int k = 0; k < tamanho; k++) {
            No *p = fila[ini++];
            printf(" %s", p->nome);
            if (p->esq != NULL) {
                fila[fim++] = p->esq;
            }
            if (p->dir != NULL) {
                fila[fim++] = p->dir;
            }
        }
        printf("\n");
        nivel++;
    }
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    No *raiz = novo("Joana",
                    novo("Pedro", novo("Lara", NULL, NULL), novo("Davi", novo("Nina", NULL, NULL), NULL)),
                    novo("Carla", NULL, novo("Tomas", novo("Yuri", NULL, NULL), novo("Zoe", NULL, NULL))));

    por_nivel(raiz);
    libera(raiz);
    return 0;
}
