// 0163 · Skip list
// Exercício E976 · ★★☆
//
// Ache o bug. A concessionária desativou a parada do km 23. A função
// remove_parada abaixo tira o nó da lista e libera a memória, mas a busca
// seguinte quebra: o AddressSanitizer acusa heap-use-after-free dentro de
// skip_busca. Conserte remove_parada (sem usar skip_remove) e rode de novo.
//
//   Saída esperada (sem nenhum erro do sanitizer):
//   km 47: tem parada
//   km 23: não tem parada
//   andar 2:                          56
//   andar 1:      12          40      56
//   andar 0:   5  12  18  31  40  47  56
//
// Dicas:
// 1. O 23 aparece em 3 andares. Depois do free, quem ainda aponta para ele?
//    Olhe a cabeça no andar 2 e o 12 no andar 1.
// 2. antes[k] já guarda o nó anterior em cada andar. Falta desligar o nó em
//    todos os andares dele: k de 0 até x->andares - 1.
// 3. Resposta esperada: troque a linha antes[0]->prox[0] = x->prox[0] por um
//    laço que faz antes[k]->prox[k] = x->prox[k] para cada andar do nó.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>
#include "skip.h"

void remove_parada(Skip *s, int chave) {
    NoSkip *antes[SKIP_MAX];
    NoSkip *x = &s->cabeca;
    for (int k = SKIP_MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && x->prox[k]->chave < chave) {
            x = x->prox[k];
        }
        antes[k] = x;
    }
    x = x->prox[0];
    if (x == NULL || x->chave != chave) {
        return;
    }
    antes[0]->prox[0] = x->prox[0]; // tira o nó da lista
    free(x);
    s->n--;
}

void procura(const Skip *s, int km) {
    printf("km %d: %s\n", km, skip_busca(s, km, NULL) ? "tem parada" : "não tem parada");
}

int main(void) {
    int km[] = {5, 12, 18, 23, 31, 40, 47, 56};
    int andares[] = {1, 2, 1, 3, 1, 2, 1, 3};
    Skip *linha = skip_cria(0);
    for (int i = 0; i < 8; i++) {
        skip_insere_andares(linha, km[i], andares[i]);
    }

    remove_parada(linha, 23);
    procura(linha, 47);
    procura(linha, 23);
    skip_mostra(linha);

    skip_libera(linha);
    return 0;
}
