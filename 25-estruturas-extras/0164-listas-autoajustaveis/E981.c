// 0164 · Listas autoajustáveis
// Exercício E981 · ★★☆
//
// Uma política intermediária entre mover para a frente e transposição: o
// item achado sobe DUAS casas (ou vai para o início, se estava na posição 1
// ou 2, contando do 0). Usando o autolista.h, escreva
// bool busca_sobe2(AutoLista *l, const char *nome, int *custo), que aplica
// essa política, devolve se achou e guarda em *custo quantos nós comparou.
// A agenda começa com Ana Bia Caio Duda Edu; as chamadas são Edu, Edu, Duda,
// Edu e Duda. Mostre cada chamada com o custo e a agenda depois dela, e o
// total:
//
//   Saída esperada:
//   Edu  custo 5 -> Ana Bia Edu Caio Duda
//   Edu  custo 3 -> Edu Ana Bia Caio Duda
//   Duda custo 5 -> Edu Ana Duda Bia Caio
//   Edu  custo 1 -> Edu Ana Duda Bia Caio
//   Duda custo 3 -> Duda Edu Ana Bia Caio
//   Total: 17
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include "autolista.h"

int main(void) {

    return 0;
}
