// espalha.h · funções de dispersão: divisão e multiplicação
#ifndef ESPALHA_H
#define ESPALHA_H

#include <stdint.h>

// A de Knuth: (raiz de 5 - 1) / 2, a parte fracionária da razão áurea
#define ESP_A 0.6180339887498949
// a mesma constante em 32 bits: floor(A * 2^32)
#define ESP_S 2654435769u

// método da divisão: k mod m
int esp_divisao(uint32_t k, int m);

// método da multiplicação, em ponto flutuante: floor(m * (k*A mod 1))
int esp_multiplicacao(uint32_t k, int m);

// método da multiplicação em inteiros (m = 2^p, 1 <= p <= 31): os p bits
// mais altos dos 32 bits de baixo de k * ESP_S
int esp_mult_desloca(uint32_t k, int p);

// conta quantas chaves caem em cada balde (o vetor conta tem m posições)
// e devolve o tamanho do balde mais cheio
int esp_maior_balde(const int *conta, int m);

#endif
