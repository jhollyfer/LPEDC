// Lista · Módulo 04 · Funções e modularização
// Exercício P0404 · ★☆☆ · O reajuste que não chegou
//
// O programa abaixo chama aplicar_reajuste para dar 5% de aumento ao salário
// de R$ 2400.00, mas o salário continua igual depois da chamada. O erro está
// lá de propósito: a função recebe uma cópia. Conserte trocando a função por
// "double com_reajuste(double salario)", que devolve o novo valor, e guarde o
// retorno no main:
//
//   Saída esperada:
//   Antes: R$ 2400.00
//   Depois: R$ 2520.00
//
// Dicas:
// 1. Em C, o parâmetro é uma variável nova, que recebe uma cópia do argumento.
//    Mudar a cópia não muda o original.
// 2. salario = com_reajuste(salario); no main.
// 3. Resposta esperada: Depois: R$ 2520.00.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

void aplicar_reajuste(double salario) {
    salario = salario * 1.05;
    printf("(dentro da função: R$ %.2f)\n", salario);
}

int main(void) {
    double salario = 2400.00;

    printf("Antes: R$ %.2f\n", salario);
    aplicar_reajuste(salario);
    printf("Depois: R$ %.2f\n", salario);
    return 0;
}
