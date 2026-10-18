// 0055 · calloc e realloc
// Exercício E326 · ★☆☆
//
// O problema: com notas = realloc(notas, ...), uma falha joga NULL em notas
// e o endereço do bloco antigo se perde (vazamento, e as notas 7 e 8 somem
// junto). Com o temporário, o bloco antigo continua acessível.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *notas = malloc(2 * sizeof *notas);
    if (notas == NULL) {
        return 1;
    }
    notas[0] = 7;
    notas[1] = 8;

    int *maior = realloc(notas, 3 * sizeof *notas);
    if (maior == NULL) {
        free(notas); // o bloco antigo ainda é nosso
        return 1;
    }
    notas = maior;
    notas[2] = 10;

    printf("Notas: %d %d %d\n", notas[0], notas[1], notas[2]);
    free(notas);
    return 0;
}
// Saída:
// Notas: 7 8 10
