// 0040 · Caracteres
// Exercício E236 · ★☆☆

#include <stdio.h>
#include <ctype.h>

int main(void) {
    printf("Depois de a: %c\n", 'a' + 1);
    printf("'7' vale %d\n", '7' - '0');
    printf("C em minúscula: %c\n", 'C' + ('a' - 'A'));
    printf("'B' antes de 'a'? %s\n", 'B' < 'a' ? "sim" : "não");
    printf("toupper('5') = %c, tolower('Q') = %c\n", toupper('5'), tolower('Q'));
    printf("Letras de a a z: %d\n", 'z' - 'a' + 1);
    return 0;
}
