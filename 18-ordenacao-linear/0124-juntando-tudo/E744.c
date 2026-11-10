// 0124 · Juntando tudo
// Exercício E744 · ★★★
//
// Nenhum Pix passa de R$ 9999,99: o byte 3 do valor é sempre zero e a
// quarta passada do radix copia 12 MB à toa. Escreva int radix_esperto(Pix
// v[], Pix aux[], int n), radix em base 256 pelo valor que pula a passada
// quando TODOS os bytes caem no mesmo balde (algum c[x] == n) e devolve
// quantas passadas fez, com o resultado em v. No main (pix.h), com N =
// 1000000 e pix_gera com a semente 2024, rode radix_esperto numa cópia e
// pix_por_valor em outra e compare os ids (os dois são estáveis), para os
// valores do dia e para valores até R$ 2,55 (centavos %= 256).
//
//   Saída esperada:
//   valores do dia:      3 passadas de 4, igual ao pix_por_valor? sim
//   valores até R$ 2,55: 1 passada de 4, igual ao pix_por_valor? sim
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pix.h"

int main(void) {

    return 0;
}
