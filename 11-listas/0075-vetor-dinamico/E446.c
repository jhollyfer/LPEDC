// 0075 · Vetor dinâmico
// Exercício E446 · ★☆☆
//
// Escreva um programa que acompanhe o vetor por dentro. Primeiro escreva a
// função mostra(rotulo, l), que imprime o rótulo, o tamanho, a capacidade e
// a lista, assim: "A: tam 2, cap 2 [5, 9]". Depois, começando com
// lista_cria(1), faça estas operações e chame mostra onde está indicado:
//
//   insere 5 no fim; insere 9 no fim              -> mostra "A"
//   insere 3 na posição 0; insere 7 no fim        -> mostra "B"
//   remove a posição 1 guardando em x;
//   insere x * 2 na posição 3                     -> mostra "C"
//   tenta remover a posição 4; se falhar, imprima "D: falhou, x = ..."
//   insere 1 no fim                               -> mostra "E"
//
//   Saída esperada:
//   A: tam 2, cap 2 [5, 9]
//   B: tam 4, cap 4 [3, 5, 9, 7]
//   C: tam 4, cap 4 [3, 9, 7, 10]
//   D: falhou, x = 5
//   E: tam 5, cap 8 [3, 9, 7, 10, 1]
//
// Dicas:
// 1. lista_imprime já termina com quebra de linha: em mostra, use printf
//    para o começo da linha e lista_imprime para o fim.
// 2. Inserir na posição igual ao tamanho é o mesmo que inserir no fim.
// 3. Remover numa posição que não existe devolve false e não mexe em x.
// 4. Resposta esperada: a saída acima. A capacidade dobra de 1 para 2, de 2
//    para 4 e de 4 para 8.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "lista.h"

int main(void) {

    return 0;
}
