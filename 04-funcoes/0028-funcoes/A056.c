// A056 · Funções que só fazem e funções que respondem

#include <stdio.h>

void cabecalho(void);
double menor(double a, double b);

int main(void) {
    double posto_a = 5.89;
    double posto_b = 5.79;
    double posto_c = 5.95;

    cabecalho(); // void: só faz, não devolve nada
    double mais_barato = menor(menor(posto_a, posto_b), posto_c);
    printf("Mais barato: R$ %.2f\n", mais_barato);
    printf("Encher 40 litros: R$ %.2f\n", 40 * mais_barato);
    return 0;
}

void cabecalho(void) {
    printf("=== Gasolina hoje ===\n");
}

double menor(double a, double b) {
    if (a < b) {
        return a; // o return encerra a função na hora
    }
    return b; // só chega aqui se a >= b
}
// Saída:
// === Gasolina hoje ===
// Mais barato: R$ 5.79
// Encher 40 litros: R$ 231.60
