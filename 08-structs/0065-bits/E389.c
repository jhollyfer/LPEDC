// 0065 · Bits, máscaras e flags
// Exercício E389 · ★★★
//
// No CSS, uma cor como #FF8800 são três bytes juntos: vermelho (FF), verde
// (88) e azul (00). Guarde cores num uint32_t (os 8 bits de cima ficam
// zerados) e escreva:
//
//   - uint32_t rgb(unsigned r, unsigned g, unsigned b): empacota;
//   - unsigned canal_r(uint32_t c), canal_g e canal_b: desempacotam;
//   - uint32_t escurecer(uint32_t c): divide cada canal por 2;
//   - uint32_t cinza(uint32_t c): os três canais viram a média deles.
//
//   Saída esperada:
//   rgb(255, 136, 0) = #FF8800
//   #3366CC -> r = 51, g = 102, b = 204
//   #FF8800 escurecida = #7F4400
//   #3366CC em cinza = #777777
//
// Dicas:
// 1. Empacotar: (r << 16) | (g << 8) | b.
// 2. Desempacotar o verde: (c >> 8) & 0xFF. A máscara 0xFF guarda só 8 bits.
// 3. Mostre com #%06X e um cast para unsigned.
// 4. Média: (51 + 102 + 204) / 3 = 119 = 0x77.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdint.h>
#include <stdio.h>

int main(void) {

    return 0;
}
