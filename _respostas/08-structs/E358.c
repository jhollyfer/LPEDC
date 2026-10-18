// 0060 · Typedef
// Exercício E358 · ★★☆
//
// Resposta: (1) a ordem do typedef é "tipo existente, apelido":
// typedef double Reais; (2) a struct não tem nome, então "struct Cartao" não
// existe: use só Cartao; (3) o protótipo de pagar usava Cartao antes do
// typedef: ele precisa vir depois.

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
