// 0178 · Hash: divisão e multiplicação
// Exercício E1067 · ★★★
//
// Ache o bug. O atacadão registra os fardos 16, 32, ..., 160 numa tabela de
// m = 16 baldes com o método da multiplicação em inteiros (s = 2654435769).
// O programador pegou os bits ERRADOS do produto, e todos os fardos caem no
// balde 0. Conserte UMA linha de balde() e rode de novo.
//
//   Saída esperada:
//   baldes: 14 12 10 8 7 5 3 1 15 14
//   balde mais cheio: 2
//
// Dicas:
// 1. Escreva o produto k * s em binário (ou mostre com printf("%08X")): para
//    k múltiplo de 16, os 4 bits de baixo do produto são sempre 0.
// 2. No método da multiplicação, a parte "bem misturada" do produto são os
//    bits ALTOS dos 32 de baixo: os p bits mais significativos.
// 3. Resposta esperada: return produto >> (32 - P); (em vez de
//    produto & (M - 1)). Com a correção, a saída é a de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdint.h>
#include <stdio.h>

#define P 4
#define M (1 << P)

uint32_t balde(uint32_t k) {
    uint32_t produto = k * 2654435769u; // mod 2^32
    return produto & (M - 1);
}

int main(void) {
    int conta[M] = {0};
    printf("baldes:");
    for (uint32_t k = 16; k <= 160; k += 16) {
        uint32_t b = balde(k);
        conta[b]++;
        printf(" %u", (unsigned)b);
    }
    int maior = 0;
    for (int i = 0; i < M; i++) {
        if (conta[i] > maior) {
            maior = conta[i];
        }
    }
    printf("\nbalde mais cheio: %d\n", maior);
    return 0;
}
