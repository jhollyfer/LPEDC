// Lista · Módulo 06 · Ponteiros
// Exercício P0602 · ★☆☆ · As leituras até o -1
//
// O hidrômetro manda o consumo diário (em litros) e o -1 marca o fim das
// leituras:
//
//   int leituras[] = {312, 280, 455, 301, 298, -1};
//
// Sem usar colchetes depois da declaração, ande com um ponteiro p de
// leituras até achar o -1, somando o consumo. No fim, use a diferença de
// ponteiros p - leituras para saber quantas leituras eram e mostre a média:
//
//   Saída esperada:
//   Leituras: 5
//   Total: 1646 litros
//   Média: 329.20 litros por dia
//
// Dicas:
// 1. int *p = leituras; while (*p != -1) { soma += *p; p++; }
// 2. Quando o laço termina, p aponta para o -1. A distância p - leituras
//    conta ELEMENTOS (não bytes): é a quantidade de leituras.
// 3. O tipo da diferença de ponteiros é ptrdiff_t; para mostrar, converta
//    para int e use %d (ou use %td direto).
// 4. Resposta esperada: a saída acima (5 leituras, média 329.20 litros).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int leituras[] = {312, 280, 455, 301, 298, -1};
    (void) leituras; // apague esta linha quando escrever

    return 0;
}
