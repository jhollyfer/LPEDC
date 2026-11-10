// 0177 · Rubro-negra clássica
// Exercício E1059 · ★★☆
//
// O Cormen prova que a subárvore de qualquer nó x tem pelo menos
// 2^bh(x) - 1 nós, onde bh(x) é a altura negra de x: quantos pretos há de x
// (sem contar x) até uma folha nil (contando a nil). Confira isso nó por
// nó. Insira 40, 20, 60, 10, 30, 50, 70, 5, 15, 25 (vermelhopreto.h) e
// escreva bh(T, x), nos(T, x) e tabela(T, x), que mostra em ordem, para
// cada nó: chave, cor, bh, nós da subárvore, 2^bh - 1 e "ok" se a
// desigualdade vale.
//
//   Saída esperada:
//     5 vermelho bh 1 | nós  1 | 2^bh - 1 = 1 ok
//    10 preto    bh 1 | nós  3 | 2^bh - 1 = 1 ok
//    15 vermelho bh 1 | nós  1 | 2^bh - 1 = 1 ok
//    20 vermelho bh 2 | nós  6 | 2^bh - 1 = 3 ok
//    25 vermelho bh 1 | nós  1 | 2^bh - 1 = 1 ok
//    30 preto    bh 1 | nós  2 | 2^bh - 1 = 1 ok
//    40 preto    bh 2 | nós 10 | 2^bh - 1 = 3 ok
//    50 vermelho bh 1 | nós  1 | 2^bh - 1 = 1 ok
//    60 preto    bh 1 | nós  3 | 2^bh - 1 = 1 ok
//    70 vermelho bh 1 | nós  1 | 2^bh - 1 = 1 ok
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "vermelhopreto.h"

int main(void) {

    return 0;
}
