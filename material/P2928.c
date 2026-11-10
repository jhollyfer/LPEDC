// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2928 · ★★★ · Exato contra três aproximações
//
// Compare quatro jeitos de montar a volta do entregador em três dias
// diferentes, cada um com 9 pontos (o ponto 0 é a loja). Os pontos de cada
// dia vêm deste gerador, com semente = 11 * dia (dia = 1, 2, 3), coordenadas
// de 0 a 14 e distância em quarteirões:
//
//   semente = semente * 1103515245u + 12345u;  x[i] = (int)(semente >> 16) % 15;
//   semente = semente * 1103515245u + 12345u;  y[i] = (int)(semente >> 16) % 15;
//
// Para cada dia mostre: o ótimo (Held-Karp), o vizinho mais próximo, a
// árvore mínima em pré-ordem e a árvore seguida de 2-opt, com a razão de
// cada aproximação para o ótimo (%.2f).
//
//   Saída esperada:
//   dia  ótimo  vizinho     árvore      árvore+2opt
//     1     52   60 (1.15)   60 (1.15)   52 (1.00)
//     2     44   58 (1.32)   54 (1.23)   44 (1.00)
//     3     58   68 (1.17)   70 (1.21)   58 (1.00)
//
// Dicas:
// 1. Monte cada método como função que preenche int rota[N] (rota[0] = 0) e
//    uma função custo(rota). Held-Karp só precisa do custo.
// 2. No 2-opt, troque as arestas (a, b) e (c, e) por (a, c) e (b, e) quando
//    encurtar, invertendo o trecho, até nenhuma troca ajudar.
// 3. Resposta esperada: a saída acima. A árvore nunca passa de 2 vezes o
//    ótimo; o vizinho mais próximo não tem essa garantia.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
