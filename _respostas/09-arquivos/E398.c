// 0067 · Arquivos texto
// Exercício E398 · ★☆☆

#include <stdio.h>
#include <string.h>

void grava(const char *caminho, const char *modo, const char *nome) {
    FILE *arq = fopen(caminho, modo);
    if (arq == NULL) {
        perror(caminho);
        return;
    }
    fprintf(arq, "%s\n", nome);
    fclose(arq);
}

void mostra(const char *caminho) {
    FILE *arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return;
    }
    char linha[50];
    while (fgets(linha, sizeof linha, arq) != NULL) {
        linha[strcspn(linha, "\n")] = '\0'; // tira o '\n'
        printf(" %s", linha);
    }
    fclose(arq);
}

int main(void) {
    const char *caminho = "/tmp/fila.txt";
    grava(caminho, "w", "Ana");
    printf("w Ana  ->");
    mostra(caminho);
    printf("\n");

    grava(caminho, "a", "Bia");
    printf("a Bia  ->");
    mostra(caminho);
    printf("\n");

    grava(caminho, "w", "Caio"); // "w" apaga Ana e Bia
    printf("w Caio ->");
    mostra(caminho);
    printf("\n");

    grava(caminho, "a", "Duda");
    printf("a Duda ->");
    mostra(caminho);
    printf("\n");

    remove(caminho);
    return 0;
}
