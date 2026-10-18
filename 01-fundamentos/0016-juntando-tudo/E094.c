// 0016 · Juntando tudo
// Exercício E094 · ★★☆
//
// O celular custa R$ 1299.00 e a loja parcela em 12 vezes com juros de
// 1.99% ao mês. A parcela fixa (tabela Price) é
//
//   parcela = valor * taxa / (1 - (1 + taxa) elevado a -n)
//
// Calcule a parcela, arredonde para centavos de verdade (não só na tela) e
// mostre o total pago e quanto foi de juros.
//
//   Saída esperada:
//   12x de R$ 122.76
//   Total: R$ 1473.12
//   Juros: R$ 174.12
//
// Dicas:
// 1. taxa = 0.0199; pow aceita expoente negativo: pow(1 + taxa, -12).
// 2. Arredondar para centavos: round(parcela * 100) / 100.
// 3. Resposta esperada: parcela 122.76 (era 122.7577...); total 12 * 122.76
//    = 1473.12; juros 1473.12 - 1299.00 = 174.12.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>

int main(void) {

    return 0;
}
