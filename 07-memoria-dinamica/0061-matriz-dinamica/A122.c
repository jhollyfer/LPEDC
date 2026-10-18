// A122 · O mapa do cinema num bloco só

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int fileiras = 4;
    int poltronas = 6;

    // um bloco só com fileiras * poltronas chars; a posição (i, j) fica em
    // i * poltronas + j: a mesma conta que o compilador faz numa matriz fixa
    char *sala = malloc(fileiras * poltronas * sizeof *sala);
    if (sala == NULL) {
        return 1;
    }
    for (int k = 0; k < fileiras * poltronas; k++) {
        sala[k] = 'L'; // livre
    }

    sala[1 * poltronas + 2] = 'X'; // fileira B, poltrona 3
    sala[1 * poltronas + 3] = 'X'; // fileira B, poltrona 4
    sala[3 * poltronas + 0] = 'X'; // fileira D, poltrona 1

    printf("   1 2 3 4 5 6\n");
    for (int i = 0; i < fileiras; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < poltronas; j++) {
            printf(" %c", sala[i * poltronas + j]);
        }
        printf("\n");
    }
    printf("Um malloc, um free, %d bytes seguidos\n", fileiras * poltronas);
    free(sala);
    return 0;
}
// Saída:
//    1 2 3 4 5 6
// A  L L L L L L
// B  L L X X L L
// C  L L L L L L
// D  X L L L L L
// Um malloc, um free, 24 bytes seguidos
