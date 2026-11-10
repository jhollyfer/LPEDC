// Lista · Módulo 14 · Árvores
// Exercício P1418 · ★★☆ · O heapsort passo a passo
//
// Ordene as notas 6, 9, 2, 7, 10, 4, 8 com heapsort e mostre o estado do
// vetor como a prova pede: depois de construir o heap (BUILD-MAX-HEAP) e
// depois de cada passo da fase 2 (troca a raiz com o último da parte heap e
// faz a nova raiz descer). Separe com " | " a parte heap da parte já
// ordenada. Conte TODAS as trocas (as do desce e as da raiz com o fim) numa
// global trocas.
//
//   Saída esperada:
//   heap:      10 9 8 7 6 4 2
//   passo 1:   9 7 8 2 6 4 | 10
//   passo 2:   8 7 4 2 6 | 9 10
//   passo 3:   7 6 4 2 | 8 9 10
//   passo 4:   6 2 4 | 7 8 9 10
//   passo 5:   4 2 | 6 7 8 9 10
//   passo 6:   2 | 4 6 7 8 9 10
//   trocas: 15
//
// Dicas:
// 1. Faça mostra(rotulo, v, n, fim): antes do índice fim, imprime " | " em
//    vez de " ". Na linha do heap, passe fim = n (sem barra).
// 2. Ponha trocas++ dentro da função troca: assim nenhuma escapa.
// 3. Os rótulos são "heap:     " e "passo %d: " seguido de mostra com " ".
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int trocas;

int main(void) {

    return 0;
}
