// 0110 · A ideia e a função hash
// Exercício E659 · ★★★
//
// Resposta: a) -2. Num char com sinal, os bytes de "ç" (0xC3 0xA7) e de "ã"
// (0xC3 0xA3) valem -61, -89, -61 e -93. A soma de "maçã" dá
// 109 + 97 - 61 - 89 - 61 - 93 = -98, e -98 % 8 = -2: contagem[-2] está
// fora do vetor. b) acumular num unsigned e converter cada byte para
// unsigned char (0 a 255).

#include <stdio.h>

#define M 8

int indice(const char *s) {
    unsigned soma = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        soma += (unsigned char)s[i];
    }
    return (int)(soma % M);
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
