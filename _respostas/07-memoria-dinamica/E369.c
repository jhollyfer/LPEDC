// 0062 · Erros de memória
// Exercício E369 · ★★☆
//
// O erro: backup = placar copia o endereço, não os números. Os dois
// ponteiros apontam para o mesmo bloco, e liberar os dois é free duplo. Um
// bloco, um free.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *placar = malloc(3 * sizeof *placar);
    if (placar == NULL) {
        return 1;
    }
    placar[0] = 4;
    placar[1] = 2;
    placar[2] = 7;
    int *backup = placar; // outro nome para o MESMO bloco

    printf("Gols: %d %d %d\n", backup[0], backup[1], backup[2]);
    free(placar);
    placar = NULL;
    backup = NULL; // os dois nomes deixam de apontar para o bloco
    printf("Placar encerrado\n");
    return 0;
}
// Saída:
// Gols: 4 2 7
// Placar encerrado
