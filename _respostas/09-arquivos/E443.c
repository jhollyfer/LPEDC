// 0074 · Argumentos da linha de comando
// Exercício E443 · ★★★

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }
    FILE *arq = fopen(argv[1], "r");
    if (arq == NULL) {
        perror(argv[1]);
        return 1;
    }
    long linhas = 0, palavras = 0, bytes = 0;
    bool dentro_palavra = false;
    int c;
    while ((c = fgetc(arq)) != EOF) {
        bytes++;
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
    printf("%ld linhas, %ld palavras, %ld bytes em %s\n", linhas, palavras, bytes, argv[1]);
    return 0;
}
