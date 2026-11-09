// Lista · Módulo 25 · Estruturas especiais
// Exercício P2520 · ★★☆ · A playlist que aprende o gosto
//
// A playlist é uma lista encadeada que se reorganiza pela CONTAGEM: cada
// nó guarda quantas vezes a música tocou, e a lista fica em ordem
// decrescente de toques. Escreva do zero toca(m): procura do começo
// (custo = posição, contando de 1), soma 1 nos toques e reinsere o nó
// depois de TODOS os que têm toques maior ou igual (no empate, quem já
// estava na frente fica). Religue ponteiros: não troque conteúdo.
//
//   Lista inicial: Asa Branca, Garota de Ipanema, Evidências, Aquarela,
//                  Tempo Perdido (todas com 0)
//   Toques: Aquarela, Evidências, Aquarela, Tempo Perdido, Evidências,
//           Evidências, Asa Branca, Aquarela
//
//   Saída esperada:
//   custo 4: Aquarela(1) Asa Branca(0) Garota de Ipanema(0) Evidências(0) Tempo Perdido(0)
//   custo 4: Aquarela(1) Evidências(1) Asa Branca(0) Garota de Ipanema(0) Tempo Perdido(0)
//   custo 1: Aquarela(2) Evidências(1) Asa Branca(0) Garota de Ipanema(0) Tempo Perdido(0)
//   custo 5: Aquarela(2) Evidências(1) Tempo Perdido(1) Asa Branca(0) Garota de Ipanema(0)
//   custo 2: Aquarela(2) Evidências(2) Tempo Perdido(1) Asa Branca(0) Garota de Ipanema(0)
//   custo 2: Evidências(3) Aquarela(2) Tempo Perdido(1) Asa Branca(0) Garota de Ipanema(0)
//   custo 4: Evidências(3) Aquarela(2) Tempo Perdido(1) Asa Branca(1) Garota de Ipanema(0)
//   custo 2: Evidências(3) Aquarela(3) Tempo Perdido(1) Asa Branca(1) Garota de Ipanema(0)
//   Custo total: 24
//
// Dicas:
// 1. Com No **p você acha o nó e o tira (*p = x->prox) sem casos à parte.
// 2. Para reinserir, ande com outro No **q do começo enquanto
//    (*q)->toques >= x->toques; depois x->prox = *q e *q = x.
// 3. Resposta esperada: custo total 24; no fim, Evidências(3) Aquarela(3)
//    na frente.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
