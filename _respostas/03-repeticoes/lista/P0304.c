// Lista · Módulo 03 · Laços
// Exercício P0304 · ★☆☆ · Os dígitos do protocolo

#include <stdio.h>

int main(void) {
    long long protocolo = 2026110903LL;
    long long n = protocolo;
    int digitos = 0, soma = 0;

    while (n > 0) {
        soma += (int)(n % 10);
        digitos++;
        n /= 10;
    }

    printf("Protocolo: %lld\n", protocolo);
    printf("Dígitos: %d\n", digitos);
    printf("Soma dos dígitos: %d\n", soma);
    return 0;
}
