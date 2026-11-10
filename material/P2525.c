// Lista · Módulo 25 · Estruturas especiais
// Exercício P2525 · ★★★ · O relógio da segunda chance
//
// O sistema operacional não consegue mover páginas numa lista a cada
// acesso, como o LRU pede. Ele usa o RELÓGIO (segunda chance): os quadros
// ficam numa roda, cada um com um bit de uso. Acesso a página que está lá
// liga o bit. Na falta com a roda cheia, o ponteiro anda: quem tem bit 1
// perde a chance (bit vira 0) e é pulado; o primeiro com bit 0 sai, a
// página nova entra ali com bit 1 e o ponteiro avança uma casa. Escreva
// do zero relogio(cap, mostrar) e lru(cap), que devolvem os acertos.
// Mostre o passo a passo do relógio com 3 quadros (o ponteiro marcado com
// '>' e cada quadro como página:bit) e a tabela para 2, 3 e 4 quadros.
//
//   Pedidos: 1 2 3 4 1 2 5 1 2 3 4 5
//
//   Saída esperada:
//   1 falta  >1:1
//   2 falta  >1:1  2:1
//   3 falta  >1:1  2:1  3:1
//   4 falta   4:1 >2:0  3:0
//   1 falta   4:1  1:1 >3:0
//   2 falta  >4:1  1:1  2:1
//   5 falta   5:1 >1:0  2:0
//   1 acerto  5:1 >1:1  2:0
//   2 acerto  5:1 >1:1  2:1
//   3 falta   5:0  3:1 >2:0
//   4 falta  >5:0  3:1  4:1
//   5 acerto >5:1  3:1  4:1
//   Relógio, 3 quadros: 3 acertos
//   quadros  LRU  relógio
//          2    0        0
//          3    2        3
//          4    4        2
//
// Dicas:
// 1. Enquanto a roda não está cheia, a página entra no próximo quadro
//    livre e o ponteiro fica em 0.
// 2. O relógio é uma aproximação do LRU com UM bit por página. Às vezes
//    acerta mais, às vezes menos: com 4 quadros, esta sequência engana o
//    relógio.
// 3. Resposta esperada: com 3 quadros, relógio 3 e LRU 2; com 4, relógio
//    2 e LRU 4.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
