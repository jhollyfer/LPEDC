// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1723 · ★★★ · Stooge sort: correto, recursivo e pior que o bubble

#include <math.h>
#include <stdio.h>

#define MAX 640

int voltas[MAX];
long chamadas;
int prof_max;

void stooge(int v[], int i, int j, int prof) {
    chamadas++;
    if (prof > prof_max) prof_max = prof;
    if (v[i] > v[j]) {
        int t = v[i];
        v[i] = v[j];
        v[j] = t;
    }
    if (j - i + 1 >= 3) {
        int t = (j - i + 1) / 3;
        stooge(v, i, j - t, prof + 1); // primeiros 2/3
        stooge(v, i + t, j, prof + 1); // últimos 2/3
        stooge(v, i, j - t, prof + 1); // primeiros 2/3 de novo
    }
}

int main(void) {
    for (int i = 0; i < MAX; i++) voltas[i] = 40000 + (i * 7919) % 5003; // milissegundos

    long c10 = 0;
    printf("  n  chamadas  ordenado  prof  log1.5(n)  bubble\n");
    for (int n = 10; n <= MAX; n *= 2) {
        static int v[MAX];
        for (int i = 0; i < n; i++) v[i] = voltas[i];
        chamadas = prof_max = 0;
        stooge(v, 0, n - 1, 1);
        int ok = 1;
        for (int i = 1; i < n; i++)
            if (v[i - 1] > v[i]) ok = 0;
        printf("%3d %9ld %9s %5d %10.2f %7d\n", n, chamadas, ok ? "sim" : "não", prof_max,
               log(n) / log(1.5), n * (n - 1) / 2);
        if (n == 10) c10 = chamadas;
    }
    printf("Expoente estimado: %.3f | teoria log(3) / log(1,5) = %.4f\n",
           log((double)chamadas / c10) / log(64.0), log(3.0) / log(1.5));
    return 0;
}
