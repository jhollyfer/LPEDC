// Lista · Módulo 13 · Busca e ordenação
// Exercício P1328 · ★★★ · Merge sort na lista encadeada

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

No *insere_inicio(No *lista, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->valor = valor;
    novo->prox = lista;
    return novo;
}

void mostra(const char *rotulo, const No *l) {
    printf("%s:", rotulo);
    for (; l != NULL; l = l->prox) {
        printf(" %d", l->valor);
    }
    printf("\n");
}

// corta a lista no meio (lento anda 1, rápido anda 2) e devolve a 2ª metade
No *divide(No *l) {
    No *lento = l, *rapido = l->prox;
    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }
    No *segunda = lento->prox;
    lento->prox = NULL;
    return segunda;
}

// intercala religando os nós: nenhum malloc
No *intercala(No *a, No *b) {
    No cabeca = {0, NULL};
    No *fim = &cabeca;
    while (a != NULL && b != NULL) {
        if (a->valor <= b->valor) {
            fim->prox = a;
            a = a->prox;
        } else {
            fim->prox = b;
            b = b->prox;
        }
        fim = fim->prox;
    }
    fim->prox = (a != NULL) ? a : b;
    return cabeca.prox;
}

No *merge_sort(No *l) {
    if (l == NULL || l->prox == NULL) {
        return l;
    }
    No *b = divide(l);
    return intercala(merge_sort(l), merge_sort(b));
}

void libera(No *l) {
    while (l != NULL) {
        No *prox = l->prox;
        free(l);
        l = prox;
    }
}

int main(void) {
    int pedidos[] = {58, 12, 97, 33, 12, 75, 4, 41, 66};
    No *lista = NULL;
    for (int i = 8; i >= 0; i--) {
        lista = insere_inicio(lista, pedidos[i]);
    }

    mostra("antes ", lista);
    lista = merge_sort(lista);
    mostra("depois", lista);
    libera(lista);
    return 0;
}
