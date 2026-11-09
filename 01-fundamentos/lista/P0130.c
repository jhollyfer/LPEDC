// Lista · Módulo 01 · Fundamentos de C
// Exercício P0130 · ★★★ · Os quatro bytes de um int
//
// Um int de 4 bytes guarda o número 305419896. Sem nenhum operador de bits, só
// com / e % por 256, separe os quatro bytes (do mais significativo para o
// menos), mostre cada um em decimal e em hexadecimal com dois dígitos, e depois
// remonte o número a partir dos bytes para conferir:
//
//   Saída esperada:
//   Número: 305419896 (0x12345678)
//   Bytes: 18 52 86 120
//   Em hexa: 12 34 56 78
//   Remontado: 305419896
//
// Dicas:
// 1. O byte mais baixo é n % 256. O seguinte é n / 256 % 256, depois
//    n / 65536 % 256, e o mais alto é n / 16777216.
// 2. %02X mostra um byte com dois dígitos hexadecimais.
// 3. Para remontar: b3 * 16777216 + b2 * 65536 + b1 * 256 + b0.
// 4. Resposta esperada: 18 52 86 120, ou 12 34 56 78 em hexa.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
