// Lista · Módulo 25 · Estruturas especiais
// Exercício P2517 · ★★☆ · Cache LRU contra cache FIFO
//
// O app de mapas guarda na memória os pedaços do mapa usados há pouco. Os
// pedidos de pedaços do dia são:
//
//   1 2 3 1 4 1 2 5 1 2 3 4 1 5 2 1
//
// Quando o cache está cheio e chega um pedaço novo, alguém sai. No FIFO
// sai o que ENTROU há mais tempo; no LRU sai o que foi USADO há mais tempo
// (acertar um pedaço o renova). Escreva simula(cap, lru), que devolve os
// acertos, e mostre a tabela para capacidades de 1 a 5.
//
//   Saída esperada:
//   capacidade  LRU  FIFO
//            1    0     0
//            2    1     1
//            3    5     4
//            4    7     5
//            5   11    11
//
// Dicas:
// 1. Use um vetor em que a posição 0 é sempre a próxima a sair. Falta com
//    o cache cheio: tire a posição 0 e ponha o novo no fim.
// 2. A única diferença: no LRU, um acerto leva o pedaço para o fim do
//    vetor; no FIFO, o acerto não muda nada.
// 3. Resposta esperada: com capacidade 4, LRU 7 acertos e FIFO 5; com 5
//    todos cabem e os dois dão 11 (16 pedidos - 5 primeiras entradas).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
