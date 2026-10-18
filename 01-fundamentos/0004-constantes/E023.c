// 0004 · Constantes
// Exercício E023 · ★★★
//
// Alguém quis guardar o pi numa constante e calcular o comprimento de uma
// pista circular de raio 10 m (2 * pi * raio). O programa compila sem aviso
// nenhum, mas mostra 60 m. Conserte o código de dois jeitos, e deixe os
// dois no programa: na primeira linha, com uma const do tipo certo; na
// segunda, com um #define PI.
//
//   Saída esperada (depois de consertar):
//   Comprimento (const):  62.83 m
//   Comprimento (define): 62.83 m
//
// Dicas:
// 1. const não muda o tipo: pi continua sendo um int, que guarda só a parte
//    inteira de 3.14159. Sobra 2 * 3 * 10 = 60.
// 2. Com o tipo real, o resultado da conta também é real: troque o %d.
// 3. Resposta esperada: const double pi = 3.14159; e #define PI 3.14159,
//    com %.2f nos dois printf.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int main(void) {
    const int pi = 3.14159;
    int raio = 10;

    printf("Comprimento (const):  %d m\n", 2 * pi * raio);
    return 0;
}
