// Lista · Módulo 03 · Laços
// Exercício P0306 · ★☆☆ · Os números da sorte da promoção

#include <stdio.h>

int main(void) {
    int premiados = 0, soma = 0;

    for (int n = 1; n <= 99; n++) {
        if (n % 3 == 0 || n % 5 == 0) {
            premiados++;
            soma += n;
        }
    }
    printf("Cupons premiados: %d\n", premiados);
    printf("Soma dos números: %d\n", soma);
    return 0;
}
