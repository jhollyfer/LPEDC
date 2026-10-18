// A033 · O ternário que protege a divisão

#include <stdio.h>

int main(void) {
    int vendido = 0; // o food truck ainda não abriu
    int dias = 0;

    // só um dos lados é calculado: com dias == 0, a divisão nem acontece
    double media = dias != 0 ? (double) vendido / dias : 0.0;
    printf("Média por dia: R$ %.2f\n", media);
    printf("Situação: %s\n", dias != 0 ? "funcionando" : "ainda não abriu");

    // os dois lados viram um tipo comum: int com double dá double
    int pedidos = 3;
    printf("Fator: %.1f\n", pedidos > 0 ? pedidos : 0.5); // sai 3.0, não 3

    // no meio de uma conta, o ternário vai entre parênteses
    double taxa = 5.0 + (pedidos > 2 ? 2.5 : 0.0);
    printf("Taxa de entrega: R$ %.2f\n", taxa);
    return 0;
}
// Saída:
// Média por dia: R$ 0.00
// Situação: ainda não abriu
// Fator: 3.0
// Taxa de entrega: R$ 7.50
