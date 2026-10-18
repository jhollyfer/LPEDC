// 0002 · Variáveis
// Exercício E012 · ★★★

#include <stdio.h>

int main(void) {
    char letra = 'A';
    printf("%c %d\n", letra, letra);   // A 65

    letra = 66;                        // o código do B
    printf("%c\n", letra);             // B

    letra = '7';                       // o caractere sete
    printf("%c %d\n", letra, letra);   // 7 55

    letra = 32;                        // o código do espaço
    printf("[%c] %d\n", letra, letra); // [ ] 32

    printf("'7' vale %d, 7 vale %d\n", '7', 7);
    return 0;
}
