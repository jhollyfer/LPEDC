// A274 · Nem tudo encolhe

#include <stdio.h>
#include <stdlib.h>
#include "compactador.h"

// grava n bytes gerados por uma regra e mostra quanto o .huf ocupa
void testa(const char *rotulo, int n, int tipo) {
    FILE *f = fopen("teste.bin", "wb");
    if (f == NULL) {
        return;
    }
    srand(2026);
    for (int i = 0; i < n; i++) {
        int c;
        if (tipo == 0) {
            c = 'A';                          // um byte só, repetido
        } else if (tipo == 1) {
            c = "ACGT"[rand() % 4];           // DNA: 4 letras sorteadas
        } else {
            c = rand() % 256;                 // qualquer byte, sorteado
        }
        fputc(c, f);
    }
    fclose(f);
    long depois = huf_compacta("teste.bin", "teste.huf");
    printf("%-22s %6d -> %6ld bytes", rotulo, n, depois);
    if (n > 0) {
        printf("  (%.1f%%)", 100.0 * depois / n);
    }
    printf("\n");
    remove("teste.bin");
    remove("teste.huf");
}

int main(void) {
    testa("vazio", 0, 0);
    testa("1000 letras A", 1000, 0);
    testa("100 000 letras A", 100000, 0);
    testa("DNA sorteado", 100000, 1);
    testa("bytes sorteados", 100000, 2);
    // - vazio: só o cabeçalho (1036 bytes) e nenhum bit.
    // - um símbolo só: 1 bit por byte, 1/8 do tamanho mais o cabeçalho.
    //   (Huffman nunca gasta menos de 1 bit por símbolo; quem comprime
    //   "AAAA..." de verdade conta repetições.)
    // - DNA: 4 letras igualmente frequentes, 2 bits cada: 25%.
    // - bytes sorteados: os 256 valores aparecem quase igual, todo código
    //   tem 8 bits, e o arquivo CRESCE com o cabeçalho. Por isso não adianta
    //   compactar um arquivo que já foi compactado.
    return 0;
}
// Saída:
// vazio                       0 ->   1036 bytes
// 1000 letras A            1000 ->   1161 bytes  (116.1%)
// 100 000 letras A       100000 ->  13536 bytes  (13.5%)
// DNA sorteado           100000 ->  26036 bytes  (26.0%)
// bytes sorteados        100000 -> 101036 bytes  (101.0%)
