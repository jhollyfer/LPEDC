// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2306 · ★☆☆ · Fibra nas escolas rurais
//
// A secretaria de educação vai ligar seis escolas rurais com fibra óptica:
// Sede, Vila Amazônia, Caburi, Mocambo, Tracajá e Zé Açu (índices 0 a 5).
// Os trechos possíveis (mão dupla, em km):
//
//   Sede-Vila Amazônia 7, Sede-Caburi 12, Vila Amazônia-Caburi 2,
//   Vila Amazônia-Mocambo 9, Caburi-Mocambo 6, Caburi-Tracajá 10,
//   Mocambo-Tracajá 3, Mocambo-Zé Açu 4, Tracajá-Zé Açu 5, Sede-Zé Açu 15
//
// Escreva o Kruskal do zero: um vetor de struct {a, b, km}, qsort do mais
// curto para o mais longo e union-find com pai[] (sem compressão mesmo).
// Mostre cada trecho aceito e cada trecho recusado, na ordem em que o
// algoritmo os examina, e pare quando tiver V - 1 trechos.
//
//   Saída esperada:
//   aceita Vila Amazônia-Caburi (2 km)
//   aceita Mocambo-Tracajá (3 km)
//   aceita Mocambo-Zé Açu (4 km)
//   recusa Tracajá-Zé Açu (5 km): fecharia ciclo
//   aceita Caburi-Mocambo (6 km)
//   aceita Sede-Vila Amazônia (7 km)
//   Total: 22 km
//
// Dicas:
// 1. acha(x) sobe por pai[] até achar quem é pai de si mesmo.
// 2. Trecho com acha(a) == acha(b) fecharia ciclo: recuse. Senão,
//    pai[acha(a)] = acha(b) e some os km.
// 3. Resposta esperada: só Tracajá-Zé Açu é recusado; total 22 km.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
