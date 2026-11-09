// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2619 · ★★☆ · O maior n que cabe no orçamento

#include <stdio.h>
#include <math.h>

#define ORCAMENTO 1e8

double linear(double n) { return n; }
double nlogn(double n) { return n * log2(n); }
double quadratico(double n) { return n * n; }
double cubico(double n) { return n * n * n; }
double exponencial(double n) { return pow(2, n); }

long maior_n(double (*f)(double)) {
    long cabe = 1, nao_cabe = 2;
    while (f((double)nao_cabe) <= ORCAMENTO) {
        cabe = nao_cabe;
        nao_cabe *= 2;
    }
    while (nao_cabe - cabe > 1) {
        long meio = cabe + (nao_cabe - cabe) / 2;
        if (f((double)meio) <= ORCAMENTO) {
            cabe = meio;
        } else {
            nao_cabe = meio;
        }
    }
    return cabe;
}

int main(void) {
    double (*f[5])(double) = {linear, nlogn, quadratico, cubico, exponencial};
    const char *nome[5] = {"n", "n log n", "n^2", "n^3", "2^n"};
    for (int k = 0; k < 5; k++) {
        printf("%-7s: n até %ld\n", nome[k], maior_n(f[k]));
    }
    return 0;
}
