// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1701 · ★☆☆ · O faturamento somado pelas metades

#include <stdio.h>

#define DIAS 100

int fat[DIAS];
long chamadas;

long soma(const int v[], int ini, int fim) {
    chamadas++;
    if (ini == fim) return v[ini]; // um dia só
    int meio = (ini + fim) / 2;
    return soma(v, ini, meio) + soma(v, meio + 1, fim);
}

int main(void) {
    for (int i = 0; i < DIAS; i++) fat[i] = 900 + (i % 7) * 50; // sábado vende mais

    int ns[] = {1, 2, 3, 4, 10, 16, 64, 100};
    printf("  n       soma  chamadas  2n-1\n");
    for (int k = 0; k < 8; k++) {
        int n = ns[k];
        chamadas = 0;
        long s = soma(fat, 0, n - 1);
        printf("%3d %10ld %9ld %5d\n", n, s, chamadas, 2 * n - 1);
    }
    return 0;
}
