// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0902 · ★☆☆ · Lista de chamada numerada

#include <stdio.h>
#include <string.h>

int main(void) {
    const char *caminho = "/tmp/p0902_chamada.txt";
    const char *nomes[4] = {"Ana Clara", "Bruno", "Iara Souza", "Joao"};

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        fprintf(arq, "%s\n", nomes[i]);
    }
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    char linha[100];
    int n = 0;
    while (fgets(linha, sizeof linha, arq) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        n++;
        printf("%d: %s (%zu caracteres)\n", n, linha, strlen(linha));
    }
    fclose(arq);
    remove(caminho);

    printf("Total: %d linhas\n", n);
    return 0;
}
