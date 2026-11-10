// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1914 · ★★☆ · Os anagramas de BOLO sem repetir
//
// A permutação com usado[] gera 4! = 24 ordens para as letras de BOLO, mas
// como o O aparece duas vezes, cada anagrama sai repetido. Escreva do zero
// um gerador que conta quantas vezes cada letra sobra (B: 1, L: 1, O: 2) e,
// em cada posição, tenta cada letra DIFERENTE que ainda tem sobra. Assim
// cada anagrama sai uma vez só, em ordem alfabética.
//
//   Saída esperada:
//   BLOO
//   BOLO
//   BOOL
//   LBOO
//   LOBO
//   LOOB
//   OBLO
//   OBOL
//   OLBO
//   OLOB
//   OOBL
//   OOLB
//   Total: 12 anagramas
//
// Dicas:
// 1. Guarde as letras distintas em ordem (B, L, O) e um vetor sobra[] = {1,
//    1, 2}. Escolher a letra j é sobra[j]--; desfazer é sobra[j]++.
// 2. Como cada letra distinta é tentada uma vez por posição, a ordem dos
//    Os não importa mais.
// 3. Resposta esperada: 12 anagramas, que é 4! / 2!.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
