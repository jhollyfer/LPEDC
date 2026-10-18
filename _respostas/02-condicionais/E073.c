// 0013 · Lógicos: E, OU, NÃO
// Exercício E073 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    bool a, b;
    printf("a b | E OU NAO\n");

    a = false;
    b = false;
    printf("%d %d | %d %d  %d\n", a, b, a && b, a || b, !a);

    a = false;
    b = true;
    printf("%d %d | %d %d  %d\n", a, b, a && b, a || b, !a);

    a = true;
    b = false;
    printf("%d %d | %d %d  %d\n", a, b, a && b, a || b, !a);

    a = true;
    b = true;
    printf("%d %d | %d %d  %d\n", a, b, a && b, a || b, !a);
    return 0;
}
