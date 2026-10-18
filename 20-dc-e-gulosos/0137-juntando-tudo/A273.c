// A273 · O compactador na linha de comando

#include <stdio.h>
#include <string.h>
#include "compactador.h"

// uso:  c entrada saida   (compacta)
//       d entrada saida   (descompacta)
int main(int argc, char *argv[]) {
    if (argc != 4 || (strcmp(argv[1], "c") != 0 && strcmp(argv[1], "d") != 0)) {
        fprintf(stderr, "uso: A273 c|d entrada saida\n");
        return 1;
    }
    long antes = arq_tamanho(argv[2]);
    if (antes < 0) {
        fprintf(stderr, "não consegui abrir %s\n", argv[2]);
        return 1;
    }
    long depois = argv[1][0] == 'c' ? huf_compacta(argv[2], argv[3])
                                    : huf_descompacta(argv[2], argv[3]);
    if (depois < 0) {
        fprintf(stderr, "falhou (%s não é um arquivo .huf?)\n", argv[2]);
        return 1;
    }
    printf("%s: %ld bytes -> %s: %ld bytes", argv[2], antes, argv[3], depois);
    if (antes > 0) {
        printf(" (%.1f%%)", 100.0 * depois / antes);
    }
    printf("\n");
    return 0;
}
// Sem argumentos, mostra o uso e termina com 1:
//   uso: A273 c|d entrada saida
//
// Rodando de dentro de ~/LPEDC, compactando e descompactando o huffman.c
// desta pasta:
//   ~/LPEDC/rodar 20-dc-e-gulosos/0137-juntando-tudo/A273.c c 20-dc-e-gulosos/0137-juntando-tudo/huffman.c /tmp/h.huf
//   20-dc-e-gulosos/0137-juntando-tudo/huffman.c: 3110 bytes -> /tmp/h.huf: 2900 bytes (93.2%)
//   ~/LPEDC/rodar 20-dc-e-gulosos/0137-juntando-tudo/A273.c d /tmp/h.huf /tmp/h.c
//   /tmp/h.huf: 2900 bytes -> /tmp/h.c: 3110 bytes (107.2%)
//
// Um código-fonte pequeno mal compensa o cabeçalho de 1036 bytes: sem ele,
// os bits ocupariam 1864 bytes, 60% do original.
