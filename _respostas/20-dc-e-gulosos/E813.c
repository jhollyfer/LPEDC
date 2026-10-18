// 0136 · Código de Huffman
// Exercício E813 · ★★☆

#include <stdio.h>
#include <string.h>

int main(void) {
    // a tabela de códigos que veio junto com a mensagem
    char simbolo[] = {'E', 'S', 'T', 'O', 'U', ' ', 'B', 'M'};
    const char *codigo[] = {"00", "01", "100", "101", "1100", "1101", "1110", "1111"};
    int k = 8;
    const char *bits = "0001100101110011011110001111";

    char buf[16];
    int tam = 0;
    printf("Mensagem: ");
    for (const char *b = bits; *b != '\0'; b++) {
        buf[tam++] = *b;
        buf[tam] = '\0';
        for (int i = 0; i < k; i++) {
            if (strcmp(buf, codigo[i]) == 0) { // fechou um código
                putchar(simbolo[i]);
                tam = 0;
                break;
            }
        }
    }
    putchar('\n');
    if (tam != 0) {
        printf("Sobraram %d bits sem formar código\n", tam);
    }
    return 0;
}
