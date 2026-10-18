// A146 · O mesmo número em texto e em binário

#include <stdio.h>

// Mostra o tamanho do arquivo e cada byte dele em hexadecimal
void mostrar_bytes(const char *caminho) {
    FILE *arq = fopen(caminho, "rb");
    if (arq == NULL) {
        perror(caminho);
        return;
    }
    fseek(arq, 0, SEEK_END);
    long tamanho = ftell(arq);
    rewind(arq); // volta para o byte 0

    printf("%-18s %ld bytes:", caminho, tamanho);
    int c;
    while ((c = fgetc(arq)) != EOF) {
        printf(" %02X", c);
    }
    printf("\n");
    fclose(arq);
}

int main(void) {
    int codigo = 12345678;

    FILE *txt = fopen("/tmp/codigo.txt", "w");
    FILE *bin = fopen("/tmp/codigo.bin", "wb");
    if (txt == NULL || bin == NULL) {
        perror("fopen");
        if (txt != NULL) fclose(txt);
        if (bin != NULL) fclose(bin);
        return 1;
    }
    fprintf(txt, "%d", codigo);               // vira os caracteres '1' '2' ... '8'
    fwrite(&codigo, sizeof codigo, 1, bin);   // copia os 4 bytes do int
    fclose(txt);
    fclose(bin);

    mostrar_bytes("/tmp/codigo.txt");
    mostrar_bytes("/tmp/codigo.bin");

    // ler de volta o binário: os 4 bytes voltam direto para um int
    int lido = 0;
    bin = fopen("/tmp/codigo.bin", "rb");
    if (bin != NULL) {
        if (fread(&lido, sizeof lido, 1, bin) == 1) {
            printf("Lido do binário: %d\n", lido);
        }
        fclose(bin);
    }
    remove("/tmp/codigo.txt");
    remove("/tmp/codigo.bin");
    return 0;
}
// Saída:
// /tmp/codigo.txt    8 bytes: 31 32 33 34 35 36 37 38
// /tmp/codigo.bin    4 bytes: 4E 61 BC 00
// Lido do binário: 12345678
