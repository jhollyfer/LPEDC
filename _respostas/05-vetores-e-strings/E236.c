// 0040 · Caracteres
// Exercício E236 · ★☆☆
//
// Resposta:
//   b    97 + 1 = 98
//   7    55 - 48
//   c    67 + 32 = 99
//   0    'B' (66) não é maior que 'a' (97): maiúsculas vêm antes
//   5q   toupper não mexe no '5'; tolower('Q') é 'q'
//   26   122 - 97 + 1: as letras do alfabeto

#include <stdio.h>
#include <ctype.h>

int main(void) {
    printf("%c\n", 'a' + 1);
    printf("%d\n", '7' - '0');
    printf("%c\n", 'C' + 32);
    printf("%d\n", 'B' > 'a');
    printf("%c%c\n", toupper('5'), tolower('Q'));
    printf("%d\n", 'z' - 'a' + 1);
    return 0;
}
