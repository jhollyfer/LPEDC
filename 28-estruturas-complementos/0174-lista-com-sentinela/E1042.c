// 0174 · Lista com sentinela
// Exercício E1042 · ★★☆
//
// O leitor de código de barras do caixa travou e registrou o mesmo produto
// várias vezes. Escreva remove_todas(L, codigo), que tira da lista com
// sentinela (sentinela.h) todos os nós com aquele código e devolve quantos
// saíram. A lista tem 7, 3, 3, 9, 3, 5, 3. Remova os 3 e depois os 8.
//
//   Saída esperada:
//   Antes: [ 7 3 3 9 3 5 3 ]
//   Removidos 4 do código 3: [ 7 9 5 ]
//   Removidos 0 do código 8: [ 7 9 5 ]
//
// Dicas:
// 1. Guarde x->prox numa variável antes do sent_remove(L, x): depois dele,
//    x foi liberado e não pode ser lido.
// 2. Pare quando voltar à sentinela. Os 3 seguidos e o 3 no fim não pedem
//    nenhum cuidado extra.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "sentinela.h"

int main(void) {

    return 0;
}
