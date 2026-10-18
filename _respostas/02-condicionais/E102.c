// 0017 · Ternário: condição ? a : b
// Exercício E102 · ★★★

#include <stdio.h>

int main(void) {
    int hora;
    printf("Hora (0 a 23): ");
    if (scanf("%d", &hora) != 1 || hora < 0 || hora > 23) {
        printf("Hora inválida.\n");
        return 1;
    }

    int h12 = hora % 12 == 0 ? 12 : hora % 12;
    printf("%d %s\n", h12, hora < 12 ? "AM" : "PM");
    return 0;
}
