// 0064 · Struct
// Exercício E380 · ★☆☆
//
// Preveja a saída deste trecho antes de rodar. Depois responda: e se, no
// lugar de struct placar b = a, fosse struct placar *b = &a (com b->fora)?
//
//   struct placar {
//       int casa;
//       int fora;
//   };
//
//   struct placar a = {2, 1};
//   struct placar b = a;
//   b.fora = 3;
//   a.casa = a.casa + b.fora;
//   printf("a: %d x %d\n", a.casa, a.fora);
//   printf("b: %d x %d\n", b.casa, b.fora);
//
// Dicas:
// 1. Em C, b = a copia todos os campos. Depois disso, a e b são independentes.
// 2. Faça uma tabela com a.casa, a.fora, b.casa e b.fora, linha a linha.
// 3. Resposta esperada: "a: 5 x 1" e "b: 2 x 3". Com o ponteiro, b apontaria
//    para o MESMO placar: b->fora = 3 mudaria a.fora, e os dois mostrariam
//    5 x 3.
//
// Escreva sua resposta abaixo (como comentário; depois cole o trecho no main
// e confira):

#include <stdio.h>

int main(void) {

    return 0;
}
