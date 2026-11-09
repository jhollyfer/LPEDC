// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0530 · ★★★ · O fatorial que não cabe no long long

#include <stdio.h>

#define MAX 60

void multiplicar(int d[], int tam[1], int k) {
    int vai = 0;
    for (int i = 0; i < tam[0]; i++) {
        int x = d[i] * k + vai;
        d[i] = x % 10;
        vai = x / 10;
    }
    while (vai > 0 && tam[0] < MAX) { // o que sobrou vira dígitos novos
        d[tam[0]] = vai % 10;
        tam[0]++;
        vai /= 10;
    }
}

void mostrar(int n, const int d[], int tam) {
    printf("%2d! = ", n);
    for (int i = tam - 1; i >= 0; i--) {
        printf("%d", d[i]);
    }
    printf(" (%d dígitos)\n", tam);
}

int main(void) {
    int d[MAX] = {1};
    int tam[1] = {1};

    for (int k = 2; k <= 30; k++) {
        multiplicar(d, tam, k);
        if (k == 10 || k == 20 || k == 25 || k == 30) {
            mostrar(k, d, tam[0]);
        }
    }
    return 0;
}
