// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0919 · ★★☆ · A votação em que o "sim" nunca vence

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *caminho = "/tmp/p0919_votos.txt";
    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "sim\nnao\nsim\nsim"); // a última linha não tem '\n'
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    char linha[16];
    int sim = 0, nao = 0, invalidos = 0;
    while (fgets(linha, sizeof linha, arq) != NULL) {
        linha[strcspn(linha, "\n")] = '\0'; // só corta se houver '\n'
        if (strcmp(linha, "sim") == 0) {      // strcmp devolve 0 quando são iguais
            sim++;
        } else if (strcmp(linha, "nao") == 0) {
            nao++;
        } else {
            invalidos++;
        }
    }
    fclose(arq);
    remove(caminho);

    printf("Votos sim: %d, não: %d, inválidos: %d\n", sim, nao, invalidos);
    return 0;
}
