// Lista · Módulo 02 · Decisões
// Exercício P0228 · ★★★ · O saque-aniversário do FGTS
//
// No saque-aniversário, o valor liberado depende do saldo, numa tabela de
// alíquota mais parcela fixa:
//
//   até R$ 500.00             50%  + R$ 0.00
//   de 500.01 a 1000.00       40%  + R$ 50.00
//   de 1000.01 a 5000.00      30%  + R$ 150.00
//   de 5000.01 a 10000.00     20%  + R$ 650.00
//   de 10000.01 a 15000.00    15%  + R$ 1150.00
//   de 15000.01 a 20000.00    10%  + R$ 1900.00
//   acima de 20000.00          5%  + R$ 2900.00
//
// Escreva um programa que leia o saldo, confira a leitura e se o saldo não é
// negativo, e mostre a faixa, a alíquota e o valor do saque:
//
//   Saída esperada:
//   Saldo do FGTS: 3200.00
//   Faixa 3: 30% + R$ 150.00
//   Saque liberado: R$ 1110.00
//
// Dicas:
// 1. Uma cadeia de else if, do menor limite para o maior, guardando faixa,
//    aliquota e parcela em variáveis.
// 2. Faça a conta só uma vez, depois da cadeia: saldo * aliquota + parcela.
// 3. Para mostrar o %, use %% no printf.
// 4. Resposta esperada: com 3200.00, Saque liberado: R$ 1110.00.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
