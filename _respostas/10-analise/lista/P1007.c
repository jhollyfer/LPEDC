// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1007 · ★☆☆ · O caixa que o invariante dedurou

#include <assert.h>
#include <stdio.h>

// soma de v[0..k-1], do jeito mais simples (só para conferir)
int soma_ate(const int v[], int k) {
    int s = 0;
    for (int j = 0; j < k; j++) {
        s += v[j];
    }
    return s;
}

int soma(const int v[], int n) {
    int s = 0;
    int i;
    for (i = 0; i < n; i++) { // começa na primeira venda
        assert(s == soma_ate(v, i)); // invariante
        s += v[i];
    }
    assert(s == soma_ate(v, n)); // término
    return s;
}

int main(void) {
    int vendas[4] = {45, 30, 62, 50};
    int total = soma(vendas, 4);
    printf("Caixa do dia: R$ %d\n", total);
    printf("Média por venda: R$ %.2f\n", total / 4.0);
    return 0;
}
