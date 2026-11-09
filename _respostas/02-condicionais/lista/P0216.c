// Lista · Módulo 02 · Decisões
// Exercício P0216 · ★★☆ · O cupom da loja virtual

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double compra = 80.00;
    bool vip = true;
    bool vencido = true;

    printf("Compra: R$ %.2f, VIP: %d, cupom vencido: %d\n", compra, vip, vencido);
    if ((vip || compra > 100) && !vencido) {
        printf("Cupom aplicado: 15%% de desconto.\n");
    } else {
        printf("Cupom recusado.\n");
    }
    return 0;
}
