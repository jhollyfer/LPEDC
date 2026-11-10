// 0013 · Lógicos: E, OU, NÃO
// Exercício E077 · ★★★

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int gasto = 0, dias = 0;
    scanf("%d %d", &gasto, &dias);

    bool gasto_alto = dias != 0 && gasto / dias > 100;
    bool alerta = dias == 0 || gasto / dias > 100;

    printf("Gasto alto? %d\n", gasto_alto);
    printf("Alerta? %d\n", alerta);
    return 0;
}
