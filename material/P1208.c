// Lista · Módulo 12 · Pilhas e filas
// Exercício P1208 · ★☆☆ · O jogo das bolhas de mesma cor
//
// No joguinho do celular, as bolhas caem em fila, e duas bolhas da MESMA cor
// que ficam encostadas estouram. Quando um par estoura, as vizinhas se
// encostam e podem estourar também. Cada cor é uma letra. Escreva
//
//   void estoura(const char *bolhas, char *sobra)
//
// que usa uma pilha de char: para cada bolha, se ela é igual à do topo, o
// topo sai (as duas estouram); senão, ela é empilhada. No fim, a pilha (de
// baixo para cima) é o que sobrou. Teste com abbaca, aabbcc, azxxzy e abc.
//
//   Saída esperada:
//   abbaca -> ca
//   aabbcc -> (nada)
//   azxxzy -> ay
//   abc -> abc
//
// Dicas:
// 1. Em abbaca: a; ab; o b estoura com o b (fica a); o a estoura com o a
//    (vazia); c; ca.
// 2. A pilha pode ser o próprio vetor sobra, com um índice n: o fundo da
//    pilha é sobra[0]. No fim, sobra[n] = '\0'.
// 3. Resposta esperada: a saída acima. Cada bolha entra e sai no máximo uma
//    vez: O(n).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
