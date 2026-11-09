// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2011 · ★★☆ · Mínimo e máximo de dois em dois

#include <stdio.h>

#define N 10

int main(void) {
    const int t[N] = {1520, 1384, 1702, 1455, 1611, 1398, 1830, 1290, 1477, 1563};

    int comps = 0, menor = t[0], maior = t[0];
    for (int i = 1; i < N; i++) {
        comps++;
        if (t[i] < menor) {
            menor = t[i];
        }
        comps++;
        if (t[i] > maior) {
            maior = t[i];
        }
    }
    printf("Ingênuo: menor %d, maior %d, %d comparações\n", menor, maior, comps);

    comps = 1;
    if (t[0] < t[1]) {
        menor = t[0];
        maior = t[1];
    } else {
        menor = t[1];
        maior = t[0];
    }
    for (int i = 2; i + 1 < N; i += 2) {
        int a = t[i], b = t[i + 1];
        comps++;
        if (a > b) {
            int x = a;
            a = b;
            b = x;
        }
        comps++;
        if (a < menor) {
            menor = a;
        }
        comps++;
        if (b > maior) {
            maior = b;
        }
    }
    printf("Aos pares: menor %d, maior %d, %d comparações\n", menor, maior, comps);
    return 0;
}
