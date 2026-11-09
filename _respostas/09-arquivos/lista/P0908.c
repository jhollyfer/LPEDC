// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0908 · ★☆☆ · Pulando de dois em dois no arquivo

#include <stdio.h>

int main(void) {
    const char *caminho = "/tmp/p0908_quadrados.bin";
    int q[10];
    for (int i = 0; i < 10; i++) {
        q[i] = (i + 1) * (i + 1);
    }

    FILE *arq = fopen(caminho, "wb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(q, sizeof(int), 10, arq);
    fclose(arq);

    arq = fopen(caminho, "rb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    int x, lidos = 0;
    while (fread(&x, sizeof x, 1, arq) == 1) {
        printf(lidos == 0 ? "%d" : " %d", x);
        lidos++;
        fseek(arq, sizeof(int), SEEK_CUR); // pula o próximo
    }
    printf("\nLidos: %d\n", lidos);
    fclose(arq);
    remove(caminho);
    return 0;
}
