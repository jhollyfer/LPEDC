// A120 · A enquete com calloc

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int votos[] = {2, 3, 2, 1, 4, 2, 3, 2, 1, 2}; // opção escolhida por voto
    int total_votos = 10;
    int opcoes = 4;

    // um contador por opção (1 a 4); a posição 0 fica sem uso.
    // calloc(quantidade, tamanho) entrega tudo zerado: os contadores já
    // começam em 0. Com malloc, começariam com lixo.
    int *contagem = calloc(opcoes + 1, sizeof *contagem);
    if (contagem == NULL) {
        return 1;
    }

    for (int i = 0; i < total_votos; i++) {
        contagem[votos[i]]++;
    }

    for (int op = 1; op <= opcoes; op++) {
        printf("Opção %d: %d ", op, contagem[op]);
        for (int k = 0; k < contagem[op]; k++) {
            printf("#");
        }
        printf("\n");
    }
    free(contagem);
    return 0;
}
// Saída:
// Opção 1: 2 ##
// Opção 2: 5 #####
// Opção 3: 2 ##
// Opção 4: 1 #
