// Lista · Módulo 03 · Laços
// Exercício P0326 · ★★★ · A tabela do empréstimo
//
// Você pegou R$ 1200.00 emprestado em 6 parcelas iguais, com juros de 2% ao
// mês (tabela Price). A parcela é P = V · i / (1 − (1 + i)^−n). Todo mês, os
// juros são i vezes o saldo devedor, e o resto da parcela amortiza a dívida.
// Escreva um programa que mostre a tabela mês a mês e, no fim, o total pago e
// o total de juros:
//
//   Saída esperada:
//   Parcela: R$ 214.23
//   Mês  Juros   Amortização  Saldo
//    1   24.00      190.23   1009.77
//    2   20.20      194.04    815.73
//    3   16.31      197.92    617.82
//    4   12.36      201.87    415.94
//    5    8.32      205.91    210.03
//    6    4.20      210.03      0.00
//   Total pago: R$ 1285.39
//   Total de juros: R$ 85.39
//
// Dicas:
// 1. pow(1 + i, -n) faz o (1 + i) elevado a −n.
// 2. Dentro do laço: juros = saldo * i; amortizacao = parcela - juros; saldo
//    -= amortizacao; some os juros num acumulador.
// 3. No último mês, o saldo pode dar -0.00 por causa do arredondamento: use
//    fabs(saldo) < 0.005 para mostrar 0.00.
// 4. Resposta esperada: Total de juros: R$ 85.39.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

int main(void) {

    return 0;
}
