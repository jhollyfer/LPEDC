// 0117 · Limite inferior da ordenação
// Exercício E699 · ★★☆

#include <stdio.h>

int comparacoes = 0;

int menor(int a, int b) {
    comparacoes++;
    return a < b;
}

// cada elemento contra o mínimo e contra o máximo: 2(n - 1)
void ingenuo(const int v[], int n, int *mn, int *mx) {
    *mn = *mx = v[0];
    for (int i = 1; i < n; i++) {
        if (menor(v[i], *mn)) {
            *mn = v[i];
        }
        if (menor(*mx, v[i])) {
            *mx = v[i];
        }
    }
}

// de dois em dois: o menor do par disputa o mínimo, o maior disputa o máximo
void pares(const int v[], int n, int *mn, int *mx) {
    int i;
    if (n % 2 == 1) {
        *mn = *mx = v[0];             // ímpar: o primeiro começa sozinho
        i = 1;
    } else {
        if (menor(v[0], v[1])) {
            *mn = v[0];
            *mx = v[1];
        } else {
            *mn = v[1];
            *mx = v[0];
        }
        i = 2;
    }
    for (; i + 1 < n; i += 2) {
        int a = v[i], b = v[i + 1];
        if (menor(b, a)) {            // 1 comparação dentro do par
            int t = a;
            a = b;
            b = t;
        }
        if (menor(a, *mn)) { // 1 com o mínimo
            *mn = a;
        }
        if (menor(*mx, b)) { // 1 com o máximo
            *mx = b;
        }
    }
}

void testa(const int v[], int n) {
    int mn, mx;
    comparacoes = 0;
    ingenuo(v, n, &mn, &mx);
    int c1 = comparacoes;
    comparacoes = 0;
    pares(v, n, &mn, &mx);
    printf("%d dias: mín %d, máx %d | ingênuo %d comparações | pares %d\n", n, mn, mx, c1, comparacoes);
}

int main(void) {
    int temp[11] = {23, 31, 18, 27, 35, 22, 19, 30, 26, 21, 33};
    testa(temp, 10);
    testa(temp, 11);
    return 0;
}
