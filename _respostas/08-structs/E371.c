// 0062 · Ponteiro para struct
// Exercício E371 · ★★★

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    double preco;
} Produto;

int main(void) {
    int n = 0;
    int cap = 2;
    Produto *v = malloc(cap * sizeof *v);
    if (v == NULL) {
        return 1;
    }

    Produto lido;
    while (scanf("%19s %lf", lido.nome, &lido.preco) == 2) {
        if (n == cap) {
            Produto *novo = realloc(v, 2 * cap * sizeof *v);
            if (novo == NULL) {
                free(v);
                return 1;
            }
            printf("capacidade: %d -> %d\n", cap, 2 * cap);
            v = novo;
            cap *= 2;
        }
        v[n++] = lido; // copia a struct inteira
    }

    double total = 0;
    printf("%d produtos:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  %-10s R$ %.2f\n", v[i].nome, v[i].preco);
        total += v[i].preco;
    }
    printf("Total: R$ %.2f\n", total);

    free(v);
    return 0;
}
