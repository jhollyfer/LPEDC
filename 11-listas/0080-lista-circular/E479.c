// 0080 · Lista circular
// Exercício E479 · ★★★
//
// O sistema operacional divide a CPU entre os programas com o escalonamento
// round-robin: cada processo roda no máximo um QUANTUM de tempo e vai para
// o fim da fila; quem termina sai da roda. Simule com uma lista circular de
// processos (id e tempo que falta), quantum 2, e os processos P1 (precisa de
// 5 unidades), P2 (2) e P3 (4), chegando nessa ordem no tempo 0. A struct é sua.
//
//   Saída esperada:
//   t=0..2: P1 (falta 3)
//   t=2..4: P2 (terminou)
//   t=4..6: P3 (falta 2)
//   t=6..8: P1 (falta 1)
//   t=8..10: P3 (terminou)
//   t=10..11: P1 (terminou)
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
