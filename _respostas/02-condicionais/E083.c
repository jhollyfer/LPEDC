// 0014 · if
// Exercício E083 · ★★★
//
// Resposta: sete ímpar igual fim
// - n > 10 é falso: só o printf("grande ") é pulado; "sete " roda sempre.
// - n % 2 vale 1: verdade, mostra "ímpar ".
// - n - 7 vale 0 e !0 vale 1: mostra "igual ".
// - n & 1 == 0 é n & (1 == 0) = n & 0 = 0: "par " nunca aparece.
// Abaixo, o mesmo trecho com chaves e parênteses mostrando o que o C entende.

#include <stdio.h>

int main(void) {
    int n = 7;
    if (n > 10) {
        printf("grande ");
    }
    printf("sete ");
    if (n % 2) {
        printf("ímpar ");
    }
    if (!(n - 7)) {
        printf("igual ");
    }
    if (n & (1 == 0)) {
        printf("par ");
    }
    printf("fim\n");
    return 0;
}
