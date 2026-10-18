// 0137 · Juntando tudo
// Exercício E820 · ★★☆

#include <stdio.h>

typedef struct {
    FILE *f;
    unsigned char byte;
    int n;
} Saida;

void poe_bit(Saida *s, int bit) {
    s->byte = (unsigned char)((s->byte << 1) | bit);
    s->n++;
    if (s->n == 8) {
        fputc(s->byte, s->f);
        s->byte = 0;
        s->n = 0;
    }
}

// grava o byte incompleto, completando com zeros à direita
void fecha_bits(Saida *s) {
    if (s->n > 0) {
        fputc((unsigned char)(s->byte << (8 - s->n)), s->f);
        s->byte = 0;
        s->n = 0;
    }
}

int main(void) {
    const char *bits = "1011001110"; // 10 bits: um byte e mais 2 bits
    FILE *f = fopen("bits.bin", "wb");
    if (f == NULL) {
        return 1;
    }
    Saida s = {f, 0, 0};
    for (const char *p = bits; *p != '\0'; p++) {
        poe_bit(&s, *p - '0');
    }
    fecha_bits(&s);
    fclose(f);

    // lê de volta e mostra os bits de cada byte
    f = fopen("bits.bin", "rb");
    if (f == NULL) {
        return 1;
    }
    int c, bytes = 0;
    printf("Lido:");
    while ((c = fgetc(f)) != EOF) {
        printf(" ");
        for (int b = 7; b >= 0; b--) {
            putchar((c >> b) & 1 ? '1' : '0');
        }
        bytes++;
    }
    printf("\n%d byte(s) no arquivo\n", bytes);
    fclose(f);
    remove("bits.bin");
    return 0;
}
