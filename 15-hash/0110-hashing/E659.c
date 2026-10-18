// 0110 · A ideia e a função hash
// Exercício E659 · ★★★
//
// O hortifrúti conta quantas frutas caem em cada um dos 8 baldes. O
// programa abaixo funciona com "banana" e "uva", mas o AddressSanitizer
// reclama quando entra "maçã". O erro está aí de propósito: rode, leia o
// relatório e responda:
//
// a) Qual índice a função indice() devolve para "maçã"? Por quê?
// b) Conserte a função para que funcione com qualquer texto em UTF-8.
//
// Dicas:
// 1. Em UTF-8, "ç" é 0xC3 0xA7 e "ã" é 0xC3 0xA3. Quanto vale 0xC3 num
//    char com sinal?
// 2. Em C, o resto de um número negativo é negativo: -98 % 8 dá -2.
// 3. Resposta esperada: a) -2, porque os bytes de "ç" e "ã" viram -61, -89,
//    -61 e -93 num char com sinal, a soma dá -98 e -98 % 8 = -2;
//    contagem[-2] fica fora do vetor. b) acumule num unsigned e converta
//    cada byte para unsigned char. Consertado, "maçã" cai no balde 6 e a
//    saída mostra 1 no balde 1 (banana), 1 no 4 (uva) e 1 no 6.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define M 8

int indice(const char *s) {
    int soma = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        soma += s[i];
    }
    return soma % M;
}

int main(void) {
    int contagem[M] = {0};
    const char *frutas[] = {"banana", "uva", "maçã"};

    for (int i = 0; i < 3; i++) {
        contagem[indice(frutas[i])]++;
    }
    for (int b = 0; b < M; b++) {
        printf("balde %d: %d\n", b, contagem[b]);
    }
    return 0;
}
