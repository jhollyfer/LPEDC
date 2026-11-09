// Lista · Módulo 02 · Decisões
// Exercício P0208 · ★☆☆ · A recarga do cartão do ônibus

#include <stdio.h>

int main(void) {
    int passagens;

    printf("Quantas passagens? ");
    if (scanf("%d", &passagens) != 1) {
        printf("Entrada inválida.\n");
        return 1;
    }
    printf("Recarga: R$ %.2f\n", passagens * 4.50);
    return 0;
}
