// 0019 · Juntando tudo: a conta de luz
// Exercício E112 · ★★☆

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int categoria, hora;
    double tarifa = 0;

    if (scanf("%d", &categoria) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    switch (categoria) {
    case 1:
        tarifa = 6.00;
        break;
    case 2:
        tarifa = 12.00;
        break;
    case 3: {
        int eixos;
        if (scanf("%d", &eixos) != 1) {
            printf("Entrada inválida\n");
            return 1;
        }
        tarifa = 12.00 * eixos;
        break;
    }
    default:
        printf("Categoria inválida.\n");
        return 1;
    }

    if (scanf("%d", &hora) != 1) {
        printf("Entrada inválida\n");
        return 1;
    }

    bool pico = hora >= 17 && hora < 20;
    tarifa = pico ? tarifa * 1.2 : tarifa;

    printf("Horário de pico? %s\n", pico ? "sim" : "não");
    printf("Tarifa: R$ %.2f\n", tarifa);
    return 0;
}
