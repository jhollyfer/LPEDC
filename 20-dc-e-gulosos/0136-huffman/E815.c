// 0136 · Código de Huffman
// Exercício E815 · ★★★
//
// Código canônico: o compactador guarda só o COMPRIMENTO do código de cada
// símbolo e refaz os códigos por uma regra fixa:
// 1. ordene por comprimento e, no empate, pelo byte;
// 2. o primeiro recebe o código 0;
// 3. cada próximo recebe codigo = (codigo + 1) << (l - l_ant).
// Use huffman.h na frase "BANANA NA CABANA" só para obter os comprimentos
// (strlen dos códigos); gere os canônicos e mostre ao lado dos do Huffman.
//
//   Saída esperada:
//   'A' 1 bits: 0  (Huffman deu 0)
//   'N' 2 bits: 10  (Huffman deu 10)
//   'B' 3 bits: 110  (Huffman deu 110)
//   ' ' 4 bits: 1110  (Huffman deu 1111)
//   'C' 4 bits: 1111  (Huffman deu 1110)
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include "huffman.h"

int main(void) {

    return 0;
}
