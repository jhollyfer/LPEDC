// 0073 · Invariantes de laço e corretude
// Exercício E433 · ★☆☆

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int soma_ate(const int v[], int i) {
    int s = 0;
    for (int k = 0; k < i; k++) {
        s += v[k];
    }
    return s;
}

int aprovados_ate(const int v[], int i) {
    int c = 0;
    for (int k = 0; k < i; k++) {
        if (v[k] >= 6) {
            c++;
        }
    }
    return c;
}

int potencia_de_2(int k) {
    int p = 1;
    for (int j = 0; j < k; j++) {
        p *= 2;
    }
    return p;
}

bool nao_esta(const int v[], int ini, int fim, int x) {
    for (int j = ini; j < fim; j++) {
        if (v[j] == x) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int gastos[4] = {20, 35, 15, 50};
    int notas[5] = {7, 4, 9, 6, 5};
    int e = 10;
    int v[5] = {3, 8, 5, 8, 1};
    int x = 8;

    // a) invariante: s é a soma de gastos[0..i-1]
    int s = 0;
    for (int i = 0; i < 4; i++) {
        assert(s == soma_ate(gastos, i));
        s = s + gastos[i];
    }
    assert(s == soma_ate(gastos, 4));
    printf("a) gastos: R$ %d\n", s);

    // b) invariante: c conta as notas >= 6 de notas[0..i-1]
    int c = 0;
    for (int i = 0; i < 5; i++) {
        assert(c == aprovados_ate(notas, i));
        if (notas[i] >= 6) {
            c++;
        }
    }
    assert(c == aprovados_ate(notas, 5));
    printf("b) aprovados: %d\n", c);

    // c) invariante: p é 2 elevado a k
    int p = 1;
    int k;
    for (k = 0; k < e; k++) {
        assert(p == potencia_de_2(k));
        p = p * 2;
    }
    assert(p == potencia_de_2(e));
    printf("c) 2 elevado a %d: %d\n", e, p);

    // d) invariante: x não está em v[k+1..n-1]
    int n = 5;
    k = n - 1;
    while (k >= 0 && v[k] != x) {
        assert(nao_esta(v, k + 1, n, x));
        k--;
    }
    assert(nao_esta(v, k + 1, n, x));
    assert(k == -1 || v[k] == x);
    printf("d) último %d na posição %d\n", x, k);
    return 0;
}
