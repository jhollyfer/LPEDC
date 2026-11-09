// 0167 · Somatórios que saem de laços
// Exercício E998 · ★☆☆

#include <stdio.h>

long passos = 0;

// compara cada produto da prateleira com ele mesmo e com os que vêm depois
void confere_prateleira(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            passos++;
        }
    }
}

int main(void) {
    printf("    n  passos  n(n+1)/2\n");
    int ns[] = {10, 100, 1000};
    for (int k = 0; k < 3; k++) {
        long n = ns[k];
        passos = 0;
        confere_prateleira(ns[k]);
        printf("%5ld %7ld %9ld\n", n, passos, n * (n + 1) / 2);
    }
    return 0;
}
