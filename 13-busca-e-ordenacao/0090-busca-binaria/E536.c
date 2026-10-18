// 0090 · Busca binária
// Exercício E536 · ★☆☆
//
// Escreva a busca binária em versão RECURSIVA:
//
//   int busca_rec(const int v[], int ini, int fim, int x)
//
// que procura x em v[ini..fim] e devolve o índice ou -1. Teste com esta
// lista de CEPs em ordem crescente (guardados como int; mostre com %08d para
// o zero da frente aparecer):
//
//   1310100, 4538132, 20040002, 30130010, 40020000,
//   50030230, 60060440, 70040010, 80010000, 90010150
//
//   Saída esperada:
//   CEP 40020000: posição 4
//   CEP 22222222: posição -1
//
// Dicas:
// 1. Dois casos base: intervalo vazio (ini > fim) e achou (v[meio] == x).
// 2. Caso recursivo: chame a função de novo só na metade que interessa.
// 3. Não esqueça o return antes da chamada recursiva: sem ele, o resultado
//    lá de baixo se perde.
// 4. Resposta esperada: a saída acima; a primeira chamada é
//    busca_rec(ceps, 0, 9, x).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
