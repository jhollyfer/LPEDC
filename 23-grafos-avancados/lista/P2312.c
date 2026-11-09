// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2312 · ★★☆ · O alfabeto do idioma inventado
//
// Num jogo, os elfos escrevem com as letras de sempre, mas a ordem do
// alfabeto deles é outra. Você recebe listas de palavras JÁ em ordem
// alfabética élfica. Comparando duas palavras vizinhas, a primeira letra
// diferente diz quem vem antes ("cab" < "cad": b antes de d). Se uma é
// prefixo da outra, não há informação.
//
//   Lista 1: cab, cad, ae, aed, eb, bd
//   Lista 2: ba, bc, ca, ab
//
// Escreva descobre(rotulo, palavras, n) do zero: mostre cada regra que a
// lista dá e, com o Kahn sobre as 26 letras (só as que aparecem nas
// palavras), o alfabeto élfico. Se o Kahn não consegue tirar todas as
// letras, a lista é inconsistente. Escolha da fila: letras livres entram
// em ordem de 'a' a 'z'.
//
//   Saída esperada:
//   Lista 1
//     cab < cad: b antes de d
//     cad < ae: c antes de a
//     aed < eb: a antes de e
//     eb < bd: e antes de b
//     alfabeto: caebd
//   Lista 2
//     ba < bc: a antes de c
//     bc < ca: b antes de c
//     ca < ab: c antes de a
//     lista inconsistente: as regras formam um ciclo
//
// Dicas:
// 1. Vértice c = letra - 'a'. Marque aparece[c] para todas as letras de
//    todas as palavras; são elas que contam no fim.
// 2. Cuidado para não somar 2 no grau se a mesma regra aparecer duas
//    vezes: só some quando antes[a][b] ainda era 0.
// 3. Resposta esperada: Lista 1 dá o alfabeto caebd; a Lista 2 tem o ciclo
//    a antes de c e c antes de a.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
