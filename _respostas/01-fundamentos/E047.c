// 0008 · Conversão e cast
// Exercício E047 · ★★★
//
// Resposta: o original mostra 1998. O 19.99 não existe exato em binário: o
// double guarda 19.989999999999998..., e 19.99 * 100 dá
// 1998.99999999999977. Na conversão para int, a parte fracionária é cortada:
// sobra 1998. Somando 0.5 antes, 1999.4999... é cortado para 1999.

#include <stdio.h>

int main(void) {
    double valor = 19.99;
    printf("valor * 100 de verdade: %.15f\n", valor * 100);

    int centavos = valor * 100 + 0.5; // arredonda para o inteiro mais próximo

    printf("R$ %.2f = %d centavos\n", valor, centavos);
    return 0;
}
