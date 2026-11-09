// 0180 · Pigeonhole e chave composta
// Exercício E1080 · ★★★
//
// A seleção não é estável porque a TROCA pula por cima de quem está no
// meio. Escreva selecao_estavel(v, n): ache o menor como de costume (o
// primeiro, no empate) e, em vez de trocar com v[i], desloque v[i..menor-1]
// uma casa para a direita e ponha o menor em v[i]. Compare com pb_selecao
// (pombal.h) na lista de chamada Ana 7, Bruno 5, Carla 9, Diego 5, Elisa 7,
// Fabio 3, Gabi 9, Hugo 5 (o campo turma não importa aqui).
//
//   Saída esperada:
//   seleção comum:   Fabio(3) Bruno(5) Diego(5) Hugo(5) Elisa(7) Ana(7) Gabi(9) Carla(9)
//   seleção estável: Fabio(3) Bruno(5) Diego(5) Hugo(5) Ana(7) Elisa(7) Carla(9) Gabi(9)
//
// Dicas:
// 1. Guarde x = v[menor]; depois for (k = menor; k > i; k--) v[k] = v[k-1];
//    e v[i] = x.
// 2. O preço: a troca era O(1); o deslocamento é O(n). O total continua
//    O(n²) comparações, mas agora com O(n²) movimentos também.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "pombal.h"

int main(void) {

    return 0;
}
