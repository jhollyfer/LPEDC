// 0007 · Aritmética
// Exercício E037 · ★☆☆

#include <stdio.h>

int main(void) {
    int brigadeiros = 50;
    int por_caixa = 12;
    int ingressos = 7;
    int preco_ingresso = 35;

    printf("Caixas cheias: %d\n", brigadeiros / por_caixa);
    printf("Sobram: %d brigadeiros\n", brigadeiros % por_caixa);
    printf("Ingressos: R$ %d\n", ingressos * preco_ingresso);
    return 0;
}
