// Lista · Módulo 06 · Ponteiros
// Exercício P0603 · ★☆☆ · Rachando a conta do bar
//
// Escreva
//
//   bool rachar(double total, int pessoas, double *por_pessoa, double *gorjeta)
//
// que calcula os 10% do garçom (em *gorjeta) e quanto cada pessoa paga com a
// gorjeta incluída (em *por_pessoa). Se pessoas for menor que 1, a função
// devolve false e não mexe em nada. Teste com R$ 186.00 para 4 pessoas,
// R$ 95.50 para 3 e R$ 50.00 para 0:
//
//   Saída esperada:
//   R$ 186.00 / 4: gorjeta R$ 18.60, cada um paga R$ 51.15
//   R$ 95.50 / 3: gorjeta R$ 9.55, cada um paga R$ 35.02
//   R$ 50.00 / 0: ninguém para pagar
//
// Dicas:
// 1. *gorjeta = total * 0.10; *por_pessoa = (total + *gorjeta) / pessoas;
// 2. No main, declare double cada, gorjeta; e passe &cada e &gorjeta.
// 3. Teste o retorno antes de usar os valores: se a função devolveu false,
//    eles não foram preenchidos.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
