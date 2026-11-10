// Lista · Módulo 25 · Estruturas especiais
// Exercício P2527 · ★★★ · A tabela de símbolos que aprende
//
// O compilador guarda os nomes das variáveis numa tabela hash com
// encadeamento (5 baldes; h = soma dos bytes do nome % 5). Cada nome novo
// entra no FIM da lista do seu balde. Dentro de um laço, "i" e "j" são
// procurados o tempo todo, mas ficaram no fundo dos baldes. A ideia:
// cada balde vira uma lista com MOVER PARA A FRENTE. Escreva do zero
// monta, procura(balde, nome, mtf) (devolve as comparações) e libera.
// Rode os 20 usos com a lista fixa e com mover para a frente, mostrando
// os baldes no começo e no fim.
//
//   Nomes, na ordem: total soma media n vetor aux maior menor k x i j
//   Usos: i j i soma i j i j k i j i soma i j i total i j i
//
//   Saída esperada:
//   Baldes no começo:
//     balde 0: n vetor menor x i
//     balde 1: maior j
//     balde 2: soma media k
//     balde 3: total
//     balde 4: aux
//   Lista fixa: 68 comparações em 20 buscas
//   Com mover para a frente: 28 comparações em 20 buscas
//   Baldes no fim:
//     balde 0: i n vetor menor x
//     balde 1: j maior
//     balde 2: soma k media
//     balde 3: total
//     balde 4: aux
//
// Dicas:
// 1. Com No **p andando pelo balde, mover o achado para a frente é
//    *p = x->prox; x->prox = balde[b]; balde[b] = x.
// 2. O custo de uma busca é o número de nomes comparados no balde (o hash
//    já levou ao balde certo).
// 3. Resposta esperada: 68 comparações com a lista fixa e 28 com mover
//    para a frente; no fim, i e j abrem os seus baldes.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
