// 0055 · calloc e realloc
// Exercício E325 · ★☆☆

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int jogadas[] = {3, 6, 1, 6, 2, 5, 6, 3, 4, 6, 1, 2};
    int *contagem = calloc(7, sizeof *contagem); // faces 1 a 6, zeradas
    if (contagem == NULL) {
        return 1;
    }
    for (int i = 0; i < 12; i++) {
        contagem[jogadas[i]]++;
    }
    for (int face = 1; face <= 6; face++) {
        printf("%d: %d ", face, contagem[face]);
        for (int k = 0; k < contagem[face]; k++) {
            printf("#");
        }
        printf("\n");
    }
    free(contagem);
    return 0;
}
// Saída:
// 1: 2 ##
// 2: 2 ##
// 3: 2 ##
// 4: 1 #
// 5: 1 #
// 6: 4 ####
