// 0042 · Lendo strings
// Exercício E249 · ★★☆
//
// Resposta: o scanf("%d") lê o 2 e deixa o '\n' na entrada; o fgets acha esse
// '\n' na hora e devolve uma linha vazia. Conserto: descartar o resto da
// linha logo depois do scanf.

#include <stdio.h>
#include <string.h>

int main(void) {
    int quantidade;
    char nome[40];

    printf("Quantidade de ingressos: ");
    if (scanf("%d", &quantidade) != 1) {
        return 1;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }

    printf("Nome do comprador: ");
    if (fgets(nome, sizeof(nome), stdin) == NULL) {
        return 1;
    }
    nome[strcspn(nome, "\n")] = '\0';

    printf("%d ingresso(s) para %s\n", quantidade, nome);
    return 0;
}
