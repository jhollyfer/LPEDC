// 0037 · Vetores
// Exercício E218 · ★☆☆
//
// Sem rodar, preveja o que cada printf mostra. Depois rode e confira.
//
//   int a[5] = {4, 2};
//   int b[] = {7, 8, 9};
//   int i = 4;
//
//   printf("%d %d\n", a[1], a[3]);
//   printf("%zu\n", sizeof(b) / sizeof(b[0]));
//   printf("%d\n", b[i % 3]);
//   printf("%d\n", a[i] + b[2]);
//   b[0] = b[0] + b[1];
//   printf("%d\n", b[0]);
//
// Dicas:
// 1. Na inicialização parcial, as posições que faltam viram 0.
// 2. Sem tamanho, o compilador conta os valores entre as chaves.
// 3. 4 % 3 é 1.
// 4. Resposta esperada: "2 0", "3", "8", "9" e "15".
//
// Escreva sua resposta abaixo (o código já está pronto para conferir):

#include <stdio.h>

int main(void) {
    int a[5] = {4, 2};
    int b[] = {7, 8, 9};
    int i = 4;

    printf("%d %d\n", a[1], a[3]);
    printf("%zu\n", sizeof(b) / sizeof(b[0]));
    printf("%d\n", b[i % 3]);
    printf("%d\n", a[i] + b[2]);
    b[0] = b[0] + b[1];
    printf("%d\n", b[0]);
    return 0;
}
