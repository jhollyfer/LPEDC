// 0080 · Lista circular
// Exercício E479 · ★★★
//
// O sistema operacional divide a CPU entre os programas com o escalonamento
// round-robin: cada processo roda no máximo um QUANTUM de tempo e vai para
// o fim da fila; quem termina sai da roda. Simule com uma lista circular de
// processos (id e tempo que falta), quantum 2, e os processos P1 (precisa de
// 5 unidades), P2 (2) e P3 (4), chegando nessa ordem no tempo 0.
//
//   Saída esperada:
//   t=0..2: P1 (falta 3)
//   t=2..4: P2 (terminou)
//   t=4..6: P3 (falta 2)
//   t=6..8: P1 (falta 1)
//   t=8..10: P3 (terminou)
//   t=10..11: P1 (terminou)
//
// Escreva tudo neste arquivo, com uma struct sua.
//
// Dicas:
// 1. Guarde a roda pelo último nó, como no lista.c. Quem roda é sempre
//    ultimo->prox, o primeiro.
// 2. A cada vez: fatia = menor entre o quantum e o que falta. Some a fatia
//    no relógio e tire do processo.
// 3. Se o processo terminou, tire ele da roda (ultimo->prox = p->prox,
//    free, e cuidado se ele era o único). Se não terminou, ele vai para o
//    fim: basta fazer ultimo = p. Girar a roda é mudar um ponteiro.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
