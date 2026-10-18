// 0055 · calloc e realloc
// Exercício E330 · ★★★
//
// O erro: primeira guardava o endereço de senhas[0] no bloco antigo. O
// realloc mudou o bloco de lugar e liberou o antigo; ler *primeira depois
// disso é heap-use-after-free (linha do printf do painel). Conserto: guardar
// o índice, que continua valendo depois do realloc.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int capacidade = 2;
    int quantidade = 0;
    int *senhas = malloc(capacidade * sizeof *senhas);
    if (senhas == NULL) {
        return 1;
    }
    senhas[quantidade++] = 101;
    int primeira = 0; // índice, não endereço

    for (int nova = 102; nova <= 104; nova++) {
        if (quantidade == capacidade) {
            int *maior = realloc(senhas, 2 * capacidade * sizeof *senhas);
            if (maior == NULL) {
                free(senhas);
                return 1;
            }
            senhas = maior;
            capacidade *= 2;
        }
        senhas[quantidade++] = nova;
    }

    printf("Painel: senha %d\n", senhas[primeira]);
    printf("Senhas na fila: %d\n", quantidade);
    free(senhas);
    return 0;
}
// Saída:
// Painel: senha 101
// Senhas na fila: 4
