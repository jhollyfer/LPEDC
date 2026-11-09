// Lista · Módulo 15 · Tabelas hash
// Exercício P1528 · ★★★ · A teoria do fator de carga, medida

#include <stdio.h>

#define M 1009
#define VAZIO -1

unsigned long long semente = 2026;

// gerador congruente linear próprio: a mesma sequência em qualquer máquina
int sorteia(void) {
    semente = (semente * 1103515245ULL + 12345ULL) % 2147483648ULL;
    return (int)(semente % 1000000);
}

int linear(int k, int i) {
    return (k % M + i) % M;
}

int dupla(int k, int i) {
    return (k % M + i * (1 + k % (M - 1))) % M;
}

// enche até n = alfa * M e mede a média de sondagens das buscas sem sucesso
double mede(int (*sonda)(int, int), double alfa) {
    int t[M];
    for (int i = 0; i < M; i++) {
        t[i] = VAZIO;
    }
    semente = 2026;
    int n = (int)(alfa * M);
    for (int c = 0; c < n; c++) {
        int k = sorteia();
        for (int i = 0; i < M; i++) {
            int pos = sonda(k, i);
            if (t[pos] == VAZIO) {
                t[pos] = k;
                break;
            }
        }
    }
    long total = 0;
    for (int c = 0; c < 2000; c++) {
        int k = 1000000 + sorteia(); // chaves que nunca foram inseridas
        for (int i = 0; i < M; i++) {
            total++;
            if (t[sonda(k, i)] == VAZIO) {
                break;
            }
        }
    }
    return (double)total / 2000;
}

int main(void) {
    double alfas[] = {0.5, 0.75, 0.9};
    printf("alfa  linear (teoria)   dupla (teoria)\n");
    for (int a = 0; a < 3; a++) {
        double x = alfas[a];
        double teoria_linear = (1 + 1 / ((1 - x) * (1 - x))) / 2;
        double teoria_uniforme = 1 / (1 - x);
        printf("%.2f  %5.2f (%5.2f)     %5.2f (%5.2f)\n", x, mede(linear, x), teoria_linear, mede(dupla, x), teoria_uniforme);
    }
    return 0;
}
