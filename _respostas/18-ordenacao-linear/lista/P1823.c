// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1823 · ★★★ · O ponto de encontro da turma: duas medianas

#include <stdio.h>
#include <stdlib.h>

#define N 9
#define L 21 // esquinas de 0 a 20

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int quickselect(const int orig[], int n, int pos) {
    int v[N];
    for (int i = 0; i < n; i++) v[i] = orig[i]; // cópia: o original fica intacto
    int ini = 0, fim = n - 1;
    for (;;) {
        int pivo = v[fim], i = ini;
        for (int j = ini; j < fim; j++)
            if (v[j] < pivo) troca(&v[i++], &v[j]);
        troca(&v[i], &v[fim]);
        if (i == pos) return v[i];
        if (pos < i) fim = i - 1;
        else ini = i + 1;
    }
}

int soma(const int x[], const int y[], int n, int px, int py) {
    int s = 0;
    for (int i = 0; i < n; i++) s += abs(x[i] - px) + abs(y[i] - py);
    return s;
}

int main(void) {
    int x[N] = {2, 6, 3, 7, 20, 5, 9, 6, 15};
    int y[N] = {4, 5, 9, 1, 18, 6, 3, 12, 5};

    int mx = quickselect(x, N, N / 2), my = quickselect(y, N, N / 2);
    printf("Medianas: (%d, %d), soma %d\n", mx, my, soma(x, y, N, mx, my));

    int sx = 0, sy = 0;
    for (int i = 0; i < N; i++) {
        sx += x[i];
        sy += y[i];
    }
    int cx = (2 * sx + N) / (2 * N), cy = (2 * sy + N) / (2 * N); // médias arredondadas
    printf("Centro de massa: (%d, %d), soma %d\n", cx, cy, soma(x, y, N, cx, cy));

    int bx = 0, by = 0;
    for (int px = 0; px < L; px++)
        for (int py = 0; py < L; py++)
            if (soma(x, y, N, px, py) < soma(x, y, N, bx, by)) {
                bx = px;
                by = py;
            }
    printf("Força bruta: (%d, %d), soma %d\n", bx, by, soma(x, y, N, bx, by));
    return 0;
}
