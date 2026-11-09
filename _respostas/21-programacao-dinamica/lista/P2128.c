// Lista · Módulo 21 · Programação dinâmica
// Exercício P2128 · ★★★ · As reservas que dão mais dinheiro

#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef struct {
    char nome;
    int ini, fim, valor;
} Pedido;

int por_fim(const void *a, const void *b) {
    const Pedido *x = a, *y = b;
    return x->fim - y->fim;
}

int main(void) {
    Pedido p[N + 1] = {{' ', 0, 0, 0},
                       {'A', 8, 11, 400}, {'B', 9, 13, 700}, {'C', 10, 12, 300}, {'D', 11, 15, 600},
                       {'E', 12, 16, 500}, {'F', 14, 18, 1500}, {'G', 15, 20, 900}, {'H', 17, 22, 450}};
    qsort(p + 1, N, sizeof p[0], por_fim);
    int ant[N + 1], melhor[N + 1];
    melhor[0] = 0;
    for (int j = 1; j <= N; j++) {
        int ini = 1, fim = j - 1, r = 0;
        while (ini <= fim) {
            int meio = ini + (fim - ini) / 2;
            if (p[meio].fim <= p[j].ini) {
                r = meio;
                ini = meio + 1;
            } else {
                fim = meio - 1;
            }
        }
        ant[j] = r;
        int com = p[j].valor + melhor[ant[j]];
        melhor[j] = com > melhor[j - 1] ? com : melhor[j - 1];
    }
    printf("Faturamento máximo: R$ %d\n", melhor[N]);
    char aceitos[N];
    int na = 0;
    for (int j = N; j > 0;) {
        if (p[j].valor + melhor[ant[j]] >= melhor[j - 1]) {
            aceitos[na++] = p[j].nome;
            j = ant[j];
        } else {
            j--;
        }
    }
    printf("Pedidos:");
    for (int k = na - 1; k >= 0; k--) {
        printf(" %c", aceitos[k]);
    }
    printf("\n");
    return 0;
}
