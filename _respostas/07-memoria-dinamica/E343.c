// 0058 · Juntando tudo
// Exercício E343 · ★☆☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char buffer[100];
    char *nomes[3] = {NULL, NULL, NULL};

    for (int i = 0; i < 3; i++) {
        printf("Nome %d: ", i + 1);
        if (fgets(buffer, sizeof buffer, stdin) == NULL) {
            buffer[0] = '\0';
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        nomes[i] = malloc(strlen(buffer) + 1);
        if (nomes[i] == NULL) {
            for (int k = 0; k < i; k++) {
                free(nomes[k]);
            }
            return 1;
        }
        strcpy(nomes[i], buffer);
    }
    for (int i = 0; i < 3; i++) {
        printf("%s (%zu bytes)\n", nomes[i], strlen(nomes[i]) + 1);
        free(nomes[i]);
    }
    return 0;
}
// Exemplo de uso:
// Nome 1: Ana
// Nome 2: Joao Pedro
// Nome 3: Lu
// Ana (4 bytes)
// Joao Pedro (11 bytes)
// Lu (3 bytes)
