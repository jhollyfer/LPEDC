// 0114 · Recorrências e árvore de recursão
// Exercício E681 · ★★☆
//
// Um comparador de preços confere um lote assim: compara cada preço com todos
// os do lote (n² comparações), divide o lote ao meio e confere cada metade do
// mesmo jeito: T(n) = 2 T(n/2) + n², T(1) = 1. Escreva a função recursiva
// que conta as comparações POR NÍVEL da recursão e mostre os níveis para n = 8
// e, depois, o total para n = 16, 32 e 64 ao lado de 2n² - n. Preços:
// preco[i] = 5 + (i * 13) % 40, e um par é suspeito quando um preço passa do
// dobro do outro (conte também os suspeitos, sem mostrar).
//
//   Saída esperada:
//   nível 0: 64 comparações
//   nível 1: 32 comparações
//   nível 2: 16 comparações
//   nível 3: 8 comparações
//   total: 120
//    n  T(n)  2n² - n
//   16   496   496
//   32  2016  2016
//   64  8128  8128
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
