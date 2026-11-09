// A355 · Potência de 2 só enxerga os bits de baixo

#include <stdio.h>
#include "espalha.h"

int main(void) {
    // etiquetas do estoque: o lote fica no byte de cima, o item embaixo é 0
    uint32_t etiquetas[] = {0x1A00, 0x2B00, 0x3C00, 0x4D00, 0x5E00};
    printf("etiqueta | k %% 256 | k & 255 | k %% 251\n");
    for (int i = 0; i < 5; i++) {
        uint32_t k = etiquetas[i];
        printf("  0x%04X | %7d | %7u | %d\n", (unsigned)k, esp_divisao(k, 256), k & 255u,
               esp_divisao(k, 251));
    }

    // o mesmo vale em base 10: m = 100 só olha os dois últimos dígitos
    uint32_t precos[] = {1500, 2300, 4700, 990, 12000}; // em centavos
    printf("preço | k %% 100 | k %% 97\n");
    for (int i = 0; i < 5; i++) {
        printf("%5u | %7d | %d\n", precos[i], esp_divisao(precos[i], 100),
               esp_divisao(precos[i], 97));
    }
    return 0;
}
// Saída:
// etiqueta | k % 256 | k & 255 | k % 251
//   0x1A00 |       0 |       0 | 130
//   0x2B00 |       0 |       0 | 215
//   0x3C00 |       0 |       0 | 49
//   0x4D00 |       0 |       0 | 134
//   0x5E00 |       0 |       0 | 219
// preço | k % 100 | k % 97
//  1500 |       0 | 45
//  2300 |       0 | 69
//  4700 |       0 | 44
//   990 |      90 | 20
// 12000 |       0 | 69
