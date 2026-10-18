// 0051 · void * e cast
// Exercício E306 · ★★★
//
// Escreva a função
//
//   void mostra_bytes(const char *rotulo, const void *p, size_t tam)
//
// que imprime, em hexa, os tam bytes que estão a partir de p (como no
// A102). No main, com
//
//   short curto = 258;
//   unsigned int cor = 0x0A0B0C0D;
//   int negativo = -2;
//   char sigla[] = "BR";
//
// mostre os bytes das quatro variáveis. Depois, usando um unsigned char *
// apontado para cada variável, troque SÓ o primeiro byte de cor para 0xFF
// e SÓ o primeiro byte de negativo para 0x00, e mostre os dois valores
// inteiros (cor com printf("%#010x"), negativo com %d).
//
//   Saída esperada (num PC Intel/AMD ou ARM, que são little-endian):
//   curto: 02 01
//   cor: 0d 0c 0b 0a
//   negativo: fe ff ff ff
//   sigla: 42 52 00
//   cor depois: 0x0a0b0cff
//   negativo depois: -256
//
// Dicas:
// 1. Escreva cada número em hexa com todos os bytes (short tem 2, int 4):
//    258 é 0x0102 e -2 é 0xFFFFFFFE. No little-endian, o primeiro byte na
//    memória é o MENOS significativo.
// 2. unsigned char *b = (unsigned char *)&cor; b[0] = 0xFF; muda só o byte
//    de baixo.
// 3. Resposta esperada: a saída acima. negativo vira 0xFFFFFF00, que em
//    complemento de dois é -256.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
