// 0117 · Limite inferior da ordenação
// Exercício E702 · ★★★

#include <stdio.h>

int comparacoes = 0;

int menor(int a, int b) {
    comparacoes++;
    return a < b;
}

// ordena 4 valores com no máximo 5 comparações
void ordena4(int v[]) {
    int lo1 = v[0], hi1 = v[1], lo2 = v[2], hi2 = v[3];
    if (menor(hi1, lo1)) {            // 1: o par (v0, v1)
        int t = lo1;
        lo1 = hi1;
        hi1 = t;
    }
    if (menor(hi2, lo2)) {            // 2: o par (v2, v3)
        int t = lo2;
        lo2 = hi2;
        hi2 = t;
    }
    int minimo, meio1, maximo, meio2;
    if (menor(lo1, lo2)) {            // 3: o menor dos menores é o mínimo
        minimo = lo1;
        meio1 = lo2;
    } else {
        minimo = lo2;
        meio1 = lo1;
    }
    if (menor(hi1, hi2)) {            // 4: o maior dos maiores é o máximo
        maximo = hi2;
        meio2 = hi1;
    } else {
        maximo = hi1;
        meio2 = hi2;
    }
    if (menor(meio2, meio1)) {        // 5: sobram dois no meio
        int t = meio1;
        meio1 = meio2;
        meio2 = t;
    }
    v[0] = minimo;
    v[1] = meio1;
    v[2] = meio2;
    v[3] = maximo;
}

int main(void) {
    int precos[4] = {10, 20, 30, 40};
    int testadas = 0, certas = 0, pior = 0;
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                for (int d = 0; d < 4; d++) {
                    if (a == b || a == c || a == d || b == c || b == d || c == d) {
                        continue;
                    }
                    int v[4] = {precos[a], precos[b], precos[c], precos[d]};
                    comparacoes = 0;
                    ordena4(v);
                    testadas++;
                    if (v[0] == 10 && v[1] == 20 && v[2] == 30 && v[3] == 40) {
                        certas++;
                    }
                    if (comparacoes > pior) {
                        pior = comparacoes;
                    }
                }
            }
        }
    }
    printf("%d ordens testadas, %d certas\n", testadas, certas);
    printf("pior caso: %d comparações (limite: 5)\n", pior);
    return 0;
}
