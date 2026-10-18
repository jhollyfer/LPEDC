// 0031 · Aleatórios
// Exercício E183 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned) time(NULL));
    int segredo = 1 + rand() % 100;
    int palpite;
    int tentativas = 0;

    do {
        printf("Palpite: ");
        if (scanf("%d", &palpite) != 1) {
            printf("\nFim de jogo. O número era %d.\n", segredo);
            return 0;
        }
        tentativas++;
        if (palpite < segredo) {
            printf("Mais alto.\n");
        } else if (palpite > segredo) {
            printf("Mais baixo.\n");
        }
    } while (palpite != segredo);

    printf("Acertou em %d tentativas!\n", tentativas);
    return 0;
}
