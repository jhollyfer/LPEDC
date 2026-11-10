// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2030 · ★★★ · O guloso que pinta demais
//
// Oito transmissores de rádio comunitária ficam em dois morros: A0, A1, A2
// e A3 num, B0, B1, B2 e B3 no outro. Ai interfere com Bj sempre que i !=
// j (e os do mesmo morro não interferem entre si). Transmissores que
// interferem precisam de frequências diferentes. Isso é colorir o grafo, e
// o guloso popular é: percorra os vértices numa ordem e dê a cada um a
// menor frequência que nenhum vizinho já pintado usa. Escreva do zero:
// (a) o guloso na ordem A0 B0 A1 B1 A2 B2 A3 B3; (b) o guloso na ordem A0
// A1 A2 A3 B0 B1 B2 B3; (c) o mínimo de cores por backtracking (como no
// módulo 19). Mostre a frequência de cada um e o total de cada método.
//
//   Saída esperada:
//   Guloso intercalado: A0=0 A1=1 A2=2 A3=3 B0=0 B1=1 B2=2 B3=3 (4 frequências)
//   Guloso por morro: A0=0 A1=0 A2=0 A3=0 B0=1 B1=1 B2=1 B3=1 (2 frequências)
//   Ótimo: A0=0 A1=0 A2=0 A3=0 B0=1 B1=1 B2=1 B3=1 (2 frequências)
//
// Dicas:
// 1. Numere A0..A3 como 0..3 e B0..B3 como 4..7; viz(u, v) é verdadeiro
//    quando um é A, o outro é B e os números são diferentes.
// 2. guloso(ordem[]) usa cor[] = -1 para "ainda não pintado" e procura a
//    menor cor c que nenhum vizinho pintado tem.
// 3. Resposta esperada: a ordem intercalada usa 4 frequências, a ordem por
//    morro usa 2, e o ótimo é 2. O guloso depende da ordem e pode errar
//    feio: neste tipo de grafo (a "coroa"), com n pares, ele chega a n cores.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
