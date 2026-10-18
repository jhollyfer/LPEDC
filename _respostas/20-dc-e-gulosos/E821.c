// 0137 · Juntando tudo
// Exercício E821 · ★★★

#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(void) {
    const char *frase = "BANANA NA CABANA";
    uint32_t freq[256] = {0};
    for (const char *p = frase; *p != '\0'; p++) {
        freq[(unsigned char)*p]++;
    }

    // grava: quantos símbolos (uint16_t) e, para cada um, o byte e a frequência
    FILE *f = fopen("cab.bin", "wb");
    if (f == NULL) {
        return 1;
    }
    uint16_t k = 0;
    for (int c = 0; c < 256; c++) {
        if (freq[c] > 0) {
            k++;
        }
    }
    fwrite(&k, sizeof k, 1, f);
    for (int c = 0; c < 256; c++) {
        if (freq[c] > 0) {
            unsigned char simbolo = (unsigned char)c;
            fwrite(&simbolo, 1, 1, f);
            fwrite(&freq[c], sizeof freq[c], 1, f);
        }
    }
    long tamanho = ftell(f);
    fclose(f);

    // lê de volta num vetor zerado e compara com o original
    uint32_t lida[256] = {0};
    f = fopen("cab.bin", "rb");
    if (f == NULL) {
        return 1;
    }
    uint16_t m;
    if (fread(&m, sizeof m, 1, f) != 1) {
        fclose(f);
        return 1;
    }
    for (int i = 0; i < m; i++) {
        unsigned char simbolo;
        uint32_t q;
        if (fread(&simbolo, 1, 1, f) != 1 || fread(&q, sizeof q, 1, f) != 1) {
            break;
        }
        lida[simbolo] = q;
    }
    fclose(f);
    remove("cab.bin");

    printf("Símbolos: %d\n", m);
    printf("Cabeçalho compacto: %ld bytes (o completo tem 1024)\n", tamanho);
    printf("Frequências %s\n", memcmp(freq, lida, sizeof freq) == 0 ? "iguais" : "DIFERENTES");
    return 0;
}
