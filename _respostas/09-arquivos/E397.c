// 0067 · Arquivos texto
// Exercício E397 · ★☆☆

#include <stdio.h>

int main(void) {
    const char *caminho = "/tmp/tabuada7.txt";

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    for (int i = 1; i <= 10; i++) {
        fprintf(arq, "7 x %d = %d\n", i, 7 * i);
    }
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    char linha[40];
    while (fgets(linha, sizeof linha, arq) != NULL) {
        printf("%s", linha);
    }
    fclose(arq);
    return 0;
}
