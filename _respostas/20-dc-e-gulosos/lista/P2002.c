// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2002 · ★☆☆ · Maior e menor temperatura, dividindo ao meio

#include <stdio.h>

#define N 8

int comps = 0;

void extremos(const int v[], int ini, int fim, int *menor, int *maior) {
    if (ini == fim) {
        *menor = *maior = v[ini];
        return;
    }
    if (fim == ini + 1) {
        comps++;
        if (v[ini] < v[fim]) {
            *menor = v[ini];
            *maior = v[fim];
        } else {
            *menor = v[fim];
            *maior = v[ini];
        }
        return;
    }
    int meio = ini + (fim - ini) / 2;
    int me1, ma1, me2, ma2;
    extremos(v, ini, meio, &me1, &ma1);
    extremos(v, meio + 1, fim, &me2, &ma2);
    comps++;
    *menor = me1 < me2 ? me1 : me2;
    comps++;
    *maior = ma1 > ma2 ? ma1 : ma2;
}

int main(void) {
    const int temp[N] = {31, 34, 29, 36, 33, 30, 35, 32};
    int menor, maior;
    extremos(temp, 0, N - 1, &menor, &maior);
    printf("Menor: %d graus\n", menor);
    printf("Maior: %d graus\n", maior);
    printf("Comparações: %d\n", comps);
    return 0;
}
