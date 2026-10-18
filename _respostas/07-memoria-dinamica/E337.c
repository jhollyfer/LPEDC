// 0057 · Erros de memória
// Exercício E337 · ★☆☆
//
// Vazavam 192 bytes em 3 blocos: 4 malloc de 64 bytes e só 1 free, o do
// último bloco. A cada volta, msg recebia um endereço novo e o anterior se
// perdia. O free agora fica dentro do laço, e os contadores mostram o
// balanço.

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
        free(msg); // cada aviso devolve o seu bloco
        liberados++;
    }
    printf("malloc: %d | free: %d\n", alocados, liberados);
    return 0;
}
// Saída:
// Aviso: Ônibus para Belém às 08h
// Aviso: Ônibus para Macapá às 09h
// Aviso: Ônibus para Santarém às 11h
// Aviso: Ônibus para Manaus às 14h
// malloc: 4 | free: 4
