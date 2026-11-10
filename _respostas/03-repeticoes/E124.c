// 0021 · Do-while
// Exercício E124 · ★★☆

#include <stdio.h>

int main(void) {
    int opcao;

    do {
        printf("Sessão (1, 2 ou 3):\n");
        if (scanf("%d", &opcao) != 1) {
            return 1;
        }
    } while (opcao < 1 || opcao > 3);

    printf("Sessão %d escolhida.\n", opcao);
    return 0;
}
