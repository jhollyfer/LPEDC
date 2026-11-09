// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2820 · ★★☆ · Múltiplos de 32 na tabela

#include <stdint.h>
#include <stdio.h>

void relata(const char *nome, const int *conta, int m) {
    int vazios = 0, maior = 0;
    for (int i = 0; i < m; i++) {
        vazios += conta[i] == 0;
        if (conta[i] > maior) {
            maior = conta[i];
        }
    }
    printf("vazios %2d | mais cheio %3d | %s\n", vazios, maior, nome);
}

int main(void) {
    int div[32] = {0}, mult[32] = {0}, div31[31] = {0};
    for (uint32_t i = 1; i <= 100; i++) {
        uint32_t k = 32 * i;
        div[k % 32]++;
        mult[(k * 2654435769u) >> 27]++;
        div31[k % 31]++;
    }
    relata("divisão, m = 32", div, 32);
    relata("multiplicação, m = 32", mult, 32);
    relata("divisão, m = 31", div31, 31);
    return 0;
}
