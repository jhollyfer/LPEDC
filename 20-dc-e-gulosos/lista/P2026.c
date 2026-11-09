// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2026 · ★★★ · Comprar barato, vender caro
//
// O preço de fechamento de uma ação em 12 pregões, em reais:
//
//   dia:    0  1  2  3  4  5  6  7  8  9 10 11
//   preço: 31 27 34 22 25 41 36 19 24 33 38 29
//
// Você compra num dia i e vende num dia j > i. Qual o maior lucro? Por
// divisão e conquista: o melhor negócio está todo na metade esquerda, ou
// todo na direita, ou compra na esquerda e vende na direita (aí é o menor
// preço da esquerda com o maior da direita). Escreva do zero uma função
// que, para v[ini..fim], devolve num struct o lucro, os dias de compra e
// venda, e também o menor e o maior preço do pedaço (com os dias), para o
// caso que cruza sair em O(1). Confira com a força bruta de todos os pares.
//
//   Saída esperada:
//   Compra no dia 3 (R$ 22), vende no dia 5 (R$ 41)
//   Lucro: R$ 19
//   Força bruta: R$ 19
//
// Dicas:
// 1. Caso base, um dia só: lucro 0 (não há venda), menor = maior = v[i].
// 2. Junte: cruza = d.maior - e.menor; o menor do pedaço é o menor entre
//    e.menor e d.menor; o maior, o maior entre e.maior e d.maior. Com o
//    trabalho de junção O(1), a recorrência é T(n) = 2T(n/2) + O(1), O(n).
// 3. Resposta esperada: compra no dia 3 (R$ 22) e vende no dia 5 (R$ 41),
//    lucro R$ 19. A força bruta concorda.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
