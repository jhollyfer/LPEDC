// 0054 · malloc e free
// Exercício E323 · ★★★
//
// O app de caminhada calcula a média de passos dos últimos 4 dias. A conta
// sai certa, mas o programa termina com um relatório do AddressSanitizer.
// O erro está de propósito. Rode, leia o relatório e responda: qual linha
// está errada e por quê? Depois conserte.
//
//   Saída esperada depois do conserto:
//   Média: 9000 passos
//
// Dicas:
// 1. Procure "attempting free on address which was not malloc()-ed".
// 2. Para onde passos aponta depois do laço?
// 3. Resposta esperada: o free(passos) recebe um endereço que não veio do
//    malloc, porque passos++ andou 4 posições. O free precisa do endereço
//    exato do início. Conserte usando passos[i] no laço (ou andando com uma
//    cópia do ponteiro: int *p = passos;).
//
// Escreva sua resposta abaixo (conserte o código):

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
        total += *passos;
        passos++;
    }
    printf("Média: %ld passos\n", total / dias);
    free(passos);
    return 0;
}
