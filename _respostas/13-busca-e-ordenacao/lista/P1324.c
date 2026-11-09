// Lista · Módulo 13 · Busca e ordenação
// Exercício P1324 · ★★★ · O quick sort com dois defeitos
//
// Resposta: (1) o for parava em j < r - 1 e nunca olhava o v[r - 1], o
// vizinho do pivô; o certo é j < r. (2) faltava a troca final, que leva o
// pivô de v[r] para v[i + 1]; sem ela, a função devolve i + 1 como se o pivô
// estivesse lá, mas ele continua no fim.

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particiona(int v[], int p, int r) {
    int pivo = v[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (v[j] <= pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[r]);
    return i + 1;
}

void quick(int v[], int p, int r) {
    if (p < r) {
        int q = particiona(v, p, r);
        quick(v, p, q - 1);
        quick(v, q + 1, r);
    }
}

int main(void) {
    int corridas[] = {23, 8, 41, 15, 4, 36, 19, 2, 30};
    int n = 9;

    quick(corridas, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf(" %d", corridas[i]);
    }
    printf("\n");
    return 0;
}
