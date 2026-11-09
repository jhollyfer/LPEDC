// Lista · Módulo 15 · Tabelas hash
// Exercício P1505 · ★☆☆ · Dispersão dupla no guarda-volumes
//
// O guarda-volumes da rodoviária tem m = 13 posições e usa DISPERSÃO DUPLA:
// h(k, i) = (h1(k) + i · h2(k)) % 13, com h1(k) = k % 13 e
// h2(k) = 1 + (k % 11). Escreva h1, h2 e int insere(int tab[], int k), que
// devolve a posição. Insira os tickets 27, 40, 53, 14, 66, 1 (todos com
// h1 = 1) e mostre a tabela final.
//
//   Saída esperada:
//   27 (h1 = 1, h2 = 6) -> posição 1
//   40 (h1 = 1, h2 = 8) -> posição 9
//   53 (h1 = 1, h2 = 10) -> posição 11
//   14 (h1 = 1, h2 = 4) -> posição 5
//   66 (h1 = 1, h2 = 1) -> posição 2
//   1 (h1 = 1, h2 = 2) -> posição 3
//   tabela: _ 27 66 1 _ 14 _ _ _ 40 _ 53 _
//
// Dicas:
// 1. Cada chave anda com um passo próprio, h2(k): mesmo com o mesmo h1, as
//    sequências se separam logo. É isso que acaba com o agrupamento.
// 2. h2 nunca pode ser 0 (a sondagem ficaria parada): daí o "1 +".
// 3. Com m primo, qualquer passo entre 1 e m - 1 visita as 13 posições.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define M 13
#define VAZIO -1

int main(void) {

    return 0;
}
