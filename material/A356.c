// A356 · Multiplicação com double e com deslocamento

#include <math.h>
#include <stdio.h>
#include "0178-espalha.h"

// a fórmula floor(m * (k*A mod 1)) com qualquer A
int mult_com_A(uint32_t k, int m, double A) {
    double produto = k * A;
    return (int)(m * (produto - floor(produto)));
}

int main(void) {
    // 1. as duas versões dão o mesmo balde? m = 1024 = 2^10
    double a_exato = ESP_S / 4294967296.0; // s / 2^32: o A que os inteiros usam
    int dif_knuth = 0, dif_exato = 0;
    for (uint32_t k = 0; k < 100000; k++) {
        int inteiro = esp_mult_desloca(k, 10);
        dif_knuth += esp_multiplicacao(k, 1024) != inteiro;
        dif_exato += mult_com_A(k, 1024, a_exato) != inteiro;
    }
    printf("k de 0 a 99999, m = 1024, comparado com o deslocamento:\n");
    printf("  double com A = 0.6180339887...: %d baldes diferentes\n", dif_knuth);
    printf("  double com A = s / 2^32:        %d baldes diferentes\n", dif_exato);

    // 2. a versão com double aceita qualquer m; a de inteiros, só 2^p
    printf("m = 1000 (não é potência de 2): k = 123456 -> %d\n", esp_multiplicacao(123456, 1000));

    // 3. chaves seguidas espalham bem? 1000 chaves em m = 64
    int div[64] = {0}, mult[64] = {0};
    for (uint32_t k = 5000; k < 6000; k++) {
        div[esp_divisao(k, 64)]++;
        mult[esp_mult_desloca(k, 6)]++;
    }
    printf("1000 chaves seguidas, m = 64 (ideal: 15.6 por balde)\n");
    printf("  divisão: balde mais cheio com %d\n", esp_maior_balde(div, 64));
    printf("  multiplicação: balde mais cheio com %d\n", esp_maior_balde(mult, 64));

    // 4. mas múltiplos de 64 derrubam a divisão, não a multiplicação
    int div2[64] = {0}, mult2[64] = {0};
    for (uint32_t i = 1; i <= 1000; i++) {
        div2[esp_divisao(64 * i, 64)]++;
        mult2[esp_mult_desloca(64 * i, 6)]++;
    }
    printf("1000 múltiplos de 64, m = 64\n");
    printf("  divisão: balde mais cheio com %d\n", esp_maior_balde(div2, 64));
    printf("  multiplicação: balde mais cheio com %d\n", esp_maior_balde(mult2, 64));
    return 0;
}
// Saída:
// k de 0 a 99999, m = 1024, comparado com o deslocamento:
//   double com A = 0.6180339887...: 592 baldes diferentes
//   double com A = s / 2^32:        0 baldes diferentes
// m = 1000 (não é potência de 2): k = 123456 -> 4
// 1000 chaves seguidas, m = 64 (ideal: 15.6 por balde)
//   divisão: balde mais cheio com 16
//   multiplicação: balde mais cheio com 17
// 1000 múltiplos de 64, m = 64
//   divisão: balde mais cheio com 1000
//   multiplicação: balde mais cheio com 17
