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
// Dicas:
// 1. anda(l, c, passos): o primeiro teste da função é a poda,
//    passos >= menor. Comece menor com um valor maior que qualquer caminho
//    possível (L * C + 1 serve).
// 2. Ao chegar em F, a poda garante que passos < menor: atualize menor e
//    copie o mapa inteiro (com os '*') para uma matriz melhor.
// 3. Sem a poda, testando todos os caminhos e comparando só na chegada,
//    seriam 449 chamadas, e a diferença cresce muito com o mapa. Mesmo
//    assim, para menor caminho em mapa grande, a BFS (assunto 0110) é a
//    ferramenta certa: O(L · C), sem retrocesso.
// 4. Resposta esperada: as 7 linhas acima.
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
