// 0018 · Lógicos: E, OU, NÃO
// Exercício E103 · ★☆☆
//
// Resposta: 0 1 0 1 1 0
// a && b = 1 && 0 = 0; a || b = 1; !a = 0; !b && c = 1 && 1 = 1;
// (a && b) || c = 0 || 1 = 1; a && (b || !c) = 1 && (0 || 0) = 0.

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    bool a = true, b = false, c = true;
    printf("%d ", a && b);
    printf("%d ", a || b);
    printf("%d ", !a);
    printf("%d ", !b && c);
    printf("%d ", (a && b) || c);
    printf("%d\n", a && (b || !c));
    return 0;
}
