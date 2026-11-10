// 0177 · Rubro-negra clássica
// Exercício E1060 · ★★☆
//
// Acompanhe o conserto da rubro-negra. Insira as senhas 10, 20, 30, 15, 25,
// 5, 1 e 27 (vermelhopreto.h) e, depois de cada uma, mostre quantas vezes
// cada caso do conserto rodou NAQUELA inserção (use T->casos[1], [2] e [3]
// antes e depois) e a pré-ordem. No fim, mostre o total de rotações.
//
//   Saída esperada:
//   insere 10: caso 1: 0 | caso 2: 0 | caso 3: 0 | pré 10
//   insere 20: caso 1: 0 | caso 2: 0 | caso 3: 0 | pré 10 20*
//   insere 30: caso 1: 0 | caso 2: 0 | caso 3: 1 | pré 20 10* 30*
//   insere 15: caso 1: 1 | caso 2: 0 | caso 3: 0 | pré 20 10 15* 30
//   insere 25: caso 1: 0 | caso 2: 0 | caso 3: 0 | pré 20 10 15* 30 25*
//   insere  5: caso 1: 0 | caso 2: 0 | caso 3: 0 | pré 20 10 5* 15* 30 25*
//   insere  1: caso 1: 1 | caso 2: 0 | caso 3: 0 | pré 20 10* 5 1* 15 30 25*
//   insere 27: caso 1: 0 | caso 2: 1 | caso 3: 1 | pré 20 10* 5 1* 15 27 25* 30*
//   rotações no total: 3
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "0177-vermelhopreto.h"

int main(void) {

    return 0;
}
