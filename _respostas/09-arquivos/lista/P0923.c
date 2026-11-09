// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0923 · ★★★ · O índice de linhas do cardápio

#include <stdio.h>
#include <string.h>

#define MAX_LINHAS 100

int main(void) {
    const char *caminho = "/tmp/p0923_cardapio.txt";
    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "Tacaca na esquina\nPirarucu de casaca\nTucupi no pato\n");
    fprintf(arq, "Bolo de macaxeira\nCupuacu gelado\nPupunha com cafe\n");
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    long pos[MAX_LINHAS];
    char linha[200];
    int n = 0;
    while (n < MAX_LINHAS) {
        long aqui = ftell(arq);
        if (fgets(linha, sizeof linha, arq) == NULL) {
            break;
        }
        pos[n++] = aqui;
    }
    printf("%d linhas indexadas\n", n);

    int pedidas[4] = {5, 2, 6, 9};
    for (int i = 0; i < 4; i++) {
        int k = pedidas[i];
        if (k < 1 || k > n) {
            printf("Linha %d: não existe\n", k);
            continue;
        }
        fseek(arq, pos[k - 1], SEEK_SET);
        if (fgets(linha, sizeof linha, arq) != NULL) {
            linha[strcspn(linha, "\n")] = '\0';
            printf("Linha %d (byte %ld): %s\n", k, pos[k - 1], linha);
        }
    }
    fclose(arq);
    remove(caminho);
    return 0;
}
