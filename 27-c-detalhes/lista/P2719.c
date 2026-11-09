// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2719 · ★★☆ · Ordenar andando com ponteiros
//
// Sem usar índice nenhum (nada de v[i]), só aritmética de ponteiros, escreva:
//
//   int *maior(int *ini, int *fim)   // o maior em [ini, fim); fim fica de fora
//   void ordenar(int *ini, int *fim) // ordem crescente, por seleção
//
// Ordenar coloca o maior do trecho na última posição, encurta o trecho e
// repete. Use com o vetor {42, 7, 19, 88, 3} e mostre o índice do maior
// com a diferença de ponteiros.
//
//   Saída esperada:
//   maior: 88 no índice 3
//   ordenado: 3 7 19 42 88
//
// Dicas:
// 1. for (int *p = ini + 1; p < fim; p++) percorre o trecho.
// 2. p - v dá o índice, do tipo ptrdiff_t: mostre com %td.
// 3. Na ordenação, troque *maior(ini, fim) com *(fim - 1) e faça fim--.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
