// 0042 · Lendo strings
// Exercício E247 · ★☆☆

#include <stdio.h>
#include <string.h>

int main(void) {
    char cidade[50];

    printf("Cidade: ");
    if (fgets(cidade, sizeof(cidade), stdin) == NULL) {
        printf("Nada foi digitado.\n");
        return 1;
    }
    cidade[strcspn(cidade, "\n")] = '\0';

    printf("Você mora em %s (%zu caracteres).\n", cidade, strlen(cidade));
    return 0;
}
