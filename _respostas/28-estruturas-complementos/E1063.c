// 0178 · Hash: divisão e multiplicação
// Exercício E1063 · ★☆☆

#include <stdio.h>
#include "espalha.h"

int main(void) {
    uint32_t ceps[] = {69050000, 69020120, 69099999, 1310100, 20040002, 69050097};
    printf("     CEP | balde (m = 97)\n");
    for (int i = 0; i < 6; i++) {
        printf("%08u | %d\n", (unsigned)ceps[i], esp_divisao(ceps[i], 97));
    }
    return 0;
}
