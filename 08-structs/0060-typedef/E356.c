// 0060 · Typedef
// Exercício E356 · ★☆☆
//
// Preveja: o trecho compila? Se compila, o que mostra?
//
//   typedef int Metros;
//   typedef int Segundos;
//   typedef char Nome[12];
//
//   Metros distancia = 100;
//   Segundos tempo = 20;
//   Nome atleta = "Rayssa";
//
//   printf("%d\n", distancia + tempo);
//   printf("%d m/s\n", distancia / tempo);
//   printf("%zu\n", sizeof(Nome));
//   printf("%zu %zu\n", sizeof atleta, strlen(atleta));
//
// Dicas:
// 1. typedef não cria tipo novo: Metros e Segundos são int.
// 2. Nome é um apelido para "vetor de 12 char".
// 3. Resposta esperada: compila (somar metros com segundos não faz sentido,
//    mas o C não sabe disso) e mostra 120, "5 m/s", 12 e "12 6".
//
// Escreva sua resposta abaixo (como comentário; depois cole o trecho no main
// e confira):

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
