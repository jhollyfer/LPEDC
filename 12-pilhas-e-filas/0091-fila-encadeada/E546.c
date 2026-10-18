// 0091 · Fila encadeada
// Exercício E546 · ★★★
//
// Dá para fazer uma fila com UM ponteiro só: numa lista circular, o último
// nó aponta de volta para o primeiro. Guardando só ultimo, o primeiro é
// ultimo->prox. Escreva do zero (sem o fila.h) as funções
//
//   bool circ_insere(No **ultimo, int valor)
//   bool circ_retira(No **ultimo, int *valor)
//
// e teste com a mesma história do A181: entram 501, 502 e 503, sai um, entra
// o 504 e a fila é esvaziada.
//
//   Saída esperada:
//   Preparando: 501
//   Depois: 502 503 504
//
// Dicas:
// 1. Fila vazia: ultimo == NULL. Com um nó só, ele aponta para ele mesmo.
// 2. Inserir: o novo aponta para o primeiro (ultimo->prox), o antigo
//    último aponta para o novo, e o novo vira o último.
// 3. Retirar: o primeiro é ultimo->prox. Se ele for o próprio último (um
//    nó só), a fila fica vazia; senão, ultimo->prox pula para o seguinte.
// 4. Resposta esperada: as duas linhas acima, sem vazamento.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
