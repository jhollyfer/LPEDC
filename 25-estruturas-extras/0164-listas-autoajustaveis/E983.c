// 0164 · Listas autoajustáveis
// Exercício E983 · ★★★
//
// O aplicativo de fotos guarda na memória só as 3 últimas fotos abertas
// (um cache). Foto pedida que está no cache é um ACERTO: ela vai para a
// frente. Foto que não está é uma FALTA: ela é carregada e entra na frente;
// se o cache passar de 3, sai a do fim, a usada há mais tempo. Essa política
// se chama LRU (least recently used) e é mover para a frente com um corte.
//
// Escreva do zero, com uma lista encadeada de int: leia os números das
// fotos até o fim da entrada, mostre o que aconteceu em cada pedido e, no
// fim, o total de acertos e faltas. Libere a lista.
//
// Teste com:
//   printf '7 3 7 5 9 3 7 9 9 1\n' | ~/LPEDC/rodar 25-estruturas-extras/0164-listas-autoajustaveis/E983.c
//
//   Saída esperada:
//   foto 7: falta  -> 7
//   foto 3: falta  -> 3 7
//   foto 7: acerto -> 7 3
//   foto 5: falta  -> 5 7 3
//   foto 9: falta  -> 9 5 7
//   foto 3: falta  -> 3 9 5
//   foto 7: falta  -> 7 3 9
//   foto 9: acerto -> 9 7 3
//   foto 9: acerto -> 9 7 3
//   foto 1: falta  -> 1 9 7
//   Acertos: 3, faltas: 7
//
// Dicas:
// 1. A busca com mover para a frente é a do texto, com int no lugar do
//    nome. Se achou, é acerto.
// 2. Na falta, crie o nó no início e some 1 no tamanho. Se o tamanho passar
//    de 3, ande até o penúltimo nó, libere o último e ponha NULL no prox do
//    penúltimo.
// 3. Resposta esperada: a saída acima. Repare na foto 3 do sexto pedido:
//    ela já tinha estado no cache, mas saiu antes de ser pedida de novo.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 3

int main(void) {

    return 0;
}
