// 0169 · Juntando tudo: passos e bytes conferidos
// Exercício E1012 · ★★☆

#include <stdio.h>

long passos = 0;

void misterio_a(int n) {
    for (int i = 1; i < n; i *= 2) {
        for (int j = 0; j < n; j++) {
            passos++;
        }
    }
}

void misterio_b(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i / 2; j++) {
            passos++;
        }
    }
}

void misterio_c(int n) {
    for (int i = n; i > 0; i /= 2) {
        for (int j = 0; j < i; j++) {
            passos++;
        }
    }
}

const char *classe(double razao) {
    if (razao < 1.5) return "constante ou log n";
    if (razao < 2.1) return "n";
    if (razao < 3.0) return "n log n";
    if (razao < 5.0) return "n²";
    return "pior que n²";
}

int main(void) {
    void (*f[3])(int) = {misterio_a, misterio_b, misterio_c};
    const char *nome = "abc";
    for (int k = 0; k < 3; k++) {
        passos = 0;
        f[k](1024);
        long p1 = passos;
        passos = 0;
        f[k](2048);
        long p2 = passos;
        double r = (double)p2 / p1;
        printf("%c: %7ld -> %7ld, razão %.2f, classe %s\n", nome[k], p1, p2, r, classe(r));
    }
    return 0;
}
