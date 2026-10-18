// 0073 · Invariantes de laço e corretude
// Exercício E436 · ★★☆

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// true se x está em v[0..i-1] e ninguém passa dele.
bool eh_maximo(const int v[], int i, int x) {
    bool esta = false;
    for (int k = 0; k < i; k++) {
        if (v[k] > x) {
            return false;
        }
        if (v[k] == x) {
            esta = true;
        }
    }
    return esta;
}

// Recebe n >= 1 e v; devolve o valor de um elemento máximo de v[0..n-1].
int maximo(const int v[], int n) {
    int maior = v[0];
    for (int i = 1; i < n; i++) {
        // invariante: maior é um máximo de v[0..i-1]
        assert(eh_maximo(v, i, maior));
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    assert(eh_maximo(v, n, maior));
    return maior;
}

int main(void) {
    int saldos[4] = {-120, -45, -300, -80};
    int um[1] = {-7};
    int positivos[3] = {10, 3, 25};

    printf("Maior saldo: R$ %d\n", maximo(saldos, 4));
    printf("Um saldo só: R$ %d\n", maximo(um, 1));
    printf("Positivos: R$ %d\n", maximo(positivos, 3));
    return 0;
}
