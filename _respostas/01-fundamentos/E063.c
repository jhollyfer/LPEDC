// 0011 · scanf
// Exercício E063 · ★★☆
//
// Resposta: com "6 05", o scanf lê o 6 e espera um ":"; acha um espaço,
// para ali e devolve 1. Os minutos continuam 0 (o valor inicial).

#include <stdio.h>

int main(void) {
    int hora = 0, minuto = 0;

    printf("Alarme (hh:mm): ");
    int lidos = scanf("%d:%d", &hora, &minuto);

    printf("Itens lidos: %d\n", lidos);
    printf("Alarme para %dh%02d\n", hora, minuto);
    printf("Alarme para %02d:%02d\n", hora, minuto);
    return 0;
}
