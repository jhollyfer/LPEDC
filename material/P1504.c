// Lista · Módulo 15 · Tabelas hash
// Exercício P1504 · ★☆☆ · Sondagem quadrática nas vagas
//
// O estacionamento usa uma tabela com m = 8 vagas e sondagem QUADRÁTICA:
// h(k, i) = (k % 8 + (i + i²) / 2) % 8, para i = 0, 1, 2, ... (o caso
// c₁ = c₂ = 1/2 do Cormen; os deslocamentos são 0, 1, 3, 6, 10, ...).
// Escreva int insere(int tab[], int k), que devolve a posição onde k ficou
// (ou -1). Insira 12, 20, 4, 28, 13, 36 e mostre a tabela final.
//
//   Saída esperada:
//   12 -> posição 4
//   20 -> posição 5
//   4 -> posição 7
//   28 -> posição 2
//   13 -> posição 6
//   36 -> posição 3
//   tabela: _ _ 28 36 12 20 13 4
//
// Dicas:
// 1. 12, 20, 4, 28 e 36 têm todos k % 8 = 4. Com a linear, eles fariam um
//    bloco 4, 5, 6, 7, 0; com a quadrática, cada um salta mais longe.
// 2. Faça à mão o 28: 4 (ocupado), 5 (ocupado), 7 (ocupado), 4 + 6 = 10 % 8
//    = 2 (livre).
// 3. Com m potência de 2 e esses c₁ e c₂, a sequência visita todas as
//    posições. Com outros m, pode não visitar.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define M 8
#define VAZIO -1

int main(void) {

    return 0;
}
