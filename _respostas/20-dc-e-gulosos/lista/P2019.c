// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2019 · ★★☆ · Rotas de ônibus com potência de matriz

#include <stdio.h>

#define T 4

typedef struct {
    long long m[T][T];
} Mat;

int produtos;

Mat multiplica(Mat a, Mat b) {
    produtos++;
    Mat r;
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            r.m[i][j] = 0;
            for (int k = 0; k < T; k++) {
                r.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return r;
}

Mat potencia(Mat a, int k) {
    if (k == 0) {
        Mat id = {{{0}}};
        for (int i = 0; i < T; i++) {
            id.m[i][i] = 1;
        }
        return id;
    }
    Mat meia = potencia(a, k / 2);
    Mat r = multiplica(meia, meia);
    if (k % 2 == 1) {
        r = multiplica(r, a);
    }
    return r;
}

int main(void) {
    const Mat a = {{{0, 1, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 0}}};
    const int ks[3] = {3, 6, 12};
    for (int i = 0; i < 3; i++) {
        produtos = 0;
        Mat p = potencia(a, ks[i]);
        printf("%2d trechos: %lld rotas de T0 a T3 (%d produtos)\n", ks[i], p.m[0][3], produtos);
    }
    return 0;
}
