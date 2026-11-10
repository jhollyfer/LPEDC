// Lista · Módulo 06 · Ponteiros
// Exercício P0607 · ★☆☆ · A regra de desconto como parâmetro
//
// A loja tem três promoções, cada uma uma função double regra(double preco):
// - black_friday: 30% de desconto;
// - cupom10: R$ 10 a menos, mas nunca abaixo de zero;
// - leve_mais: 5% de desconto se o preço passar de R$ 100, senão nada.
//
// Escreva double total_com(const double *precos, int n, double
// (*regra)(double)),
// que soma os preços depois de aplicar a regra recebida em cada um. Para o
// carrinho abaixo, mostre o total sem desconto e com cada promoção:
//
//   double carrinho[4] = {129.90, 8.50, 45.00, 210.00};
//
//   Saída esperada:
//   Sem desconto  R$  393.40
//   Black Friday  R$  275.38
//   Cupom R$ 10   R$  354.90
//   Leve mais     R$  376.40
//
// Dicas:
// 1. Para "sem desconto", escreva também double nenhuma(double p) { return p;
//    }.
// 2. Dentro de total_com: soma += regra(precos[i]); chamar pelo ponteiro é
//    igual a chamar pelo nome.
// 3. Para não repetir o printf, guarde os ponteiros num vetor:
//    double (*regras[4])(double) = {nenhuma, black_friday, cupom10, leve_mais};
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    double carrinho[4] = {129.90, 8.50, 45.00, 210.00};
    (void) carrinho; // apague esta linha quando escrever

    return 0;
}
