// 0121 · Radix sort
// Exercício E726 · ★★★

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>

// inverte o bit de sinal: INT_MIN vira 0, -1 vira 0x7FFFFFFF,
// 0 vira 0x80000000 e INT_MAX vira 0xFFFFFFFF. A ordem dos int vira a
// ordem dos uint32_t
uint32_t chave(int32_t x) {
    return (uint32_t) x ^ 0x80000000u;
}

// com_chave = false: usa os bits do int direto, como se não tivesse sinal
uint32_t bits(int32_t x, bool com_chave) {
    return com_chave ? chave(x) : (uint32_t) x;
}

void radix(int32_t v[], int32_t aux[], int n, bool com_chave) {
    for (int b = 0; b < 4; b++) {
        int desloca = 8 * b;
        int c[256] = {0};
        for (int i = 0; i < n; i++) {
            c[(bits(v[i], com_chave) >> desloca) & 0xFF]++;
        }
        for (int x = 1; x < 256; x++) {
            c[x] += c[x - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            aux[--c[(bits(v[i], com_chave) >> desloca) & 0xFF]] = v[i];
        }
        for (int i = 0; i < n; i++) {
            v[i] = aux[i];
        }
    }
}

void testa(const char *rotulo, bool com_chave) {
    // movimentações da conta, em centavos: saques negativos, depósitos positivos
    int32_t mov[] = {-150000, 3200, -7, 0, INT_MAX, INT_MIN, 98000, -98000, 7};
    int32_t aux[9];
    int n = 9;

    radix(mov, aux, n, com_chave);
    printf("%s", rotulo);
    for (int i = 0; i < n; i++) {
        printf(" %d", (int) mov[i]);
    }
    printf("\n");
}

int main(void) {
    printf("-7 como uint32_t: %08X\n", (unsigned) (uint32_t) -7);
    testa("sem a chave:", false);
    testa("com a chave:", true);
    return 0;
}
