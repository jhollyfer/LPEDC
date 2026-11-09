// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2206 · ★☆☆ · O começo que todas têm
//
// O professor de português escreveu no quadro as palavras da família de
// "comer": comer, comida, comilão, comedor, comestível (sem acento, para a
// trie de 'a' a 'z': comer, comida, comilao, comedor, comestivel). Qual o
// MAIOR PREFIXO COMUM a todas? Escreva do zero uma trie (26 filhos e um
// bool fim por nó) e a função prefixo_comum(r, buf): desça a partir da
// raiz enquanto o nó tem EXATAMENTE um filho e não é fim de palavra,
// anotando as letras. Mostre o resultado para as duas listas do main.
//
//   Saída esperada:
//   comer, comida, comilao, comedor, comestivel: prefixo comum "com"
//   solar, sol, solteiro, soldado: prefixo comum "sol"
//
// Dicas:
// 1. conta_filhos(n) percorre os 26 ponteiros. Se o nó tem 1 filho, ache
//    qual (a letra 'a' + i) e desça.
// 2. Pare se o nó é fim de palavra: "sol" e "solar" têm prefixo comum
//    "sol", e não "sola".
// 3. Resposta esperada: "com" para a primeira lista e "sol" para a
//    segunda. Libere a trie no fim.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
