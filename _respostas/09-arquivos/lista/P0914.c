// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0914 · ★★☆ · O extrato com sujeira

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *caminho = "/tmp/p0914_extrato.txt";
    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "150 abc 32 -10 x9 20 7a\n");
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    char palavra[32];
    char ignorados[256] = "";
    long soma = 0;
    int validos = 0;
    while (fscanf(arq, "%31s", palavra) == 1) {
        char *fim;
        long v = strtol(palavra, &fim, 10);
        if (fim != palavra && *fim == '\0') {
            soma += v;
            validos++;
        } else if (strlen(ignorados) + strlen(palavra) + 2 < sizeof ignorados) {
            strcat(ignorados, " ");
            strcat(ignorados, palavra);
        }
    }
    fclose(arq);
    remove(caminho);

    printf("Válidos: %d (soma %ld)\n", validos, soma);
    printf("Ignorados:%s\n", ignorados);
    return 0;
}
