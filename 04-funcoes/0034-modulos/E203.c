// 0034 · Módulos: .h, .c e compilação separada
// Exercício E203 · ★★★
//
// Um projeto de placar tem dois arquivos, compilados juntos com
// "gcc placar.c main.c -o placar":
//
//   // placar.c
//   static int gols = 0;
//   int partidas = 0;
//   static void anotar(void) { gols++; }
//   void marcar_gol(void) { anotar(); }
//   int total_gols(void) { return gols; }
//
//   // main.c
//   #include <stdio.h>
//   void marcar_gol(void);
//   int total_gols(void);
//   extern int partidas;
//   int main(void) {
//       marcar_gol();
//       marcar_gol();
//       partidas = partidas + 1;
//       printf("%d gols em %d partida\n", total_gols(), partidas);
//       return 0;
//   }
//
// Responda:
// a) O que o programa mostra?
// b) Se o main.c tivesse "extern int gols;" e usasse gols, o que aconteceria?
// c) E se o main.c chamasse anotar() (com o protótipo "void anotar(void);")?
// d) Se o main.c tivesse "int partidas = 0;" em vez de "extern int partidas;",
//    o que aconteceria?
// e) Qual a vantagem de gols ser static e ter a função total_gols?
//
// Dicas:
// 1. static fora de função: o nome não sai do arquivo. extern: "está definida
//    em outro arquivo".
// 2. Erros com nomes que não existem ou existem duas vezes aparecem no
//    ligador, não no compilador.
// 3. Resposta esperada: a) "2 gols em 1 partida". b) e c) compila, mas o
//    ligador dá "undefined reference": gols e anotar são static em placar.c.
//    d) duas definições de partidas: o ligador dá "multiple definition of
//    partidas". e) ninguém de fora consegue mudar o placar sem passar por
//    marcar_gol: o módulo controla o próprio dado.
//
// Escreva sua resposta abaixo (em comentário):

#include <stdio.h>

int main(void) {

    return 0;
}
