// 0065 · Bits, máscaras e flags
// Exercício E385 · ★☆☆
//
// Escreva a função void mostrar(const char *nome, unsigned char r), que
// mostra o nome, os 8 bits de r (com um espaço no meio), o valor em hexa e
// em decimal. Com a = 0xCA e b = 0x5C (dois unsigned char), use a função
// para mostrar a, b e os seis resultados abaixo, guardando cada um num
// unsigned char:
//
//   a & b    a | b    a ^ b    ~a    a << 1    a >> 3
//
//   Saída esperada:
//   a       1100 1010 = 0xCA = 202
//   b       0101 1100 = 0x5C = 92
//   a & b   0100 1000 = 0x48 = 72
//   a | b   1101 1110 = 0xDE = 222
//   a ^ b   1001 0110 = 0x96 = 150
//   ~a      0011 0101 = 0x35 = 53
//   a << 1  1001 0100 = 0x94 = 148
//   a >> 3  0001 1001 = 0x19 = 25
//
// Dicas:
// 1. O bit b de r: (r >> b) & 1u. Percorra b de 7 até 0 e ponha o espaço
//    depois do bit 4.
// 2. Para conferir uma linha: C = 1100, A = 1010, 5 = 0101. Com um
//    embaixo do outro, a regra se aplica casa por casa.
// 3. Num unsigned char só sobram os 8 bits de baixo: passe
//    (unsigned char)~a e (unsigned char)(a << 1). Em a << 1, o 1 da esquerda
//    cai fora.
// 4. Resposta esperada: a saída acima (%-7s alinha os nomes).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
