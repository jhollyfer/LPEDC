// 0178 · Hash: divisão e multiplicação
// Exercício E1068 · ★★★
//
// O método da multiplicação aceita m = 2^p, e isso permite uma tabela que
// DOBRA de tamanho. Escreva uma tabela hash com encadeamento (listas) cujo
// índice é (k * 2654435769u) >> (32 - p), com uint32_t. Ela começa com m = 4
// e, antes de inserir, se n + 1 passar de m, dobra: cria 2m baldes vazios e
// move cada nó para o balde novo (o índice muda, porque p muda), sem malloc
// novo por item, mostrando "dobrou: m = ... (n = ...)". Insira as
// matrículas 1000, 2000, ..., 100000 e mostre n, m, o fator de carga e o
// tamanho da maior lista. Libere tudo no fim.
//
//   Saída esperada:
//   dobrou: m = 8 (n = 4)
//   dobrou: m = 16 (n = 8)
//   dobrou: m = 32 (n = 16)
//   dobrou: m = 64 (n = 32)
//   dobrou: m = 128 (n = 64)
//   fim: n = 100, m = 128, fator de carga 0.78, maior lista 2
//
// Dicas:
// 1. A struct da tabela guarda Item **balde, int p e int n. Os baldes vêm
//    de calloc((size_t)1 << p, sizeof(Item *)).
// 2. Na dobra, ande em cada lista velha guardando o prox antes de religar o
//    nó no balde novo; no fim, free no vetor velho (os nós continuam vivos).
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
