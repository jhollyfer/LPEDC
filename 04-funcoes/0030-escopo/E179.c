// 0030 · Escopo e tempo de vida
// Exercício E179 · ★★★
//
// Quatro variáveis chamadas x, cada uma com escopo e tempo de vida
// diferentes. Escreva o programa a partir destas regras:
//
//   int x = 10;     global
//   void a(void)    tem uma local x = 1; mostra "a: <x>", soma 1, mostra " -> <x>"
//   int b(void)     tem uma static x = 5; mostra "b: <x>", soma 5, mostra
//                   " -> <x>" e devolve o x novo
//   void c(void)    não declara x: mostra "c: <x>", dobra, mostra " -> <x>"
//
// O main tem a própria local x = 20 e mostra "main: 20"; abre um bloco com
// outra x = 30 e mostra "bloco: 30"; chama a, b e c duas vezes, nessa ordem,
// somando numa local os dois retornos de b; mostra "main: <x>" e a soma.
//
//   Saída esperada:
//   main: 20
//   bloco: 30
//   a: 1 -> 2
//   b: 5 -> 10
//   c: 10 -> 20
//   a: 1 -> 2
//   b: 10 -> 15
//   c: 20 -> 40
//   main: 20
//   soma dos b: 25
//
// Dicas:
// 1. A local de a recomeça em 1 a cada chamada; a static de b continua de
//    onde parou; c mexe na global, porque é a única x que ela enxerga.
// 2. O main não enxerga a static de b: o único jeito de saber o valor dela
//    lá fora é pelo return.
// 3. Resposta esperada: a saída acima. A x do main nunca muda, e a global
//    termina valendo 40.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
