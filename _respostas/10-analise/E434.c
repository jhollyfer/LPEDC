// 0073 · Invariantes de laço e corretude
// Exercício E434 · ★☆☆
//
// Resposta: Total: R$ 132. Invariante: s é a soma de v[0..i-1].

#include <assert.h>
#include <stdio.h>

// Devolve a soma de v[0..i-1], recalculando tudo (só para conferir).
int soma_ate(const int v[], int i) {
    int s = 0;
    for (int k = 0; k < i; k++) {
        s += v[k];
    }
    return s;
}

// Recebe n >= 0 e v; devolve a soma de v[0..n-1].
int soma(const int v[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        // invariante: s é a soma de v[0..i-1]
        assert(s == soma_ate(v, i));
        s += v[i];
    }
    assert(s == soma_ate(v, n));
    return s;
}

int main(void) {
    int vendas[5] = {35, 12, 50, 8, 27};

    printf("Total: R$ %d\n", soma(vendas, 5));
    return 0;
}
