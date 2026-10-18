// 0009 · Constantes
// Exercício E050 · ★☆☆

#include <stdio.h>

#define POSTO "Auto Posto Ipê"
#define GASOLINA 6.29 // o reajuste é só trocar para 6.49 aqui
#define ETANOL 4.19

int main(void) {
    printf("%s\n", POSTO);
    printf("Gasolina: R$ %.2f\n", GASOLINA);
    printf("Etanol:   R$ %.2f\n", ETANOL);
    return 0;
}
