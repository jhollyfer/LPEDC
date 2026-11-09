// Lista · Módulo 21 · Programação dinâmica
// Exercício P2110 · ★☆☆ · Quantas mensagens cabem nesses números?
//
// Um aplicativo antigo codifica letras como números: A = 1, B = 2, ...,
// Z = 26, e manda tudo grudado. A sequência 226 pode ser BZ (2 26), VF
// (22 6) ou BBF (2 2 6): 3 leituras. Quantas leituras tem 1122612?
// Escreva do zero a PD: formas[i] é o número de leituras dos i primeiros
// dígitos. O dígito i sozinho vale se não é '0'; os dígitos i - 1 e i
// juntos valem se formam um número de 10 a 26.
//
//   Saída esperada:
//   226: 3 leituras
//   1122612: 16 leituras
//   301: 0 leituras
//
// Dicas:
// 1. formas[0] = 1 (a sequência vazia tem uma leitura: nenhuma letra).
// 2. formas[i] = (s[i - 1] != '0' ? formas[i - 1] : 0) + (i >= 2 e 10 <=
//    dois dígitos <= 26 ? formas[i - 2] : 0).
// 3. Resposta esperada: 3 para 226, 16 para 1122612 e 0 para 301 (o 30 e o
//    0 sozinho não são letras).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
