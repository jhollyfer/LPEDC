// 0134 · Seleção de intervalos
// Exercício E801 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ini, fim;
} Pedido;

int por_inicio(const void *a, const void *b) {
    const Pedido *x = a, *y = b;
    return (x->ini > y->ini) - (x->ini < y->ini);
}

int por_duracao(const void *a, const void *b) {
    const Pedido *x = a, *y = b;
    int dx = x->fim - x->ini, dy = y->fim - y->ini;
    return (dx > dy) - (dx < dy);
}

int por_fim(const void *a, const void *b) {
    const Pedido *x = a, *y = b;
    return (x->fim > y->fim) - (x->fim < y->fim);
}

// ordena uma cópia pelo critério dado e aceita quem não choca com os já
// aceitos (que podem estar antes OU depois, se o critério não for o fim)
int seleciona(const Pedido p[], int n, int (*criterio)(const void *, const void *)) {
    Pedido c[20], aceitos[20];
    int k = 0;
    memcpy(c, p, n * sizeof p[0]);
    qsort(c, n, sizeof c[0], criterio);
    for (int i = 0; i < n; i++) {
        int choca = 0;
        for (int j = 0; j < k; j++) {
            if (c[i].ini < aceitos[j].fim && aceitos[j].ini < c[i].fim) {
                choca = 1;
            }
        }
        if (!choca) {
            aceitos[k++] = c[i];
        }
    }
    return k;
}

int main(void) {
    Pedido p[] = {{0, 10}, {1, 4}, {4, 7}, {7, 10}, {3, 5}, {6, 8}, {10, 12}};
    int n = 7;
    printf("Começa primeiro: %d\n", seleciona(p, n, por_inicio));
    printf("Mais curto:      %d\n", seleciona(p, n, por_duracao));
    printf("Termina primeiro: %d\n", seleciona(p, n, por_fim));
    return 0;
}
