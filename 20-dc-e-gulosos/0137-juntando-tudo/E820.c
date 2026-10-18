// 0137 · Juntando tudo
// Exercício E820 · ★★☆
//
// Ache o bug. Este programa grava 10 bits soltos num arquivo, 8 por byte,
// e depois lê o arquivo de volta mostrando os bits de cada byte. Ele roda
// sem aviso, mas os 2 últimos bits somem:
//
//   Saída que aparece:
//   Lido: 10110011
//   1 byte(s) no arquivo
//
//   Saída esperada:
//   Lido: 10110011 10000000
//   2 byte(s) no arquivo
//
// Conserte escrevendo a função que falta e chamando-a no lugar certo. Os
// bits que sobram devem ir para a ESQUERDA do último byte, completados com
// zeros à direita (por isso 10 vira 10000000).
//
// Dicas:
// 1. Depois do laço, s.n vale 2 e s.byte guarda os bits 1 e 0 (o valor 2).
//    Ninguém grava esse byte.
// 2. void fecha_bits(Saida *s): se s->n > 0, grave s->byte << (8 - s->n) e
//    zere byte e n. Chame antes do fclose.
// 3. Resposta esperada: a saída acima. É o descarrega do compactador.c; sem
//    ele, o descompactador perde o fim do arquivo.
//
// Escreva sua resposta abaixo (conserte o código):

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
