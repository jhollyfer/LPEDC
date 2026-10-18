// 0059 · malloc e free
// Exercício E353 · ★★★
//
// O erro: passos++ andou 4 posições e o free recebeu um endereço que não
// veio do malloc. O free precisa do endereço exato do início do bloco.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int dias = 4;
    int *passos = malloc(dias * sizeof(int));
    if (passos == NULL) {
        return 1;
    }
    passos[0] = 8000;
    passos[1] = 12500;
    passos[2] = 6400;
    passos[3] = 9100;

    long total = 0;
    for (int i = 0; i < dias; i++) {
        total += passos[i]; // o ponteiro fica parado no início
    }
    printf("Média: %ld passos\n", total / dias);
    free(passos);
    return 0;
}
// Saída:
// Média: 9000 passos
