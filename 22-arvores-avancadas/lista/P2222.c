// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2222 · ★★★ · A árvore B dos códigos de rastreio
//
// Escreva do zero uma árvore B de grau mínimo t = 2 (de 1 a 3 chaves por
// nó, até 4 filhos), com a inserção do Cormen que DIVIDE os nós cheios na
// descida, a busca e um percurso por níveis. Insira os códigos de rastreio
// abaixo, nesta ordem, mostre a árvore por níveis, a altura (em arestas) e
// o resultado da busca de 57 e de 60, com o número de nós visitados.
//
//   41 17 88 5 63 29 72 95 12 57 34 80 3 66 21 48 99 9
//
//   Saída esperada:
//   Nível 0: [41]
//   Nível 1: [5 17] [63 72 88]
//   Nível 2: [3] [9 12] [21 29 34] [48 57] [66] [80] [95 99]
//   Altura: 2
//   Busca 57: achou (nós visitados: 3)
//   Busca 60: não achou (nós visitados: 3)
//
// Dicas:
// 1. divide(x, i): o filho i de x (cheio, 3 chaves) vira dois nós de uma
//    chave, e a do meio sobe para x na posição i. Na raiz cheia, crie uma
//    raiz nova vazia antes.
// 2. Na descida, se o filho em que você vai entrar está cheio, divida
//    antes e decida de novo entre os dois pedaços.
// 3. Resposta esperada: a árvore da saída, com todas as folhas no mesmo
//    nível; o 57 está na árvore e o 60 não.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
