// Lista · Módulo 11 · Listas
// Exercício P1105 · ★☆☆ · Engatar o trem da tarde no da manhã em O(1)

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct {
    No *inicio, *fim;
    int n;
} Lista;

void insere_fim(Lista *l, int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    if (l->fim == NULL) {
        l->inicio = novo;
    } else {
        l->fim->prox = novo;
    }
    l->fim = novo;
    l->n++;
}

void concatena(Lista *a, Lista *b) {
    if (b->inicio == NULL) {
        return;
    }
    if (a->inicio == NULL) {
        a->inicio = b->inicio;
    } else {
        a->fim->prox = b->inicio;
    }
    a->fim = b->fim;
    a->n += b->n;
    b->inicio = b->fim = NULL;
    b->n = 0;
}

void imprime(const char *rotulo, const Lista *l) {
    printf("%s: ", rotulo);
    for (const No *p = l->inicio; p != NULL; p = p->prox) {
        printf("%d -> ", p->valor);
    }
    printf("NULL (%d nós)\n", l->n);
}

void libera(Lista *l) {
    No *p = l->inicio;
    while (p != NULL) {
        No *seguinte = p->prox;
        free(p);
        p = seguinte;
    }
    l->inicio = l->fim = NULL;
    l->n = 0;
}

int main(void) {
    Lista a = {NULL, NULL, 0}, b = {NULL, NULL, 0};
    for (int v = 1; v <= 3; v++) {
        insere_fim(&a, v);
    }
    insere_fim(&b, 4);
    insere_fim(&b, 5);
    imprime("a", &a);
    imprime("b", &b);

    concatena(&a, &b);
    imprime("a depois", &a);
    imprime("b depois", &b);
    printf("último de a: %d\n", a.fim->valor);

    concatena(&a, &b);
    imprime("a com b vazia", &a);
    libera(&a);
    return 0;
}
