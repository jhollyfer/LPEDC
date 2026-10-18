// 0081 · Juntando tudo
// Exercício E482 · ★☆☆
//
// Hora de testar as pontas da playlist. Escreva a função
//
//   void mostra(const Musica *m)
//
// que imprime o título da música, ou "(nada)" quando m é NULL. Depois crie
// uma playlist com Um (Banda A, 100 s), Dois (Banda B, 200 s) e Tres
// (Banda C, 300 s) e faça, nesta ordem, chamando mostra com o que cada
// passo marcado com * devolve:
//
//   * a música atual
//   * volta uma (anterior)
//     avança uma
//   * avança uma
//   * avança uma
//     liga o repetir
//   * avança uma
//   * volta uma
//     remove "Tres"
//   * a música atual
//     remove "Um" e mostra quantas músicas e quantos segundos sobraram
//   * avança uma
//
//   Saída esperada:
//   Um
//   (nada)
//   Tres
//   (nada)
//   Um
//   Tres
//   Dois
//   1 música, 200 s
//   Dois
//
// Dicas:
// 1. Com repetir desligado, andar além da ponta devolve NULL e não sai do
//    lugar; ligado, dá a volta.
// 2. Removendo a música que toca, passa a tocar a seguinte; se ela era a
//    última, a anterior. Com uma música só e repetir ligado, a próxima é
//    ela mesma.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "playlist.h"

int main(void) {

    return 0;
}
