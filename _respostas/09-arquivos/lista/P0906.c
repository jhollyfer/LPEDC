// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0906 · ★☆☆ · O recibo da conta de luz, letra por letra

#include <stdio.h>

int main(void) {
    const char *caminho = "/tmp/p0906_recibo.txt";
    int consumo = 230;
    double tarifa = 0.85;

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fprintf(arq, "Consumo: %d kWh\n", consumo);
    fprintf(arq, "Tarifa: R$ %.2f\n", tarifa);
    fprintf(arq, "Total: R$ %.2f\n", consumo * tarifa);
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    int c, caracteres = 0, linhas = 0;
    while ((c = fgetc(arq)) != EOF) {
        putchar(c);
        caracteres++;
        if (c == '\n') {
            linhas++;
        }
    }
    fclose(arq);
    remove(caminho);

    printf("%d linhas, %d caracteres\n", linhas, caracteres);
    return 0;
}
