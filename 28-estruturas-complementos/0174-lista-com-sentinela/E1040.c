// 0174 · Lista com sentinela
// Exercício E1040 · ★☆☆
//
// No guichê da prefeitura, a lista com sentinela (sentinela.h) funciona como
// fila dupla: a atendente chama alternadamente o primeiro e o último da
// fila. Insira as senhas 1 a 5 no fim e, até a fila esvaziar, remova o
// primeiro (L->nil.prox), depois o último (L->nil.ant), e assim por diante,
// mostrando quem foi chamado e como a fila ficou. Nenhum if para "lista com
// um nó só": o mesmo sent_remove serve para tudo.
//
//   Saída esperada:
//   chama 1: [ 2 3 4 5 ]
//   chama 5: [ 2 3 4 ]
//   chama 2: [ 3 4 ]
//   chama 4: [ 3 ]
//   chama 3: [ ]
//
// Dicas:
// 1. Use uma variável bool (ou um contador) para alternar entre a frente e o
//    fim, e um while (L->n > 0).
// 2. Guarde a chave antes do sent_remove: depois dele o nó já foi liberado.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include "sentinela.h"

int main(void) {

    return 0;
}
