// 0079 · TAD: interface (.h) e implementação (.c)
// Exercício E471 · ★★☆
//
// Escreva um TAD Ponto para o app de entregas, com estas operações:
//
//   Ponto *ponto_cria(double x, double y);   // NULL se faltar memória
//   void ponto_libera(Ponto *p);
//   double ponto_x(const Ponto *p);
//   double ponto_y(const Ponto *p);
//   double ponto_distancia(const Ponto *a, const Ponto *b);
//
// Num projeto de verdade seriam ponto.h e ponto.c. Aqui, para o exercício
// ficar num arquivo só, separe as três partes com comentários: "ponto.h"
// (typedef e protótipos), "ponto.c" (struct e funções) e "cliente" (main).
// No main, use só as funções, nunca os campos: loja em (0, 0), cliente em
// (3, 4); depois um ponto A em (-2, 1) e um ponto B em (4, 9). Distâncias em
// km.
//
//   Saída esperada:
//   Loja (0.0, 0.0) -> cliente (3.0, 4.0): 5.00 km
//   A -> B: 10.00 km
//
// Dicas:
// 1. Distância: sqrt(dx * dx + dy * dy), com sqrt de <math.h>.
// 2. typedef struct ponto Ponto; em cima, a struct ponto { double x, y; }
//    só na parte "ponto.c".
// 3. São 4 pontos criados: 4 ponto_libera no fim (o rodar acusa vazamento).
// 4. Resposta esperada: a saída acima (os triângulos 3-4-5 e 6-8-10).
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
