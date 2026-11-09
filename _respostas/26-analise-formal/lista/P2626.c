// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2626 · ★★★ · Mesma soma, pilha menor

#include <stdio.h>

#define N 100000

long chamadas = 0;
int prof = 0, prof_max = 0;

void entra(void) {
    chamadas++;
    prof++;
    if (prof > prof_max) {
        prof_max = prof;
    }
}

long soma(const int v[], int n) {
    entra();
    long r = (n == 0) ? 0 : v[n - 1] + soma(v, n - 1);
    prof--;
    return r;
}

long soma_meio(const int v[], int ini, int fim) {
    entra();
    long r;
    if (fim - ini == 0) {
        r = 0;
    } else if (fim - ini == 1) {
        r = v[ini];
    } else {
        int meio = ini + (fim - ini) / 2;
        r = soma_meio(v, ini, meio) + soma_meio(v, meio, fim);
    }
    prof--;
    return r;
}

int main(void) {
    static int consumo[N];
    for (int i = 0; i < N; i++) {
        consumo[i] = i % 50 + 100;
    }
    chamadas = 0;
    prof_max = 0;
    long a = soma(consumo, N);
    printf("linear: soma %ld, %6ld chamadas, profundidade %d\n", a, chamadas, prof_max);
    chamadas = 0;
    prof_max = 0;
    long b = soma_meio(consumo, 0, N);
    printf("metade: soma %ld, %6ld chamadas, profundidade %d\n", b, chamadas, prof_max);
    return 0;
}
