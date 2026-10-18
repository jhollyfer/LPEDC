// 0054 · malloc e free
// Exercício E322 · ★★☆
//
// Resposta: a) 20; b) 40; c) 24; d) 7; e) 5 bytes. Em e) cabe só um int
// (sobra 1 byte); e[1] ocuparia os bytes 4 a 7, fora do bloco:
// heap-buffer-overflow.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf("a) %zu\n", 5 * sizeof(int));
    printf("b) %zu\n", 5 * sizeof(double));
    printf("c) %zu\n", 3 * sizeof(int *));
    printf("d) %zu\n", strlen("Recife") + 1);
    printf("e) %d (cabem %zu int)\n", 5, 5 / sizeof(int));
    return 0;
}
// Saída:
// a) 20
// b) 40
// c) 24
// d) 7
// e) 5 (cabem 1 int)
