// Lista · Módulo 02 · Decisões
// Exercício P0229 · ★★★ · A tarifa do aplicativo de corrida

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double km = 10.0;
    int minutos = 20;
    int dia = 6, hora = 23;  // sábado, 23h
    bool chovendo = false;
    bool tem_cupom = true;

    double preco = 4.00 + 1.80 * km + 0.35 * minutos;
    printf("Preço base: R$ %.2f\n", preco);

    bool dinamica = chovendo || ((dia == 5 || dia == 6) && hora >= 22);
    if (dinamica) {
        preco *= 1.5;
    }
    printf("Dinâmica: %s\n", dinamica ? "sim (x1.5)" : "não");

    if (preco < 9.00) {
        preco = 9.00;
    }
    printf("Antes do cupom: R$ %.2f\n", preco);

    double desconto = 0.0;
    if (tem_cupom) {
        desconto = preco * 0.10 > 8.00 ? 8.00 : preco * 0.10;
    }
    printf("Desconto do cupom: R$ %.2f\n", desconto);
    printf("Total: R$ %.2f\n", preco - desconto);
    return 0;
}
