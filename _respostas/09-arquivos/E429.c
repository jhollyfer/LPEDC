// 0072 · Arquivos texto
// Exercício E429 · ★★☆

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    const char *caminho = "/tmp/recado.txt";

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "Feira no domingo\n");
    fprintf(arq, "leve sacolas\n");
    fprintf(arq, "e o dinheiro do pastel\n");
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    int linhas = 0, palavras = 0, caracteres = 0;
    bool dentro_palavra = false;
    int c; // int, para caber o EOF
    while ((c = fgetc(arq)) != EOF) {
        caracteres++;
        if (c == '\n') {
            linhas++;
        }
        if (isspace(c)) {
            dentro_palavra = false;
        } else if (!dentro_palavra) {
            dentro_palavra = true;
            palavras++;
        }
    }
    fclose(arq);

    printf("Linhas: %d\n", linhas);
    printf("Palavras: %d\n", palavras);
    printf("Caracteres: %d\n", caracteres);
    return 0;
}
