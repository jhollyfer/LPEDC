// 0136 · Código de Huffman
// Exercício E812 · ★☆☆
//
// Um sensor de uma máquina manda um estado por segundo: N (normal), A
// (alerta), F (falha) ou D (desligado). Em 1000 leituras, as contagens
// foram N 700, A 200, F 80 e D 20. Com 4 estados, um código fixo gasta 2
// bits por leitura. Quanto o Huffman gasta?
//
// Preencha o vetor de frequências direto com as contagens (freq['N'] = 700
// e assim por diante), use o TAD huffman.h e mostre os códigos, o total do
// Huffman, o total do código fixo e a média de bits por leitura.
//
//   Saída esperada:
//   A: 01
//   D: 000
//   F: 001
//   N: 1
//   Huffman: 1400 bits
//   Fixo de 2 bits: 2000 bits
//   Média: 1.40 bits por leitura
//
// Dicas:
// 1. Um char é um número: freq['N'] usa a posição 78 do vetor.
// 2. Some freq[c] * strlen(cod[c]) para os bits e freq[c] para o total de
//    leituras.
// 3. Resposta esperada: a saída acima. Quanto mais desigual a distribuição,
//    maior o ganho: com as quatro contagens iguais (250 cada), o Huffman
//    daria os mesmos 2 bits do código fixo.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include "huffman.h"

int main(void) {

    return 0;
}
