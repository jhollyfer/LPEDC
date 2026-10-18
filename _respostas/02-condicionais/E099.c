// 0017 · Ternário: condição ? a : b
// Exercício E099 · ★★☆
//
// Resposta: a) 5 (k é 0, falso); b) 3 (5 > 2, então 5 - 2);
// c) 7 ((i == 2 || k) é verdade); d) 2 (k falso, então i ? 2 : 3, e i é
// verdade); e) ímpar (5 % 2 vale 1).

#include <stdio.h>

int main(void) {
    int i = 2, j = 5, k = 0;
    printf("a) %d\n", k ? i : j);
    printf("b) %d\n", j > i ? j - i : i - j);
    printf("c) %d\n", i == 2 || k ? 7 : 8);
    printf("d) %d\n", k ? 1 : i ? 2 : 3);
    printf("e) %s\n", j % 2 ? "ímpar" : "par");
    return 0;
}
