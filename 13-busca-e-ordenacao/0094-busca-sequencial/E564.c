// 0094 · Busca sequencial
// Exercício E564 · ★★★
//
// Na agenda do celular você liga muito mais para umas pessoas do que para
// outras. Uma heurística antiga é o MOVER PARA A FRENTE: toda vez que a busca
// acha um contato, ele vai para a posição 0 e os anteriores andam uma casa.
//
// Agenda inicial: "Chefe", "Banco", "Pizzaria", "Ana", "Mãe".
// Acessos, nessa ordem: Mãe, Ana, Mãe, Mãe, Pizzaria, Mãe.
//
// Mostre a agenda depois de cada acesso e compare o total de comparações com
// uma busca que nunca mexe na agenda.
//
//   Saída esperada:
//   Mãe -> Mãe Chefe Banco Pizzaria Ana
//   Ana -> Ana Mãe Chefe Banco Pizzaria
//   Mãe -> Mãe Ana Chefe Banco Pizzaria
//   Mãe -> Mãe Ana Chefe Banco Pizzaria
//   Pizzaria -> Pizzaria Mãe Ana Chefe Banco
//   Mãe -> Mãe Pizzaria Ana Chefe Banco
//   Sem mover: 27 comparações
//   Movendo para a frente: 20 comparações
//
// Dicas:
// 1. Use const char *agenda[5]: mover um contato é só mover ponteiros.
// 2. Achou na posição i? Guarde agenda[i], empurre agenda[i-1..0] uma casa
//    para a direita (de trás para frente) e ponha o guardado em agenda[0].
// 3. Sem mover: Mãe custa 5 sempre, Ana 4, Pizzaria 3: 5+4+5+5+3+5 = 27.
// 4. Resposta esperada: a saída acima (5+5+2+1+5+2 = 20 comparações).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
