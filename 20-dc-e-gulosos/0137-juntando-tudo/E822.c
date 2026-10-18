// 0137 · Juntando tudo
// Exercício E822 · ★★★
//
// Existe um limite para a compactação símbolo a símbolo: a ENTROPIA de
// Shannon. Se o símbolo i aparece com probabilidade p_i, nenhum código gasta
// em média menos que H = soma de (-p_i · log2 p_i) bits por símbolo. O
// Huffman chega perto: H <= média do Huffman < H + 1.
//
// Para o texto "O PADEIRO PEDIU PAPEL PARDO PARA O PAO DE PAPAI", use o TAD
// huffman.h para obter os códigos e calcule: quantos símbolos diferentes,
// quantos bits por letra gastaria um código fixo (o teto de log2 do número
// de símbolos), a média de bits por letra do Huffman e a entropia.
//
//   Saída esperada:
//   10 símbolos em 47 letras
//   Código fixo:  4 bits por letra
//   Huffman:      3.106 bits por letra
//   Entropia:     3.040 bits por letra
//
// Dicas:
// 1. log2 e ceil estão em math.h (o rodar já liga com -lm). Calcule p como
//    double: (double)freq[c] / n.
// 2. A média do Huffman é a soma de freq[c] * strlen(cod[c]) dividida por n.
// 3. Resposta esperada: a saída acima. A diferença de 0,07 bit por letra
//    vem de o Huffman só usar comprimentos inteiros. Os compactadores que
//    chegam ainda mais perto da entropia usam outra técnica (codificação
//    aritmética).
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>
#include <string.h>
#include "huffman.h"

int main(void) {

    return 0;
}
