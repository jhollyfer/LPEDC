// 0069 · Union
// Exercício E411 · ★★☆
//
// Um arquivo vindo de uma máquina big-endian guardou números de 16 bits com
// os dois bytes na ordem oposta à do seu PC. Escreva
// uint16_t trocar_bytes(uint16_t x) usando uma union de um uint16_t com um
// unsigned char[2] (sem operadores de bits), e teste com três valores.
//
//   Saída esperada:
//   0xABCD -> 0xCDAB
//   0x0102 -> 0x0201
//   258 -> 513
//
// Dicas:
// 1. Grave x no campo de 16 bits, troque b[0] com b[1] e devolva o campo de
//    16 bits.
// 2. 258 = 0x0102. Trocado, vira 0x0201 = 2 * 256 + 1.
// 3. Curiosidade: esta função dá o mesmo resultado em qualquer endianness,
//    porque ela só troca as duas metades de lugar.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdint.h>
#include <stdio.h>

int main(void) {

    return 0;
}
