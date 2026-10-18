// 0012 · Relacionais e a verdade em C
// Exercício E068 · ★☆☆

#include <stdio.h>

int main(void) {
    int a = 0, b = 0;
    printf("Idades: ");
    scanf("%d %d", &a, &b);

    printf("%d >  %d? %d\n", a, b, a > b);
    printf("%d <  %d? %d\n", a, b, a < b);
    printf("%d >= %d? %d\n", a, b, a >= b);
    printf("%d <= %d? %d\n", a, b, a <= b);
    printf("%d == %d? %d\n", a, b, a == b);
    printf("%d != %d? %d\n", a, b, a != b);
    return 0;
}
