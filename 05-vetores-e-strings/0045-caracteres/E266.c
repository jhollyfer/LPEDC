// 0045 · Caracteres
// Exercício E266 · ★☆☆
//
// Sem rodar, preveja cada linha. Depois rode e confira.
//
//   printf("%c\n", 'a' + 1);
//   printf("%d\n", '7' - '0');
//   printf("%c\n", 'C' + 32);
//   printf("%d\n", 'B' > 'a');
//   printf("%c%c\n", toupper('5'), tolower('Q'));
//   printf("%d\n", 'z' - 'a' + 1);
//
// Dicas:
// 1. 'a' é 97, 'A' é 65, '0' é 48. Faça as contas com os códigos.
// 2. Toda maiúscula vem ANTES de toda minúscula na tabela.
// 3. toupper de algo que não é letra devolve o mesmo caractere.
// 4. Resposta esperada: b, 7, c, 0, 5q e 26.
//
// Escreva sua resposta abaixo (o código está pronto para conferir):

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
