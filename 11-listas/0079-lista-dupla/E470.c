// 0079 · Lista dupla
// Exercício E470 · ★☆☆
//
// Na lista dupla, quem acha um nó acha também os dois vizinhos dele, sem
// percorrer de novo. O main abaixo já monta a lista misturando inserções no
// início e no fim. Escreva a função
//
//   void mostra_vizinhos(const Lista *l, int valor)
//
// que busca o valor com lista_busca e mostra quem vem antes e quem vem
// depois dele ("nenhum" nas pontas), ou avisa que ele não está na lista.
//
//   Saída esperada:
//   4 <-> 2 <-> 1 <-> 3
//   4: antes nenhum, depois 2
//   1: antes 2, depois 3
//   3: antes 1, depois nenhum
//   9: não está na lista
//
// Dicas:
// 1. Desenhe os nós com as duas setas antes: a ordem saiu 4 2 1 3.
// 2. Achado o nó p, o vizinho de trás é p->ant e o da frente é p->prox.
//    Teste cada um contra NULL antes de ler o valor.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "lista.h"

int main(void) {
    Lista l;
    lista_inicia(&l);
    lista_insere_fim(&l, 1);
    lista_insere_inicio(&l, 2);
    lista_insere_fim(&l, 3);
    lista_insere_inicio(&l, 4);
    lista_imprime(&l);

    // chame mostra_vizinhos para 4, 1, 3 e 9

    lista_libera(&l);
    return 0;
}
