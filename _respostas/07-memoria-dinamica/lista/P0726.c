// Lista · Módulo 07 · Memória dinâmica
// Exercício P0726 · ★★★ · Multiplicar polinômios

#include <stdio.h>
#include <stdlib.h>

int *mult_poli(const int *p, int gp, const int *q, int gq, int *gr) {
    *gr = gp + gq;
    int *r = calloc(*gr + 1, sizeof *r);
    if (r == NULL) {
        return NULL;
    }
    for (int i = 0; i <= gp; i++) {
        for (int j = 0; j <= gq; j++) {
            r[i + j] += p[i] * q[j];
        }
    }
    return r;
}

long long valor(const int *p, int g, int x) {
    long long r = 0;
    for (int i = g; i >= 0; i--) {
        r = r * x + p[i]; // Horner
    }
    return r;
}

void mostrar(const int *p, int g) {
    int primeiro = 1;
    for (int i = 0; i <= g; i++) {
        if (p[i] == 0) {
            continue;
        }
        int c = p[i];
        if (!primeiro) {
            printf(c < 0 ? " - " : " + ");
            if (c < 0) {
                c = -c;
            }
        } else if (c < 0) {
            printf("-");
            c = -c;
        }
        if (i == 0 || c != 1) {
            printf("%d", c);
        }
        if (i == 1) {
            printf("x");
        } else if (i > 1) {
            printf("x^%d", i);
        }
        primeiro = 0;
    }
    printf("%s\n", primeiro ? "0" : "");
}

int main(void) {
    int p[3] = {3, -2, 1};
    int q[2] = {1, 4};
    int gr;

    int *r = mult_poli(p, 2, q, 1, &gr);
    if (r == NULL) {
        return 1;
    }
    printf("p(x) = ");
    mostrar(p, 2);
    printf("q(x) = ");
    mostrar(q, 1);
    printf("r(x) = ");
    mostrar(r, gr);
    printf("r(2) = %lld; p(2) * q(2) = %lld\n", valor(r, gr, 2), valor(p, 2, 2) * valor(q, 1, 2));
    free(r);

    int um_mais_x[2] = {1, 1};
    int *pot = calloc(1, sizeof *pot);
    int gpot = 0;
    if (pot == NULL) {
        return 1;
    }
    pot[0] = 1;
    for (int k = 0; k < 5; k++) {
        int gnovo;
        int *novo = mult_poli(pot, gpot, um_mais_x, 1, &gnovo);
        free(pot); // o antigo não serve mais
        if (novo == NULL) {
            return 1;
        }
        pot = novo;
        gpot = gnovo;
    }
    printf("(1 + x)^5 = ");
    mostrar(pot, gpot);
    free(pot);
    return 0;
}
