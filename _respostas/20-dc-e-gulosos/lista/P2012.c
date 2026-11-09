// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2012 · ★★☆ · As duas antenas mais próximas

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef struct {
    int x, y;
} Ponto;

int calculos = 0;
Ponto par_a, par_b;

int d2(Ponto a, Ponto b) {
    calculos++;
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int por_x(const void *a, const void *b) {
    const Ponto *p = a, *q = b;
    return (p->x > q->x) - (p->x < q->x);
}

int bruta(const Ponto p[], int n) {
    int melhor = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = d2(p[i], p[j]);
            if (melhor < 0 || d < melhor) {
                melhor = d;
                par_a = p[i];
                par_b = p[j];
            }
        }
    }
    return melhor;
}

int proximo(const Ponto p[], int n) {
    if (n <= 3) {
        return bruta(p, n);
    }
    int m = n / 2;
    int de = proximo(p, m);
    Ponto ea = par_a, eb = par_b;
    int dd = proximo(p + m, n - m);
    int d = dd;
    if (de <= dd) {
        d = de;
        par_a = ea;
        par_b = eb;
    }
    Ponto faixa[N];
    int nf = 0;
    int xm = p[m].x;
    for (int i = 0; i < n; i++) {
        if ((p[i].x - xm) * (p[i].x - xm) < d) {
            faixa[nf++] = p[i];
        }
    }
    for (int i = 0; i < nf; i++) {
        for (int j = i + 1; j < nf; j++) {
            int dist = d2(faixa[i], faixa[j]);
            if (dist < d) {
                d = dist;
                par_a = faixa[i];
                par_b = faixa[j];
            }
        }
    }
    return d;
}

int main(void) {
    Ponto p[N] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}, {31, 33}, {18, 21}};
    calculos = 0;
    int db = bruta(p, N);
    printf("Força bruta: (%d, %d) e (%d, %d), %.2f, %d distâncias\n",
           par_a.x, par_a.y, par_b.x, par_b.y, sqrt(db), calculos);
    qsort(p, N, sizeof p[0], por_x);
    calculos = 0;
    int dc = proximo(p, N);
    printf("Divisão e conquista: (%d, %d) e (%d, %d), %.2f, %d distâncias\n",
           par_a.x, par_a.y, par_b.x, par_b.y, sqrt(dc), calculos);
    return 0;
}
