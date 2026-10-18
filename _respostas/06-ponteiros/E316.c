// 0053 · Ponteiros e strings
// Exercício E316 · ★★☆
//
// Resposta: (1) saudacao apontava para um literal, que é só leitura: vira
// um vetor (cópia); (2) bloco era um ponteiro sem alvo: vira um vetor de 2;
// (3) == comparava endereços: o certo é strcmp.

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
