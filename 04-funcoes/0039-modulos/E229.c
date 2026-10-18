// 0039 · Módulos: .h, .c e compilação separada
// Exercício E229 · ★☆☆
//
// Você vai criar o módulo "frete" (frete.h e frete.c). Para cada linha
// abaixo, diga se ela vai no frete.h, no frete.c ou em nenhum dos dois:
//
//   a) double calcular_frete(double peso_kg, int distancia_km);
//   b) double calcular_frete(double peso_kg, int distancia_km) { ... }
//   c) #ifndef FRETE_H
//   d) static double taxa_por_km(int distancia_km) { ... }
//   e) #include "frete.h"
//   f) int main(void) { ... }
//   g) #define FRETE_GRATIS_ACIMA 200.0
//   h) #include "frete.c"
//
// Dicas:
// 1. O .h diz O QUE o módulo oferece; o .c diz COMO.
// 2. Uma função static é interna: quem usa o módulo não precisa saber que ela existe.
// 3. Resposta esperada: a) .h; b) .c; c) .h (abre o include guard); d) .c;
//    e) .c (o frete.c inclui o próprio .h, e o programa que usa também);
//    f) nenhum dos dois: o main fica no programa que usa o módulo; g) .h, se
//    quem usa precisa saber o valor (senão, no .c); h) nenhum: nunca inclua
//    um .c.
//
// Escreva sua resposta abaixo (em comentário):

#include <stdio.h>

int main(void) {

    return 0;
}
