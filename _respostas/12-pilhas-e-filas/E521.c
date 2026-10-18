// 0087 · Deque
// Exercício E521 · ★★★

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
    int valor;
    struct nod *ant;
    struct nod *prox;
} NoD;

typedef struct {
    NoD *inicio;
    NoD *fim;
} DequeLista;

static NoD *novo_no(int valor) {
    NoD *n = malloc(sizeof *n);
    if (n != NULL) {
        n->valor = valor;
        n->ant = NULL;
        n->prox = NULL;
    }
    return n;
}

bool dl_insere_inicio(DequeLista *d, int valor) {
    NoD *novo = novo_no(valor);
    if (novo == NULL) {
        return false;
    }
    novo->prox = d->inicio;
    if (d->inicio == NULL) {
        d->fim = novo; // estava vazio
    } else {
        d->inicio->ant = novo;
    }
    d->inicio = novo;
    return true;
}

bool dl_insere_fim(DequeLista *d, int valor) {
    NoD *novo = novo_no(valor);
    if (novo == NULL) {
        return false;
    }
    novo->ant = d->fim;
    if (d->fim == NULL) {
        d->inicio = novo;
    } else {
        d->fim->prox = novo;
    }
    d->fim = novo;
    return true;
}

bool dl_retira_inicio(DequeLista *d, int *valor) {
    if (d->inicio == NULL) {
        return false;
    }
    NoD *velho = d->inicio;
    *valor = velho->valor;
    d->inicio = velho->prox;
    if (d->inicio == NULL) {
        d->fim = NULL; // esvaziou
    } else {
        d->inicio->ant = NULL;
    }
    free(velho);
    return true;
}

bool dl_retira_fim(DequeLista *d, int *valor) {
    if (d->fim == NULL) {
        return false;
    }
    NoD *velho = d->fim;
    *valor = velho->valor;
    d->fim = velho->ant; // o penúltimo: é por isso que a lista é dupla
    if (d->fim == NULL) {
        d->inicio = NULL;
    } else {
        d->fim->prox = NULL;
    }
    free(velho);
    return true;
}

void dl_libera(DequeLista *d) {
    while (d->inicio != NULL) {
        NoD *prox = d->inicio->prox;
        free(d->inicio);
        d->inicio = prox;
    }
    d->fim = NULL;
}

int main(void) {
    DequeLista fila = {NULL, NULL};
    int faixa;

    dl_insere_fim(&fila, 5);
    dl_insere_fim(&fila, 8);
    dl_insere_fim(&fila, 3);
    dl_insere_inicio(&fila, 11);

    if (dl_retira_inicio(&fila, &faixa)) {
        printf("Tocando a faixa %d\n", faixa);
    }
    if (dl_retira_fim(&fila, &faixa)) {
        printf("Removida a faixa %d\n", faixa);
    }
    printf("Ainda na fila:");
    while (dl_retira_inicio(&fila, &faixa)) {
        printf(" %d", faixa);
    }
    printf("\n");
    dl_libera(&fila);
    return 0;
}
