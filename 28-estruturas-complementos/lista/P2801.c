// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2801 · ★☆☆ · A fila do caixa com sentinela
//
// O caixa rápido do mercado atende pela ordem de chegada. Escreva, do zero,
// uma lista dupla circular com nó sentinela (a struct da lista guarda o nó
// nil dentro dela): inicia(L), insere_fim(L, senha), mostra(L) do primeiro
// ao último, mostra_inverso(L) do último ao primeiro e libera(L). Entram as
// senhas 31, 32, 33 e 34. Mostre a fila nos dois sentidos e, no fim, se a
// sentinela da lista vazia aponta para ela mesma.
//
//   Saída esperada:
//   ida:   [ 31 32 33 34 ]
//   volta: [ 34 33 32 31 ]
//   vazia: nil aponta para ela mesma? sim
//
// Dicas:
// 1. Lista vazia: nil.prox e nil.ant apontam para &L->nil.
// 2. Inserir no fim é inserir depois de nil.ant: quatro ponteiros, sem if.
// 3. Os laços começam em nil.prox (ou nil.ant) e param quando voltam a
//    &L->nil.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
