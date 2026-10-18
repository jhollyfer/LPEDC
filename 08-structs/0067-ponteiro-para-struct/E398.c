// 0067 · Ponteiro para struct
// Exercício E398 · ★☆☆
//
// Preveja a saída antes de rodar:
//
//   typedef struct {
//       int gols;
//   } Placar;
//
//   void gol_copia(Placar p) { p.gols++; }
//   void gol(Placar *p) { p->gols++; }
//
//   int main(void) {
//       Placar casa = {0};
//       gol_copia(casa);
//       gol(&casa);
//       gol(&casa);
//       gol_copia(casa);
//       printf("%d\n", casa.gols);
//
//       Placar *ptr = &casa;
//       ptr->gols += 10;
//       printf("%d %d\n", casa.gols, (*ptr).gols);
//       return 0;
//   }
//
// Dicas:
// 1. Quem recebe Placar (sem *) trabalha numa cópia.
// 2. ptr->gols e (*ptr).gols são a mesma coisa, e ptr aponta para casa.
// 3. Resposta esperada: 2 e depois "12 12". Só as duas chamadas de gol(&casa)
//    contam; gol_copia aumenta uma cópia que some no fim da função.
//
// Escreva sua resposta abaixo (como comentário; depois cole o código e
// confira):

#include <stdio.h>

int main(void) {

    return 0;
}
