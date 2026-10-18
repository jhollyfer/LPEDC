// 0057 · Erros de memória
// Exercício E340 · ★★☆
//
// O sistema do estacionamento guarda a placa do carro e os km rodados nos
// últimos 5 dias. O programa tem DOIS estouros de memória, de propósito. O
// AddressSanitizer para no primeiro: conserte, rode de novo e ache o
// segundo.
//
//   Saída esperada depois do conserto:
//   Placa: QTX3E21
//   Km da semana: 238
//
// Dicas:
// 1. Quantos bytes "QTX3E21" ocupa de verdade?
// 2. O vetor km tem 5 posições: índices de 0 a 4.
// 3. Resposta esperada: (a) malloc(strlen(original)) esquece o '\0': o
//    strcpy escreve 1 byte depois do fim (heap-buffer-overflow, WRITE of
//    size 8). Use strlen(original) + 1. (b) o for com i <= dias lê km[5],
//    4 bytes depois do fim do bloco. Use i < dias. Total: 238.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *original = "QTX3E21";
    char *placa = malloc(strlen(original));
    if (placa == NULL) {
        return 1;
    }
    strcpy(placa, original);

    int dias = 5;
    int *km = malloc(dias * sizeof *km);
    if (km == NULL) {
        free(placa);
        return 1;
    }
    km[0] = 42;
    km[1] = 55;
    km[2] = 38;
    km[3] = 61;
    km[4] = 42;

    int total = 0;
    for (int i = 0; i <= dias; i++) {
        total += km[i];
    }
    printf("Placa: %s\n", placa);
    printf("Km da semana: %d\n", total);
    free(km);
    free(placa);
    return 0;
}
