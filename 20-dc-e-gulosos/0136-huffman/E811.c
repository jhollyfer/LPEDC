// 0136 · Código de Huffman
// Exercício E811 · ★☆☆
//
// Use o TAD huffman.h da pasta para comprimir a frase "PAPAI PAGOU A
// PIPOCA": conte as frequências, monte a árvore, gere os códigos e mostre,
// para cada símbolo que aparece (na ordem da tabela ASCII), a frequência e
// o código. No fim, o total de bits, o tamanho original (8 bits por letra)
// e a porcentagem.
//
//   Saída esperada:
//   ' ' 3: 110
//   'A' 5: 01
//   'C' 1: 0010
//   'G' 1: 0011
//   'I' 2: 1111
//   'O' 2: 000
//   'P' 5: 10
//   'U' 1: 1110
//   55 bits de 160 (34.4%)
//
// Dicas:
// 1. long freq[256] = {0}; e um laço que faz freq[(unsigned char)*p]++.
// 2. huf_constroi(freq), huf_codigos(raiz, cod) com static char
//    cod[256][256], e no fim huf_libera(raiz).
// 3. Resposta esperada: a saída acima. Para imprimir o símbolo %, escreva
//    %% no printf. O P e o A, os mais frequentes, ganharam 2 bits.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include "huffman.h"

int main(void) {

    return 0;
}
