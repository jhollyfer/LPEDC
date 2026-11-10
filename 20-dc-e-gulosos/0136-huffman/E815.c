// 0136 · Código de Huffman
// Exercício E815 · ★★★
//
// Código canônico. Guardar a árvore inteira no arquivo compactado ocupa
// espaço. Os compactadores de verdade guardam só o COMPRIMENTO do código de
// cada símbolo e refazem os códigos com uma regra fixa, a do código
// canônico:
//
// 1. ordene os símbolos por comprimento e, no empate, pelo byte;
// 2. o primeiro recebe o código 0 (com o comprimento dele, em bits);
// 3. cada próximo recebe o anterior + 1 e, se o comprimento cresceu,
//    desloque para a esquerda a diferença: codigo = (codigo + 1) << (l - l_ant).
//
// Use o TAD huffman.h na frase "BANANA NA CABANA" só para obter os
// comprimentos (strlen dos códigos). Depois gere e mostre os códigos
// canônicos, ao lado do código que o Huffman deu.
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
