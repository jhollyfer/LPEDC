// 0122 · Bucket sort
// Exercício E731 · ★★★

#include <stdio.h>
#include <stdlib.h>

#define NB 10 // valores de R$ 0 a R$ 99: um balde para cada R$ 10

typedef struct {
    char cliente;
    int valor; // em reais
} Pedido;

typedef struct No {
    Pedido p;
    struct No *prox;
} No;

No *insere_ordenado(No *lista, Pedido x) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->p = x;
    if (lista == NULL || x.valor < lista->p.valor) {
        novo->prox = lista;
        return novo;
    }
    No *q = lista;
    while (q->prox != NULL && q->prox->p.valor <= x.valor) { // <= : estável
        q = q->prox;
    }
    novo->prox = q->prox;
    q->prox = novo;
    return lista;
}

void bucket_sort(Pedido v[], int n) {
    No *baldes[NB] = {NULL};
    for (int i = 0; i < n; i++) {
        int b = v[i].valor / 10;
        baldes[b] = insere_ordenado(baldes[b], v[i]);
    }
    int k = 0;                            // fora do laço: não volta a 0
    for (int b = 0; b < NB; b++) {
        while (baldes[b] != NULL) {
            No *q = baldes[b];
            v[k++] = q->p;
            baldes[b] = q->prox;
            free(q);
        }
    }
}

int main(void) {
    // pedidos da padaria, na ordem em que chegaram
    Pedido dia[] = {{'A', 35}, {'B', 12}, {'C', 35}, {'D', 87}, {'E', 12},
                    {'F', 50}, {'G', 38}, {'H', 35}, {'I', 9}};
    int n = 9;

    bucket_sort(dia, n);
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%c:%d" : " %c:%d", dia[i].cliente, dia[i].valor);
    }
    printf("\n");
    return 0;
}
