// A060 · Os divisores de 28: contar, somar e levantar uma flag

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int n = 28;
    int quantos = 0;      // contador: começa em 0
    int soma = 0;         // acumulador de soma: começa em 0
    long produto = 1;     // acumulador de produto: começa em 1!

    printf("Divisores de %d:", n);
    for (int d = 1; d <= n; d++) {
        if (n % d == 0) {
            printf(" %d", d);
            quantos++;
            if (d < n) {
                soma += d; // só os divisores próprios (menores que n)
            }
            produto *= d;
        }
    }
    printf("\n");

    bool perfeito = (soma == n); // a flag pode nascer de uma comparação
    printf("Quantos: %d\n", quantos);
    printf("Soma dos próprios: %d\n", soma);
    printf("Produto de todos: %ld\n", produto);
    printf("%d é perfeito? %s\n", n, perfeito ? "sim" : "não");
    return 0;
}
// Saída:
// Divisores de 28: 1 2 4 7 14 28
// Quantos: 6
// Soma dos próprios: 28
// Produto de todos: 21952
// 28 é perfeito? sim
