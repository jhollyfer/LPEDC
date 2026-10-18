// A005 · O estacionamento do shopping

#include <stdio.h>

int main(void) {
    int minutos = 40;

    if (minutos <= 15) {
        printf("Grátis. Boa compra!\n");
    } else {
        printf("Valor: R$ 8.00\n");
    }
    return 0;
}
// Saída:
// Valor: R$ 8.00
