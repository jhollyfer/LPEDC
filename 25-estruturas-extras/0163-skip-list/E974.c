// 0163 · Skip list
// Exercício E974 · ★☆☆
//
// Escreva faixa(s, a, b), que mostra todas as chaves entre a e b (incluindo
// os dois), em ordem. Use os andares para chegar perto de a sem passar por
// todo mundo; depois ande pelo andar 0 até passar de b. Se não houver
// nenhuma, mostre " nenhuma".
//
//   Saída esperada:
//   Paradas entre km 15 e km 45: 18 23 31 40
//   Paradas entre km 41 e km 46: nenhuma
//   Paradas entre km 50 e km 99: 56
//
// Dicas:
// 1. A primeira parte é a busca de a: em cada andar, avance enquanto
//    x->prox[k] != NULL e x->prox[k]->chave < a; depois desça.
// 2. No fim da descida, x->prox[0] é a primeira chave >= a. Ande com
//    p = x->prox[0] enquanto p != NULL e p->chave <= b.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "skip.h"

int main(void) {
    int km[] = {5, 12, 18, 23, 31, 40, 47, 56};
    int andares[] = {1, 2, 1, 3, 1, 2, 1, 3};
    Skip *linha = skip_cria(0);
    for (int i = 0; i < 8; i++) {
        skip_insere_andares(linha, km[i], andares[i]);
    }

    skip_libera(linha);
    return 0;
}
