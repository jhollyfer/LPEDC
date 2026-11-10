// Lista · Módulo 02 · Decisões
// Exercício P0216 · ★★☆ · O cupom da loja virtual
//
// A regra da promoção é: o cupom vale para cliente VIP ou para compra acima de
// R$ 100, mas em qualquer caso só se o cupom não estiver vencido. O programa
// abaixo dá desconto para um VIP com cupom vencido, porque o && é feito antes
// do ||. O erro está lá de propósito: conserte a condição com parênteses:
//
//   Saída esperada:
//   Compra: R$ 80.00, VIP: 1, cupom vencido: 1
//   Cupom recusado.
//
// Dicas:
// 1. vip || compra > 100 && !vencido é lido como vip || (compra > 100 &&
//    !vencido).
// 2. Agrupe o que vem antes do "mas": (vip || compra > 100) && !vencido.
// 3. Resposta esperada: Cupom recusado.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double compra = 80.00;
    bool vip = true;
    bool vencido = true;

    printf("Compra: R$ %.2f, VIP: %d, cupom vencido: %d\n", compra, vip, vencido);
    if (vip || compra > 100 && !vencido) {
        printf("Cupom aplicado: 15%% de desconto.\n");
    } else {
        printf("Cupom recusado.\n");
    }
    return 0;
}
