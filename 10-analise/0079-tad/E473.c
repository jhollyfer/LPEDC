// 0079 · TAD: interface (.h) e implementação (.c)
// Exercício E473 · ★★★
//
// A receita pede 1/2 xícara de leite e depois mais 1/3. Escreva um TAD
// Racional (fração), num arquivo só, separado em "racional.h", "racional.c" e
// "cliente", com o invariante: denominador > 0 e fração sempre simplificada
// (mdc(|num|, den) == 1). Operações:
//
//   Racional *racional_cria(int num, int den);  // NULL se den == 0
//   void racional_libera(Racional *r);
//   Racional *racional_soma(const Racional *a, const Racional *b);
//   Racional *racional_multiplica(const Racional *a, const Racional *b);
//   void racional_imprime(const Racional *r);   // ex.: 5/6
//
// No cliente, mostre: 1/2 + 1/3; 2/4 (já simplificado); 3/-6; (1/2) * (2/3);
// e tente criar 1/0.
//
//   Saída esperada:
//   1/2 + 1/3 = 5/6
//   2/4 vira 1/2
//   3/-6 vira -1/2
//   1/2 * 2/3 = 1/3
//   1/0: não existe
//
// Dicas:
// 1. Toda criação passa por racional_cria, que simplifica e acerta o sinal.
//    Assim soma e multiplica só fazem a conta e chamam racional_cria.
// 2. a/b + c/d = (a*d + c*b) / (b*d). O mdc vem de Euclides (assunto 0038)
//    e pode ser uma função static.
// 3. Denominador negativo: troque o sinal dos dois.
// 4. Cada Racional devolvido é um malloc: libere todos.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
