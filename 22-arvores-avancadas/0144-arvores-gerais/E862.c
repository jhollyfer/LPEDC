// 0144 · Árvores gerais
// Exercício E862 · ★★☆
//
// A árvore genealógica de seu Joaquim está numa árvore geral (arvgen.h). Para
// a foto da festa, os netos querem a família arrumada por geração. Escreva:
// - conta_nivel(r, alvo): quantas pessoas estão na profundidade alvo;
// - mostra_nivel(r, alvo): imprime os nomes dessa profundidade, da esquerda
//  para a direita.
// No main, use ag_altura para saber quantas gerações existem.
//
//   Saída esperada:
//   Geração 0 (1): Joaquim
//   Geração 1 (3): Rosa Jorge Vera
//   Geração 2 (5): Paulo Rita Nina Otto Pedro
//   Geração 3 (1): Leo
//
// Dicas:
// 1. Desça subtraindo: se alvo == 0, r é da geração procurada. Senão, peça
//    a cada filho a geração alvo - 1.
// 2. As gerações vão de 0 até ag_altura(r).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (escreva as duas funções e o laço do main):

#include <stdio.h>
#include "arvgen.h"

int main(void) {
    NoG *joaquim = ag_cria("Joaquim", 0);
    NoG *rosa = ag_adiciona(joaquim, "Rosa", 0);
    ag_adiciona(rosa, "Paulo", 0);
    NoG *rita = ag_adiciona(rosa, "Rita", 0);
    ag_adiciona(rita, "Leo", 0);
    NoG *jorge = ag_adiciona(joaquim, "Jorge", 0);
    ag_adiciona(jorge, "Nina", 0);
    ag_adiciona(jorge, "Otto", 0);
    ag_adiciona(jorge, "Pedro", 0);
    ag_adiciona(joaquim, "Vera", 0);

    ag_libera(joaquim);
    return 0;
}
