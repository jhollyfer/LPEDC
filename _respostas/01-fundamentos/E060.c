// 0010 · printf
// Exercício E060 · ★★★
//
// Resposta:
//   [3456.8]        a largura 5 é mínima: o número sai inteiro
//   [Bra]           em %s, a precisão é o máximo de caracteres
//   [2.67]          2.675 vira 2.67499999... em binário, e arredonda para baixo
//   [1.234560e+05]  1,23456 x 10 elevado a 5
//   [0.0001] [1e-05]  o %g muda para científico com expoente menor que -4
//   Pão
//   [5]             P (1) + ã (2) + o (1) + \n (1) = 5 bytes

#include <stdio.h>

int main(void) {
    printf("[%5.1f]\n", 3456.78);
    printf("[%.3s]\n", "Brasília");
    printf("[%.2f]\n", 2.675);
    printf("[%e]\n", 123456.0);
    printf("[%g] [%g]\n", 0.0001, 0.00001);
    int n = printf("Pão\n");
    printf("[%d]\n", n);
    return 0;
}
