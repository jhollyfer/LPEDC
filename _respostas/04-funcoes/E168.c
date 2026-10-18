// 0028 · Funções
// Exercício E168 · ★★★

#include <stdbool.h>
#include <stdio.h>

int soma_divisores(int n);
bool eh_perfeito(int n);

int main(void) {
    for (int n = 2; n <= 10000; n++) {
        if (eh_perfeito(n)) {
            printf("%d = soma dos divisores %d\n", n, soma_divisores(n));
        }
    }
    return 0;
}

int soma_divisores(int n) {
    int soma = 0;
    for (int d = 1; d <= n / 2; d++) {
        if (n % d == 0) {
            soma += d;
        }
    }
    return soma;
}

bool eh_perfeito(int n) {
    return soma_divisores(n) == n;
}
