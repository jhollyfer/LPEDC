// 0040 · Caracteres
// Exercício E235 · ★☆☆

#include <stdio.h>

int main(void) {
    char simbolos[] = {'A', 'Z', 'a', 'z', '0', '9', ' ', '@'};
    int n = sizeof(simbolos) / sizeof(simbolos[0]);

    for (int i = 0; i < n; i++) {
        printf("'%c' = %d\n", simbolos[i], simbolos[i]);
    }
    putchar(72);
    putchar(105);
    putchar(33);
    putchar('\n');
    return 0;
}
