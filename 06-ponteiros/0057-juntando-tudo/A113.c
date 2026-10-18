// A113 · O ranking da feira

#include <stdio.h>
#include <stdlib.h>

#define N 4

// devolve dois resultados: o total (double *) e ONDE está o maior (const double **)
void resumo(const double *v, int n, double *total, const double **maior) {
    *total = 0;
    *maior = v;
    for (const double *p = v; p < v + n; p++) {
        *total += *p;
        if (*p > **maior) {
            *maior = p;
        }
    }
}

// cada elemento de ordem é um const double *; o qsort entrega o ENDEREÇO dele
int maior_primeiro(const void *a, const void *b) {
    double x = **(const double * const *)a;
    double y = **(const double * const *)b;
    return (x < y) - (x > y); // decrescente
}

int main(void) {
    const char *produtos[N] = {"tomate", "alface", "queijo", "pastel"};
    int qtd[N] = {30, 45, 8, 60};
    double preco[N] = {6.50, 3.00, 32.00, 9.00};
    double fat[N];               // faturamento de cada barraca
    const double *ordem[N];      // ponteiros para fat: é isso que vamos ordenar

    for (int i = 0; i < N; i++) {
        fat[i] = qtd[i] * preco[i];
        ordem[i] = &fat[i];
    }
    qsort(ordem, N, sizeof ordem[0], maior_primeiro); // fat continua intacto

    for (int i = 0; i < N; i++) {
        int k = (int)(ordem[i] - fat); // ponteiro - início = índice do produto
        printf("%dº %-7s R$ %7.2f\n", i + 1, produtos[k], *ordem[i]);
    }

    double total;
    const double *maior;
    resumo(fat, N, &total, &maior);
    printf("Total: R$ %.2f  Campeão: %s\n", total, produtos[maior - fat]);
    return 0;
}
// Saída:
// 1º pastel  R$  540.00
// 2º queijo  R$  256.00
// 3º tomate  R$  195.00
// 4º alface  R$  135.00
// Total: R$ 1126.00  Campeão: pastel
