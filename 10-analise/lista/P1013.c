// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1013 · ★★☆ · Busca binária com o invariante à vista
//
// As senhas atendidas no dia estão em ordem: 3, 8, 15, 21, 29, 34, 42, 50,
// 57 e 63. Escreva int busca(const int v[], int n, int x, int *passos), a
// busca binária com ini e fim (intervalo fechado), e ponha dois assert:
//
//   - no começo de cada volta, o invariante: "x não está fora de
//     v[ini..fim]", isto é, não está em v[0..ini-1] nem em v[fim+1..n-1];
//   - depois do laço (quando não achou), ini > fim: o intervalo ficou vazio,
//     e então o invariante garante que x não está no vetor.
//
// Para o assert, escreva bool fora_ausente(v, n, ini, fim, x), que confere
// as duas pontas de fora com laços simples. Conte em *passos as voltas do
// laço. Procure 42, 3 e 60.
//
//   Saída esperada:
//   42: posição 6 (4 passos)
//   3: posição 0 (3 passos)
//   60: não está (4 passos)
//
// Dicas:
// 1. Se v[meio] < x, todo v[0..meio] é < x (o vetor é crescente): ini =
//    meio + 1 preserva o invariante. O mesmo vale do outro lado.
// 2. fora_ausente custa O(n) por chamada, então ela só serve para provar a
//    corretude. Numa versão de produção, os assert saem (ou se compila com
//    -DNDEBUG) e a busca volta a ser O(log n).
// 3. Resposta esperada: a saída acima, sem nenhum assert disparar.
//
// Escreva sua resposta abaixo:

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
