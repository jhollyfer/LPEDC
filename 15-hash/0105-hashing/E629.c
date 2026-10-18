// 0105 · A ideia e a função hash
// Exercício E629 · ★★★
//
// O hortifrúti conta quantas frutas caem em cada um dos 8 baldes. O
// programa abaixo funciona com "banana" e "uva", mas o AddressSanitizer
// reclama quando entra "maçã". O erro está aí de propósito. Faça assim:
//
// 1. No primeiro for do main, antes de contar, acrescente um printf que
//    mostre o índice de cada fruta ("banana -> 1"). Rode e veja o índice
//    que sai para "maçã" logo antes do erro.
// 2. Conserte a função indice() para que funcione com qualquer texto em
//    UTF-8. Rode de novo: o sanitizer não pode reclamar.
//
//   Saída esperada (depois do conserto):
//   banana -> 1
//   uva -> 4
//   maçã -> 6
//   balde 0: 0
//   balde 1: 1
//   ...
//
// Dicas:
// 1. Em UTF-8, "ç" é 0xC3 0xA7 e "ã" é 0xC3 0xA3. Quanto vale 0xC3 num
//    char com sinal?
// 2. Em C, o resto de um número negativo é negativo: -98 % 8 dá -2.
// 3. Resposta esperada: antes do conserto, "maçã -> -2" (os bytes viram
//    -61, -89, -61 e -93 e a soma dá -98). Acumulando num unsigned e
//    convertendo cada byte para unsigned char, "maçã" cai no balde 6 e a
//    contagem fica 1 no balde 1, 1 no 4 e 1 no 6.
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
