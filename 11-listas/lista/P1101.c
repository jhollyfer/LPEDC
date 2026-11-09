// Lista · Módulo 11 · Listas
// Exercício P1101 · ★☆☆ · Encaixar uma música no meio da playlist
//
// A playlist da festa junina é uma lista sequencial: um vetor de 8 códigos
// de música e um contador n. Escreva
//
//   bool seq_insere(ListaSeq *l, int pos, int codigo)
//
// que põe o código na posição pos (0 <= pos <= n), empurrando uma casa para
// a direita os que estavam de pos em diante, e devolve false se a lista
// estiver cheia ou se pos for inválida. Conte os deslocamentos numa variável
// global. Faça, nesta ordem: insere(0, 10), insere(1, 30), insere(1, 20),
// insere(0, 5) e insere(9, 99).
//
//   Saída esperada:
//   [5 10 20 30]
//   Inserir na posição 9: recusado
//   Deslocamentos: 4
//
// Dicas:
// 1. Empurre de trás para a frente: for (i = n; i > pos; i--) v[i] =
//    v[i - 1]. Da frente para trás, você copiaria o mesmo valor em tudo.
// 2. pos == n é válido: é inserir no fim, sem deslocar ninguém.
// 3. Inserir na posição pos custa n - pos deslocamentos: O(n) no pior caso
//    (pos = 0), O(1) no fim.
// 4. Resposta esperada: a saída acima (0 + 0 + 1 + 3 deslocamentos).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define CAP 8

typedef struct {
    int v[CAP];
    int n;
} ListaSeq;

int main(void) {

    return 0;
}
