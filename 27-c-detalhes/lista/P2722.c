// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2722 · ★★★ · O byte de trás para a frente
//
// Escreva, para uint8_t, as funções abaixo e mostre os resultados para o
// byte 0x1D (00011101):
//
//   int contar(uint8_t b)          // quantos bits 1
//   int paridade(uint8_t b)        // 1 se a quantidade de bits 1 é ímpar
//   uint8_t espelhar(uint8_t b)    // bit 0 vira bit 7, bit 1 vira bit 6...
//   uint8_t girar(uint8_t b, int n) // gira n casas à esquerda (0 a 7)
//
//   Saída esperada:
//   b = 00011101 (0x1D)
//   bits ligados: 4
//   paridade: 0
//   espelhado: 10111000 (0xB8)
//   girado 3: 11101000 (0xE8)
//   girado 0: 00011101 (0x1D)
//
// Dicas:
// 1. Espelhar: para cada b de 0 a 7, se o bit b está ligado, ligue o bit
//    7 - b do resultado.
// 2. Girar: (b << n) | (b >> (8 - n)), guardado num uint8_t. Com n = 0,
//    b >> 8 é definido (o b virou int de 32 bits), mas trate o caso
//    separado para ficar claro.
// 3. A promoção inteira transforma o uint8_t em int antes do <<: corte de
//    volta com (uint8_t)(...).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdint.h>
#include <stdio.h>

int main(void) {

    return 0;
}
