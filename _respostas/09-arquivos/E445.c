// 0075 · Juntando tudo
// Exercício E445 · ★☆☆

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <arquivo> <nome> <palpite>\n", argv[0]);
        return 1;
    }
    FILE *arq = fopen(argv[1], "a");
    if (arq == NULL) {
        perror(argv[1]);
        return 1;
    }
    fprintf(arq, "%s %s\n", argv[2], argv[3]);
    fclose(arq);

    arq = fopen(argv[1], "r");
    if (arq == NULL) {
        perror(argv[1]);
        return 1;
    }
    char linha[100];
    int n = 0;
    while (fgets(linha, sizeof linha, arq) != NULL) {
        n++;
        printf("%d. %s", n, linha);
    }
    fclose(arq);
    return 0;
}
