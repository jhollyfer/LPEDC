// 0032 · Juntando tudo
// Exercício E191 · ★★★

#include <stdio.h>

int main(void) {
    int palitos = 21;
    int tira;

    while (palitos > 0) {
        // sua vez
        do {
            printf("Você tira: ");
            if (scanf("%d", &tira) != 1) {
                printf("\nJogo abandonado.\n");
                return 1;
            }
        } while (tira < 1 || tira > 3 || tira > palitos);
        palitos -= tira;
        printf("Sobram %d. ", palitos);
        if (palitos == 0) {
            printf("Você tirou o último palito. Perdeu!\n");
            break;
        }

        // vez do computador
        tira = (palitos - 1) % 4;
        if (tira == 0) {
            tira = 1;
        }
        palitos -= tira;
        printf("O computador tira %d. Sobram %d.\n", tira, palitos);
        if (palitos == 0) {
            printf("O computador tirou o último palito. Você ganhou!\n");
        }
    }
    return 0;
}
