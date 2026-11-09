// Lista · Módulo 08 · Tipos compostos
// Exercício P0818 · ★★☆ · Os números complexos

#include <stdio.h>
#include <math.h>

typedef struct {
    double re, im;
} Complexo;

Complexo soma(Complexo a, Complexo b) {
    return (Complexo) {a.re + b.re, a.im + b.im};
}

Complexo multiplica(Complexo a, Complexo b) {
    return (Complexo) {a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re};
}

double modulo(Complexo z) {
    return sqrt(z.re * z.re + z.im * z.im);
}

void mostrar(const char *rotulo, Complexo z) {
    double re = (z.re == 0) ? 0 : z.re; // troca o -0 por 0
    printf("%s %g %c %gi\n", rotulo, re, z.im < 0 ? '-' : '+', fabs(z.im));
}

int main(void) {
    Complexo z = {1, 2}, w = {3, -1};

    mostrar("z + w =", soma(z, w));
    Complexo p = multiplica(z, w);
    mostrar("z * w =", p);
    printf("|z * w| = %.4f\n", modulo(p));

    Complexo i = {0, 1};
    Complexo pot = {1, 0};
    char rotulo[8];
    for (int k = 1; k <= 8; k++) {
        pot = multiplica(pot, i);
        snprintf(rotulo, sizeof rotulo, "i^%d =", k);
        mostrar(rotulo, pot);
    }
    return 0;
}
