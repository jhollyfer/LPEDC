// 0013 · Lógicos: E, OU, NÃO
// Exercício E077 · ★★★
//
// Do jeito antigo, a divisão vinha antes do teste e rodava mesmo com
// dias == 0. Com a proteção à esquerda, o curto-circuito pula a divisão.

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int gasto = 0, dias = 0;
    printf("Gasto total e dias: ");
    scanf("%d %d", &gasto, &dias);

    bool gasto_alto = dias != 0 && gasto / dias > 100;
    bool alerta = dias == 0 || gasto / dias > 100;

    printf("Gasto alto? %d\n", gasto_alto);
    printf("Alerta? %d\n", alerta);
    return 0;
}
