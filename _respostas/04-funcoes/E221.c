// 0037 · Recursão
// Exercício E221 · ★★★
//
// Resposta: (1) "if (n = 0)" atribui 0 a n, e a expressão vale 0 (falso): o
// caso base nunca é aceito, e a chamada recursiva passa a ser soma_digitos(0),
// que faz a mesma coisa, para sempre, até a pilha estourar. O certo é n == 0.
// (2) Faltava o return no caso recursivo: a soma era calculada e jogada fora,
// e quem chamava recebia lixo.

#include <stdio.h>

int soma_digitos(int n) {
    if (n == 0) {
        return 0;
    }
    return n % 10 + soma_digitos(n / 10);
}

int main(void) {
    printf("2026 -> %d\n", soma_digitos(2026));
    printf("99999 -> %d\n", soma_digitos(99999));
    return 0;
}
