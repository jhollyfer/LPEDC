// Lista · Módulo 07 · Memória dinâmica
// Exercício P0709 · ★☆☆ · O realloc não zera
//
// O calloc entrega o bloco zerado, mas, quando o realloc aumenta o bloco, a
// parte nova vem com o que estiver lá (lixo). Escreva
//
//   int *crescer_zerado(int *v, int n_velho, int n_novo);
//
// que aumenta o bloco com realloc e zera SÓ as posições novas (de n_velho a
// n_novo - 1), devolvendo o novo endereço (ou NULL, deixando v intacto). No
// main, crie com calloc os pontos de 3 jogadores de um torneio de dominó,
// anote algumas vitórias, cresça para 5 jogadores e anote mais. Mostre o
// placar nas duas etapas:
//
//   Saída esperada:
//   Placar (3 jogadores): 2 0 1
//   Placar (5 jogadores): 3 0 1 0 3
//
// Dicas:
// 1. int *novo = realloc(v, n_novo * sizeof *novo); if (novo == NULL)
//    return NULL;
// 2. for (int i = n_velho; i < n_novo; i++) novo[i] = 0;
// 3. As posições antigas o realloc preserva (ele copia, se precisar mudar o
//    bloco de lugar).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
