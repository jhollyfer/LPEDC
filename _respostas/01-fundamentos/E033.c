// 0006 · scanf
// Exercício E033 · ★★☆

#include <stdio.h>

int main(void) {
    int hora = 0, minuto = 0;
    int lidos = scanf("%d:%d", &hora, &minuto);

    printf("Itens lidos: %d\n", lidos);
    printf("Alarme para %dh%02d\n", hora, minuto);
    printf("Alarme para %02d:%02d\n", hora, minuto);
    return 0;
}
