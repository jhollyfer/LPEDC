// 0127 · Backtracking
// Exercício E762 · ★★★
//
// Desafio da revista de passatempos: coloque um sinal + ou - antes de cada
// número de 2 a 7, na sequência 1 _ 2 _ 3 _ 4 _ 5 _ 6 _ 7, para que a conta
// dê 10 (o 1 é sempre positivo). Escreva do zero um backtracking que mostre
// todas as soluções, tentando sempre + antes de -, e conte as chamadas da
// função recursiva. Use esta poda, no começo de cada chamada: se nem
// somando nem subtraindo todos os números que faltam dá para chegar a 10,
// volte.
//
//   Saída esperada:
//   1+2+3-4-5+6+7 = 10
//   1+2-3+4+5-6+7 = 10
//   1-2+3+4+5+6-7 = 10
//   1-2-3-4+5+6+7 = 10
//   4 expressões, 83 chamadas
//
// Dicas:
// 1. A função tenta(k, soma) decide o sinal do número k; a primeira chamada
//    é tenta(2, 1). Guarde os sinais num vetor de char.
// 2. Os números que faltam são k, k + 1, ..., 7. Se a distância
//    abs(10 - soma) for maior que a soma deles, nenhuma escolha de sinais
//    fecha a conta. Pré-calcule essas somas num vetor resto[].
// 3. Sem a poda seriam 127 chamadas (a árvore completa de 6 decisões).
// 4. Resposta esperada: as 5 linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
