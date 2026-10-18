// 0126 · Permutações
// Exercício E756 · ★★★
//
// Às vezes você não quer TODAS as permutações de uma vez, só a próxima
// depois de uma dada, em ordem de dicionário. Escreva do zero a função
//
//   bool proxima(int v[], int n)
//
// que transforma v na permutação seguinte e devolve true, ou devolve false
// se v já é a última (em ordem decrescente). Sem recursão. Depois use-a para
// listar as permutações de {1, 2, 3} e teste os dois casos abaixo.
//
//   Saída esperada:
//   1 2 3
//   1 3 2
//   2 1 3
//   2 3 1
//   3 1 2
//   3 2 1
//   depois de 1 3 5 4 2 vem 1 4 2 3 5
//   5 4 3 2 1 é a última
//
// Dicas:
// 1. Ande da direita para a esquerda e ache o maior i com v[i] < v[i + 1]
//    (o "pivô"). Se não existe, v é a última. Em 1 3 5 4 2, o pivô é o 3.
// 2. Ache o maior j > i com v[j] > v[i] (o 4), troque v[i] com v[j] e
//    inverta o trecho v[i + 1..n - 1]: 1 4 5 3 2 vira 1 4 2 3 5.
// 3. Para listar todas: comece da ordem crescente e use
//    do { mostra(v); } while (proxima(v, n));
// 4. Resposta esperada: as 8 linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
