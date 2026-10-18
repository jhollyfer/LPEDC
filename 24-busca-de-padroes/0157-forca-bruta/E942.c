// 0157 · Força bruta
// Exercício E942 · ★★★
//
// Caça-palavras da revistinha. A grade tem 5 linhas e 8 colunas, guardada
// numa matriz de char (cada linha é uma string). Procure as palavras "SOL",
// "MAR", "LUA", "CEU" e "RIO" na horizontal (da esquerda para a direita) e
// na vertical (de cima para baixo), por força bruta: teste cada casa como
// começo e cada direção.
//
//   S O L X M A R Z
//   A Q L U A P E O
//   B M U S O L X R
//   R A A I B Z X A
//   A R R C E U P S
//
//   Saída esperada:
//   SOL: linha 0, coluna 0, horizontal
//   SOL: linha 2, coluna 3, horizontal
//   MAR: linha 0, coluna 4, horizontal
//   MAR: linha 2, coluna 1, vertical
//   LUA: linha 1, coluna 2, horizontal
//   LUA: linha 1, coluna 2, vertical
//   CEU: linha 4, coluna 3, horizontal
//   RIO: não está na grade
//
// Dicas:
// 1. Declare const char grade[5][9] = {"SOLXMARZ", ...}: 8 letras + '\0'.
// 2. Uma função casa(grade, l, c, dl, dc, palavra) testa a palavra a partir
//    de (l, c) andando dl linhas e dc colunas por letra: (0, 1) é horizontal,
//    (1, 0) é vertical.
// 3. Antes de comparar, veja se a última letra cabe na grade:
//    l + dl * (m - 1) < 5 e c + dc * (m - 1) < 8. Sem isso, você lê fora da
//    matriz.
// 4. Percorra as casas linha por linha e, em cada casa, teste horizontal e
//    depois vertical. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
