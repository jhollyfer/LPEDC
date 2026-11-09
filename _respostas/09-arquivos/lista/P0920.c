// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0920 · ★★☆ · A planilha de vendas no arquivo

#include <stdio.h>

int main(void) {
    const char *caminho = "/tmp/p0920_vendas.txt";
    int vendas[3][4] = {{120, 90, 150, 80}, {200, 110, 70, 130}, {95, 140, 160, 100}};

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            fprintf(arq, "%d ", vendas[i][j]);
        }
        fprintf(arq, "\n");
    }
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    int lida[3][4];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (fscanf(arq, "%d", &lida[i][j]) != 1) {
                printf("Arquivo incompleto\n");
                fclose(arq);
                remove(caminho);
                return 1;
            }
        }
    }
    fclose(arq);
    remove(caminho);

    for (int j = 0; j < 4; j++) {
        int soma = 0;
        for (int i = 0; i < 3; i++) {
            soma += lida[i][j];
        }
        printf("Semana %d: R$ %d\n", j + 1, soma);
    }
    int melhor = 0, maior = -1;
    for (int i = 0; i < 3; i++) {
        int soma = 0;
        for (int j = 0; j < 4; j++) {
            soma += lida[i][j];
        }
        if (soma > maior) {
            maior = soma;
            melhor = i;
        }
    }
    printf("Melhor vendedor: %d (R$ %d)\n", melhor + 1, maior);
    return 0;
}
