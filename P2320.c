// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2320 · ★★☆ · Quantos jeitos de descer a ladeira
//
// Em Olinda, um bloco de carnaval quer descer do Alto da Sé até a Praia
// sem subir nunca. As ladeiras (só de descida) ligam:
//
//   Alto da Sé -> Amparo, Alto da Sé -> Misericórdia, Amparo -> Bonsucesso,
//   Misericórdia -> Bonsucesso, Misericórdia -> Carmo, Bonsucesso -> Varadouro,
//   Carmo -> Varadouro, Bonsucesso -> Praia, Varadouro -> Praia,
//   Carmo -> Praia, Amparo -> Carmo
//
// Quantos trajetos diferentes chegam em cada ponto? Escreva do zero: ordem
// topológica pelo Kahn e, nessa ordem, jeitos[v] += jeitos[u] para cada
// ladeira u -> v, com jeitos[Alto da Sé] = 1. Mostre cada ponto na ordem
// topológica com a sua contagem.
//
//   Saída esperada:
//   Alto da Sé: 1
//   Amparo: 1
//   Misericórdia: 1
//   Bonsucesso: 2
//   Carmo: 2
//   Varadouro: 4
//   Praia: 8
//
// Dicas:
// 1. Os índices são 0 a 6 na ordem em que os pontos aparecem acima.
// 2. É programação dinâmica num DAG: quando u é processado, jeitos[u] já
//    tem todos os caminhos que chegam nele.
// 3. Resposta esperada: 8 trajetos chegam à Praia.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
