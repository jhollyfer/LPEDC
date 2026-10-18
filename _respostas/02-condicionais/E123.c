// 0021 · else if, if aninhado e o else pendurado
// Exercício E123 · ★★☆
//
// Resposta: o else é do if (b > 0), o mais próximo sem else.
// a) a = -1, b = 5: o if de fora é falso; mostra só "C".
// b) a = 2, b = -1: entra no de fora, b > 0 é falso, cai no else: "B", "C".
// c) a = 2, b = 3: "A", "C".
// Abaixo, a versão com chaves em que o else fica com o if (a > 0). Com ela:
// a) "B" e "C"; b) só "C"; c) "A" e "C". Troque os valores para testar.

#include <stdio.h>

int main(void) {
    int a = -1, b = 5;

    if (a > 0) {
        if (b > 0) {
            printf("A\n");
        }
    } else {
        printf("B\n");
    }
    printf("C\n");
    return 0;
}
