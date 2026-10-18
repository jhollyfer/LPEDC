// A058 · void, conversão e expressões como argumento

#include <stdio.h>

void mostrar_parcelas(double total, int vezes);
void linha(void);

int main(void) {
    double celular = 1800.00;

    linha();
    mostrar_parcelas(celular, 3);       // os tipos batem
    mostrar_parcelas(900, 2);           // 900 (int) vira 900.0 (double)
    mostrar_parcelas(celular * 0.9, 4); // a expressão é calculada antes
    mostrar_parcelas(celular, 2.9);     // 2.9 vira 2: a parte decimal some
    linha();
    // linha(5); // erro: linha foi declarada com (void), não aceita argumento
    return 0;
}

void mostrar_parcelas(double total, int vezes) {
    printf("%d x R$ %.2f\n", vezes, total / vezes);
}

void linha(void) {
    printf("--------------------\n");
}
// Saída:
// --------------------
// 3 x R$ 600.00
// 2 x R$ 450.00
// 4 x R$ 405.00
// 2 x R$ 900.00
// --------------------
