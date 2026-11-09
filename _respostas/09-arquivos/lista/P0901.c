// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0901 · ★☆☆ · Calor de Manaus no arquivo

#include <stdio.h>

int main(void) {
    const char *caminho = "/tmp/p0901_temps.txt";
    int maximas[7] = {33, 35, 31, 36, 34, 32, 30};

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    for (int i = 0; i < 7; i++) {
        fprintf(arq, "%d\n", maximas[i]);
    }
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    int t, dias = 0, maior = 0, dia_maior = 0, soma = 0;
    while (fscanf(arq, "%d", &t) == 1) {
        dias++;
        soma += t;
        if (dias == 1 || t > maior) {
            maior = t;
            dia_maior = dias;
        }
    }
    fclose(arq);
    remove(caminho);

    if (dias == 0) {
        printf("Arquivo vazio\n");
        return 1;
    }
    printf("Dias lidos: %d\n", dias);
    printf("Maior: %d graus (dia %d)\n", maior, dia_maior);
    printf("Média: %.1f graus\n", (double) soma / dias);
    return 0;
}
