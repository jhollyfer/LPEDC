// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0910 · ★☆☆ · Os preços da feira pela linha de comando

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("uso: P0910 preco1 preco2 ...\n");
        return 1;
    }
    const char *caminho = "/tmp/p0910_precos.txt";

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        fprintf(arq, "%.2f\n", atof(argv[i]));
    }
    fclose(arq);

    arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    double preco, total = 0;
    int n = 0;
    while (fscanf(arq, "%lf", &preco) == 1) {
        total += preco;
        n++;
    }
    fclose(arq);
    remove(caminho);

    printf("%d preços gravados\n", n);
    printf("Total: R$ %.2f\n", total);
    return 0;
}
