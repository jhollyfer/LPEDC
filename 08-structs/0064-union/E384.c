// 0064 · Union
// Exercício E384 · ★★★
//
// Na rede, a convenção é mandar os números em big-endian (a "ordem de
// rede"). Use a union abaixo para escrever:
//
//   typedef union {
//       uint32_t n;
//       uint16_t m[2];
//       unsigned char b[4];
//   } Visao;
//
//   - void mostrar_memoria(Visao x): mostra os 4 bytes na ordem da memória;
//   - int little_endian(void): devolve 1 se a máquina é little-endian;
//   - uint32_t ordem_de_rede(uint32_t x): devolve o número com os bytes
//     arrumados para que, na memória, apareçam do mais significativo para o
//     menos. Numa máquina big-endian, devolve x sem mexer.
//
// Teste com x.n = 0x11223344: mostre a memória, m[0] e m[1], a endianness e
// a memória do número convertido.
//
//   Saída esperada (num PC Intel/AMD ou ARM):
//   memória: 44 33 22 11
//   m[0] = 0x3344, m[1] = 0x1122
//   esta máquina é little-endian
//   em ordem de rede, memória: 11 22 33 44
//
// Dicas:
// 1. Para descobrir a endianness: grave 1 em .n e olhe se .b[0] vale 1.
// 2. Para inverter: duas Visao, de e para; para.b[i] = de.b[3 - i].
// 3. m[0] são os dois primeiros bytes da memória, lidos como um número de 16
//    bits na ordem da máquina: 44 33 vira 0x3344.
// 4. Resposta esperada: a saída acima. A última linha sai igual em qualquer
//    máquina: é para isso que serve a ordem de rede.
//
// Escreva sua resposta abaixo:

#include <stdint.h>
#include <stdio.h>

int main(void) {

    return 0;
}
