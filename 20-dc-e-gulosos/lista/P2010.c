// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2010 · ★☆☆ · A poltrona com o próprio número
//
// No teatro, os ingressos vendidos (já em ordem crescente e sem repetição)
// foram para as poltronas -5 -2 0 1 2 5 9 12 15 18 (o negativo é o
// camarote). O gerente desconfia que algum ingresso está na POSIÇÃO igual
// ao próprio número: v[i] == i. Escreva do zero pos_fixa(v, ini, fim), por
// divisão e conquista como a busca binária: se v[meio] < meio, a resposta
// só pode estar à direita; se v[meio] > meio, só à esquerda. Conte as
// chamadas.
//
//   Saída esperada:
//   Posição 5: v[5] = 5
//   Chamadas: 3
//
// Dicas:
// 1. Por que dá para jogar metade fora? Com valores inteiros distintos e
//    crescentes, v[i + 1] >= v[i] + 1: a diferença v[i] - i nunca diminui.
// 2. Se v[meio] - meio < 0, à esquerda todas as diferenças são < 0.
// 3. Resposta esperada: posição 5 (v[5] = 5), em 3 chamadas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
