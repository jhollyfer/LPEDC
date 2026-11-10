// 0073 · Invariantes de laço e corretude
// Exercício E435 · ★★☆
//
// Escreva int ultima(const int v[], int n, int x), que procura a ÚLTIMA vez
// que um aluno tirou a nota x, andando do fim para o começo (começa em
// k = n - 1 e anda enquanto k >= 0 e v[k] != x). Devolve a posição, ou -1 se a
// nota não aparece. Transforme a prova de que ela está certa em código:
//
// 1. escreva bool nao_esta(v, ini, fim, x), que devolve true se x não aparece
//    em v[ini..fim-1] (pedaço vazio: true);
// 2. dentro do laço, confira com assert o invariante "x não está em v[k+1..n-1]";
// 3. depois do laço, confira com assert o término: ou k == -1, ou v[k] == x e
//    o invariante ainda vale.
//
// Teste com notas = {7, 9, 4, 9, 6}, e também com um vetor vazio (n = 0).
//
//   Saída esperada:
//   última nota 9: posição 3
//   última nota 5: posição -1
//   última nota 7: posição 0
//   vetor vazio: posição -1
//
// Escreva sua resposta abaixo:

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
