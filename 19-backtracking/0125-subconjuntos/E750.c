// 0125 · Subconjuntos
// Exercício E750 · ★★★
//
// O pisca-pisca da varanda tem 3 lâmpadas, cada uma com seu interruptor, e
// você quer testar as 8 combinações de lâmpadas acesas. Contar 000, 001,
// 010, 011... obriga a mexer em vários interruptores de uma vez (de 011
// para 100 são três). Escreva do zero um programa que percorra as 8
// combinações mexendo em UM interruptor por vez (o código de Gray), mostre
// o estado (lâmpada 2 à esquerda, lâmpada 0 à direita) e diga qual
// lâmpada mudou.
//
//   Saída esperada:
//   000 começo, tudo apagado
//   001 liga a lâmpada 0
//   011 liga a lâmpada 1
//   010 desliga a lâmpada 0
//   110 liga a lâmpada 2
//   111 liga a lâmpada 0
//   101 desliga a lâmpada 1
//   100 desliga a lâmpada 0
//
// Dicas:
// 1. O m-ésimo estado do código de Gray é g = m ^ (m >> 1). Confira no
//    papel para m = 0 a 7.
// 2. O bit que mudou é o único ligado em anterior ^ g. Ache qual é com um
//    laço que testa cada bit (assunto 0065).
// 3. Se o bit mudou e agora está ligado em g, a lâmpada acendeu; senão,
//    apagou.
// 4. Resposta esperada: as 8 linhas acima. Repare que também é uma
//    enumeração de todos os subconjuntos de {0, 1, 2}, só que em outra ordem.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
