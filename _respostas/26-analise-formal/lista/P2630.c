// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2630 · ★★★ · Três jeitos do melhor trecho

#include <stdio.h>

unsigned semente = 314;
long passos;

int sorteia(int limite) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente / 65536u) % (unsigned)limite);
}

long cubica(const int v[], int n) {
    long melhor = v[0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long s = 0;
            for (int k = i; k <= j; k++) {
                passos++;
                s += v[k];
            }
            if (s > melhor) melhor = s;
        }
    }
    return melhor;
}

long quadratica(const int v[], int n) {
    long melhor = v[0];
    for (int i = 0; i < n; i++) {
        long s = 0;
        for (int j = i; j < n; j++) {
            passos++;
            s += v[j];
            if (s > melhor) melhor = s;
        }
    }
    return melhor;
}

long linear(const int v[], int n) {
    long melhor = v[0], atual = 0;
    for (int i = 0; i < n; i++) {
        passos++;
        atual = (atual + v[i] > v[i]) ? atual + v[i] : v[i];
        if (atual > melhor) melhor = atual;
    }
    return melhor;
}

int main(void) {
    int saldo[200];
    for (int i = 0; i < 200; i++) {
        saldo[i] = sorteia(201) - 100;
    }
    long (*f[3])(const int[], int) = {cubica, quadratica, linear};
    const char *nome[3] = {"cubica", "quadratica", "linear"};
    for (int n = 100; n <= 200; n *= 2) {
        printf("n = %d\n", n);
        for (int k = 0; k < 3; k++) {
            passos = 0;
            long m = f[k](saldo, n);
            printf("  %-10s: soma %ld, %8ld passos\n", nome[k], m, passos);
        }
    }
    return 0;
}
