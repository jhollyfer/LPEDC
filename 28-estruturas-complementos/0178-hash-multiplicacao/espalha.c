// espalha.c · implementação das funções de dispersão
#include <math.h>
#include "espalha.h"

int esp_divisao(uint32_t k, int m) {
    return (int)(k % (uint32_t)m);
}

int esp_multiplicacao(uint32_t k, int m) {
    double produto = k * ESP_A;
    double fracao = produto - floor(produto); // k*A mod 1: só a parte depois da vírgula
    return (int)(m * fracao);
}

int esp_mult_desloca(uint32_t k, int p) {
    uint32_t produto = k * ESP_S; // unsigned: a conta é feita mod 2^32, sem estouro
    return (int)(produto >> (32 - p));
}

int esp_maior_balde(const int *conta, int m) {
    int maior = 0;
    for (int i = 0; i < m; i++) {
        if (conta[i] > maior) {
            maior = conta[i];
        }
    }
    return maior;
}
