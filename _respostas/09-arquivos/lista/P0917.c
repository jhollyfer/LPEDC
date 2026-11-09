// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0917 · ★★☆ · Virar o arquivo do avesso no lugar

#include <stdio.h>

int le(FILE *arq, int i) {
    int v = 0;
    fseek(arq, i * (long) sizeof(int), SEEK_SET);
    if (fread(&v, sizeof v, 1, arq) != 1) {
        return 0;
    }
    return v;
}

void grava(FILE *arq, int i, int valor) {
    fseek(arq, i * (long) sizeof(int), SEEK_SET);
    fwrite(&valor, sizeof valor, 1, arq);
}

void mostra(FILE *arq, const char *rotulo, int n) {
    printf("%s", rotulo);
    for (int i = 0; i < n; i++) {
        printf(" %d", le(arq, i));
    }
    printf("\n");
}

int main(void) {
    const char *caminho = "/tmp/p0917_pressao.bin";
    int leituras[6] = {120, 118, 125, 130, 122, 119};
    int n = 6;

    FILE *arq = fopen(caminho, "wb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(leituras, sizeof(int), n, arq);
    fclose(arq);

    arq = fopen(caminho, "rb+");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    mostra(arq, "Antes: ", n);
    for (int i = 0; i < n / 2; i++) {
        int a = le(arq, i);
        int b = le(arq, n - 1 - i);
        grava(arq, i, b);
        grava(arq, n - 1 - i, a);
    }
    mostra(arq, "Depois:", n);
    fclose(arq);
    remove(caminho);
    return 0;
}
