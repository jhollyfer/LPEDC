// 0083 · Pilha encadeada
// Exercício E498 · ★★★
//
// Uma estação meteorológica empilha as temperaturas do dia e às vezes
// descarta a última leitura (sensor com defeito). A qualquer momento ela
// quer saber a MENOR temperatura que está na pilha, e essa consulta precisa
// custar O(1): nada de percorrer a pilha.
//
// Escreva um tipo PilhaMin com duas Pilha * dentro (a dos valores e a dos
// mínimos) e as funções min_cria, min_empilha, min_desempilha, min_atual e
// min_libera. Teste empilhando 22, 19, 25, 17 e 30 e depois desempilhando
// quatro vezes.
//
//   Saída esperada:
//   empilha 22 -> mínimo 22
//   empilha 19 -> mínimo 19
//   empilha 25 -> mínimo 19
//   empilha 17 -> mínimo 17
//   empilha 30 -> mínimo 17
//   desempilha 30 -> mínimo 17
//   desempilha 17 -> mínimo 19
//   desempilha 25 -> mínimo 19
//   desempilha 19 -> mínimo 22
//
// Dicas:
// 1. A pilha dos mínimos anda junto com a dos valores: a cada empilhamento,
//    empilhe nela o menor entre o valor novo e o mínimo atual.
// 2. Ao desempilhar, tire das duas.
// 3. min_atual é só um pilha_topo na pilha dos mínimos.
// 4. Resposta esperada: as nove linhas acima. Custa o dobro de memória em
//    troca de O(1) na consulta.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void) {

    return 0;
}
