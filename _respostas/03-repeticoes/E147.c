// 0025 · Padrões de laço
// Exercício E147 · ★★☆

#include <stdio.h>

int main(void) {
    double preco, menor = 0.0, maior = 0.0;
    int posto_menor = 0, posto_maior = 0;

    for (int posto = 1; posto <= 6; posto++) {
        printf("Posto %d: ", posto);
        if (scanf("%lf", &preco) != 1) {
            return 1;
        }
        if (posto == 1 || preco < menor) {
            menor = preco;
            posto_menor = posto;
        }
        if (posto == 1 || preco > maior) {
            maior = preco;
            posto_maior = posto;
        }
    }
    printf("Mais barato: posto %d (R$ %.2f)\n", posto_menor, menor);
    printf("Mais caro: posto %d (R$ %.2f)\n", posto_maior, maior);
    printf("Diferença: R$ %.2f por litro\n", maior - menor);
    return 0;
}
