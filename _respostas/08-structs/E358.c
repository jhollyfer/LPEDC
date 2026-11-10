// 0060 · Typedef
// Exercício E358 · ★★☆

#include <stdio.h>

typedef double Reais;

typedef struct {
    char titular[20];
    Reais saldo;
} Cartao;

Cartao pagar(Cartao c, Reais valor);

int main(void) {
    Cartao c = {"Ana", 600.00};
    Cartao depois = pagar(c, 36.50);

    printf("%s: R$ %.2f -> R$ %.2f\n", c.titular, c.saldo, depois.saldo);
    return 0;
}

Cartao pagar(Cartao c, Reais valor) {
    c.saldo = c.saldo - valor;
    return c;
}
