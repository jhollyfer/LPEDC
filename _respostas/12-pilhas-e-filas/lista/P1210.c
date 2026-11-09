// Lista · Módulo 12 · Pilhas e filas
// Exercício P1210 · ★☆☆ · Copiar a pilha sem virar de cabeça para baixo

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

void empilha(No **topo, int x) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = x;
    novo->prox = *topo;
    *topo = novo;
}

bool desempilha(No **topo, int *x) {
    if (*topo == NULL) {
        return false;
    }
    No *velho = *topo;
    *x = velho->valor;
    *topo = velho->prox;
    free(velho);
    return true;
}

bool vazia(const No *topo) {
    return topo == NULL;
}

void mostra(const char *rotulo, const No *topo) {
    printf("%s", rotulo);
    for (const No *p = topo; p != NULL; p = p->prox) {
        printf(" %d", p->valor);
    }
    printf("\n");
}

No *copia(No **original) {
    No *aux = NULL, *nova = NULL;
    int x;
    while (desempilha(original, &x)) { // aux fica invertida
        empilha(&aux, x);
    }
    while (desempilha(&aux, &x)) { // desinverte nas duas
        empilha(original, x);
        empilha(&nova, x);
    }
    return nova;
}

int main(void) {
    No *original = NULL;
    empilha(&original, 10);
    empilha(&original, 20);
    empilha(&original, 30);
    mostra("original (topo primeiro):", original);

    No *c = copia(&original);
    mostra("cópia (topo primeiro):   ", c);
    printf("desempilhando a cópia:");
    int x;
    while (!vazia(c) && desempilha(&c, &x)) {
        printf(" %d", x);
    }
    printf("\n");
    mostra("original depois:         ", original);

    while (desempilha(&original, &x)) {
    }
    return 0;
}
