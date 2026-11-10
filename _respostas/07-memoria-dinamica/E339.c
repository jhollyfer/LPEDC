// 0057 · Erros de memória
// Exercício E339 · ★★☆

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

    int *backup = malloc(3 * sizeof *backup);
    if (backup == NULL) {
        free(placar);
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        backup[i] = placar[i]; // copia os números, não o endereço
    }

    placar[0] = 0; // jogo anulado: o backup não pode mudar
    printf("Placar: %d %d %d\n", placar[0], placar[1], placar[2]);
    printf("Backup: %d %d %d\n", backup[0], backup[1], backup[2]);
    free(placar);
    printf("Placar encerrado\n");
    free(backup); // agora é outro bloco: o free é legítimo
    return 0;
}
