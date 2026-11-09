// Lista · Módulo 15 · Tabelas hash
// Exercício P1527 · ★★★ · Dispersão dupla com o tamanho errado

#include <stdio.h>

#define VAZIO -1

int sondagem(int k, int i, int m) {
    int h1 = k % m;
    int h2 = 1 + k % (m - 1);
    return (h1 + i * h2) % m;
}

// quantas posições diferentes a sequência de k visita em m tentativas
int visitadas(int k, int m) {
    int marcou[16] = {0}, total = 0;
    for (int i = 0; i < m; i++) {
        int pos = sondagem(k, i, m);
        if (!marcou[pos]) {
            marcou[pos] = 1;
            total++;
        }
    }
    return total;
}

void testa(int m, const int chaves[], int n) {
    int t[16];
    for (int i = 0; i < m; i++) {
        t[i] = VAZIO;
    }
    printf("m = %d:\n", m);
    for (int c = 0; c < n; c++) {
        int k = chaves[c], pos = -1;
        for (int i = 0; i < m && pos < 0; i++) {
            int p = sondagem(k, i, m);
            if (t[p] == VAZIO) {
                t[p] = k;
                pos = p;
            }
        }
        printf("  %d: h2 = %d, visita %d de %d posições, ", k, 1 + k % (m - 1), visitadas(k, m), m);
        if (pos >= 0) {
            printf("ficou na %d\n", pos);
        } else {
            printf("NÃO COUBE\n");
        }
    }
}

int main(void) {
    int chaves[] = {3, 19, 43, 99, 59, 27};
    testa(8, chaves, 6);
    testa(11, chaves, 6);
    return 0;
}
