// 0046 · Strings
// Exercício E275 · ★★★
//
// Resposta: char uf[2] = "RJ" não tem lugar para o '\0' (o C aceita sem
// avisar, e o strcat lê além do vetor): use uf[3]; local[10] não cabe os 20
// bytes do endereço (estouro no strcat): use local[30]; cidade == "Rio"
// compara endereços, não texto: use strcmp(cidade, "Rio") == 0.

#include <stdio.h>
#include <string.h>

int main(void) {
    char uf[3] = "RJ";
    char cidade[] = "Rio";
    char local[30];

    strcpy(local, cidade);
    strcat(local, " de Janeiro - ");
    strcat(local, uf);
    printf("%s\n", local);

    if (strcmp(cidade, "Rio") == 0) {
        printf("Cidade conferida.\n");
    }
    return 0;
}
