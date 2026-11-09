// Lista · Módulo 03 · Laços
// Exercício P0305 · ★☆☆ · O tamanho do açaí

#include <stdio.h>

int main(void) {
    int opcao;

    do {
        printf("Tamanho (1, 2 ou 3): ");
        if (scanf("%d", &opcao) != 1) {
            return 1;
        }
        if (opcao < 1 || opcao > 3) {
            printf("Opção inválida.\n");
        }
    } while (opcao < 1 || opcao > 3);

    int ml = 100 + 200 * opcao;       // 300, 500 ou 700
    double preco = 6.00 + 6.00 * opcao; // 12, 18 ou 24
    printf("Açaí de %d ml: R$ %.2f\n", ml, preco);
    return 0;
}
