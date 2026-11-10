// 0129 · Labirinto
// Exercício E774 · ★★★
//
// O entregador quer o MENOR caminho da loja (S) até o cliente (F) no mapa
// do condomínio. O backtracking do texto acha um caminho qualquer; aqui
// você vai testar todos, com o "desfazer" do exemplo A258 (a casa volta a
// '.' na volta), e podar com o melhor resultado conhecido: se o caminho
// atual já tem tantos passos quanto o menor achado até agora, volte. Escreva
// do zero, tentando os vizinhos na ordem direita, baixo, esquerda, cima, e
// conte as chamadas da função recursiva.
//
//   Saída esperada:
//   menor caminho: 9 passos
//   ******
//   .##.#*
//   .....*
//   .#.##*
//   ...#.F
//   177 chamadas
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define L 5
#define C 6

char mapa[L][C + 1] = {
    "S.....",
    ".##.#.",
    "......",
    ".#.##.",
    "...#.F",
};

int main(void) {

    return 0;
}
