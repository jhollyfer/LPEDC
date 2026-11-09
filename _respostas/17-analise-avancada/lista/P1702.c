// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1702 · ★☆☆ · A maior nota dividindo a turma em três

#include <stdio.h>

#define N 243

int nota[N];
long chamadas;

int maior3(const int v[], int ini, int n) {
    chamadas++;
    if (n == 1) return v[ini];
    int t = n / 3;
    int a = maior3(v, ini, t), b = maior3(v, ini + t, t), c = maior3(v, ini + 2 * t, t);
    int m = a > b ? a : b;
    return m > c ? m : c;
}

int main(void) {
    for (int i = 0; i < N; i++) nota[i] = (i * 37 + 11) % 101; // notas de 0 a 100

    int ns[] = {1, 3, 9, 27, 81, 243};
    printf("  n  maior  chamadas  (3n-1)/2\n");
    for (int k = 0; k < 6; k++) {
        chamadas = 0;
        int m = maior3(nota, 0, ns[k]);
        printf("%3d %6d %9ld %9d\n", ns[k], m, chamadas, (3 * ns[k] - 1) / 2);
    }
    return 0;
}
