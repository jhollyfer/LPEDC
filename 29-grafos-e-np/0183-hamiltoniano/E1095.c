// 0183 · Hamiltoniano
// Exercício E1095 · ★★☆
//
// O carro-forte quer saber quantas rotas diferentes existem, não só uma.
// Escreva int conta(int pos), uma variação do hamilton do texto que não
// para na primeira rota: soma quantas rotas completas existem a partir da
// Base. Cada ciclo aparece duas vezes (uma em cada sentido), então divida
// por 2 para ter os ciclos distintos. Rode no mapa das agências e no grafo
// completo de 5 vértices (todos ligados a todos).
//
//   Saída esperada:
//   Agências: 4 rotas, 2 ciclos distintos
//   Completo com 5: 24 rotas, 12 ciclos distintos
//
// Dicas:
// 1. Quando pos == n, devolva 1 se o último liga na Base, senão 0. No
//    laço, some conta(pos + 1) em vez de devolver true.
// 2. Use uma matriz MAXV x MAXV e uma variável global n para reaproveitar o
//    mesmo código nos dois grafos (lembre de zerar usado[]).
// 3. Resposta esperada: a saída acima. No completo com n vértices são
//    (n - 1)! rotas, ou (n - 1)! / 2 ciclos: 24 e 12 para n = 5.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
