// 0060 · Typedef
// Exercício E359 · ★★★
//
// Ponteiro para função (assunto 0050) tem uma declaração difícil de ler:
// double (*f)(double, double). Com typedef ela fica limpa. Crie:
//
//   typedef double (*Operacao)(double, double);
//
// e um tipo Botao (struct com um char simbolo e uma Operacao). Monte um
// vetor com os quatro botões de uma calculadora (+ - * /) e, num laço, aplique
// cada um aos números 12 e 4.
//
//   Saída esperada:
//   12 + 4 = 16
//   12 - 4 = 8
//   12 * 4 = 48
//   12 / 4 = 3
//
// Dicas:
// 1. Escreva as quatro funções: double somar(double a, double b) etc.
// 2. Botao botoes[] = {{'+', somar}, {'-', subtrair}, ...};
// 3. Chame com botoes[i].f(12, 4). %g mostra 16 em vez de 16.000000.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
