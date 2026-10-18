// 0121 · Radix sort
// Exercício E725 · ★★★
//
// Ache o bug. A loja de aplicativos ordena os downloads do mês com um radix
// sort em base 256. O programa compila, roda sem erro de memória e quase
// acerta: os números pequenos saem em ordem, mas os grandes não.
//
//   Saída esperada:
//   5 300 65535 70000 131072 1000000 16777216 4000000000
//
//   Saída que aparece:
//   16777216 5 300 65535 70000 131072 4000000000 1000000
//
// Ache a linha errada, conserte e rode.
//
// Dicas:
// 1. Acrescente um printf que mostre desloca em cada passada. Que bits a
//    última passada olha?
// 2. 16777216 é 2 elevado a 24: só o byte 3 dele não é zero. Alguma passada
//    olha esse byte?
// 3. Resposta esperada: desloca = 4 * b anda meio byte (4 bits) por
//    passada; as 4 passadas só cobrem os bits 0 a 19. O certo é
//    desloca = 8 * b: os bytes 0, 1, 2 e 3 (deslocamentos 0, 8, 16 e 24).
//    Consertado, sai a saída esperada.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdint.h>

// radix sort em base 256: 4 passadas, um byte por vez
void radix_256(uint32_t v[], uint32_t aux[], int n) {
    for (int b = 0; b < 4; b++) {
        int desloca = 4 * b;
        int c[256] = {0};
        for (int i = 0; i < n; i++) {
            c[(v[i] >> desloca) & 0xFF]++;
        }
        for (int x = 1; x < 256; x++) {
            c[x] += c[x - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            aux[--c[(v[i] >> desloca) & 0xFF]] = v[i];
        }
        for (int i = 0; i < n; i++) {
            v[i] = aux[i];
        }
    }
}

int main(void) {
    // downloads de cada app da loja no mês
    uint32_t downloads[] = {70000, 16777216, 300, 131072, 5, 1000000, 65535, 4000000000u};
    uint32_t aux[8];
    int n = 8;

    radix_256(downloads, aux, n);
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%u" : " %u", (unsigned) downloads[i]);
    }
    printf("\n");
    return 0;
}
