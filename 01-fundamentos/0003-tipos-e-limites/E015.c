// 0003 · Tipos e limites
// Exercício E015 · ★★☆
//
// Três contadores unsigned, três estouros que dão a volta. O programa abaixo
// já tem os valores iniciais. Complete: faça cada conta indicada no
// comentário (guardando o resultado na própria variável) e mostre uma
// linha por contador, com o valor de antes, a conta, o valor de depois e o
// máximo do tipo, tirado do limits.h.
//
//   Saída esperada:
//   brilho: 250 + 10 = 4 (máximo 255)
//   estoque: 0 - 1 = 4294967295 (máximo 4294967295)
//   odômetro: 65000 + 1000 = 464 (máximo 65535)
//
// Dicas:
// 1. A conta muda a variável. Para mostrar o valor de antes, guarde uma
//    cópia numa variável int antes da conta.
// 2. Os máximos: UCHAR_MAX, UINT_MAX e USHRT_MAX. O unsigned int se mostra
//    com %u; o unsigned char e o unsigned short, com %d.
// 3. Passou do máximo, volta a contar do zero: 260 - 256 = 4 e
//    66000 - 65536 = 464. Abaixo de zero, vai para o máximo.
// 4. Resposta esperada: as três linhas acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <limits.h>

int main(void) {
    unsigned char brilho = 250;      // LED, de 0 a 255: some 10
    unsigned int estoque = 0;        // vendeu um que não tinha: tire 1
    unsigned short odometro = 65000; // painel de 16 bits: some 1000

    (void)brilho; (void)estoque; (void)odometro; // apague esta linha
    return 0;
}
