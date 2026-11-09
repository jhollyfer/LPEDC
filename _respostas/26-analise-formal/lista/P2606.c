// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2606 · ★☆☆ · O primeiro débito do extrato

#include <stdio.h>

int comparacoes = 0;

int primeiro_debito(const double extrato[], int n) {
    for (int i = 0; i < n; i++) {
        comparacoes++;
        if (extrato[i] < 0) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    double a[8] = {-50.0, 120.0, 30.5, 80.0, 15.0, 200.0, 9.9, 60.0};
    double b[8] = {120.0, 30.5, 80.0, -50.0, 15.0, 200.0, 9.9, 60.0};
    double c[8] = {120.0, 30.5, 80.0, 15.0, 200.0, 9.9, 60.0, 45.0};
    const double *extratos[3] = {a, b, c};
    const char *nome[3] = {"a (melhor caso)", "b", "c (pior caso)"};
    for (int k = 0; k < 3; k++) {
        comparacoes = 0;
        int pos = primeiro_debito(extratos[k], 8);
        printf("extrato %s: posição %d, %d comparações\n", nome[k], pos, comparacoes);
    }
    return 0;
}
