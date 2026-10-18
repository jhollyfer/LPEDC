// A065 · O preço da corrida, calculado num lugar só

#include <stdio.h>

// protótipo: avisa o compilador que a função existe e como chamá-la
double preco_corrida(double km);

int main(void) {
    printf("Corrida 1: R$ %.2f\n", preco_corrida(4.0));
    printf("Corrida 2: R$ %.2f\n", preco_corrida(10.0));
    printf("Corrida 3: R$ %.2f\n", preco_corrida(2.5));
    return 0;
}

// definição: bandeirada de R$ 5.00 mais R$ 2.50 por km
double preco_corrida(double km) {
    double preco = 5.00 + 2.50 * km;
    return preco; // devolve o valor para quem chamou
}
// Saída:
// Corrida 1: R$ 15.00
// Corrida 2: R$ 30.00
// Corrida 3: R$ 11.25
