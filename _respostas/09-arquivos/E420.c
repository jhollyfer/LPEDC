// 0070 · Juntando tudo
// Exercício E420 · ★★★

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    bool so_contar = false;
    int i_palavra;
    if (argc == 4 && strcmp(argv[1], "-c") == 0) {
        so_contar = true;
        i_palavra = 2;
    } else if (argc == 3) {
        i_palavra = 1;
    } else {
        fprintf(stderr, "Uso: %s [-c] <palavra> <arquivo>\n", argv[0]);
        return 2;
    }
    const char *palavra = argv[i_palavra];
    const char *caminho = argv[i_palavra + 1];

    FILE *arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 2;
    }
    char linha[256];
    int numero = 0, achadas = 0;
    while (fgets(linha, sizeof linha, arq) != NULL) {
        numero++;
        if (strstr(linha, palavra) != NULL) {
            achadas++;
            if (!so_contar) {
                printf("%d: %s", numero, linha);
            }
        }
    }
    fclose(arq);

    if (so_contar) {
        printf("%d\n", achadas);
    } else {
        printf("%d linhas\n", achadas);
    }
    return achadas > 0 ? 0 : 1;
}
