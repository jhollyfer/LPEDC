// 0044 · Matrizes
// Exercício E262 · ★★☆

#include <stdio.h>

#define FILEIRAS 5
#define POLTRONAS 6

int main(void) {
    int sala[FILEIRAS][POLTRONAS] = {
        {1, 1, 0, 1, 1, 1},
        {0, 0, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1},
        {0, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 0},
    };
    int melhor = 0;
    int max_livres = -1;

    for (int f = 0; f < FILEIRAS; f++) {
        int livres = 0;
        printf("%c", 'A' + f);
        for (int p = 0; p < POLTRONAS; p++) {
            printf(" %c", sala[f][p] ? 'X' : '.');
            if (sala[f][p] == 0) {
                livres++;
            }
        }
        printf("  livres: %d\n", livres);
        if (livres > max_livres) {
            max_livres = livres;
            melhor = f;
        }
    }
    printf("Melhor fileira: %c\n", 'A' + melhor);
    return 0;
}
