// 0050 · Ponteiros
// Exercício E300 · ★★★
//
// Você tem três contas: conta_a com R$ -50.25 (no cheque especial),
// conta_b com R$ 300.00 e conta_c com R$ 12.00. Escreva um programa que:
//
//   1. faça um ponteiro menor apontar para a conta de menor saldo;
//   2. se esse saldo for negativo, guarde o endereço num segundo ponteiro
//      negativa; senão, deixe negativa = NULL;
//   3. se negativa não for NULL, zere a conta pelo ponteiro (você cobriu o
//      negativo) e mostre quanto precisou pôr; senão, mostre
//      "Nenhuma conta negativa";
//   4. mostre as três contas no fim.
//
// Teste também trocando conta_a para 50.25: deve aparecer a outra mensagem.
//
//   Saída esperada:
//   Cobri R$ 50.25
//   A: 0.00  B: 300.00  C: 12.00
//
// Dicas:
// 1. Comece com menor = &conta_a e compare *menor com as outras.
// 2. Para saber quanto pôr antes de zerar: -(*negativa).
// 3. Resposta esperada: a conta A é a menor e negativa; cobre R$ 50.25 e
//    ela vira 0.00. Com 50.25, a menor é C (12.00) e aparece
//    "Nenhuma conta negativa".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
