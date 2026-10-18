// 0003 · Tipos e limites
// Exercício E015 · ★★☆
//
// Os três contadores abaixo são unsigned, então o estouro dá a volta.
// Sem rodar, escreva o que cada printf mostra:
//
//   unsigned char brilho = 250;      // LED, de 0 a 255
//   brilho = brilho + 10;
//   printf("%d\n", brilho);
//
//   unsigned int estoque = 0;
//   estoque = estoque - 1;           // vendeu um que não tinha
//   printf("%u\n", estoque);
//
//   unsigned short odometro = 65000; // km, num painel de 16 bits
//   odometro = odometro + 1000;
//   printf("%d\n", odometro);
//
// Depois copie para a main, rode e confira.
//
// Dicas:
// 1. Passou do máximo, volta a contar do zero: faça a conta e tire 2^n
//    (256 para 8 bits, 65536 para 16, 4294967296 para 32).
// 2. Abaixo de zero, dá a volta para o máximo: 0 - 1 vira o maior valor.
// 3. Resposta esperada: 4 (260 - 256), 4294967295 (o maior unsigned int) e
//    464 (66000 - 65536).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
