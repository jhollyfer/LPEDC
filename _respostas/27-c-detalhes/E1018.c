// 0170 · Precedência e ordem de avaliação
// Exercício E1018 · ★★☆

#include <stdio.h>

int main(void) {
    int total = 2400, pessoas = 4, dias = 3;

    int por_dia = total / (pessoas * dias);
    printf("por pessoa por dia: R$ %d\n", por_dia);

    int cada_um = total / pessoas + (dias > 2 ? 50 : 0);
    printf("cada um paga: R$ %d\n", cada_um);

    int desconto = total * 10 / 100;
    printf("desconto à vista: R$ %d\n", desconto);
    return 0;
}
