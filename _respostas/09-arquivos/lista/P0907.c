// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0907 · ★☆☆ · O aviso da feira em maiúsculas

#include <ctype.h>
#include <stdio.h>

int main(void) {
    const char *origem = "/tmp/p0907_aviso.txt";
    const char *destino = "/tmp/p0907_grito.txt";

    FILE *arq = fopen(origem, "w");
    if (arq == NULL) {
        perror(origem);
        return 1;
    }
    fprintf(arq, "Bom dia, Manaus!\n");
    fprintf(arq, "A feira abre as 6h.\n");
    fclose(arq);

    FILE *ent = fopen(origem, "r");
    if (ent == NULL) {
        perror(origem);
        return 1;
    }
    FILE *sai = fopen(destino, "w");
    if (sai == NULL) {
        perror(destino);
        fclose(ent);
        return 1;
    }
    int c;
    while ((c = fgetc(ent)) != EOF) {
        fputc(toupper(c), sai);
    }
    fclose(ent);
    fclose(sai);

    sai = fopen(destino, "r");
    if (sai == NULL) {
        perror(destino);
        return 1;
    }
    char linha[100];
    while (fgets(linha, sizeof linha, sai) != NULL) {
        printf("%s", linha);
    }
    fclose(sai);
    remove(origem);
    remove(destino);
    return 0;
}
