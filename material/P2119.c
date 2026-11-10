// Lista · Módulo 21 · Programação dinâmica
// Exercício P2119 · ★★☆ · O triângulo do cofrinho
//
// No jogo da quermesse, as moedas estão num triângulo. Você começa no topo
// e, a cada linha, desce para a moeda logo abaixo ou para a de baixo à
// direita, somando os valores (em reais). Qual o maior total?
//
//         7
//        3 8
//       8 1 0
//      2 7 4 4
//     4 5 2 6 5
//    1 6 9 3 2 8
//
// Testar todos os caminhos custa 2^(n-1). Escreva do zero a PD de BAIXO
// PARA CIMA: a última linha já é a resposta de cada moeda; em cada linha de
// cima, melhor[l][c] = t[l][c] + o maior entre melhor[l + 1][c] e
// melhor[l + 1][c + 1]. O topo fica com a resposta. Mostre também o
// caminho.
//
//   Saída esperada:
//   Maior total: R$ 39
//   Caminho: 7 3 8 7 5 9
//
// Dicas:
// 1. Guarde o triângulo numa matriz 6 × 6 em que a linha l usa as colunas 0
//    a l.
// 2. Para o caminho, comece no topo (c = 0) e, em cada linha, vá para a
//    coluna c ou c + 1, a que tiver o maior melhor[][] embaixo.
// 3. Resposta esperada: R$ 39, pelo caminho 7 3 8 7 5 9.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
