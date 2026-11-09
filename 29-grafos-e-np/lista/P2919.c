// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2919 · ★★☆ · Quão longe do ótimo fica a 2-aproximação?
//
// Rode a cobertura de vértices 2-aproximada (arestas na ordem dada; aresta
// descoberta -> as duas pontas entram) e a cobertura ótima por força bruta
// em três grafos de 8 vértices, e mostre a razão:
//
//   caminho: 0-1, 1-2, 2-3, 3-4, 4-5, 5-6, 6-7
//   estrela: 0-1, 0-2, 0-3, 0-4, 0-5, 0-6, 0-7
//   completo + caminho: 0-1, 0-2, 0-3, 1-2, 1-3, 2-3, 4-5, 5-6, 6-7
//
// Escreva void compara(const char *nome, int ne, int a[][2]).
//
//   Saída esperada:
//   caminho: aprox 8, ótimo 4, razão 2.00
//   estrela: aprox 2, ótimo 1, razão 2.00
//   completo + caminho: aprox 8, ótimo 5, razão 1.60
//
// Dicas:
// 1. A força bruta testa as 256 máscaras e fica com a menor que cobre todas as
//    arestas.
// 2. Mostre "aprox A, ótimo O, razão R" com R em %.2f.
// 3. Resposta esperada: a saída acima. A razão nunca passa de 2: no caminho e
//    na estrela ela bate exatamente em 2; com o K4 ela cai.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
