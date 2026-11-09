// Lista · Módulo 21 · Programação dinâmica
// Exercício P2113 · ★★☆ · LCS de três versões
//
// Três alunos copiaram o mesmo resumo e cada um errou umas letras. O
// professor quer a maior sequência de letras que aparece, na ordem, nas
// TRÊS versões. É a LCS com três strings: a tabela vira um cubo
// t[i][j][k]. Se as três letras a[i - 1], b[j - 1] e c[k - 1] são iguais,
// t = 1 + t[i - 1][j - 1][k - 1]; senão, o máximo de tirar uma letra de
// cada uma das três (t[i - 1][j][k], t[i][j - 1][k] e t[i][j][k - 1]).
// Escreva do zero e reconstrua a sequência.
//
//   A: AMAZONIA
//   B: AMAZONAS
//   C: MAZOMBA
//
//   Saída esperada:
//   Comum às três: MAZOA (5 letras)
//
// Dicas:
// 1. int t[9][9][9]; com i, j ou k igual a 0, vale 0.
// 2. Reconstrução, de (m, n, p) para trás: letras iguais e t = 1 + diagonal
//    entra na resposta; senão, vá para o vizinho que tem o mesmo valor.
//    Monte a string de trás para a frente.
// 3. Resposta esperada: MAZO, 4 letras. O custo é O(m · n · p).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
