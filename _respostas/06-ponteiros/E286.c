// 0048 · Ponteiros e strings
// Exercício E286 · ★★☆

#include <stdio.h>
#include <string.h>

int main(void) {
    char saudacao[] = "ola, visitante!";
    char bloco[2];
    char morador[10] = "ana";

    saudacao[0] = 'O';
    printf("%s\n", saudacao);

    strcpy(bloco, "B");
    printf("Bloco: %s\n", bloco);

    if (strcmp(morador, "ana") == 0) {
        printf("Mesmo morador\n");
    }
    return 0;
}
