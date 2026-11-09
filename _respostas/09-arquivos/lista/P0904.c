// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0904 · ★☆☆ · Quantos produtos tem o arquivo?

#include <stdio.h>

typedef struct {
    int codigo;
    double preco;
} Produto;

long conta_registros(FILE *arq) {
    fseek(arq, 0, SEEK_END);
    return ftell(arq) / (long) sizeof(Produto);
}

int main(void) {
    const char *caminho = "/tmp/p0904_produtos.bin";
    Produto p[5] = {{101, 7.50}, {102, 12.00}, {103, 3.25}, {104, 9.90}, {105, 4.99}};

    FILE *arq = fopen(caminho, "wb+"); // "+": também deixa ler
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(p, sizeof(Produto), 5, arq);

    long n = conta_registros(arq);
    printf("Tamanho do arquivo: %ld bytes\n", ftell(arq));
    printf("Registros: %ld\n", n);

    Produto ultimo;
    fseek(arq, -(long) sizeof(Produto), SEEK_END);
    if (fread(&ultimo, sizeof ultimo, 1, arq) == 1) {
        printf("Último: código %d, R$ %.2f\n", ultimo.codigo, ultimo.preco);
    }

    fclose(arq);
    remove(caminho);
    return 0;
}
