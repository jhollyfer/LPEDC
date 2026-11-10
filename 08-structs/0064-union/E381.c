// 0064 · Union
// Exercício E381 · ★★☆
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
// Escreva sua resposta abaixo:

#include <stdint.h>
#include <stdio.h>

int main(void) {

    return 0;
}
