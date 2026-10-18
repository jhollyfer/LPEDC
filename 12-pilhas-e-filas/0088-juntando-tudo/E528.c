// 0088 · Juntando tudo: a calculadora de expressões
// Exercício E528 · ★★★
//
// O sistema operacional divide a CPU entre os processos com o rodízio
// (round-robin): cada processo da fila roda no máximo 2 ms (o quantum). Se
// terminou, sai; se não, volta para o FIM da fila com o tempo que falta.
// Quatro processos chegam juntos, nesta ordem: P1 precisa de 5 ms, P2 de 3,
// P3 de 1 e P4 de 4.
//
// Simule com uma fila do fila.h (guardando o número do processo) e um vetor
// com o tempo restante de cada um. Mostre o instante em que cada processo
// termina e o tempo médio de término.
//
//   Saída esperada:
//   t = 5 ms: P3 terminou
//   t = 10 ms: P2 terminou
//   t = 12 ms: P4 terminou
//   t = 13 ms: P1 terminou
//   Tempo médio de término: 10.0 ms
//
// Dicas:
// 1. A cada volta: retire um processo, rode min(2, restante) ms somando no
//    relógio, desconte do restante e, se ainda sobrar, insira de novo.
// 2. Para depurar, mostre a fila a cada volta: [1 2 3 4], [2 3 4 1],
//    [3 4 1 2]...
// 3. Resposta esperada: as cinco linhas acima ((13 + 10 + 5 + 12) / 4).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "fila.h"

int main(void) {

    return 0;
}
