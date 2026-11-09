// Lista · Módulo 25 · Estruturas especiais
// Exercício P2506 · ★☆☆ · Quantos nós em cada andar

#include <stdio.h>

#define MAX 16
#define N 1000

unsigned semente = 2026;

int moeda(void) {
    semente = semente * 1103515245u + 12345u;
    return (semente >> 16) & 1;
}

int main(void) {
    int por_andar[MAX + 1] = {0}; // por_andar[a]: nós com exatamente a andares
    for (int i = 0; i < N; i++) {
        int andares = 1;
        while (andares < MAX && moeda() == 1) andares++;
        por_andar[andares]++;
    }
    int alcancam = N, ponteiros = 0;
    for (int a = 1; a <= MAX; a++) {
        if (alcancam == 0) break;
        printf("andar %2d: %4d nós (esperado %6.1f)\n", a - 1, alcancam, N / (double)(1 << (a - 1)));
        ponteiros += alcancam;
        alcancam -= por_andar[a];
    }
    printf("Ponteiros: %d (%.2f por nó)\n", ponteiros, ponteiros / (double)N);
    return 0;
}
