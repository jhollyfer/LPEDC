// 0141 · Maior subsequência comum (LCS)
// Exercício E841 · ★☆☆
//
// Duas linhas de ônibus atravessam o centro. Cada ponto tem uma letra:
//
//   linha 101: A B C D E F G H
//   linha 202: B D C E G A H
//
// Quantos pontos as duas visitam na MESMA ordem (sem precisar ser pontos
// seguidos)? Escreva a função
//
//   int lcs(const char *a, const char *b)
//
// que devolve o tamanho da maior subsequência comum, e teste com os pares
// abaixo, mostrando cada um entre aspas.
//
//   Saída esperada:
//   "ABCDEFGH" x "BDCEGAH": 5
//   "CASA" x "ASA": 3
//   "" x "ABC": 0
//   "XYZ" x "XYZ": 3
//   "ABC" x "DEF": 0
//
// Dicas:
// 1. Tabela int c[51][51]; c[i][j] fala dos prefixos a[0..i-1] e b[0..j-1].
// 2. Linha 0 e coluna 0 valem 0. Letras iguais (a[i - 1] == b[j - 1]):
//    diagonal + 1. Diferentes: o maior entre cima e esquerda.
// 3. Para mostrar as aspas dentro do printf, use \".
// 4. Resposta esperada: a saída acima (na primeira, B C E G H, por exemplo).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
