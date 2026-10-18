// 0055 · Ponteiro para função
// Exercício E327 · ★★☆
//
// Faça uma calculadora SEM switch. Escreva soma, subtrai, multiplica e
// divide, todas com a assinatura int f(int, int), e guarde-as num vetor de
// ponteiros para função:
//
//   int (*ops[4])(int, int) = {soma, subtrai, multiplica, divide};
//
// Leia uma conta no formato "12 * 4" com scanf("%d %c %d", ...), ache o
// índice do operador na string "+-*/" e chame ops[indice](a, b). Operador
// desconhecido mostra "Operador inválido"; divisão por zero mostra
// "Divisão por zero".
//
//   Digite a conta: 12 * 4
//   Resultado: 48
//
// Dicas:
// 1. Para achar o índice: percorra "+-*/" com um for até achar o char.
// 2. Confira o retorno do scanf (tem que ser 3).
// 3. Resposta esperada: 12 * 4 dá 48; 20 / 3 dá 6 (divisão inteira);
//    7 % 2 dá "Operador inválido".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
