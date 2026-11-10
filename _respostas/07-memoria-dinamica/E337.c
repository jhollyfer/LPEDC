// 0057 · Erros de memória
// Exercício E337 · ★☆☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *destinos[] = {"Belém", "Macapá", "Santarém", "Manaus"};
    const char *horas[] = {"08h", "09h", "11h", "14h"};
    int alocados = 0;
    int liberados = 0;

    for (int i = 0; i < 4; i++) {
        char *msg = malloc(64);
        if (msg == NULL) {
            return 1;
        }
        alocados++;
        strcpy(msg, "Ônibus para ");
        strcat(msg, destinos[i]);
        strcat(msg, " às ");
        strcat(msg, horas[i]);
        printf("Aviso: %s\n", msg);
        free(msg);
        liberados++;
    }
    printf("malloc: %d | free: %d\n", alocados, liberados);
    return 0;
}
