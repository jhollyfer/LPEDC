// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2815 · ★★☆ · O fiscal da rubro-negra
//
// Três árvores foram coloridas à mão e você tem que conferir se são rubro-
// negras. Cada nó tem chave, cor ('V' ou 'P') e dois filhos (NULL faz o
// papel da folha nil, preta). Escreva fiscal(x), que devolve a altura negra
// de x (pretos de x até NULL, contando x, sem contar o NULL) ou -1 se: um
// vermelho tem filho vermelho, ou os dois lados têm alturas negras
// diferentes. Confira também a raiz preta. As árvores (pré-ordem, com o
// filho vazio como -):
//
//   A: 20P (10V (5P, 15P), 30P (-, 35V))
//   B: 20P (10V (5V, 15P), 30P)
//   C: 20P (10P (5P, -), 30P)
//
// Monte-as com uma função novo(chave, cor, esq, dir) que usa malloc.
//
//   Saída esperada:
//   A: rubro-negra, altura negra 2
//   B: não é rubro-negra
//   C: não é rubro-negra
//
// Dicas:
// 1. NULL devolve 0. Se um filho devolveu -1, devolva -1.
// 2. Em B, o 10 vermelho tem o 5 vermelho embaixo (propriedade 4).
// 3. Em C, à esquerda do 10 há dois pretos e à direita só um (propriedade
//    5).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
