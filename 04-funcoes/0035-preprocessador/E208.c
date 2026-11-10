// 0035 · Pré-processador: macros e #ifdef
// Exercício E208 · ★★☆
//
// Escreva um simulador de parcelas com modo de teste. Uma compra de R$ 1000.00
// em 4 parcelas com juros de 2% ao mês: cada parcela é o valor original
// dividido por 4, mais 2% de juros por mês de espera (a 1ª parcela tem 2%, a
// 2ª 4%, e assim por diante, juros simples). Mostre o total pago.
//
// Com "#define MODO_TESTE" no topo, mostre também cada parcela, com o prefixo
// "[teste]". Sem a linha, só o total. Use #ifdef; nada de if comum.
//
//   Saída esperada com MODO_TESTE:
//   [teste] parcela 1: 255.00
//   [teste] parcela 2: 260.00
//   [teste] parcela 3: 265.00
//   [teste] parcela 4: 270.00
//   Total: R$ 1050.00
//
//   Saída esperada sem MODO_TESTE:
//   Total: R$ 1050.00
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
