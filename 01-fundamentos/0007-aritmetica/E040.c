// 0007 · Aritmética
// Exercício E040 · ★★☆
//
// Este programa compila e roda sem aviso nenhum, mas as duas médias estão
// erradas. As notas são 8, 7 e 8; a média certa é 7.67. Descubra os DOIS
// erros e conserte.
//
//   Saída esperada (depois de consertar):
//   Média 1: 7.67
//   Média 2: 7.67
//
// Dicas:
// 1. Faça as contas na mão, na ordem em que o C faz.
// 2. Na média 1, os dois lados da divisão são int. Na média 2, olhe a
//    precedência.
// 3. Resposta esperada: a média 1 mostra 7.00 porque 23 / 3 é divisão
//    inteira (7) antes de virar double: use 3.0. A média 2 mostra 17.67
//    porque só a terceira nota é dividida (8 + 7 + 8 / 3.0): faltam os
//    parênteses em volta da soma.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    int nota1 = 8, nota2 = 7, nota3 = 8;

    double media1 = (nota1 + nota2 + nota3) / 3;
    double media2 = nota1 + nota2 + nota3 / 3.0;

    printf("Média 1: %.2f\n", media1);
    printf("Média 2: %.2f\n", media2);
    return 0;
}
