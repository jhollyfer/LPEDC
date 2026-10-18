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
// Dicas:
// 1. Guarde os símbolos presentes em simb[] e os comprimentos em comp[] e
//    ordene os dois juntos (um insertion sort basta: são poucos).
// 2. Guarde o código num unsigned. Para mostrar com l bits:
//    for (int b = l - 1; b >= 0; b--) putchar((codigo >> b) & 1 ? '1' : '0');
// 3. Resposta esperada: a saída acima. Os comprimentos são os mesmos, então o
//    total de bits continua 33, e o código continua livre de prefixo. A
//    vantagem: para descompactar, bastam 5 números (os comprimentos).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include "huffman.h"

int main(void) {

    return 0;
}
