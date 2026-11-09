// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1928 · ★★★ · A próxima trinca pelos bits
//
// O técnico do vôlei de praia escolhe 3 entre 5 jogadoras (Ana, Bia, Cris,
// Dani e Eli) para um treino. Cada escolha é uma máscara de 5 bits com
// exatamente 3 bits ligados (bit i = jogadora i). Em vez de recursão, use o
// truque de Gosper, que salta de uma máscara direto para a PRÓXIMA maior
// com o mesmo número de bits:
//
//   c = x & -x;               (o bit ligado mais baixo)
//   r = x + c;                (soma, empurrando o bloco de 1s)
//   x = (((r ^ x) >> 2) / c) | r;
//
// Complete proxima(x) e o laço do main, que começa em 0b00111 (7) e para
// quando a máscara passa de 5 bits. Mostre cada máscara em binário (bit 4
// à esquerda) e as jogadoras dela.
//
//   Saída esperada:
//   00111: Ana Bia Cris
//   01011: Ana Bia Dani
//   01101: Ana Cris Dani
//   01110: Bia Cris Dani
//   10011: Ana Bia Eli
//   10101: Ana Cris Eli
//   10110: Bia Cris Eli
//   11001: Ana Dani Eli
//   11010: Bia Dani Eli
//   11100: Cris Dani Eli
//   Total: 10 trincas
//
// Dicas:
// 1. Use unsigned: com unsigned, -x é bem definido (vale 2^32 - x) e x &
//    -x isola o bit mais baixo.
// 2. Condição do laço: x < (1u << N). A primeira é (1u << K) - 1.
// 3. Resposta esperada: 10 trincas (C(5, 3)), de 00111 (Ana Bia Cris) até
//    11100 (Cris Dani Eli), em ordem crescente de máscara.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

#define N 5
#define K 3

const char *nome[N] = {"Ana", "Bia", "Cris", "Dani", "Eli"};

unsigned proxima(unsigned x) {
    // COMPLETE AQUI
    return x;
}

void mostra(unsigned x) {
    for (int b = N - 1; b >= 0; b--) {
        printf("%u", (x >> b) & 1u);
    }
    printf(":");
    for (int i = 0; i < N; i++) {
        if (x & (1u << i)) {
            printf(" %s", nome[i]);
        }
    }
    printf("\n");
}

int main(void) {
    int total = 0;
    // COMPLETE AQUI: percorra as máscaras com proxima, chamando mostra(x)
    (void)mostra;
    printf("Total: %d trincas\n", total);
    return 0;
}
