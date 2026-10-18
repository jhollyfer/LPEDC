// A061 · O valor que desce a pilha, quadro por quadro

#include <stdio.h>

// topo da pilha: não chama ninguém, só devolve
double tarifa_base(void) {
    double valor = 5.00;
    printf("      tarifa_base devolve %.2f\n", valor);
    return valor;
}

double com_integracao(void) {
    double valor = 1.50; // outro "valor": cada quadro tem o seu
    printf("    com_integracao espera (o seu valor é %.2f)\n", valor);
    valor = valor + tarifa_base();
    printf("    com_integracao devolve %.2f\n", valor);
    return valor;
}

double meia_passagem(void) {
    double valor = 0.50;
    printf("  meia_passagem espera (o seu valor é %.2f)\n", valor);
    valor = com_integracao() * valor;
    printf("  meia_passagem devolve %.2f\n", valor);
    return valor;
}

int main(void) {
    double valor = 0; // o do main fica parado esperando lá embaixo

    printf("main espera\n");
    valor = meia_passagem();
    printf("main recebe %.2f\n", valor);
    return 0;
}
// Saída:
// main espera
//   meia_passagem espera (o seu valor é 0.50)
//     com_integracao espera (o seu valor é 1.50)
//       tarifa_base devolve 5.00
//     com_integracao devolve 6.50
//   meia_passagem devolve 3.25
// main recebe 3.25
