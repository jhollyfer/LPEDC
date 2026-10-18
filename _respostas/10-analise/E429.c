// 0072 · Notação O: como o custo cresce
// Exercício E429 · ★★☆
//
// Resposta: n = 100: pares 4950, marcas 100; n = 1000: pares 499500, marcas 1000.

#include <stdbool.h>
#include <stdio.h>

long passos_pares = 0;
long passos_marcas = 0;

bool repetido_pares(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            passos_pares++;
            if (v[i] == v[j]) {
                return true;
            }
        }
    }
    return false;
}

bool repetido_marcas(const int v[], int n) {
    bool visto[1000] = {false};
    for (int i = 0; i < n; i++) {
        passos_marcas++;
        if (visto[v[i]]) {
            return true;
        }
        visto[v[i]] = true;
    }
    return false;
}

int main(void) {
    int v[1000];
    int tamanhos[2] = {100, 1000};

    for (int k = 0; k < 2; k++) {
        int n = tamanhos[k];
        for (int i = 0; i < n; i++) {
            v[i] = (i * 37) % 1000;
        }
        passos_pares = 0;
        passos_marcas = 0;
        bool a = repetido_pares(v, n);
        bool b = repetido_marcas(v, n);
        if (a || b) {
            printf("achou repetido?!\n");
        }
        printf("n = %4d: pares %6ld passos, marcas %4ld passos\n", n, passos_pares, passos_marcas);
    }
    return 0;
}
