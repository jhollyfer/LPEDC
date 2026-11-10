// 0042 · Lendo strings
// Exercício E249 · ★★☆

#include <stdio.h>
#include <string.h>

int main(void) {
    int quantidade;
    char nome[40];

    if (scanf("%d", &quantidade) != 1) {
        return 1;
    }
    // descarta o resto da linha, senão o fgets pega o '\n' que sobrou
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }

    if (fgets(nome, sizeof(nome), stdin) == NULL) {
        return 1;
    }
    nome[strcspn(nome, "\n")] = '\0';

    printf("%d ingresso(s) para %s\n", quantidade, nome);
    return 0;
}
