// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0926 · ★★★ · Compactar a leitura do sensor (RLE)

#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned char qtd;
    char c;
} Par;

int compacta(const char *texto, const char *caminho) {
    FILE *arq = fopen(caminho, "wb");
    if (arq == NULL) {
        return -1;
    }
    int pares = 0;
    size_t i = 0, n = strlen(texto);
    while (i < n) {
        Par p = {0, texto[i]};
        while (i < n && texto[i] == p.c && p.qtd < 255) {
            p.qtd++;
            i++;
        }
        fwrite(&p, sizeof p, 1, arq);
        pares++;
    }
    fclose(arq);
    return pares;
}

int descompacta(const char *caminho, char *saida, int max) {
    FILE *arq = fopen(caminho, "rb");
    if (arq == NULL) {
        return -1;
    }
    Par p;
    int t = 0;
    while (fread(&p, sizeof p, 1, arq) == 1) {
        for (int k = 0; k < p.qtd && t < max - 1; k++) {
            saida[t++] = p.c;
        }
    }
    saida[t] = '\0';
    fclose(arq);
    return t;
}

int main(void) {
    const char *caminho = "/tmp/p0926_sensor.rle";
    const char *leitura = "AAAAABBBCCCCCCCCDAA";

    int pares = compacta(leitura, caminho);
    if (pares < 0) {
        perror(caminho);
        return 1;
    }
    FILE *arq = fopen(caminho, "rb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fseek(arq, 0, SEEK_END);
    long bytes = ftell(arq);
    rewind(arq);
    printf("Original: %zu bytes\n", strlen(leitura));
    printf("Compactado: %ld bytes (%d pares)\n", bytes, pares);
    Par p;
    int primeiro = 1;
    while (fread(&p, sizeof p, 1, arq) == 1) {
        printf(primeiro ? "%dx%c" : " %dx%c", p.qtd, p.c);
        primeiro = 0;
    }
    printf("\n");
    fclose(arq);

    char volta[100];
    descompacta(caminho, volta, sizeof volta);
    printf("Descompactado: %s\n", volta);
    printf("Confere: %s\n", strcmp(volta, leitura) == 0 ? "sim" : "não");
    remove(caminho);
    return 0;
}
