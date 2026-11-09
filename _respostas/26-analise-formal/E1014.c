// 0169 · Juntando tudo: passos e bytes conferidos
// Exercício E1014 · ★★★

#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define Q 1000

unsigned semente = 99;

int sorteia(int limite) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente / 65536u) % (unsigned)limite);
}

int main(void) {
    static int vendas[N];
    for (int d = 0; d < N; d++) {
        vendas[d] = 100 + sorteia(900); // vendas do dia, em reais
    }
    int ini[Q], fim[Q];
    for (int q = 0; q < Q; q++) {
        int a = sorteia(N), b = sorteia(N);
        ini[q] = a < b ? a : b;
        fim[q] = a < b ? b : a;
    }

    // jeito 1: soma o intervalo a cada pergunta; Θ(n·q) tempo, Θ(1) espaço
    long passos1 = 0, total1 = 0;
    for (int q = 0; q < Q; q++) {
        for (int d = ini[q]; d <= fim[q]; d++) {
            passos1++;
            total1 += vendas[d];
        }
    }

    // jeito 2: prefixo[k] = soma dos k primeiros dias; Θ(n + q), Θ(n) espaço
    long passos2 = 0, total2 = 0;
    long *prefixo = malloc((N + 1) * sizeof(long));
    if (prefixo == NULL) {
        return 1;
    }
    prefixo[0] = 0;
    for (int d = 0; d < N; d++) {
        passos2++;
        prefixo[d + 1] = prefixo[d] + vendas[d];
    }
    for (int q = 0; q < Q; q++) {
        passos2++;
        total2 += prefixo[fim[q] + 1] - prefixo[ini[q]];
    }
    free(prefixo);

    printf("sem prefixos: %7ld passos, %5d bytes, total %ld\n", passos1, 0, total1);
    printf("com prefixos: %7ld passos, %5zu bytes, total %ld\n", passos2,
           (N + 1) * sizeof(long), total2);
    return 0;
}
