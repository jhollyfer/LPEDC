// 0087 · Deque
// Exercício E519 · ★★☆
//
// No vôlei, os 6 jogadores de um time fazem rodízio. Guarde os números 1 a 6
// num deque do deque.h e escreva três funções que usam só a interface:
//
// - void mostra(Deque *d): mostra os itens da frente para o fundo, sem
// perder nenhum (o deque tem que ficar igual);
// - void gira_esquerda(Deque *d, int k): o da frente vai para o fundo, k
// vezes;
// - void gira_direita(Deque *d, int k): o do fundo vem para a frente, k
// vezes.
//
//   Saída esperada:
//   Início: 1 2 3 4 5 6
//   Esquerda 2: 3 4 5 6 1 2
//   Direita 3: 6 1 2 3 4 5
//
// Dicas:
// 1. mostra pode girar o deque uma volta completa: tira da frente, mostra e
//    põe no fundo, deque_tamanho vezes.
// 2. gira_direita é o espelho: retira_fim e insere_inicio.
// 3. Cada giro custa O(1). Num vetor comum, girar uma posição custaria
//    O(n), porque todo mundo anda uma casa.
// 4. Resposta esperada: as três linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "deque.h"

int main(void) {

    return 0;
}
