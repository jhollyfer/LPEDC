// 0095 · Busca binária
// Exercício E570 · ★★★

#include <stdio.h>

// maior lado L com L * L <= area. Busca binária na RESPOSTA:
// o "vetor" é 0, 1, 2, ..., e a pergunta "L * L <= area?" é sim, sim, ..., não, não.
long long maior_lado(long long area, int *voltas) {
    long long ini = 0, fim = area;   // a resposta está em [ini, fim]
    *voltas = 0;
    while (ini < fim) {
        long long meio = ini + (fim - ini + 1) / 2; // arredonda para cima
        (*voltas)++;
        if (meio * meio <= area) {
            ini = meio;              // meio serve; talvez um maior sirva
        } else {
            fim = meio - 1;          // meio é grande demais
        }
    }
    return ini;
}

int main(void) {
    long long areas[] = {50, 1000000, 2147395600, 2147483647};
    int voltas;

    for (int k = 0; k < 4; k++) {
        long long lado = maior_lado(areas[k], &voltas);
        printf("%lld m²: lado %lld m (%d voltas)\n", areas[k], lado, voltas);
    }
    return 0;
}
