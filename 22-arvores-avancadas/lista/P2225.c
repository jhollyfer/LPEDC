// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2225 · ★★★ · Pintar uma árvore de busca de rubro-negra
//
// Nem toda árvore de busca pode virar rubro-negra só escolhendo as cores:
// a forma precisa deixar. Escreva do zero um backtracking (módulo 19) que
// tenta pintar os nós de uma árvore de busca, um por um em pré-ordem, de
// preto ou vermelho, cortando o ramo assim que um vermelho ganha um pai
// vermelho; quando todos têm cor, confira a raiz preta e a altura negra
// igual em todos os caminhos. Conte quantas colorações válidas cada árvore
// tem e mostre a primeira (vermelho com *, em pré-ordem).
//
//   A: 20(10(5, 15), 30(25, 40))
//   B: 20(10(5, -), 30(25, 40(-, 50)))
//   C: 20(10, 30(25, 40(-, 50(-, 60))))
//
//   Saída esperada:
//   A: 5 coloração(ões), a primeira: 20 10 5 15 30 25 40
//   B: 1 coloração(ões), a primeira: 20 10 5* 30* 25 40 50*
//   C: 0 coloração(ões)
//
// Dicas:
// 1. Guarde os nós num vetor em pré-ordem (com o índice do pai de cada
//    um). Ao pintar o nó i de vermelho, corte se o pai dele é vermelho.
// 2. A conferência final é a altura_negra que devolve -1 quando dois
//    caminhos discordam.
// 3. Resposta esperada: A tem 5 colorações; B, algumas; C nenhuma (o ramo
//    da direita é comprido demais: o caminho mais longo passaria do dobro
//    do mais curto).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
