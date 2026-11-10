// 0123 · Quickselect
// Exercício E737 · ★★★
//
// A secretaria da faculdade tem 10001 matrículas, numeradas de 1 a 10001 e
// já em ordem, e quer a matrícula mediana (a da posição 5000 do vetor).
// Para fugir do pior caso do vetor ordenado, escreva um quickselect com
// pivô sorteado. A cada passada do laço, sorteie a posição do pivô entre p
// e r, troque-a com v[r] e só então faça a separação de Lomuto (pivô v[r],
// comparação <=), contando as separações numa variável static. O sorteio
// usa uma semente unsigned, que começa em 2025:
//
//   semente = semente * 1103515245u + 12345u;
//   posição = p + (int) ((semente >> 16) % (unsigned) (r - p + 1));
//
//   Saída esperada:
//   mediana: 5001 (19 separações)
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
