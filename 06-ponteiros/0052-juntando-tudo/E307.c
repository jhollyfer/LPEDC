// 0052 · Juntando tudo: o ranking da feira
// Exercício E307 · ★☆☆
//
// O caixa da padaria precisa separar reais e centavos para imprimir o
// cupom. Escreva
//
//   void separa(double valor, int *reais, int *centavos)
//
// e teste com 37.85, 0.99 e 19.99.
//
//   Saída esperada:
//   R$ 37.85 = 37 reais e 85 centavos
//   R$ 0.99 = 0 reais e 99 centavos
//   R$ 19.99 = 19 reais e 99 centavos
//
// Dicas:
// 1. Converta tudo para centavos primeiro: long total = lround(valor * 100);
//    (math.h). Por que lround e não um cast direto? Teste (int)(19.99 * 100).
// 2. Depois, *reais = total / 100 e *centavos = total % 100.
// 3. Resposta esperada: as três linhas acima. Com cast direto, 19.99 * 100
//    vira 1998.9999... e o cast corta para 98 centavos.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>

int main(void) {

    return 0;
}
