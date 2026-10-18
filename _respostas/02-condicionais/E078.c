// 0013 · Lógicos: E, OU, NÃO
// Exercício E078 · ★★★
//
// Resposta: n & 1 == 0 é lido como n & (1 == 0), ou seja n & 0, que é
// sempre 0. 10 < n < 20 é (10 < n) < 20: 0 ou 1 comparado com 20, sempre 1.

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int n;
    printf("Número: ");
    scanf("%d", &n);

    bool par = (n & 1) == 0;
    bool na_faixa = n > 10 && n < 20;

    printf("Par? %d\n", par);
    printf("Entre 10 e 20? %d\n", na_faixa);
    return 0;
}
