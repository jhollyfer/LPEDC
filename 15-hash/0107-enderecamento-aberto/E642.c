// 0107 · Endereçamento aberto
// Exercício E642 · ★★★
//
// A sondagem linear sofre com o agrupamento: chaves com o mesmo hash formam
// um bloco que cresce. O hash duplo resolve com um passo que depende da
// chave: em vez de i = (i + 1) % m, faz i = (i + passo) % m, com
// passo = 1 + k % 10. Com m = 11 (primo), qualquer passo de 1 a 10 visita
// todas as posições.
//
// Escreva uma função que simula as inserções numa tabela de 11 posições e
// recebe o passo como ponteiro para função. Para as chaves
//
//   5 16 27 8 38 19 30 2
//
// mostre as sondagens de cada inserção e o total, primeiro com passo 1
// (linear), depois com o hash duplo.
//
//   Saída esperada:
//   linear: 1 2 3 1 5 3 4 1 | total: 20
//   duplo : 1 2 2 1 2 2 2 4 | total: 16
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
