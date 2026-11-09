// Lista · Módulo 04 · Funções e modularização
// Exercício P0420 · ★★☆ · O maior dígito que sumiu

#include <stdio.h>

int maior_digito(int n) {
    if (n < 10) {
        return n; // um dígito só: ele mesmo é o maior
    }
    int resto = maior_digito(n / 10);
    return n % 10 > resto ? n % 10 : resto;
}

int main(void) {
    printf("Maior dígito de 9123: %d\n", maior_digito(9123));
    printf("Maior dígito de 4718: %d\n", maior_digito(4718));
    printf("Maior dígito de 5: %d\n", maior_digito(5));
    return 0;
}
