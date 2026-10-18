// 0068 · Arquivos binários
// Exercício E403 · ★☆☆

#include <stdio.h>

int main(void) {
    const char *caminho = "/tmp/maximas.bin";
    int maximas[5] = {31, 29, 33, 35, 30};

    FILE *arq = fopen(caminho, "wb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(maximas, sizeof(int), 5, arq);
    fclose(arq);

    int lidas[5];
    arq = fopen(caminho, "rb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    size_t n = fread(lidas, sizeof(int), 5, arq);
    fclose(arq);
    remove(caminho);

    printf("Lidos: %zu valores\n", n);
    if (n != 5) {
        printf("Arquivo incompleto\n");
        return 1;
    }
    int soma = 0;
    for (int i = 0; i < 5; i++) {
        soma += lidas[i];
    }
    printf("Média: %.1f graus\n", soma / 5.0);
    return 0;
}
