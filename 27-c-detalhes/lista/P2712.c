// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2712 · ★★☆ · A célula da planilha (union com etiqueta)
//
// Uma célula de planilha guarda um inteiro, um número real ou um texto, um
// de cada vez. Monte uma union com etiqueta:
//
//   typedef enum { INTEIRO, REAL, TEXTO } Tipo;
//   typedef struct { Tipo tipo; union { int i; double d; char s[16]; } v; } Celula;
//
// Escreva void mostrar(const Celula *c), com um switch sobre c->tipo que lê
// só o campo certo da union. Mostre as células 42, 3.14 e "feira" e, no fim,
// o sizeof de Celula e da union.
//
//   Saída esperada:
//   inteiro: 42
//   real: 3.14
//   texto: feira
//   sizeof(Celula) = 24, sizeof da union = 16
//
// Dicas:
// 1. Na union, os três campos começam no mesmo byte: o tamanho é o do maior
//    (16, o vetor de char), e não a soma.
// 2. A struct tem 4 bytes do enum, 4 de sobra para alinhar o double da
//    union e os 16 da union: 24.
// 3. Para o texto, use strcpy(c.v.s, "feira") depois de pôr c.tipo = TEXTO.
// 4. sizeof c.v mede só a union.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
