// A001 · O Pix passo a passo

#include <stdio.h>

int main(void) {
    double saldo = 120.0; // entrada: quanto tem na conta
    double valor = 50.0;  // entrada: quanto quer mandar

    printf("Pix de R$ %.2f\n", valor);

    if (saldo >= valor) {                // decisão: o saldo cobre?
        saldo = saldo - valor;           // processamento: desconta
        printf("Pix enviado!\n");        // saída
        printf("Saldo: R$ %.2f\n", saldo);
    } else {
        printf("Saldo insuficiente.\n");
    }
    return 0;
}
// Saída:
// Pix de R$ 50.00
// Pix enviado!
// Saldo: R$ 70.00
